#include <stdio.h>
#include "lvgl.h"
#include "custom.h"
#include "gui_guider.h"  // 包含UI结构体定义
#include "Tasks/AppState.h"
#include "Tasks/TimeUpdateTask.h"
#include "Tasks/SensorDataTask.h"


// 声明自动生成的计算器屏幕初始化函数（必须添加，否则链接失败）
extern void setup_scr_calculator(lv_ui *ui);

void scr1_screen_loaded_event_handler(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_SCREEN_LOADED) {
        refresh_current_time_on_scr1();
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

void environment_screen_loaded_cb(lv_event_t *e) {
    trigger_immediate_envir_update();
}

// 自定义初始化函数（GUI Guider会自动调用）
void custom_init(lv_ui *ui) {

}