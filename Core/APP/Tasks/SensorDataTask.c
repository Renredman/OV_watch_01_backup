                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          #include "AHT21.h"
#include "cmsis_os2.h"
#include "main.h"
#include "FreeRTOS.h"
#include "gui_guider.h"
#include "rtc.h"
#include "Types/Sensor.h"

// RTC_DateTypeDef nowdate;
// RTC_TimeTypeDef nowtime;
date_time time={2025, 12, 31, 17, 34, 32};
// float humidity, temperature;
uint8_t AHT_State=0;
void trigger_immediate_envir_update(void);

void SensorDataRenewTask(void *argument) {

    // lv_obj_add_event_cb(guider_ui.environment, environment_screen_loaded_cb, LV_EVENT_SCREEN_LOADED, NULL);
    for (;;) {
        // AHT_State=Sensor_MPU_Erro;

        trigger_immediate_envir_update();

        // HAL_RTC_GetTime(&hrtc,&nowtime,RTC_FORMAT_BIN);
        // HAL_RTC_GetDate(&hrtc,&nowdate,RTC_FORMAT_BIN);


        osDelay(3000);
    }
}



void trigger_immediate_envir_update(void) {
    if (!Sensor_AHT21_Erro) {
        float humidity,temperature;
        if (AHT_Read(&humidity, &temperature)==0) {
            EnvirMessage *envir_msg=(EnvirMessage*)pvPortMalloc(sizeof(EnvirMessage));
            if (envir_msg!=NULL) {
                envir_msg->humidity=humidity;
                envir_msg->temperature=temperature;

                if (osMessageQueuePut(EnvirQueueHandle,&envir_msg,0,0)!= osOK) {
                    vPortFree(envir_msg);
                }
            }
        }
    }
}

