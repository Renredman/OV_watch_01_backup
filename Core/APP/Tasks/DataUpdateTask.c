#include "cmsis_os2.h"
#include "FreeRTOS.h"
#include "lv_obj.h"
#include "Types/Sensor.h"
#include "stdio.h"
#include "main.h"

static osStatus_t queue_status;
extern lv_ui  guider_ui;

typedef struct {
    float humidity;
    float temperature;
}envir_update_data_t;

static void environment_update_callback(void *data) {
    envir_update_data_t *envir_data = (envir_update_data_t*)data;

    if (lv_scr_act() == guider_ui.environment) {
        char humi_str[10],temp_str[10];
        snprintf(humi_str, sizeof(humi_str), "%d",(uint8_t)envir_data->humidity);
        snprintf(temp_str, sizeof(temp_str), "%d",(uint8_t)envir_data->temperature);

        lv_label_set_text(guider_ui.environment_label_3,humi_str);
        lv_label_set_text(guider_ui.environment_label_1,temp_str);

        lv_bar_set_value(guider_ui.environment_bar_2, (uint8_t)envir_data->humidity, LV_ANIM_OFF);
        lv_bar_set_value(guider_ui.environment_bar_1, (uint8_t)envir_data->temperature, LV_ANIM_OFF);
    }

    vPortFree(envir_data);
}

void SensorDataUpdateTask(void *argument) {
    for (;;) {
        EnvirMessage *envir_msg = NULL;
        if (osMessageQueueGet(EnvirQueueHandle,&envir_msg,NULL,osWaitForever)==osOK) {
            envir_update_data_t *p_async_data =(envir_update_data_t*)pvPortMalloc(sizeof(envir_update_data_t));
            if (p_async_data != NULL) {
                p_async_data->humidity = envir_msg->humidity;
                p_async_data->temperature = envir_msg->temperature;

                lv_async_call(environment_update_callback,p_async_data);
            }
            vPortFree(envir_msg);
        }
    }
}
