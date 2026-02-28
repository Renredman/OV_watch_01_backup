#include "cmsis_os2.h"
#include "FreeRTOS.h"
#include "lv_obj.h"
#include "Types/Sensor.h"
#include "stdio.h"
#include "main.h"
#include "events_init.h"
#include "lcd_init.h"
#include "custom.h"

static osStatus_t queue_status;
extern lv_ui  guider_ui;

typedef struct {
    float humidity;
    float temperature;
    float altitude;
    float azimuth;
}envir_update_data_t;


static void environment_update_callback(void *data) {
    envir_update_data_t *envir_data = (envir_update_data_t*)data;
    if (envir_data != NULL) {
        if (lv_scr_act() == guider_ui.environment) {
            char humi_str[10],temp_str[10];
            snprintf(humi_str, sizeof(humi_str), "%d",(uint8_t)envir_data->humidity);
            snprintf(temp_str, sizeof(temp_str), "%d",(uint8_t)envir_data->temperature);

            lv_label_set_text(guider_ui.environment_label_3,humi_str);
            lv_label_set_text(guider_ui.environment_label_1,temp_str);

            lv_bar_set_value(guider_ui.environment_bar_2, (uint8_t)envir_data->humidity, LV_ANIM_OFF);
            lv_bar_set_value(guider_ui.environment_bar_1, (uint8_t)envir_data->temperature, LV_ANIM_OFF);
        }
        
        // 更新指南针页面的高度和方位显示
        if (lv_scr_act() == guider_ui.compass) {
            // 更新高度显示
            char altitude_str[10];
            snprintf(altitude_str, sizeof(altitude_str), ":%dm", (int)envir_data->altitude);
            lv_label_set_text(guider_ui.compass_label_4, altitude_str);
            
            // 更新方位显示
            char azimuth_str[10];
            snprintf(azimuth_str, sizeof(azimuth_str), ":%d", (int)envir_data->azimuth);
            lv_label_set_text(guider_ui.compass_label_3, azimuth_str);
            
            // 更新指南针指针指向
            lv_meter_set_indicator_value(guider_ui.compass_meter_1, guider_ui.compass_meter_1_scale_0_ndline_0, (int)envir_data->azimuth);
        }
        vPortFree(envir_data);
    }
}

static void heart_update_callback(void *data) {
    HeartMessage *msg = (HeartMessage*)data;
    if (msg != NULL) {
        // 【调用新的、更具体的回调】
        heart_update_callback_from_data_task(msg);
        vPortFree(data);
    }

}


void SensorDataUpdateTask(void *argument) {
    for (;;) {
        EnvirMessage *envir_msg = NULL;
        if (osMessageQueueGet(EnvirQueueHandle,&envir_msg,NULL,10)==osOK) {
            envir_update_data_t *p_async_data =(envir_update_data_t*)pvPortMalloc(sizeof(envir_update_data_t));
            if (p_async_data != NULL) {
                p_async_data->humidity = envir_msg->humidity;
                p_async_data->temperature = envir_msg->temperature;
                p_async_data->altitude = envir_msg->altitude;
                p_async_data->azimuth = envir_msg->azimuth;
                scr1_sensor_data.humidity=envir_msg->humidity;
                scr1_sensor_data.temperature=envir_msg->temperature;
                scr1_sensor_data.altitude=envir_msg->altitude;
                scr1_sensor_data.azimuth=envir_msg->azimuth;
                lv_async_call(environment_update_callback,p_async_data);
            }
            vPortFree(envir_msg);
        }

        HeartMessage *heart_msg = NULL;
        if (osMessageQueueGet(HeartQueueHandle,&heart_msg,NULL,10)==osOK) {
            if (heart_msg != NULL) {
                lv_async_call(heart_update_callback,heart_msg);
                if (heart_msg->status==1)
                scr1_sensor_data.heart_rate=heart_msg->heart;
            }
            // vPortFree(heart_msg);
        }

        osDelay(1);// 防止任务在无消息时空转，降低CPU占用
    }
}
