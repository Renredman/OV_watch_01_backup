#include "AHT21.h"
#include "em70x8.h"
#include "HrAlgorythm.h"
#include "cmsis_os2.h"
#include "main.h"
#include "FreeRTOS.h"
#include "gui_guider.h"
#include "Types/Sensor.h"

// RTC_DateTypeDef nowdate;
// RTC_TimeTypeDef nowtime;
// date_time time={2025, 12, 31, 17, 34, 32};
// float humidity, temperature;
uint8_t AHT_State=0;
uint32_t user_HR_timecount=0;
void trigger_immediate_envir_update(void);
void trigger_immediate_heart_update(void);

void SensorDataRenewTask(void *argument) {
    for (;;) {
        trigger_immediate_envir_update();
        osDelay(3000);
    }
}

// void HeartDataRenewTask(void *argument) {
//     for (;;) {
//         trigger_immediate_heart_update();
//         osDelay(40);
//     }
// }
void HeartDataRenewTask(void *argument)
{
    hr_command_t cmd;
    for (;;)
    {
        // 【关键】阻塞等待命令
        if (osMessageQueueGet(HrCmdQueueHandle, &cmd, NULL, osWaitForever) == osOK)
        {
            if (cmd == HR_CMD_START)
            {
                // 启用心率传感器
                EM7028_hrs_Enable();

                Simple_HeartRate(0, HAL_GetTick(), true);

                // 进入测量循环
                for (int i = 0; i < 125; i++) // 假设测量5秒，40ms一次
                {
                    uint16_t raw_ppg = EM7028_Get_HRS1();
                    uint32_t current_time = HAL_GetTick();
                    uint16_t heart_rate = Simple_HeartRate(raw_ppg, current_time,false);

                    if (heart_rate >0) {
                        HeartMessage *heart_msg = pvPortMalloc(sizeof(HeartMessage));
                        if (heart_msg != NULL) {
                            heart_msg->status = 1;
                            heart_msg->heart = heart_rate;
                            if (osMessageQueuePut(HeartQueueHandle, &heart_msg, 0, 0) != osOK) {
                                vPortFree(heart_msg);
                            }
                        }
                    }
                    osDelay(40);
                }

                // 测量结束，发送完成消息
                HeartMessage *complete_msg = pvPortMalloc(sizeof(HeartMessage));
                if (complete_msg != NULL) {
                    complete_msg->status = 2; // 2 表示测量完成
                    complete_msg->heart = 0;
                    osMessageQueuePut(HeartQueueHandle, &complete_msg, 0, 0);
                }

                // 停用传感器
                EM7028_hrs_DisEnable();
            }
        }
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


