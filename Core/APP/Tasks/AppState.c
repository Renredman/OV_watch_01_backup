#include "gui_guider.h"
#include "AppState.h"

#include <stdlib.h>
#include "FreeRTOS.h"
#include "custom.h"


void AppState_SyncToUI(lv_ui *ui);
AppState g_app_state = {0};

void Appstate_Init(void) {
    g_app_state.scr1_btn_2_checked = false;
    g_app_state.scr1_btn_4_checked = false;
    g_app_state.scr1_slider_value = 50;
    g_app_state.settings_sw_1_state = false;
}

static void app_state_sync_to_ui_async_cb(void *data) {
    AppState_SyncData_t *sync_data = (AppState_SyncData_t *)data;
    if (sync_data != NULL && sync_data->ui != NULL) {
        AppState_SyncToUI(sync_data->ui);
    }
    vPortFree(sync_data);
}

void AppState_SyncToUI_ASync(lv_ui *ui) {
    AppState_SyncData_t *sync_data = pvPortMalloc(sizeof(AppState_SyncData_t));
    if (sync_data == NULL) {
        return;
    }
    sync_data->ui = ui;
    lv_async_call(app_state_sync_to_ui_async_cb,sync_data);
}

void AppState_SyncToUI(lv_ui *ui) {
    if (ui == NULL) {
        return;
    }

    if (ui->scr1 != NULL) {
        if (g_app_state.scr1_btn_2_checked) {
            lv_obj_add_state(ui->scr1_btn_2,LV_STATE_CHECKED);
        }
        else {
            lv_obj_clear_state(ui->scr1_btn_4,LV_STATE_CHECKED);
        }

        if (g_app_state.scr1_btn_4_checked) {
            lv_obj_add_state(ui->scr1_btn_4,LV_STATE_CHECKED);
        }
        else {
            lv_obj_clear_state(ui->scr1_btn_4,LV_STATE_CHECKED);
        }

        lv_slider_set_value(ui->scr1_slider_1,g_app_state.scr1_slider_value,LV_ANIM_OFF);
    }

    if (ui->settings != NULL) {
        if (g_app_state.settings_sw_1_state) {
            lv_obj_add_state(ui->settings_sw_1,LV_STATE_CHECKED);
        }
        else {
            lv_obj_clear_state(ui->settings_sw_1,LV_STATE_CHECKED);
        }
    }
}

// AppState.c

// 【实现】同步 scr1
void AppState_SyncToScr1(lv_ui *ui)
{
    if (ui == NULL || ui->scr1 == NULL) return;

    if (g_app_state.scr1_btn_2_checked) {
        lv_obj_add_state(ui->scr1_btn_2, LV_STATE_CHECKED);
    } else {
        lv_obj_clear_state(ui->scr1_btn_2, LV_STATE_CHECKED);
    }

    if (g_app_state.scr1_btn_4_checked) {
        lv_obj_add_state(ui->scr1_btn_4, LV_STATE_CHECKED);
    } else {
        lv_obj_clear_state(ui->scr1_btn_4, LV_STATE_CHECKED);
    }

    lv_slider_set_value(ui->scr1_slider_1, g_app_state.scr1_slider_value, LV_ANIM_OFF);
} 

// 【实现】同步 settings
void AppState_SyncToSettings(lv_ui *ui)
{
    if (ui == NULL || ui->settings == NULL) return;

    if (g_app_state.settings_sw_1_state) {
        lv_obj_add_state(ui->settings_sw_1, LV_STATE_CHECKED);
    } else {
        lv_obj_clear_state(ui->settings_sw_1, LV_STATE_CHECKED);
    }
}


