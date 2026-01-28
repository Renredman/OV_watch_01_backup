/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_settings(lv_ui *ui)
{
    //Write codes settings
    ui->settings = lv_obj_create(NULL);
    lv_obj_set_size(ui->settings, 240, 320);
    lv_obj_set_scrollbar_mode(ui->settings, LV_SCROLLBAR_MODE_OFF);

    //Write style for settings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->settings, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->settings, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->settings, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes settings_btn_5
    ui->settings_btn_5 = lv_btn_create(ui->settings);
    ui->settings_btn_5_label = lv_label_create(ui->settings_btn_5);
    lv_label_set_text(ui->settings_btn_5_label, "    密码设置");
    lv_label_set_long_mode(ui->settings_btn_5_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->settings_btn_5_label, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_set_style_pad_all(ui->settings_btn_5, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->settings_btn_5_label, LV_PCT(100));
    lv_obj_set_pos(ui->settings_btn_5, 0, 240);
    lv_obj_set_size(ui->settings_btn_5, 240, 60);

    //Write style for settings_btn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->settings_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->settings_btn_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->settings_btn_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->settings_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->settings_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->settings_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->settings_btn_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->settings_btn_5, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->settings_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->settings_btn_5, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for settings_btn_5, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->settings_btn_5, 90, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->settings_btn_5, lv_color_hex(0x3eff00), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->settings_btn_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->settings_btn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->settings_btn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->settings_btn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->settings_btn_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->settings_btn_5, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->settings_btn_5, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write codes settings_btn_4
    ui->settings_btn_4 = lv_btn_create(ui->settings);
    ui->settings_btn_4_label = lv_label_create(ui->settings_btn_4);
    lv_label_set_text(ui->settings_btn_4_label, "    抬腕亮屏");
    lv_label_set_long_mode(ui->settings_btn_4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->settings_btn_4_label, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_set_style_pad_all(ui->settings_btn_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->settings_btn_4_label, LV_PCT(100));
    lv_obj_set_pos(ui->settings_btn_4, 0, 180);
    lv_obj_set_size(ui->settings_btn_4, 240, 60);

    //Write style for settings_btn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->settings_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->settings_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->settings_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->settings_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->settings_btn_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->settings_btn_4, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->settings_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->settings_btn_4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for settings_btn_4, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->settings_btn_4, 91, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->settings_btn_4, lv_color_hex(0x3eff00), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->settings_btn_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->settings_btn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->settings_btn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->settings_btn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->settings_btn_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->settings_btn_4, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->settings_btn_4, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write codes settings_btn_3
    ui->settings_btn_3 = lv_btn_create(ui->settings);
    ui->settings_btn_3_label = lv_label_create(ui->settings_btn_3);
    lv_label_set_text(ui->settings_btn_3_label, "    时间日期");
    lv_label_set_long_mode(ui->settings_btn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->settings_btn_3_label, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_set_style_pad_all(ui->settings_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->settings_btn_3_label, LV_PCT(100));
    lv_obj_set_pos(ui->settings_btn_3, 0, 120);
    lv_obj_set_size(ui->settings_btn_3, 240, 60);

    //Write style for settings_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->settings_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->settings_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->settings_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->settings_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->settings_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->settings_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->settings_btn_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->settings_btn_3, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->settings_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->settings_btn_3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for settings_btn_3, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->settings_btn_3, 90, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->settings_btn_3, lv_color_hex(0x3eff00), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->settings_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->settings_btn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->settings_btn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->settings_btn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->settings_btn_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->settings_btn_3, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->settings_btn_3, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write codes settings_btn_2
    ui->settings_btn_2 = lv_btn_create(ui->settings);
    ui->settings_btn_2_label = lv_label_create(ui->settings_btn_2);
    lv_label_set_text(ui->settings_btn_2_label, "    熄屏时间");
    lv_label_set_long_mode(ui->settings_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->settings_btn_2_label, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_set_style_pad_all(ui->settings_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->settings_btn_2_label, LV_PCT(100));
    lv_obj_set_pos(ui->settings_btn_2, 0, 60);
    lv_obj_set_size(ui->settings_btn_2, 240, 60);

    //Write style for settings_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->settings_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->settings_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->settings_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->settings_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->settings_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->settings_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->settings_btn_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->settings_btn_2, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->settings_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->settings_btn_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for settings_btn_2, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->settings_btn_2, 90, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->settings_btn_2, lv_color_hex(0x3eff00), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->settings_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->settings_btn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->settings_btn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->settings_btn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->settings_btn_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->settings_btn_2, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->settings_btn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write codes settings_btn_1
    ui->settings_btn_1 = lv_btn_create(ui->settings);
    ui->settings_btn_1_label = lv_label_create(ui->settings_btn_1);
    lv_label_set_text(ui->settings_btn_1_label, "    常亮时间");
    lv_label_set_long_mode(ui->settings_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->settings_btn_1_label, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_set_style_pad_all(ui->settings_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->settings_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->settings_btn_1, 0, 0);
    lv_obj_set_size(ui->settings_btn_1, 240, 60);

    //Write style for settings_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->settings_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->settings_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->settings_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->settings_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->settings_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->settings_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->settings_btn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->settings_btn_1, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->settings_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->settings_btn_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for settings_btn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->settings_btn_1, 90, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->settings_btn_1, lv_color_hex(0x3eff00), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->settings_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->settings_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->settings_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->settings_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->settings_btn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->settings_btn_1, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->settings_btn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write codes settings_label_3
    ui->settings_label_3 = lv_label_create(ui->settings);
    lv_label_set_text(ui->settings_label_3, "");
    lv_label_set_long_mode(ui->settings_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->settings_label_3, 7, 14);
    lv_obj_set_size(ui->settings_label_3, 34, 30);

    //Write style for settings_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->settings_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->settings_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->settings_label_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->settings_label_3, &lv_font_icomoon_32, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->settings_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->settings_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->settings_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->settings_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->settings_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->settings_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->settings_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->settings_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->settings_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->settings_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes settings_label_2
    ui->settings_label_2 = lv_label_create(ui->settings);
    lv_label_set_text(ui->settings_label_2, "");
    lv_label_set_long_mode(ui->settings_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->settings_label_2, 7, 74);
    lv_obj_set_size(ui->settings_label_2, 34, 30);

    //Write style for settings_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->settings_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->settings_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->settings_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->settings_label_2, &lv_font_icomoon_32, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->settings_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->settings_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->settings_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->settings_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->settings_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->settings_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->settings_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->settings_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->settings_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->settings_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes settings_label_1
    ui->settings_label_1 = lv_label_create(ui->settings);
    lv_label_set_text(ui->settings_label_1, "");
    lv_label_set_long_mode(ui->settings_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->settings_label_1, 7, 134);
    lv_obj_set_size(ui->settings_label_1, 34, 30);

    //Write style for settings_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->settings_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->settings_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->settings_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->settings_label_1, &lv_font_icomoon_32, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->settings_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->settings_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->settings_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->settings_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->settings_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->settings_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->settings_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->settings_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->settings_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->settings_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes settings_label_5
    ui->settings_label_5 = lv_label_create(ui->settings);
    lv_label_set_text(ui->settings_label_5, "");
    lv_label_set_long_mode(ui->settings_label_5, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->settings_label_5, 7, 194);
    lv_obj_set_size(ui->settings_label_5, 34, 30);

    //Write style for settings_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->settings_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->settings_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->settings_label_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->settings_label_5, &lv_font_icomoon_32, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->settings_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->settings_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->settings_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->settings_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->settings_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->settings_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->settings_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->settings_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->settings_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->settings_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes settings_label_4
    ui->settings_label_4 = lv_label_create(ui->settings);
    lv_label_set_text(ui->settings_label_4, "");
    lv_label_set_long_mode(ui->settings_label_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->settings_label_4, 7, 254);
    lv_obj_set_size(ui->settings_label_4, 34, 30);

    //Write style for settings_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->settings_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->settings_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->settings_label_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->settings_label_4, &lv_font_icomoon_32, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->settings_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->settings_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->settings_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->settings_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->settings_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->settings_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->settings_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->settings_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->settings_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->settings_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes settings_sw_1
    ui->settings_sw_1 = lv_switch_create(ui->settings);
    lv_obj_set_pos(ui->settings_sw_1, 181, 200);
    lv_obj_set_size(ui->settings_sw_1, 40, 20);

    //Write style for settings_sw_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->settings_sw_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->settings_sw_1, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->settings_sw_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->settings_sw_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->settings_sw_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->settings_sw_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for settings_sw_1, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->settings_sw_1, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->settings_sw_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->settings_sw_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->settings_sw_1, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for settings_sw_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->settings_sw_1, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->settings_sw_1, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->settings_sw_1, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->settings_sw_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->settings_sw_1, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes settings_label_6
    ui->settings_label_6 = lv_label_create(ui->settings);
    lv_label_set_text(ui->settings_label_6, "");
    lv_label_set_long_mode(ui->settings_label_6, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->settings_label_6, 0, 301);
    lv_obj_set_size(ui->settings_label_6, 101, 20);

    //Write style for settings_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->settings_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->settings_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->settings_label_6, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->settings_label_6, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->settings_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->settings_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->settings_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->settings_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->settings_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->settings_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->settings_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->settings_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->settings_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->settings_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of settings.


    //Update current screen layout.
    lv_obj_update_layout(ui->settings);

    //Init events for screen.
    events_init_settings(ui);
}
