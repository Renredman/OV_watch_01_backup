#include "AHT21.h"
#include "em70x8.h"
#include "HrAlgorythm.h"
#include "cmsis_os2.h"
#include "main.h"
#include "FreeRTOS.h"
#include "gui_guider.h"
#include "Types/Sensor.h"
#include "Config/ov_project_config.h"
#include "Services/ProjectLog.h"
#include "Services/SystemStatus.h"
#include "SPL06_001.h"
#include "LSM303.h"

uint8_t AHT_State = 0;
uint32_t user_HR_timecount = 0;

void trigger_immediate_envir_update(void);
void trigger_immediate_heart_update(void);

void SensorDataRenewTask(void *argument)
{
    (void)argument;

    for (;;) {
        trigger_immediate_envir_update();
        osDelay(OV_ENVIRONMENT_REFRESH_PERIOD_MS);
    }
}

void HeartDataRenewTask(void *argument)
{
    hr_command_t cmd;

    (void)argument;

    for (;;) {
        if (osMessageQueueGet(HrCmdQueueHandle, &cmd, NULL, osWaitForever) == osOK) {
            if (cmd == HR_CMD_START) {
                HeartMessage heart_msg;

                SystemStatus_SetHeartMeasurement(true);
                OV_LOGI("heart", "measurement start");
                EM7028_hrs_Enable();
                Simple_HeartRate(0, HAL_GetTick(), true);

                for (int i = 0; i < OV_HEART_SAMPLE_COUNT; i++) {
                    uint16_t raw_ppg = EM7028_Get_HRS1();
                    uint32_t current_time = HAL_GetTick();
                    uint16_t heart_rate = Simple_HeartRate(raw_ppg, current_time, false);

                    if (heart_rate > 0U) {
                        heart_msg.status = 1U;
                        heart_msg.heart = heart_rate;
                        if (osMessageQueuePut(HeartQueueHandle, &heart_msg, 0, 0) != osOK) {
                            OV_LOGW("heart", "drop realtime heart sample");
                        }
                    }

                    osDelay(OV_HEART_SAMPLE_PERIOD_MS);
                }

                heart_msg.status = 2U;
                heart_msg.heart = 0U;
                if (osMessageQueuePut(HeartQueueHandle, &heart_msg, 0, 0) != osOK) {
                    OV_LOGW("heart", "drop heart complete message");
                }

                EM7028_hrs_DisEnable();
                SystemStatus_SetHeartMeasurement(false);
                OV_LOGI("heart", "measurement complete");
            }
        }
    }
}

void trigger_immediate_envir_update(void)
{
    float humidity = 0;
    float temperature = 0;
    float altitude = 0;
    float azimuth = 0;
    int16_t Xa;
    int16_t Ya;
    int16_t Za;
    int16_t Xm;
    int16_t Ym;
    int16_t Zm;
    EnvirMessage envir_msg;

    if (!Sensor_AHT21_Erro) {
        if (AHT_Read(&humidity, &temperature) != 0) {
            humidity = 0;
            temperature = 0;
        }
    }

    if (!Sensor_SPL_Erro) {
        altitude = Altitude_Calculate();
    }

    if (!Sensor_LSM303_Erro) {
        LSM303_ReadAcceleration(&Xa, &Ya, &Za);
        LSM303_ReadMagnetic(&Xm, &Ym, &Zm);
        azimuth = Azimuth_Calculate(Xa, Ya, Za, Xm, Ym, Zm);
    }

    envir_msg.humidity = humidity;
    envir_msg.temperature = temperature;
    envir_msg.altitude = altitude;
    envir_msg.azimuth = azimuth;

    if (osMessageQueuePut(EnvirQueueHandle, &envir_msg, 0, 0) != osOK) {
        OV_LOGW("sensor", "drop environment sample");
    }
}
