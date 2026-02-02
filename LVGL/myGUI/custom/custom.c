#include <stdio.h>
#include "lvgl.h"
#include "custom.h"


#include "cmsis_os2.h"
#include "gui_guider.h"  // 包含UI结构体定义
#include "main.h"
#include "Tasks/AppState.h"
#include "Tasks/TimeUpdateTask.h"
#include "Tasks/SensorDataTask.h"
#include "Tasks/user_PowerManager.h"

// 声明自动生成的计算器屏幕初始化函数（必须添加，否则链接失败）
extern void setup_scr_calculator(lv_ui *ui);

void scr1_screen_loaded_event_handler(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_SCREEN_LOADED) {
        refresh_current_time_on_scr1();
        // printf("sss");
        lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
        if (ui !=NULL) {
            // AppState_SyncToUI_ASync(ui);
            AppState_SyncToScr1(ui);
        }
    }
}

void setting_screen_loaded_event_handler(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_SCREEN_LOADED) {
        lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
        if (ui !=NULL) {
            // AppState_SyncToUI_ASync(ui);
            AppState_SyncToSettings(ui);
        }
    }
}

char chat_history[MAX_CHAT_LINES][MAX_LINE_LENGTH] = {0};
uint8_t history_count = 0;
void chat_screen_loaded_handler(lv_event_t *e)
{
    // 拼接所有消息（用 \n 分隔）
    static char full_text[1024] = {0}; // 10*64 + 10 个换行符 ≈ 650 字节
    full_text[0] = '\0';

    // 如果历史记录为空，则显示 "123"
    if (history_count == 0) {
        strcpy(full_text, "123");
    } else {
        for (int i = 0; i < history_count; i++) {
            strcat(full_text, chat_history[i]);
            strcat(full_text, "\n");
        }
    }

    // 更新 label 文本
    lv_label_set_text(guider_ui.chat_win_1_label, full_text);

    // 【可选】滚动到底部（如果内容超出窗口）
    lv_obj_t *content = lv_win_get_content(guider_ui.chat_win_1);
    lv_coord_t content_h = lv_obj_get_content_height(content);
    lv_coord_t win_h = lv_obj_get_height(guider_ui.chat_win_1);
    lv_coord_t scroll_y = (content_h > win_h) ? (content_h - win_h) : 0;
    lv_obj_scroll_to_y(content, scroll_y, LV_ANIM_OFF); // 加载时不使用动画
}

void environment_screen_loaded_cb(lv_event_t *e) {
    trigger_immediate_envir_update();
}

// 自定义初始化函数（GUI Guider会自动调用）
void custom_init(lv_ui *ui) {

}