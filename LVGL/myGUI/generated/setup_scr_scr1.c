/*
* Copyright 2025 NXP
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
#include "Types/Sensor.h"


void setup_scr_scr1(lv_ui *ui)
{
    //Write codes scr1
    ui->scr1 = lv_obj_create(NULL);
    lv_obj_set_size(ui->scr1, 240, 320);
    lv_obj_set_scrollbar_mode(ui->scr1, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr1_arc_1
    ui->scr1_arc_1 = lv_arc_create(ui->scr1);
    lv_arc_set_mode(ui->scr1_arc_1, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->scr1_arc_1, 0, 99);
    lv_arc_set_bg_angles(ui->scr1_arc_1, 120, 40);
    lv_arc_set_value(ui->scr1_arc_1, 34);
    lv_arc_set_rotation(ui->scr1_arc_1, 10);
    lv_obj_set_pos(ui->scr1_arc_1, 8, 52);
    lv_obj_set_size(ui->scr1_arc_1, 74, 70);

    //Write style for scr1_arc_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr1_arc_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr1_arc_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr1_arc_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr1_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->scr1_arc_1, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->scr1_arc_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->scr1_arc_1, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_arc_1, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr1_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr1_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr1_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr1_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr1_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr1_arc_1, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->scr1_arc_1, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->scr1_arc_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->scr1_arc_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->scr1_arc_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->scr1_arc_1, 6, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_arc_width(ui->scr1_arc_1, 8, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_arc_opa(ui->scr1_arc_1, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_arc_color(ui->scr1_arc_1, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->scr1_arc_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_bottom(ui->scr1_arc_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->scr1_arc_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->scr1_arc_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->scr1_arc_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write style for scr1_arc_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->scr1_arc_1, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->scr1_arc_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->scr1_arc_1, lv_color_hex(0x08f96c), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for scr1_arc_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr1_arc_1, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr1_arc_1, lv_color_hex(0x08f96c), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr1_arc_1, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->scr1_arc_1, 1, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes scr1_label_1
    ui->scr1_label_1 = lv_label_create(ui->scr1);
    lv_label_set_text(ui->scr1_label_1, "70%");
    lv_label_set_long_mode(ui->scr1_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scr1_label_1, 17, 76);
    lv_obj_set_size(ui->scr1_label_1, 56, 18);

    //Write style for scr1_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr1_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr1_label_1, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr1_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr1_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr1_label_2
    ui->scr1_label_2 = lv_label_create(ui->scr1);
    lv_label_set_text(ui->scr1_label_2, "11-08");
    lv_label_set_long_mode(ui->scr1_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scr1_label_2, 80, 20);
    lv_obj_set_size(ui->scr1_label_2, 86, 32);

    //Write style for scr1_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr1_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr1_label_2, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr1_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr1_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr1_label_3
    ui->scr1_label_3 = lv_label_create(ui->scr1);
    lv_label_set_text(ui->scr1_label_3, "Sat.");
    lv_label_set_long_mode(ui->scr1_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scr1_label_3, 158, 20);
    lv_obj_set_size(ui->scr1_label_3, 100, 32);

    //Write style for scr1_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr1_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr1_label_3, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr1_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr1_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr1_label_4
    ui->scr1_label_4 = lv_label_create(ui->scr1);
    lv_label_set_text(ui->scr1_label_4, "11:59");
    lv_label_set_long_mode(ui->scr1_label_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scr1_label_4, 93, 55);
    lv_obj_set_size(ui->scr1_label_4, 136, 53);

    //Write style for scr1_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr1_label_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr1_label_4, &lv_font_simsun_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr1_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr1_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr1_label_5
    ui->scr1_label_5 = lv_label_create(ui->scr1);
    lv_label_set_text(ui->scr1_label_5, "今日步数");
    lv_label_set_long_mode(ui->scr1_label_5, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scr1_label_5, 34, 153);
    lv_obj_set_size(ui->scr1_label_5, 100, 32);

    //Write style for scr1_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr1_label_5, lv_color_hex(0x3b4cff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr1_label_5, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr1_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr1_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    char text[10];
    //Write codes scr1_label_6
    ui->scr1_label_6 = lv_label_create(ui->scr1);
    lv_label_set_text(ui->scr1_label_6, "0");
    lv_label_set_long_mode(ui->scr1_label_6, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scr1_label_6, 3, 175);
    lv_obj_set_size(ui->scr1_label_6, 65, 23);

    //Write style for scr1_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr1_label_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr1_label_6, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr1_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr1_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr1_led_1
    ui->scr1_led_1 = lv_led_create(ui->scr1);
    lv_led_set_brightness(ui->scr1_led_1, 255);
    lv_led_set_color(ui->scr1_led_1, lv_color_hex(0xff0027));
    lv_obj_set_pos(ui->scr1_led_1, 180, 143);
    lv_obj_set_size(ui->scr1_led_1, 40, 40);

    //Write codes scr1_arc_2
    ui->scr1_arc_2 = lv_arc_create(ui->scr1);
    lv_arc_set_mode(ui->scr1_arc_2, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->scr1_arc_2, 0, 100);
    lv_arc_set_bg_angles(ui->scr1_arc_2, 46, 45);
    lv_arc_set_value(ui->scr1_arc_2, 75);
    lv_arc_set_rotation(ui->scr1_arc_2, 0);
    lv_obj_set_style_arc_rounded(ui->scr1_arc_2, 0,  LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->scr1_arc_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->scr1_arc_2, 13, 228);
    lv_obj_set_size(ui->scr1_arc_2, 66, 60);

    //Write style for scr1_arc_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr1_arc_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr1_arc_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr1_arc_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr1_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->scr1_arc_2, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->scr1_arc_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->scr1_arc_2, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_arc_2, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr1_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr1_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr1_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr1_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr1_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr1_arc_2, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->scr1_arc_2, 8, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->scr1_arc_2, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->scr1_arc_2, lv_color_hex(0xe8ba00), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for scr1_arc_2, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr1_arc_2, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr1_arc_2, lv_color_hex(0xe8ba00), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr1_arc_2, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->scr1_arc_2, 1, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes scr1_label_8
    ui->scr1_label_8 = lv_label_create(ui->scr1);
    lv_label_set_text(ui->scr1_label_8, "");
    lv_label_set_long_mode(ui->scr1_label_8, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scr1_label_8, 23, 245);
    lv_obj_set_size(ui->scr1_label_8, 39, 37);

    //Write style for scr1_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr1_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr1_label_8, lv_color_hex(0xe8ba00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr1_label_8, &lv_font_icomoon_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr1_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr1_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr1_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr1_label_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr1_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr1_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr1_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr1_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr1_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr1_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr1_arc_3
    ui->scr1_arc_3 = lv_arc_create(ui->scr1);
    lv_arc_set_mode(ui->scr1_arc_3, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->scr1_arc_3, 0, 100);
    lv_arc_set_bg_angles(ui->scr1_arc_3, 46, 45);
    lv_arc_set_value(ui->scr1_arc_3, 75);
    lv_arc_set_rotation(ui->scr1_arc_3, 0);
    lv_obj_set_style_arc_rounded(ui->scr1_arc_3, 0,  LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->scr1_arc_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->scr1_arc_3, 88, 228);
    lv_obj_set_size(ui->scr1_arc_3, 66, 60);

    //Write style for scr1_arc_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr1_arc_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr1_arc_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr1_arc_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr1_arc_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->scr1_arc_3, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->scr1_arc_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->scr1_arc_3, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_arc_3, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr1_arc_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr1_arc_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr1_arc_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr1_arc_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr1_arc_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr1_arc_3, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->scr1_arc_3, 8, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->scr1_arc_3, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->scr1_arc_3, lv_color_hex(0x0093ff), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for scr1_arc_3, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr1_arc_3, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr1_arc_3, lv_color_hex(0x0093ff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr1_arc_3, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->scr1_arc_3, 1, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes scr1_label_9
    ui->scr1_label_9 = lv_label_create(ui->scr1);
    lv_label_set_text(ui->scr1_label_9, "");
    lv_label_set_long_mode(ui->scr1_label_9, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scr1_label_9, 101, 244);
    lv_obj_set_size(ui->scr1_label_9, 34, 32);

    //Write style for scr1_label_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr1_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr1_label_9, lv_color_hex(0x0093ff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr1_label_9, &lv_font_icomoon_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr1_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr1_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr1_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr1_label_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr1_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr1_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr1_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr1_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr1_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr1_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr1_arc_4
    ui->scr1_arc_4 = lv_arc_create(ui->scr1);
    lv_arc_set_mode(ui->scr1_arc_4, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->scr1_arc_4, 0, 100);
    lv_arc_set_bg_angles(ui->scr1_arc_4, 46, 45);
    lv_arc_set_value(ui->scr1_arc_4, 75);
    lv_arc_set_rotation(ui->scr1_arc_4, 0);
    lv_obj_set_style_arc_rounded(ui->scr1_arc_4, 0,  LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->scr1_arc_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->scr1_arc_4, 162, 228);
    lv_obj_set_size(ui->scr1_arc_4, 66, 60);

    //Write style for scr1_arc_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr1_arc_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr1_arc_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr1_arc_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr1_arc_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->scr1_arc_4, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->scr1_arc_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->scr1_arc_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_arc_4, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr1_arc_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr1_arc_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr1_arc_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr1_arc_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr1_arc_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr1_arc_4, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->scr1_arc_4, 8, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->scr1_arc_4, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->scr1_arc_4, lv_color_hex(0xef0025), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for scr1_arc_4, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr1_arc_4, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr1_arc_4, lv_color_hex(0xd71533), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr1_arc_4, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->scr1_arc_4, 1, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes scr1_label_10
    ui->scr1_label_10 = lv_label_create(ui->scr1);
    lv_label_set_text(ui->scr1_label_10, "");
    lv_label_set_long_mode(ui->scr1_label_10, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scr1_label_10, 173, 244);
    lv_obj_set_size(ui->scr1_label_10, 38, 30);

    //Write style for scr1_label_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr1_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr1_label_10, lv_color_hex(0xff0027), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr1_label_10, &lv_font_icomoon_32, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr1_label_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr1_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr1_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr1_label_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr1_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr1_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr1_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr1_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr1_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr1_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr1_bar_1
    ui->scr1_bar_1 = lv_bar_create(ui->scr1);
    lv_obj_set_style_anim_time(ui->scr1_bar_1, 1000, 0);
    lv_bar_set_mode(ui->scr1_bar_1, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->scr1_bar_1, 0, 100);
    lv_bar_set_value(ui->scr1_bar_1, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->scr1_bar_1, 8, 204);
    lv_obj_set_size(ui->scr1_bar_1, 222, 11);

    //Write style for scr1_bar_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr1_bar_1, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr1_bar_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr1_bar_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_bar_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr1_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr1_bar_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr1_bar_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr1_bar_1, lv_color_hex(0x3b4cff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr1_bar_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_bar_1, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes scr1_label_7
    ui->scr1_label_7 = lv_label_create(ui->scr1);
    lv_label_set_text(ui->scr1_label_7, "");
    lv_label_set_long_mode(ui->scr1_label_7, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scr1_label_7, 13, 143);
    lv_obj_set_size(ui->scr1_label_7, 43, 29);

    //Write style for scr1_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr1_label_7, lv_color_hex(0x3b4cff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr1_label_7, &lv_font_icomoon_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr1_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr1_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr1_label_12
    ui->scr1_label_12 = lv_label_create(ui->scr1);
    lv_label_set_text(ui->scr1_label_12, "");
    lv_label_set_long_mode(ui->scr1_label_12, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scr1_label_12, 31, 111);
    lv_obj_set_size(ui->scr1_label_12, 22, 20);

    //Write style for scr1_label_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr1_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr1_label_12, lv_color_hex(0x08f96c), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr1_label_12, &lv_font_icomoon_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr1_label_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr1_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr1_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr1_label_12, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr1_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr1_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr1_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr1_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr1_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr1_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr1_cont_1
    ui->scr1_cont_1 = lv_obj_create(ui->scr1);
    lv_obj_set_pos(ui->scr1_cont_1, 0, -130);
    lv_obj_set_size(ui->scr1_cont_1, 240, 130);
    lv_obj_set_scrollbar_mode(ui->scr1_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr1_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr1_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr1_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr1_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr1_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr1_cont_1, 144, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr1_cont_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr1_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr1_btn_4
    ui->scr1_btn_4 = lv_btn_create(ui->scr1_cont_1);
    lv_obj_add_flag(ui->scr1_btn_4, LV_OBJ_FLAG_CHECKABLE);
    ui->scr1_btn_4_label = lv_label_create(ui->scr1_btn_4);
    lv_label_set_text(ui->scr1_btn_4_label, "" LV_SYMBOL_WIFI "");
    lv_label_set_long_mode(ui->scr1_btn_4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr1_btn_4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr1_btn_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr1_btn_4_label, LV_PCT(100));
    lv_obj_set_pos(ui->scr1_btn_4, 22, 19);
    lv_obj_set_size(ui->scr1_btn_4, 45, 39);

    //Write style for scr1_btn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr1_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr1_btn_4, lv_color_hex(0x646464), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr1_btn_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr1_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_btn_4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr1_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr1_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr1_btn_4, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr1_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr1_btn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr1_btn_4, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr1_btn_4, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr1_btn_4, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr1_btn_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr1_btn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr1_btn_4, 5, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr1_btn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr1_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr1_btn_4, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr1_btn_4, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr1_slider_1
    ui->scr1_slider_1 = lv_slider_create(ui->scr1_cont_1);
    lv_slider_set_range(ui->scr1_slider_1, 0, 100);
    lv_slider_set_mode(ui->scr1_slider_1, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->scr1_slider_1, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->scr1_slider_1, 169, 14);
    lv_obj_set_size(ui->scr1_slider_1, 45, 101);

    //Write style for scr1_slider_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr1_slider_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr1_slider_1, lv_color_hex(0x646464), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr1_slider_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_slider_1, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->scr1_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr1_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr1_slider_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr1_slider_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr1_slider_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr1_slider_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_slider_1, 8, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for scr1_slider_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr1_slider_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_slider_1, 8, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes scr1_btn_3
    ui->scr1_btn_3 = lv_btn_create(ui->scr1_cont_1);
    lv_obj_add_flag(ui->scr1_btn_3, LV_OBJ_FLAG_CHECKABLE);
    ui->scr1_btn_3_label = lv_label_create(ui->scr1_btn_3);
    lv_label_set_text(ui->scr1_btn_3_label, "" LV_SYMBOL_POWER "");
    lv_label_set_long_mode(ui->scr1_btn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr1_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr1_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr1_btn_3_label, LV_PCT(100));
    lv_obj_set_pos(ui->scr1_btn_3, 96, 17);
    lv_obj_set_size(ui->scr1_btn_3, 45, 45);

    //Write style for scr1_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr1_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr1_btn_3, lv_color_hex(0x646464), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr1_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr1_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr1_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr1_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr1_btn_3, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr1_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr1_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr1_btn_3, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr1_btn_3, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr1_btn_3, lv_color_hex(0x0093ff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr1_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr1_btn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr1_btn_3, 5, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr1_btn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr1_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr1_btn_3, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr1_btn_3, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr1_btn_2
    ui->scr1_btn_2 = lv_btn_create(ui->scr1_cont_1);
    lv_obj_add_flag(ui->scr1_btn_2, LV_OBJ_FLAG_CHECKABLE);
    ui->scr1_btn_2_label = lv_label_create(ui->scr1_btn_2);
    lv_label_set_text(ui->scr1_btn_2_label, "" LV_SYMBOL_BLUETOOTH "");
    lv_label_set_long_mode(ui->scr1_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr1_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr1_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr1_btn_2_label, LV_PCT(100));
    lv_obj_set_pos(ui->scr1_btn_2, 22, 75);
    lv_obj_set_size(ui->scr1_btn_2, 45, 45);

    //Write style for scr1_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr1_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr1_btn_2, lv_color_hex(0x646464), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr1_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr1_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr1_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr1_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr1_btn_2, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr1_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr1_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr1_btn_2, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr1_btn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr1_btn_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr1_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr1_btn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr1_btn_2, 5, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr1_btn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr1_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr1_btn_2, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr1_btn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr1_btn_1
    ui->scr1_btn_1 = lv_btn_create(ui->scr1_cont_1);
    lv_obj_add_flag(ui->scr1_btn_1, LV_OBJ_FLAG_CHECKABLE);
    ui->scr1_btn_1_label = lv_label_create(ui->scr1_btn_1);
    lv_label_set_text(ui->scr1_btn_1_label, "" LV_SYMBOL_SETTINGS "");
    lv_label_set_long_mode(ui->scr1_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr1_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr1_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr1_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->scr1_btn_1, 96, 74);
    lv_obj_set_size(ui->scr1_btn_1, 45, 45);

    //Write style for scr1_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr1_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr1_btn_1, lv_color_hex(0x646464), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr1_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr1_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr1_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr1_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr1_btn_1, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr1_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr1_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr1_btn_1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scr1_btn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scr1_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scr1_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scr1_btn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scr1_btn_1, 5, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scr1_btn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scr1_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scr1_btn_1, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scr1_btn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scr1_label_11
    ui->scr1_label_11 = lv_label_create(ui->scr1_cont_1);
    lv_label_set_text(ui->scr1_label_11, "");
    lv_label_set_long_mode(ui->scr1_label_11, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scr1_label_11, 172, 78);
    lv_obj_set_size(ui->scr1_label_11, 39, 34);

    //Write style for scr1_label_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr1_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr1_label_11, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr1_label_11, &lv_font_icomoon_32, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr1_label_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr1_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr1_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr1_label_11, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr1_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr1_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr1_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr1_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr1_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr1_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr1_label_13
    ui->scr1_label_13 = lv_label_create(ui->scr1);
    lv_label_set_text(ui->scr1_label_13, "25");
    lv_label_set_long_mode(ui->scr1_label_13, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scr1_label_13, 26, 291);
    lv_obj_set_size(ui->scr1_label_13, 30, 22);

    //Write style for scr1_label_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr1_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr1_label_13, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr1_label_13, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr1_label_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr1_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr1_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr1_label_13, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr1_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr1_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr1_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr1_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr1_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr1_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr1_label_14
    ui->scr1_label_14 = lv_label_create(ui->scr1);
    lv_label_set_text(ui->scr1_label_14, "67");
    lv_label_set_long_mode(ui->scr1_label_14, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scr1_label_14, 104, 291);
    lv_obj_set_size(ui->scr1_label_14, 30, 22);

    //Write style for scr1_label_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr1_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr1_label_14, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr1_label_14, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr1_label_14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr1_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr1_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr1_label_14, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr1_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr1_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr1_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr1_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr1_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr1_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr1_label_15
    ui->scr1_label_15 = lv_label_create(ui->scr1);
    lv_label_set_text(ui->scr1_label_15, "0");
    lv_label_set_long_mode(ui->scr1_label_15, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scr1_label_15, 177, 291);
    lv_obj_set_size(ui->scr1_label_15, 30, 22);

    //Write style for scr1_label_15, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr1_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr1_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr1_label_15, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr1_label_15, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr1_label_15, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr1_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr1_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr1_label_15, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr1_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr1_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr1_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr1_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr1_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr1_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of scr1.
    lv_obj_clear_flag(ui->scr1_arc_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->scr1_arc_2, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->scr1_arc_3, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->scr1_arc_4, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_clear_flag(ui->scr1_bar_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->scr1_led_1, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_clear_flag(ui->scr1_label_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->scr1_label_2, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->scr1_label_3, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->scr1_label_4, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->scr1_label_5, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->scr1_label_6, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->scr1_label_7, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->scr1_label_8, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->scr1_label_9, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->scr1_label_10, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_clear_flag(ui->scr1_cont_1, LV_OBJ_FLAG_CLICKABLE);


    //data
    char text_buf[15];
    // snprintf(text_buf, sizeof(text_buf), "%02d-%02d", nowdate.Month,nowdate.Date);
    // lv_label_set_text(ui->scr1_label_2, text_buf);
    // switch (nowdate.WeekDay) {
    //     case 0:snprintf(text_buf, sizeof(text_buf), "Sun.");break;
    //     case 1:snprintf(text_buf, sizeof(text_buf), "Mon.");break;
    //     case 2:snprintf(text_buf, sizeof(text_buf), "Tue.");break;
    //     case 3:snprintf(text_buf, sizeof(text_buf), "Wed.");break;
    //     case 4:snprintf(text_buf, sizeof(text_buf), "Thu.");break;
    //     case 5:snprintf(text_buf, sizeof(text_buf), "Fri.");break;
    //     case 6:snprintf(text_buf, sizeof(text_buf), "Sat.");break;
    // }
    // lv_label_set_text(ui->scr1_label_3, text_buf);
    //
    // //time
    // snprintf(text_buf, sizeof(text_buf), "%02d:%02d", nowtime.Hours,nowtime.Minutes);
    // lv_label_set_text(ui->scr1_label_4, text_buf);
    // extern float humidity, temperature;
    extern uint8_t AHT_State;
    extern int key_state;
    snprintf(text_buf,sizeof(text_buf),"%d %d",nowtime.Minutes,nowtime.Seconds);
    lv_label_set_text(guider_ui.scr1_label_6, text_buf);


    //Update current screen layout.
    lv_obj_update_layout(ui->scr1);

    //Init events for screen.
    events_init_scr1(ui);
}
