/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *scr1;
	bool scr1_del;
	lv_obj_t *scr1_arc_1;
	lv_obj_t *scr1_label_1;
	lv_obj_t *scr1_label_2;
	lv_obj_t *scr1_label_3;
	lv_obj_t *scr1_label_4;
	lv_obj_t *scr1_label_5;
	lv_obj_t *scr1_label_6;
	lv_obj_t *scr1_led_1;
	lv_obj_t *scr1_arc_2;
	lv_obj_t *scr1_label_8;
	lv_obj_t *scr1_arc_3;
	lv_obj_t *scr1_label_9;
	lv_obj_t *scr1_arc_4;
	lv_obj_t *scr1_label_10;
	lv_obj_t *scr1_bar_1;
	lv_obj_t *scr1_label_7;
	lv_obj_t *scr1_label_12;
	lv_obj_t *scr1_cont_1;
	lv_obj_t *scr1_btn_4;
	lv_obj_t *scr1_btn_4_label;
	lv_obj_t *scr1_slider_1;
	lv_obj_t *scr1_btn_3;
	lv_obj_t *scr1_btn_3_label;
	lv_obj_t *scr1_btn_2;
	lv_obj_t *scr1_btn_2_label;
	lv_obj_t *scr1_btn_1;
	lv_obj_t *scr1_btn_1_label;
	lv_obj_t *scr1_label_11;
	lv_obj_t *scr1_label_13;
	lv_obj_t *scr1_label_14;
	lv_obj_t *scr1_label_15;
	lv_obj_t *menu;
	bool menu_del;
	lv_obj_t *menu_list_1;
	lv_obj_t *menu_list_1_item0;
	lv_obj_t *menu_list_1_item1;
	lv_obj_t *menu_list_1_item2;
	lv_obj_t *menu_list_1_item3;
	lv_obj_t *menu_list_1_item4;
	lv_obj_t *menu_list_1_item5;
	lv_obj_t *menu_list_1_item6;
	lv_obj_t *menu_list_1_item7;
	lv_obj_t *menu_list_1_item8;
	lv_obj_t *menu_list_1_item9;
	lv_obj_t *menu_list_1_item10;
	lv_obj_t *menu_list_1_item11;
	lv_obj_t *calendar;
	bool calendar_del;
	lv_obj_t *calendar_calendar_1;
	lv_obj_t *calculator;
	bool calculator_del;
	lv_obj_t *calculator_label_1;
	lv_obj_t *calculator_btnm_1;
	lv_obj_t *second_chronograph;
	bool second_chronograph_del;
	lv_obj_t *second_chronograph_meter_1;
	lv_meter_scale_t *second_chronograph_meter_1_scale_0;
	lv_meter_indicator_t *second_chronograph_meter_1_scale_0_ndline_0;
	lv_obj_t *second_chronograph_btn_1;
	lv_obj_t *second_chronograph_btn_1_label;
	lv_obj_t *second_chronograph_btn_3;
	lv_obj_t *second_chronograph_btn_3_label;
	lv_obj_t *environment;
	bool environment_del;
	lv_obj_t *environment_bar_1;
	lv_obj_t *environment_label_1;
	lv_obj_t *environment_label_2;
	lv_obj_t *environment_label_4;
	lv_obj_t *environment_label_3;
	lv_obj_t *environment_bar_2;
	lv_obj_t *environment_label_5;
	lv_obj_t *environment_label_6;
	lv_obj_t *card_bag;
	bool card_bag_del;
	lv_obj_t *card_bag_cont_1;
	lv_obj_t *card_bag_btn_2;
	lv_obj_t *card_bag_btn_2_label;
	lv_obj_t *card_bag_btn_1;
	lv_obj_t *card_bag_btn_1_label;
	lv_obj_t *card_bag_label_1;
	lv_obj_t *card_bag_label_6;
	lv_obj_t *card_bag_cont_2;
	lv_obj_t *card_bag_btn_4;
	lv_obj_t *card_bag_btn_4_label;
	lv_obj_t *card_bag_btn_3;
	lv_obj_t *card_bag_btn_3_label;
	lv_obj_t *card_bag_label_2;
	lv_obj_t *card_bag_label_7;
	lv_obj_t *card_bag_cont_3;
	lv_obj_t *card_bag_btn_8;
	lv_obj_t *card_bag_btn_8_label;
	lv_obj_t *card_bag_btn_7;
	lv_obj_t *card_bag_btn_7_label;
	lv_obj_t *card_bag_label_4;
	lv_obj_t *card_bag_label_8;
	lv_obj_t *menu2;
	bool menu2_del;
	lv_obj_t *menu2_btn_1;
	lv_obj_t *menu2_btn_1_label;
	lv_obj_t *menu2_btn_2;
	lv_obj_t *menu2_btn_2_label;
	lv_obj_t *menu2_btn_3;
	lv_obj_t *menu2_btn_3_label;
	lv_obj_t *menu2_btn_4;
	lv_obj_t *menu2_btn_4_label;
	lv_obj_t *menu2_btn_5;
	lv_obj_t *menu2_btn_5_label;
	lv_obj_t *menu2_btn_6;
	lv_obj_t *menu2_btn_6_label;
	lv_obj_t *menu2_btn_7;
	lv_obj_t *menu2_btn_7_label;
	lv_obj_t *menu2_btn_8;
	lv_obj_t *menu2_btn_8_label;
	lv_obj_t *menu2_btn_9;
	lv_obj_t *menu2_btn_9_label;
	lv_obj_t *menu2_btn_10;
	lv_obj_t *menu2_btn_10_label;
	lv_obj_t *menu2_btn_11;
	lv_obj_t *menu2_btn_11_label;
	lv_obj_t *menu2_btn_12;
	lv_obj_t *menu2_btn_12_label;
	lv_obj_t *menu2_label_1;
	lv_obj_t *menu2_label_2;
	lv_obj_t *menu2_label_3;
	lv_obj_t *menu2_label_4;
	lv_obj_t *menu2_label_5;
	lv_obj_t *menu2_label_6;
	lv_obj_t *menu2_label_7;
	lv_obj_t *menu2_label_8;
	lv_obj_t *menu2_label_9;
	lv_obj_t *menu2_label_10;
	lv_obj_t *menu2_label_11;
	lv_obj_t *menu2_label_12;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;
// static page_state_t pages = {
// 	.scr1_valid = true,   // 假设 scr1 在 setup_ui 中已创建
// 	.menu2_valid = false
// };

void setup_scr_scr1(lv_ui *ui);
void setup_scr_menu(lv_ui *ui);
void setup_scr_calendar(lv_ui *ui);
void setup_scr_calculator(lv_ui *ui);
void setup_scr_second_chronograph(lv_ui *ui);
void setup_scr_environment(lv_ui *ui);
void setup_scr_card_bag(lv_ui *ui);
void setup_scr_menu2(lv_ui *ui);

LV_FONT_DECLARE(lv_font_simsun_18)
LV_FONT_DECLARE(lv_font_simsun_24)
LV_FONT_DECLARE(lv_font_simsun_48)
LV_FONT_DECLARE(lv_font_icomoon_24)
LV_FONT_DECLARE(lv_font_icomoon_32)
LV_FONT_DECLARE(lv_font_icomoon_18)
LV_FONT_DECLARE(lv_font_simsun_12)
LV_FONT_DECLARE(lv_font_simsun_32)


#ifdef __cplusplus
}
#endif
#endif
