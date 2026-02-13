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



void setup_scr_time_date(lv_ui *ui)
{
    //Write codes time_date
    ui->time_date = lv_obj_create(NULL);
    lv_obj_set_size(ui->time_date, 240, 320);
    lv_obj_set_scrollbar_mode(ui->time_date, LV_SCROLLBAR_MODE_OFF);

    //Write style for time_date, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->time_date, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->time_date, lv_color_hex(0xc2c2c2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->time_date, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_cont_6
    ui->time_date_cont_6 = lv_obj_create(ui->time_date);
    lv_obj_set_pos(ui->time_date_cont_6, 0, 215);
    lv_obj_set_size(ui->time_date_cont_6, 240, 42);
    lv_obj_set_scrollbar_mode(ui->time_date_cont_6, LV_SCROLLBAR_MODE_OFF);

    //Write style for time_date_cont_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->time_date_cont_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->time_date_cont_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->time_date_cont_6, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->time_date_cont_6, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->time_date_cont_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->time_date_cont_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->time_date_cont_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->time_date_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->time_date_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->time_date_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->time_date_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_btn_12
    ui->time_date_btn_12 = lv_btn_create(ui->time_date_cont_6);
    ui->time_date_btn_12_label = lv_label_create(ui->time_date_btn_12);
    lv_label_set_text(ui->time_date_btn_12_label, "-");
    lv_label_set_long_mode(ui->time_date_btn_12_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->time_date_btn_12_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->time_date_btn_12, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->time_date_btn_12_label, LV_PCT(100));
    lv_obj_set_pos(ui->time_date_btn_12, 44, 1);
    lv_obj_set_size(ui->time_date_btn_12, 36, 36);

    //Write style for time_date_btn_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->time_date_btn_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->time_date_btn_12, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->time_date_btn_12, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->time_date_btn_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_btn_12, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_btn_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->time_date_btn_12, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->time_date_btn_12, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->time_date_btn_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->time_date_btn_12, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_btn_11
    ui->time_date_btn_11 = lv_btn_create(ui->time_date_cont_6);
    ui->time_date_btn_11_label = lv_label_create(ui->time_date_btn_11);
    lv_label_set_text(ui->time_date_btn_11_label, "+");
    lv_label_set_long_mode(ui->time_date_btn_11_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->time_date_btn_11_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->time_date_btn_11, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->time_date_btn_11_label, LV_PCT(100));
    lv_obj_set_pos(ui->time_date_btn_11, 199, 1);
    lv_obj_set_size(ui->time_date_btn_11, 36, 36);

    //Write style for time_date_btn_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->time_date_btn_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->time_date_btn_11, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->time_date_btn_11, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->time_date_btn_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_btn_11, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_btn_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->time_date_btn_11, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->time_date_btn_11, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->time_date_btn_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->time_date_btn_11, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_label_12
    ui->time_date_label_12 = lv_label_create(ui->time_date_cont_6);
    lv_label_set_text(ui->time_date_label_12, "2025");
    lv_label_set_long_mode(ui->time_date_label_12, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->time_date_label_12, 91, 6);
    lv_obj_set_size(ui->time_date_label_12, 100, 26);

    //Write style for time_date_label_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->time_date_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->time_date_label_12, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->time_date_label_12, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->time_date_label_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->time_date_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->time_date_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->time_date_label_12, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->time_date_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->time_date_label_12, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->time_date_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->time_date_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->time_date_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_label_11
    ui->time_date_label_11 = lv_label_create(ui->time_date_cont_6);
    lv_label_set_text(ui->time_date_label_11, "秒");
    lv_label_set_long_mode(ui->time_date_label_11, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->time_date_label_11, 0, 6);
    lv_obj_set_size(ui->time_date_label_11, 40, 26);

    //Write style for time_date_label_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->time_date_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->time_date_label_11, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->time_date_label_11, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->time_date_label_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->time_date_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->time_date_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->time_date_label_11, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->time_date_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->time_date_label_11, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->time_date_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->time_date_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->time_date_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_cont_5
    ui->time_date_cont_5 = lv_obj_create(ui->time_date);
    lv_obj_set_pos(ui->time_date_cont_5, 0, 173);
    lv_obj_set_size(ui->time_date_cont_5, 240, 42);
    lv_obj_set_scrollbar_mode(ui->time_date_cont_5, LV_SCROLLBAR_MODE_OFF);

    //Write style for time_date_cont_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->time_date_cont_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->time_date_cont_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->time_date_cont_5, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->time_date_cont_5, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->time_date_cont_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->time_date_cont_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->time_date_cont_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->time_date_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->time_date_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->time_date_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->time_date_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_btn_10
    ui->time_date_btn_10 = lv_btn_create(ui->time_date_cont_5);
    ui->time_date_btn_10_label = lv_label_create(ui->time_date_btn_10);
    lv_label_set_text(ui->time_date_btn_10_label, "-");
    lv_label_set_long_mode(ui->time_date_btn_10_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->time_date_btn_10_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->time_date_btn_10, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->time_date_btn_10_label, LV_PCT(100));
    lv_obj_set_pos(ui->time_date_btn_10, 44, 1);
    lv_obj_set_size(ui->time_date_btn_10, 36, 36);

    //Write style for time_date_btn_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->time_date_btn_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->time_date_btn_10, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->time_date_btn_10, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->time_date_btn_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_btn_10, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_btn_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->time_date_btn_10, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->time_date_btn_10, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->time_date_btn_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->time_date_btn_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_btn_9
    ui->time_date_btn_9 = lv_btn_create(ui->time_date_cont_5);
    ui->time_date_btn_9_label = lv_label_create(ui->time_date_btn_9);
    lv_label_set_text(ui->time_date_btn_9_label, "+");
    lv_label_set_long_mode(ui->time_date_btn_9_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->time_date_btn_9_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->time_date_btn_9, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->time_date_btn_9_label, LV_PCT(100));
    lv_obj_set_pos(ui->time_date_btn_9, 199, 1);
    lv_obj_set_size(ui->time_date_btn_9, 36, 36);

    //Write style for time_date_btn_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->time_date_btn_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->time_date_btn_9, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->time_date_btn_9, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->time_date_btn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_btn_9, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_btn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->time_date_btn_9, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->time_date_btn_9, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->time_date_btn_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->time_date_btn_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_label_10
    ui->time_date_label_10 = lv_label_create(ui->time_date_cont_5);
    lv_label_set_text(ui->time_date_label_10, "2025");
    lv_label_set_long_mode(ui->time_date_label_10, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->time_date_label_10, 91, 6);
    lv_obj_set_size(ui->time_date_label_10, 100, 26);

    //Write style for time_date_label_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->time_date_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->time_date_label_10, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->time_date_label_10, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->time_date_label_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->time_date_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->time_date_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->time_date_label_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->time_date_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->time_date_label_10, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->time_date_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->time_date_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->time_date_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_label_9
    ui->time_date_label_9 = lv_label_create(ui->time_date_cont_5);
    lv_label_set_text(ui->time_date_label_9, "分");
    lv_label_set_long_mode(ui->time_date_label_9, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->time_date_label_9, 0, 6);
    lv_obj_set_size(ui->time_date_label_9, 40, 26);

    //Write style for time_date_label_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->time_date_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->time_date_label_9, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->time_date_label_9, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->time_date_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->time_date_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->time_date_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->time_date_label_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->time_date_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->time_date_label_9, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->time_date_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->time_date_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->time_date_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_cont_4
    ui->time_date_cont_4 = lv_obj_create(ui->time_date);
    lv_obj_set_pos(ui->time_date_cont_4, 0, 131);
    lv_obj_set_size(ui->time_date_cont_4, 240, 42);
    lv_obj_set_scrollbar_mode(ui->time_date_cont_4, LV_SCROLLBAR_MODE_OFF);

    //Write style for time_date_cont_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->time_date_cont_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->time_date_cont_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->time_date_cont_4, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->time_date_cont_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->time_date_cont_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->time_date_cont_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->time_date_cont_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->time_date_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->time_date_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->time_date_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->time_date_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_btn_8
    ui->time_date_btn_8 = lv_btn_create(ui->time_date_cont_4);
    ui->time_date_btn_8_label = lv_label_create(ui->time_date_btn_8);
    lv_label_set_text(ui->time_date_btn_8_label, "-");
    lv_label_set_long_mode(ui->time_date_btn_8_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->time_date_btn_8_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->time_date_btn_8, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->time_date_btn_8_label, LV_PCT(100));
    lv_obj_set_pos(ui->time_date_btn_8, 44, 1);
    lv_obj_set_size(ui->time_date_btn_8, 36, 36);

    //Write style for time_date_btn_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->time_date_btn_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->time_date_btn_8, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->time_date_btn_8, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->time_date_btn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_btn_8, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_btn_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->time_date_btn_8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->time_date_btn_8, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->time_date_btn_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->time_date_btn_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_btn_7
    ui->time_date_btn_7 = lv_btn_create(ui->time_date_cont_4);
    ui->time_date_btn_7_label = lv_label_create(ui->time_date_btn_7);
    lv_label_set_text(ui->time_date_btn_7_label, "+");
    lv_label_set_long_mode(ui->time_date_btn_7_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->time_date_btn_7_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->time_date_btn_7, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->time_date_btn_7_label, LV_PCT(100));
    lv_obj_set_pos(ui->time_date_btn_7, 199, 1);
    lv_obj_set_size(ui->time_date_btn_7, 36, 36);

    //Write style for time_date_btn_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->time_date_btn_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->time_date_btn_7, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->time_date_btn_7, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->time_date_btn_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_btn_7, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_btn_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->time_date_btn_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->time_date_btn_7, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->time_date_btn_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->time_date_btn_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_label_8
    ui->time_date_label_8 = lv_label_create(ui->time_date_cont_4);
    lv_label_set_text(ui->time_date_label_8, "2025");
    lv_label_set_long_mode(ui->time_date_label_8, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->time_date_label_8, 91, 6);
    lv_obj_set_size(ui->time_date_label_8, 100, 26);

    //Write style for time_date_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->time_date_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->time_date_label_8, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->time_date_label_8, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->time_date_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->time_date_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->time_date_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->time_date_label_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->time_date_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->time_date_label_8, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->time_date_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->time_date_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->time_date_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_label_7
    ui->time_date_label_7 = lv_label_create(ui->time_date_cont_4);
    lv_label_set_text(ui->time_date_label_7, "时");
    lv_label_set_long_mode(ui->time_date_label_7, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->time_date_label_7, 0, 6);
    lv_obj_set_size(ui->time_date_label_7, 40, 26);

    //Write style for time_date_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->time_date_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->time_date_label_7, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->time_date_label_7, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->time_date_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->time_date_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->time_date_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->time_date_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->time_date_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->time_date_label_7, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->time_date_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->time_date_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->time_date_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_cont_3
    ui->time_date_cont_3 = lv_obj_create(ui->time_date);
    lv_obj_set_pos(ui->time_date_cont_3, 0, 89);
    lv_obj_set_size(ui->time_date_cont_3, 240, 42);
    lv_obj_set_scrollbar_mode(ui->time_date_cont_3, LV_SCROLLBAR_MODE_OFF);

    //Write style for time_date_cont_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->time_date_cont_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->time_date_cont_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->time_date_cont_3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->time_date_cont_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->time_date_cont_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->time_date_cont_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->time_date_cont_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->time_date_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->time_date_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->time_date_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->time_date_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_btn_6
    ui->time_date_btn_6 = lv_btn_create(ui->time_date_cont_3);
    ui->time_date_btn_6_label = lv_label_create(ui->time_date_btn_6);
    lv_label_set_text(ui->time_date_btn_6_label, "-");
    lv_label_set_long_mode(ui->time_date_btn_6_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->time_date_btn_6_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->time_date_btn_6, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->time_date_btn_6_label, LV_PCT(100));
    lv_obj_set_pos(ui->time_date_btn_6, 44, 1);
    lv_obj_set_size(ui->time_date_btn_6, 36, 36);

    //Write style for time_date_btn_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->time_date_btn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->time_date_btn_6, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->time_date_btn_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->time_date_btn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_btn_6, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_btn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->time_date_btn_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->time_date_btn_6, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->time_date_btn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->time_date_btn_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_btn_5
    ui->time_date_btn_5 = lv_btn_create(ui->time_date_cont_3);
    ui->time_date_btn_5_label = lv_label_create(ui->time_date_btn_5);
    lv_label_set_text(ui->time_date_btn_5_label, "+");
    lv_label_set_long_mode(ui->time_date_btn_5_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->time_date_btn_5_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->time_date_btn_5, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->time_date_btn_5_label, LV_PCT(100));
    lv_obj_set_pos(ui->time_date_btn_5, 199, 1);
    lv_obj_set_size(ui->time_date_btn_5, 36, 36);

    //Write style for time_date_btn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->time_date_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->time_date_btn_5, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->time_date_btn_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->time_date_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_btn_5, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_btn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->time_date_btn_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->time_date_btn_5, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->time_date_btn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->time_date_btn_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_label_6
    ui->time_date_label_6 = lv_label_create(ui->time_date_cont_3);
    lv_label_set_text(ui->time_date_label_6, "2025");
    lv_label_set_long_mode(ui->time_date_label_6, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->time_date_label_6, 91, 6);
    lv_obj_set_size(ui->time_date_label_6, 100, 26);

    //Write style for time_date_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->time_date_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->time_date_label_6, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->time_date_label_6, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->time_date_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->time_date_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->time_date_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->time_date_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->time_date_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->time_date_label_6, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->time_date_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->time_date_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->time_date_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_label_5
    ui->time_date_label_5 = lv_label_create(ui->time_date_cont_3);
    lv_label_set_text(ui->time_date_label_5, "日");
    lv_label_set_long_mode(ui->time_date_label_5, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->time_date_label_5, 0, 6);
    lv_obj_set_size(ui->time_date_label_5, 40, 26);

    //Write style for time_date_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->time_date_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->time_date_label_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->time_date_label_5, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->time_date_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->time_date_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->time_date_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->time_date_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->time_date_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->time_date_label_5, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->time_date_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->time_date_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->time_date_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_cont_2
    ui->time_date_cont_2 = lv_obj_create(ui->time_date);
    lv_obj_set_pos(ui->time_date_cont_2, 0, 47);
    lv_obj_set_size(ui->time_date_cont_2, 240, 42);
    lv_obj_set_scrollbar_mode(ui->time_date_cont_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for time_date_cont_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->time_date_cont_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->time_date_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->time_date_cont_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->time_date_cont_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->time_date_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->time_date_cont_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->time_date_cont_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->time_date_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->time_date_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->time_date_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->time_date_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_btn_4
    ui->time_date_btn_4 = lv_btn_create(ui->time_date_cont_2);
    ui->time_date_btn_4_label = lv_label_create(ui->time_date_btn_4);
    lv_label_set_text(ui->time_date_btn_4_label, "-");
    lv_label_set_long_mode(ui->time_date_btn_4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->time_date_btn_4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->time_date_btn_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->time_date_btn_4_label, LV_PCT(100));
    lv_obj_set_pos(ui->time_date_btn_4, 44, 1);
    lv_obj_set_size(ui->time_date_btn_4, 36, 36);

    //Write style for time_date_btn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->time_date_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->time_date_btn_4, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->time_date_btn_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->time_date_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_btn_4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->time_date_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->time_date_btn_4, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->time_date_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->time_date_btn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_btn_3
    ui->time_date_btn_3 = lv_btn_create(ui->time_date_cont_2);
    ui->time_date_btn_3_label = lv_label_create(ui->time_date_btn_3);
    lv_label_set_text(ui->time_date_btn_3_label, "+");
    lv_label_set_long_mode(ui->time_date_btn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->time_date_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->time_date_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->time_date_btn_3_label, LV_PCT(100));
    lv_obj_set_pos(ui->time_date_btn_3, 199, 1);
    lv_obj_set_size(ui->time_date_btn_3, 36, 36);

    //Write style for time_date_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->time_date_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->time_date_btn_3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->time_date_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->time_date_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->time_date_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->time_date_btn_3, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->time_date_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->time_date_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_label_4
    ui->time_date_label_4 = lv_label_create(ui->time_date_cont_2);
    lv_label_set_text(ui->time_date_label_4, "2025");
    lv_label_set_long_mode(ui->time_date_label_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->time_date_label_4, 91, 6);
    lv_obj_set_size(ui->time_date_label_4, 100, 26);

    //Write style for time_date_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->time_date_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->time_date_label_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->time_date_label_4, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->time_date_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->time_date_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->time_date_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->time_date_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->time_date_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->time_date_label_4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->time_date_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->time_date_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->time_date_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_label_3
    ui->time_date_label_3 = lv_label_create(ui->time_date_cont_2);
    lv_label_set_text(ui->time_date_label_3, "月");
    lv_label_set_long_mode(ui->time_date_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->time_date_label_3, 0, 6);
    lv_obj_set_size(ui->time_date_label_3, 40, 26);

    //Write style for time_date_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->time_date_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->time_date_label_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->time_date_label_3, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->time_date_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->time_date_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->time_date_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->time_date_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->time_date_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->time_date_label_3, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->time_date_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->time_date_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->time_date_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_cont_1
    ui->time_date_cont_1 = lv_obj_create(ui->time_date);
    lv_obj_set_pos(ui->time_date_cont_1, 0, 5);
    lv_obj_set_size(ui->time_date_cont_1, 240, 42);
    lv_obj_set_scrollbar_mode(ui->time_date_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for time_date_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->time_date_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->time_date_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->time_date_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->time_date_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->time_date_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->time_date_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->time_date_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->time_date_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->time_date_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->time_date_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->time_date_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_btn_1
    ui->time_date_btn_1 = lv_btn_create(ui->time_date_cont_1);
    ui->time_date_btn_1_label = lv_label_create(ui->time_date_btn_1);
    lv_label_set_text(ui->time_date_btn_1_label, "-");
    lv_label_set_long_mode(ui->time_date_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->time_date_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->time_date_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->time_date_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->time_date_btn_1, 44, 1);
    lv_obj_set_size(ui->time_date_btn_1, 36, 36);

    //Write style for time_date_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->time_date_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->time_date_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->time_date_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->time_date_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->time_date_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->time_date_btn_1, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->time_date_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->time_date_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_btn_2
    ui->time_date_btn_2 = lv_btn_create(ui->time_date_cont_1);
    ui->time_date_btn_2_label = lv_label_create(ui->time_date_btn_2);
    lv_label_set_text(ui->time_date_btn_2_label, "+");
    lv_label_set_long_mode(ui->time_date_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->time_date_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->time_date_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->time_date_btn_2_label, LV_PCT(100));
    lv_obj_set_pos(ui->time_date_btn_2, 199, 1);
    lv_obj_set_size(ui->time_date_btn_2, 36, 36);

    //Write style for time_date_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->time_date_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->time_date_btn_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->time_date_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->time_date_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->time_date_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->time_date_btn_2, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->time_date_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->time_date_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_label_2
    ui->time_date_label_2 = lv_label_create(ui->time_date_cont_1);
    lv_label_set_text(ui->time_date_label_2, "2025");
    lv_label_set_long_mode(ui->time_date_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->time_date_label_2, 91, 6);
    lv_obj_set_size(ui->time_date_label_2, 100, 26);

    //Write style for time_date_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->time_date_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->time_date_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->time_date_label_2, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->time_date_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->time_date_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->time_date_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->time_date_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->time_date_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->time_date_label_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->time_date_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->time_date_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->time_date_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_label_1
    ui->time_date_label_1 = lv_label_create(ui->time_date_cont_1);
    lv_label_set_text(ui->time_date_label_1, "年");
    lv_label_set_long_mode(ui->time_date_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->time_date_label_1, 0, 6);
    lv_obj_set_size(ui->time_date_label_1, 40, 26);

    //Write style for time_date_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->time_date_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->time_date_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->time_date_label_1, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->time_date_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->time_date_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->time_date_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->time_date_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->time_date_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->time_date_label_1, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->time_date_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->time_date_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->time_date_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes time_date_msgbox_1
    static const char * time_date_msgbox_1_btns[] = {"Apply","Close", ""};
    ui->time_date_msgbox_1 = lv_msgbox_create(ui->time_date, "", "是否保存修改?", time_date_msgbox_1_btns, false);
    lv_obj_set_size(lv_msgbox_get_btns(ui->time_date_msgbox_1), 120, 30);
    lv_obj_set_pos(ui->time_date_msgbox_1, 33, 54);
    lv_obj_set_size(ui->time_date_msgbox_1, 190, 109);

    //Write style for time_date_msgbox_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->time_date_msgbox_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->time_date_msgbox_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->time_date_msgbox_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->time_date_msgbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->time_date_msgbox_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->time_date_msgbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_time_date_msgbox_1_extra_content_main_default
    static lv_style_t style_time_date_msgbox_1_extra_content_main_default;
    ui_init_style(&style_time_date_msgbox_1_extra_content_main_default);

    lv_style_set_text_color(&style_time_date_msgbox_1_extra_content_main_default, lv_color_hex(0x4e4e4e));
    lv_style_set_text_font(&style_time_date_msgbox_1_extra_content_main_default, &lv_font_simsun_18);
    lv_style_set_text_opa(&style_time_date_msgbox_1_extra_content_main_default, 255);
    lv_style_set_text_letter_space(&style_time_date_msgbox_1_extra_content_main_default, 0);
    lv_style_set_text_line_space(&style_time_date_msgbox_1_extra_content_main_default, 8);
    lv_obj_add_style(lv_msgbox_get_text(ui->time_date_msgbox_1), &style_time_date_msgbox_1_extra_content_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_time_date_msgbox_1_extra_btns_items_default
    static lv_style_t style_time_date_msgbox_1_extra_btns_items_default;
    ui_init_style(&style_time_date_msgbox_1_extra_btns_items_default);

    lv_style_set_bg_opa(&style_time_date_msgbox_1_extra_btns_items_default, 255);
    lv_style_set_bg_color(&style_time_date_msgbox_1_extra_btns_items_default, lv_color_hex(0xe6e6e6));
    lv_style_set_bg_grad_dir(&style_time_date_msgbox_1_extra_btns_items_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_time_date_msgbox_1_extra_btns_items_default, 0);
    lv_style_set_radius(&style_time_date_msgbox_1_extra_btns_items_default, 10);
    lv_style_set_text_color(&style_time_date_msgbox_1_extra_btns_items_default, lv_color_hex(0x4e4e4e));
    lv_style_set_text_font(&style_time_date_msgbox_1_extra_btns_items_default, &lv_font_simsun_12);
    lv_style_set_text_opa(&style_time_date_msgbox_1_extra_btns_items_default, 255);
    lv_obj_add_style(lv_msgbox_get_btns(ui->time_date_msgbox_1), &style_time_date_msgbox_1_extra_btns_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //The custom code of time_date.
    lv_obj_add_flag(ui->time_date_msgbox_1, LV_OBJ_FLAG_HIDDEN);

    //Update current screen layout.
    lv_obj_update_layout(ui->time_date);

    events_init_time_date(ui);
}
