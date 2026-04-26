//
// Created by 渚姏妤?on 2026/1/28.
//

#ifndef OV_WATCH_01_APPSTATE_H
#define OV_WATCH_01_APPSTATE_H

#include "stdint.h"
#include "lvgl.h"

typedef struct {
    bool scr1_btn_2_checked;
    bool scr1_btn_4_checked;
    uint8_t scr1_slider_value;

    bool settings_sw_1_state;
    
    bool password_set;
    uint8_t password[4];
    bool password_verified;
}AppState;

typedef struct {
    lv_ui *ui;
}AppState_SyncData_t;

extern AppState g_app_state;

void Appstate_Init(void);
void AppState_SetScreenBrightness(uint8_t value);
void AppState_SyncToUI_ASync(lv_ui *ui);

void AppState_SyncToScr1(lv_ui *ui);
void AppState_SyncToSettings(lv_ui *ui);

#endif //OV_WATCH_01_APPSTATE_H
