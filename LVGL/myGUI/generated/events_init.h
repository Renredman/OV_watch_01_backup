/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


#ifndef EVENTS_INIT_H_
#define EVENTS_INIT_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "gui_guider.h"
#include "Types/Sensor.h"

void events_init(lv_ui *ui);

void events_init_scr1(lv_ui *ui);
void events_init_menu(lv_ui *ui);
void events_init_calendar(lv_ui *ui);
void events_init_calculator(lv_ui *ui);
void events_init_second_chronograph(lv_ui *ui);
void events_init_environment(lv_ui *ui);
void events_init_card_bag(lv_ui *ui);
void events_init_menu2(lv_ui *ui);
void events_init_about_watch(lv_ui *ui);
void events_init_heart(lv_ui *ui);
void events_init_game(lv_ui *ui);
void events_init_game_2048(lv_ui *ui);
void events_init_settings(lv_ui *ui);
void events_init_story(lv_ui *ui);
void events_init_chat(lv_ui *ui);

void heart_update_callback_from_data_task(HeartMessage *msg);


#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
