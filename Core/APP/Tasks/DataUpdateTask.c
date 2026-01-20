#include "cmsis_os2.h"
#include "FreeRTOS.h"
#include "lv_obj.h"
#include "Types/Sensor.h"
#include "stdio.h"
#include "main.h"

static osStatus_t queue_status;
extern lv_ui  guider_ui;

static void environment_update(void *user_data) {
    char text_buf[15];
    EnvirMessage *data = (EnvirMessage *)user_data;

    // snprintf(text_buf,sizeof(text_buf),"%d",(uint8_t)data->temperature);
    // lv_label_set_text(guider_ui.environment_label_1, text_buf);
    // lv_bar_set_value(guider_ui.environment_bar_1, data->temperature, LV_ANIM_OFF);
    // snprintf(text_buf,sizeof(text_buf),"%d",(uint8_t)data->humidity);
    // lv_label_set_text(guider_ui.environment_label_3, text_buf);
    // lv_bar_set_value(guider_ui.environment_bar_2, data->humidity, LV_ANIM_OFF);

    vPortFree(data);
}

void SensorDataUpdateTask(void *argument) {
    for (;;) {
        lv_obj_t *current_scr = lv_scr_act();
        EnvirMessage *message;// = pvPortMalloc(sizeof(EnvirMessage));
        queue_status = osMessageQueueGet(EnvirQueueHandle,&message,0,osWaitForever);
        if (queue_status == osOK && message!=NULL) {
            if (current_scr == guider_ui.environment) {
                lv_async_call(environment_update,message);
            }
            else {
                vPortFree(message);
            }
        }
    }
}
