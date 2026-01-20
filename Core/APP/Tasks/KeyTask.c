#include "cmsis_os2.h"
#include "key.h"
#include "stdio.h"
#include "stdlib.h"
// #include "portable.h"
#include "FreeRTOS.h"
#include "Types/PageType.h"
#include "gui_guider.h"

// extern bool scr1_del;
char text_buf[10];
int key_state = 0;
void StartKeyTask(void *argument) {
    for (;;) {
        if (Key1_Scan() == 1) {
            lv_obj_t *current_scr = lv_scr_act();
            PageMessage *msg = pvPortMalloc(sizeof(PageMessage));

            if (current_scr == guider_ui.scr1) {
                msg->new_screen = &guider_ui.menu2;
                msg->new_scr_del = guider_ui.menu2_del;
                msg->old_scr_del = &guider_ui.scr1_del;
                msg->setup_cb = setup_scr_menu2;
                msg->anim = LV_SCR_LOAD_ANIM_MOVE_RIGHT;
            }
            else if (current_scr == guider_ui.menu2) {
                msg->new_screen = &guider_ui.scr1;
                msg->new_scr_del = guider_ui.scr1_del;
                msg->old_scr_del = &guider_ui.menu2_del;
                msg->setup_cb = setup_scr_scr1;
                msg->anim = LV_SCR_LOAD_ANIM_MOVE_LEFT;
            }
            else {
                msg->new_screen = &guider_ui.menu2;
                msg->new_scr_del = guider_ui.menu2_del;
                if (current_scr == guider_ui.calculator) {
                    msg->old_scr_del = &guider_ui.calculator_del;
                }
                else if (current_scr == guider_ui.calendar) {
                    msg->old_scr_del = &guider_ui.calendar_del;
                }
                else if (current_scr == guider_ui.card_bag) {
                    msg->old_scr_del = &guider_ui.card_bag_del;
                }
                else if (current_scr == guider_ui.second_chronograph) {
                    msg->old_scr_del = &guider_ui.second_chronograph_del;
                }
                else if (current_scr == guider_ui.environment) {
                    msg->old_scr_del = &guider_ui.environment_del;
                }
                msg->setup_cb = setup_scr_menu2;
                msg->anim = LV_SCR_LOAD_ANIM_OVER_RIGHT;
            }

            //PageMessage *msg = pvPortMalloc(sizeof(PageMessage));
            // msg->t = 1;
            // msg->page = scr1_index;

            osMessageQueuePut(PageQueueHandle, &msg, 0, 0); // 正确传 &msg
        }
        osDelay(5);
    }
}

