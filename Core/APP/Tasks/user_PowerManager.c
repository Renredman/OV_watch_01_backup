#include "rtc.h"
#include "cmsis_os.h"
#include "FreeRTOS.h"
#include "gui_guider.h"
#include "main.h"
#include "Tasks/user_PowerManager.h"
#include "lcd_init.h"
#include "Tasks/AppState.h"
#include "key.h"
#include "CST816.h"
#include "power.h"
#include "WDOG.h"
#include "gpio.h"
#include "Config/ov_project_config.h"
#include "Services/ProjectLog.h"
#include "Services/SystemStatus.h"

uint16_t IdleTimerCount = 0;
uint8_t ui_LTimeValue = OV_IDLE_TIMEOUT_SECONDS;
uint8_t ui_TTimeValue = OV_STOP_TIMEOUT_SECONDS;
static volatile uint8_t g_exit_low_power = 0;

void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc)
{
    (void)hrtc;
}

void StopEnterTask(void *argument)
{
    uint8_t stop_msg;

    (void)argument;

    while (1) {
        if (osMessageQueueGet(Stop_MessageQueueHandle, &stop_msg, NULL, 0) == osOK) {
            IdleTimerCount = 0;
            SystemStatus_SetStopResume(false);
            OV_LOGI("power", "enter stop mode");

            LCD_RES_Clr();
            LCD_Close_Light();
            CST816_Sleep();
            WDOG_Disnable();

            __HAL_RCC_GPIOA_CLK_ENABLE();
            GPIO_InitTypeDef gpio_init = {0};
            gpio_init.Pin = GPIO_PIN_5;
            gpio_init.Mode = GPIO_MODE_INPUT;
            gpio_init.Pull = GPIO_PULLUP;
            HAL_GPIO_Init(GPIOA, &gpio_init);

            while (1) {
                HAL_RTCEx_DeactivateWakeUpTimer(&hrtc);
                HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, OV_RTC_WAKEUP_STOP_TICKS, RTC_WAKEUPCLOCK_RTCCLK_DIV16);

                vTaskSuspendAll();
                SysTick->CTRL = 0;
                HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
                xTaskResumeAll();

                __HAL_RCC_GPIOA_CLK_ENABLE();

                if (HAL_GPIO_ReadPin(KEY1_PORT, KEY1_PIN) == GPIO_PIN_RESET) {
                    break;
                }
            }

            SystemClock_Config();
            HAL_SYSTICK_Config(SystemCoreClock / 1000);
            MX_GPIO_Init();
            LCD_Init();
            LCD_Set_Light(g_app_state.scr1_slider_value);
            CST816_Wakeup();
            g_app_state.password_verified = false;

            HAL_RTCEx_DeactivateWakeUpTimer(&hrtc);
            HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, OV_RTC_WAKEUP_ACTIVE_TICKS, RTC_WAKEUPCLOCK_RTCCLK_DIV16);

            WDOG_Enable();
            WDOG_Feed();
            IdleTimerCount = 0;
            SystemStatus_SetStopResume(true);
            OV_LOGI("power", "resume from stop mode");
        }
        osDelay(100);
    }
}

void IdleTimerCallback(void *argument)
{
    uint8_t msg;

    (void)argument;

    IdleTimerCount += 1;

    if (IdleTimerCount == (ui_LTimeValue * 10U)) {
        msg = 0;
        osMessageQueuePut(Idle_MessageQueueHandle, &msg, 0, 0);
    }

    if (IdleTimerCount == (ui_TTimeValue * 10U)) {
        msg = 1;
        osMessageQueuePut(Stop_MessageQueueHandle, &msg, 0, 0);
    }
}

void IdleEnterTask(void *argument)
{
    uint8_t msg;

    (void)argument;

    while (1) {
        if (osMessageQueueGet(Idle_MessageQueueHandle, &msg, NULL, 0) == osOK) {
            LCD_Set_Light(OV_DIMMED_BRIGHTNESS);
        }

        if (osMessageQueueGet(IdleBreak_MessageQueueHandle, &msg, 0, 0) == osOK) {
            IdleTimerCount = 0;
            LCD_Set_Light(g_app_state.scr1_slider_value);
        }

        osDelay(10);
    }
}
