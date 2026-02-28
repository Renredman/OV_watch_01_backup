#include "cmsis_os2.h"
#include "key.h"
#include "stdio.h"
#include "stdlib.h"
// #include "portable.h"
#include "FreeRTOS.h"
#include "Types/PageType.h"
#include "gui_guider.h"
#include "main.h"

// extern bool scr1_del;
char text_buf[10];
int key_state = 0;
void StartKeyTask(void *argument) {
    for (;;) {
        if (Key1_Scan() == 1) {
            // 发送中断空闲模式的消息
            uint8_t break_msg = 0;
            osMessageQueuePut(IdleBreak_MessageQueueHandle, &break_msg, 0, osPriorityRealtime);

            // 获取当前屏幕并创建页面切换消息
            lv_obj_t *current_scr = lv_scr_act();
            PageMessage *msg = pvPortMalloc(sizeof(PageMessage));

            // 根据当前屏幕决定切换目标
            if (current_scr == guider_ui.scr1) {
                // 从主页面切换到菜单2
                msg->new_screen = &guider_ui.menu2;
                msg->new_scr_del = guider_ui.menu2_del;
                msg->old_scr_del = &guider_ui.scr1_del;
                msg->setup_cb = setup_scr_menu2;
                msg->anim = LV_SCR_LOAD_ANIM_MOVE_RIGHT;
            }
            else if (current_scr == guider_ui.menu2) {
                // 从菜单2切换到主页面
                msg->new_screen = &guider_ui.scr1;
                msg->new_scr_del = guider_ui.scr1_del;
                msg->old_scr_del = &guider_ui.menu2_del;
                msg->setup_cb = setup_scr_scr1;
                msg->anim = LV_SCR_LOAD_ANIM_MOVE_LEFT;
            }
            else if (current_scr == guider_ui.game_2048 || current_scr == guider_ui.story || current_scr == guider_ui.chat) {
                // 从游戏子页面切换到游戏主页面
                msg->new_screen = &guider_ui.game;
                msg->new_scr_del = guider_ui.game_del;
                
                // 设置旧页面的删除函数
                if (current_scr == guider_ui.game_2048) {
                    msg->old_scr_del = &guider_ui.game_2048_del;
                } else if (current_scr == guider_ui.story) {
                    msg->old_scr_del = &guider_ui.story_del;
                } else {
                    msg->old_scr_del = &guider_ui.chat_del;
                }
                
                msg->setup_cb = setup_scr_game;
                msg->anim = LV_SCR_LOAD_ANIM_MOVE_RIGHT;
            }
            else if (current_scr == guider_ui.time_date) {
                // 从时间日期页面切换到设置页面
                msg->new_screen = &guider_ui.settings;
                msg->new_scr_del = guider_ui.settings_del;
                msg->old_scr_del = &guider_ui.time_date_del;
                msg->setup_cb = setup_scr_settings;
                msg->anim = LV_SCR_LOAD_ANIM_MOVE_RIGHT;
            }
            else {
                // 其他页面都切换到菜单2
                msg->new_screen = &guider_ui.menu2;
                msg->new_scr_del = guider_ui.menu2_del;
                
                // 根据当前页面设置旧页面的删除函数
                if (current_scr == guider_ui.calculator) {
                    msg->old_scr_del = &guider_ui.calculator_del;
                } else if (current_scr == guider_ui.calendar) {
                    msg->old_scr_del = &guider_ui.calendar_del;
                } else if (current_scr == guider_ui.card_bag) {
                    msg->old_scr_del = &guider_ui.card_bag_del;
                } else if (current_scr == guider_ui.second_chronograph) {
                    msg->old_scr_del = &guider_ui.second_chronograph_del;
                } else if (current_scr == guider_ui.environment) {
                    msg->old_scr_del = &guider_ui.environment_del;
                } else if (current_scr == guider_ui.heart) {
                    msg->old_scr_del = &guider_ui.heart_del;
                } else if (current_scr == guider_ui.compass) {
                    msg->old_scr_del = &guider_ui.compass_del;
                } else if (current_scr == guider_ui.game) {
                    msg->old_scr_del = &guider_ui.game_del;
                } else if (current_scr == guider_ui.settings) {
                    msg->old_scr_del = &guider_ui.settings_del;
                } else if (current_scr == guider_ui.about_watch) {
                    msg->old_scr_del = &guider_ui.about_watch_del;
                }
                
                msg->setup_cb = setup_scr_menu2;
                msg->anim = LV_SCR_LOAD_ANIM_OVER_RIGHT;
            }

            // 发送页面切换消息
            osMessageQueuePut(PageQueueHandle, &msg, 0, 0);
        }
        osDelay(5);
    }
}

