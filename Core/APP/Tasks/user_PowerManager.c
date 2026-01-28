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

uint16_t IdleTimerCount = 0;
uint8_t ui_LTimeValue = 3;//10;
uint8_t ui_TTimeValue = 5;//15;
static volatile uint8_t g_exit_low_power = 0;


void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc)
{
    // 在这里不做任何事，只是让 WFI 指令退出
    // 实际的按键检查在主循环中进行
}
// user_PowerManager.c

// 【修正】终极低功耗 GPIO 配置函数
// 【修正】终极低功耗 GPIO 配置函数
// user_PowerManager.c

// 【终极简化版】低功耗准备函数
// user_PowerManager.c

static void Enter_LowPower_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();
    __HAL_RCC_GPIOH_CLK_ENABLE();

    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Pin = GPIO_PIN_All;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
    HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

    // 重新配置 KEY1 (PA5)
    GPIO_InitStruct.Pin = GPIO_PIN_5;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // 配置 CST816_RST (PB0)
    GPIO_InitStruct.Pin = GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
}

// user_PowerManager.c

void StopEnterTask(void *argument)
{
    uint8_t stop_msg;
    while (1) {
        if (osMessageQueueGet(Stop_MessageQueueHandle, &stop_msg, NULL, 0) == osOK) {
            IdleTimerCount = 0;

            // --- 关闭外设 ---
            LCD_RES_Clr();
            LCD_Close_Light();
            CST816_Sleep(); // 让 CST816 自己处理 RST
            WDOG_Disnable();

            // --- 【关键】只配置 KEY1，不碰 CST816_RST ---
            __HAL_RCC_GPIOA_CLK_ENABLE();
            GPIO_InitTypeDef gpio_init = {0};
            gpio_init.Pin = GPIO_PIN_5;
            gpio_init.Mode = GPIO_MODE_INPUT;
            gpio_init.Pull = GPIO_PULLUP;
            HAL_GPIO_Init(GPIOA, &gpio_init);

            // --- 低功耗主循环 ---
            while (1) {
                HAL_RTCEx_DeactivateWakeUpTimer(&hrtc);
                HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, 204, RTC_WAKEUPCLOCK_RTCCLK_DIV16);

                vTaskSuspendAll();
                SysTick->CTRL = 0;
                HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
                xTaskResumeAll();

                // 【关键】恢复 GPIOA 时钟
                __HAL_RCC_GPIOA_CLK_ENABLE();

                if (HAL_GPIO_ReadPin(KEY1_PORT, KEY1_PIN) == GPIO_PIN_RESET) {
                    break;
                }
            }

            // --- 唤醒后恢复 ---
            SystemClock_Config();
            HAL_SYSTICK_Config(SystemCoreClock / 1000);
            MX_GPIO_Init(); // 这会正确恢复 CST816_RST_PIN
            LCD_Init();
            LCD_Set_Light(g_app_state.scr1_slider_value);
            CST816_Wakeup(); // 让 CST816 自己完成唤醒
            WDOG_Enable();
            WDOG_Feed();
            IdleTimerCount = 0;
        }
        osDelay(100);
    }
}

void IdleTimerCallback(void *argument) {
    IdleTimerCount+=1;

    if (IdleTimerCount == ui_LTimeValue*10) {
        uint8_t msg = 0;
        osMessageQueuePut(Idle_MessageQueueHandle,&msg,0,0);
    }

    if (IdleTimerCount == ui_TTimeValue*10) {
        uint8_t msg = 1;
        osMessageQueuePut(Stop_MessageQueueHandle,&msg,0,0);
    }
}

void IdleEnterTask(void *argument) {
    uint8_t msg;
    while (1) {
        if (osMessageQueueGet(Idle_MessageQueueHandle,&msg,NULL,0) == osOK) {
            LCD_Set_Light(5);
        }

        if (osMessageQueueGet(IdleBreak_MessageQueueHandle,&msg,0,0) == osOK) {
            IdleTimerCount = 0;
            LCD_Set_Light(g_app_state.scr1_slider_value);
        }

        osDelay(10);
    }
}
