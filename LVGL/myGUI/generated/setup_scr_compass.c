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



void setup_scr_compass(lv_ui *ui)
{
    //Write codes compass
    ui->compass = lv_obj_create(NULL);
    lv_obj_set_size(ui->compass, 240, 320);
    lv_obj_set_scrollbar_mode(ui->compass, LV_SCROLLBAR_MODE_OFF);

    //Write style for compass, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->compass, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->compass, lv_color_hex(0x191919), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->compass, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes compass_meter_1
    ui->compass_meter_1 = lv_meter_create(ui->compass);
    // add scale ui->compass_meter_1_scale_0
    ui->compass_meter_1_scale_0 = lv_meter_add_scale(ui->compass_meter_1);
    lv_meter_set_scale_ticks(ui->compass_meter_1, ui->compass_meter_1_scale_0, 61, 2, 10, lv_color_hex(0x865b5b));
    lv_meter_set_scale_major_ticks(ui->compass_meter_1, ui->compass_meter_1_scale_0, 5, 3, 15, lv_color_hex(0x000000), 6);
    lv_meter_set_scale_range(ui->compass_meter_1, ui->compass_meter_1_scale_0, 0, 360, 360, 270);

    // add needle images for ui->compass_meter_1_scale_0.
    ui->compass_meter_1_scale_0_ndline_0 = lv_meter_add_needle_img(ui->compass_meter_1, ui->compass_meter_1_scale_0, &_pic_compass_pointer_alpha_90x150, 45, 75);
    lv_meter_set_indicator_value(ui->compass_meter_1, ui->compass_meter_1_scale_0_ndline_0, 90);
    lv_obj_set_pos(ui->compass_meter_1, 20, 0);
    lv_obj_set_size(ui->compass_meter_1, 200, 200);

    //Write style for compass_meter_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->compass_meter_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->compass_meter_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->compass_meter_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->compass_meter_1, 100, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->compass_meter_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->compass_meter_1, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->compass_meter_1, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->compass_meter_1, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->compass_meter_1, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->compass_meter_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for compass_meter_1, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->compass_meter_1, lv_color_hex(0xff0000), LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->compass_meter_1, &lv_font_simsun_12, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->compass_meter_1, 255, LV_PART_TICKS|LV_STATE_DEFAULT);

    //Write style for compass_meter_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->compass_meter_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->compass_meter_1, lv_color_hex(0x000000), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->compass_meter_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes compass_label_1
    ui->compass_label_1 = lv_label_create(ui->compass);
    lv_label_set_text(ui->compass_label_1, " ");
    lv_label_set_long_mode(ui->compass_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->compass_label_1, 15, 205);
    lv_obj_set_size(ui->compass_label_1, 81, 28);

    //Write style for compass_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->compass_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->compass_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->compass_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->compass_label_1, &lv_font_icomoon_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->compass_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->compass_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->compass_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->compass_label_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->compass_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->compass_label_1, lv_color_hex(0x5f5f5f), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->compass_label_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->compass_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->compass_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->compass_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->compass_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->compass_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes compass_label_2
    ui->compass_label_2 = lv_label_create(ui->compass);
    lv_label_set_text(ui->compass_label_2, " ");
    lv_label_set_long_mode(ui->compass_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->compass_label_2, 144, 205);
    lv_obj_set_size(ui->compass_label_2, 81, 28);

    //Write style for compass_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->compass_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->compass_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->compass_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->compass_label_2, &lv_font_icomoon_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->compass_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->compass_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->compass_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->compass_label_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->compass_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->compass_label_2, lv_color_hex(0x5f5f5f), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->compass_label_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->compass_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->compass_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->compass_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->compass_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->compass_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes compass_label_3
    ui->compass_label_3 = lv_label_create(ui->compass);
    lv_label_set_text(ui->compass_label_3, ":0");
    lv_label_set_long_mode(ui->compass_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->compass_label_3, 53, 209);
    lv_obj_set_size(ui->compass_label_3, 39, 20);

    //Write style for compass_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->compass_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->compass_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->compass_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->compass_label_3, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->compass_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->compass_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->compass_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->compass_label_3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->compass_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->compass_label_3, lv_color_hex(0x5f5f5f), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->compass_label_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->compass_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->compass_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->compass_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->compass_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->compass_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes compass_label_4
    ui->compass_label_4 = lv_label_create(ui->compass);
    lv_label_set_text(ui->compass_label_4, ":0m");
    lv_label_set_long_mode(ui->compass_label_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->compass_label_4, 182, 209);
    lv_obj_set_size(ui->compass_label_4, 39, 20);

    //Write style for compass_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->compass_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->compass_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->compass_label_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->compass_label_4, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->compass_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->compass_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->compass_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->compass_label_4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->compass_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->compass_label_4, lv_color_hex(0x5f5f5f), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->compass_label_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->compass_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->compass_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->compass_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->compass_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->compass_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of compass.


    //Update current screen layout.
    lv_obj_update_layout(ui->compass);

    //Init events for screen.
    events_init_compass(ui);
}
