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
//上


void setup_scr_second_chronograph(lv_ui *ui)
{
    //Write codes second_chronograph
    ui->second_chronograph = lv_obj_create(NULL);
    lv_obj_set_size(ui->second_chronograph, 240, 320);
    lv_obj_set_scrollbar_mode(ui->second_chronograph, LV_SCROLLBAR_MODE_OFF);

    //Write style for second_chronograph, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->second_chronograph, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->second_chronograph, lv_color_hex(0xe8e8e8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->second_chronograph, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes second_chronograph_meter_1
    ui->second_chronograph_meter_1 = lv_meter_create(ui->second_chronograph);
    // add scale ui->second_chronograph_meter_1_scale_0
    ui->second_chronograph_meter_1_scale_0 = lv_meter_add_scale(ui->second_chronograph_meter_1);
    lv_meter_set_scale_ticks(ui->second_chronograph_meter_1, ui->second_chronograph_meter_1_scale_0, 60, 2, 5, lv_color_hex(0xff0000));
    lv_meter_set_scale_major_ticks(ui->second_chronograph_meter_1, ui->second_chronograph_meter_1_scale_0, 10, 5, 17, lv_color_hex(0xffff00), 10);
    lv_meter_set_scale_range(ui->second_chronograph_meter_1, ui->second_chronograph_meter_1_scale_0, 0, 60, 360, 90);

    // add needle line for ui->second_chronograph_meter_1_scale_0.
    ui->second_chronograph_meter_1_scale_0_ndline_0 = lv_meter_add_needle_line(ui->second_chronograph_meter_1, ui->second_chronograph_meter_1_scale_0, 5, lv_color_hex(0x000000), -18);
    lv_meter_set_indicator_value(ui->second_chronograph_meter_1, ui->second_chronograph_meter_1_scale_0_ndline_0, 0);
    lv_obj_set_pos(ui->second_chronograph_meter_1, 1, 2);
    lv_obj_set_size(ui->second_chronograph_meter_1, 234, 234);

    //Write style for second_chronograph_meter_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->second_chronograph_meter_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->second_chronograph_meter_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->second_chronograph_meter_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->second_chronograph_meter_1, 149, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->second_chronograph_meter_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->second_chronograph_meter_1, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->second_chronograph_meter_1, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->second_chronograph_meter_1, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->second_chronograph_meter_1, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->second_chronograph_meter_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for second_chronograph_meter_1, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->second_chronograph_meter_1, lv_color_hex(0xff0000), LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->second_chronograph_meter_1, &lv_font_simsun_12, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->second_chronograph_meter_1, 255, LV_PART_TICKS|LV_STATE_DEFAULT);

    //Write style for second_chronograph_meter_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->second_chronograph_meter_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->second_chronograph_meter_1, lv_color_hex(0x000000), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->second_chronograph_meter_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes second_chronograph_btn_1
    ui->second_chronograph_btn_1 = lv_btn_create(ui->second_chronograph);
    lv_obj_add_flag(ui->second_chronograph_btn_1, LV_OBJ_FLAG_CHECKABLE);
    ui->second_chronograph_btn_1_label = lv_label_create(ui->second_chronograph_btn_1);
    lv_label_set_text(ui->second_chronograph_btn_1_label, "");
    lv_label_set_long_mode(ui->second_chronograph_btn_1_label, LV_LABEL_LONG_CLIP);
    lv_obj_align(ui->second_chronograph_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->second_chronograph_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->second_chronograph_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->second_chronograph_btn_1, 156, 227);
    lv_obj_set_size(ui->second_chronograph_btn_1, 60, 60);

    //Write style for second_chronograph_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->second_chronograph_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->second_chronograph_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->second_chronograph_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->second_chronograph_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->second_chronograph_btn_1, 62, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->second_chronograph_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->second_chronograph_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->second_chronograph_btn_1, &lv_font_icomoon_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->second_chronograph_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->second_chronograph_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for second_chronograph_btn_1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->second_chronograph_btn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->second_chronograph_btn_1, lv_color_hex(0xff0027), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->second_chronograph_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->second_chronograph_btn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->second_chronograph_btn_1, 40, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->second_chronograph_btn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->second_chronograph_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->second_chronograph_btn_1, &lv_font_icomoon_48, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->second_chronograph_btn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes second_chronograph_btn_3
    ui->second_chronograph_btn_3 = lv_btn_create(ui->second_chronograph);
    ui->second_chronograph_btn_3_label = lv_label_create(ui->second_chronograph_btn_3);
    lv_label_set_text(ui->second_chronograph_btn_3_label, "");
    lv_label_set_long_mode(ui->second_chronograph_btn_3_label, LV_LABEL_LONG_CLIP);
    lv_obj_align(ui->second_chronograph_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->second_chronograph_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->second_chronograph_btn_3_label, LV_PCT(100));
    lv_obj_set_pos(ui->second_chronograph_btn_3, 23, 227);
    lv_obj_set_size(ui->second_chronograph_btn_3, 60, 60);

    //Write style for second_chronograph_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->second_chronograph_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->second_chronograph_btn_3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->second_chronograph_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->second_chronograph_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->second_chronograph_btn_3, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->second_chronograph_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->second_chronograph_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->second_chronograph_btn_3, &lv_font_icomoon_48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->second_chronograph_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->second_chronograph_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of second_chronograph.
    //下

    //Update current screen layout.
    lv_obj_update_layout(ui->second_chronograph);

    //Init events for screen.
    events_init_second_chronograph(ui);
}
