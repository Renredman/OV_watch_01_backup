#include "cmsis_os2.h"
#include "main.h"
#include "FreeRTOS.h"
#include "gui_guider.h"
#include "Types/PageType.h"

extern int key_state;
static osStatus_t queue_status;
static TargetScreen g_target_screen;


static void page_switch_callback(void *user_data) {
    lv_ui *ui = &guider_ui;
    PageMessage *data = (PageMessage *)user_data;
    if (!data)return;

    ui_load_scr_animation(
    ui,data->new_screen,data->new_scr_del,data->old_scr_del,
    data->setup_cb,
    data->anim,200,10,true,true
    );
}

void StartPageTask(void *argument) {
    for (;;) {
        //PageMessage *message;
        PageMessage *message = pvPortMalloc(sizeof(PageMessage));
        queue_status=osMessageQueueGet(PageQueueHandle,&message,0,osWaitForever);
        if (queue_status == osOK && message != NULL) {
            key_state+=5;
            lv_async_call(page_switch_callback,message);
        }
        vPortFree(message);
    }
}