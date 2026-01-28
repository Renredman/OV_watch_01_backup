#include "cmsis_os2.h"
#include "FreeRTOS.h"
#include "lv_obj.h"
#include "Types/Sensor.h"
#include "stdio.h"
#include "main.h"
#include "events_init.h"
#include "lcd_init.h"

static osStatus_t queue_status;
extern lv_ui  guider_ui;

typedef struct {
    float humidity;
    float temperature;
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

/*
        lv_obj_t * sw = guider_ui.settings_sw_1;
        if (lv_obj_has_state(sw, LV_STATE_CHECKED)) {
            lv_obj_clear_state(sw, LV_STATE_CHECKED);
        } else {
            lv_obj_add_state(sw, LV_STATE_CHECKED);
        }
        */
// static void common_data_update_callback(void *data) {
//     CommonMessage *msg = (CommonMessage*)data;
//     if (msg != NULL) {
//         if (lv_scr_act() == guider_ui.scr1) {
//             lv_slider_set_value(guider_ui.scr1_slider_1, msg->Light_value, LV_ANIM_OFF);
//             LCD_Set_Light(msg->Light_value);
//             if (msg->WiFI_state) {
//                 lv_obj_add_state(guider_ui.scr1_btn_4, LV_STATE_CHECKED);
//             }
//             else {
//                 lv_obj_clear_state(guider_ui.scr1_btn_4, LV_STATE_CHECKED);
//             }
//             if (msg->Bluetooth_state) {
//                 lv_obj_add_state(guider_ui.scr1_btn_2, LV_STATE_CHECKED);
//             }
//             else {
//                 lv_obj_clear_state(guider_ui.scr1_btn_2, LV_STATE_CHECKED);
//             }
//         }
//         else if(lv_scr_act() == guider_ui.settings) {
//             if (msg->wrist_state) {
//                 lv_obj_add_state(guider_ui.settings_sw_1, LV_STATE_CHECKED);
//             }
//             else {
//                 lv_obj_clear_state(guider_ui.settings_sw_1, LV_STATE_CHECKED);
//             }
//         }
//     }
// }


void SensorDataUpdateTask(void *argument) {
    for (;;) {
        EnvirMessage *envir_msg = NULL;
        if (osMessageQueueGet(EnvirQueueHandle,&envir_msg,NULL,10)==osOK) {
            envir_update_data_t *p_async_data =(envir_update_data_t*)pvPortMalloc(sizeof(envir_update_data_t));
            if (p_async_data != NULL) {
                p_async_data->humidity = envir_msg->humidity;
                p_async_data->temperature = envir_msg->temperature;

                lv_async_call(environment_update_callback,p_async_data);
            }
            vPortFree(envir_msg);
        }

        HeartMessage *heart_msg = NULL;
        if (osMessageQueueGet(HeartQueueHandle,&heart_msg,NULL,10)==osOK) {
            if (heart_msg != NULL) {
                lv_async_call(heart_update_callback,heart_msg);
            }
            // vPortFree(heart_msg);
        }

        // CommonMessage *com_msg = NULL;
        // if (osMessageQueueGet(CommonQueueHandle, &com_msg ,NULL,10)==osOK) {
        //     if (com_msg != NULL) {
        //         lv_async_call(common_data_update_callback,com_msg);
        //     }
        // }

        osDelay(1);// 防止任务在无消息时空转，降低CPU占用
    }
}
