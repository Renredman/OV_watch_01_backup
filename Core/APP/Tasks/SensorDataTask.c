#include "AHT21.h"
#include "cmsis_os2.h"
#include "main.h"
#include "FreeRTOS.h"
#include "gui_guider.h"
#include "rtc.h"
#include "Types/Sensor.h"

RTC_DateTypeDef nowdate;
RTC_TimeTypeDef nowtime;
date_time time={2025, 12, 31, 17, 34, 32};
float humidity, temperature;
uint8_t AHT_State=0;

void SensorDataRenewTask(void *argument) {

    for (;;) {
        // AHT_State=Sensor_MPU_Erro;

        if (!Sensor_AHT21_Erro){
            // humidity=0, temperature=0;
            // EnvirMessage *envir_msg = pvPortMalloc(sizeof(EnvirMessage));
            // if (AHT_Read(&humidity, &temperature) == 0) {
            //     envir_msg->humidity = humidity;
            //     envir_msg->temperature = temperature;
            // } else {
            //     envir_msg->humidity = -1;
            //     envir_msg->temperature = -1;
            // }
            // osMessageQueuePut(EnvirQueueHandle,&envir_msg,0,0);
            // key_state+=5;
            AHT_Read(&humidity, &temperature);
        }

        HAL_RTC_GetTime(&hrtc,&nowtime,RTC_FORMAT_BIN);
        HAL_RTC_GetDate(&hrtc,&nowdate,RTC_FORMAT_BIN);


        osDelay(1000);
    }
}
