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


void setup_scr_environment(lv_ui *ui)
{
    //Write codes environment
    ui->environment = lv_obj_create(NULL);
    lv_obj_set_size(ui->environment, 240, 320);
    lv_obj_set_scrollbar_mode(ui->environment, LV_SCROLLBAR_MODE_OFF);

    //Write style for environment, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->environment, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->environment, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->environment, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes environment_bar_1
    ui->environment_bar_1 = lv_bar_create(ui->environment);
    lv_obj_set_style_anim_time(ui->environment_bar_1, 1000, 0);
    lv_bar_set_mode(ui->environment_bar_1, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->environment_bar_1, 0, 50);
    lv_bar_set_value(ui->environment_bar_1, 25, LV_ANIM_OFF);
    lv_obj_set_pos(ui->environment_bar_1, 49, 101);
    lv_obj_set_size(ui->environment_bar_1, 24, 125);

    //Write style for environment_bar_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->environment_bar_1, 78, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->environment_bar_1, lv_color_hex(0xf04545), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->environment_bar_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->environment_bar_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->environment_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for environment_bar_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->environment_bar_1, 253, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->environment_bar_1, lv_color_hex(0xf04545), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->environment_bar_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->environment_bar_1, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes environment_label_1
    ui->environment_label_1 = lv_label_create(ui->environment);
    lv_label_set_text(ui->environment_label_1, "25\n");
    lv_label_set_long_mode(ui->environment_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->environment_label_1, 44, 236);
    lv_obj_set_size(ui->environment_label_1, 29, 23);

    //Write style for environment_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->environment_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->environment_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->environment_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->environment_label_1, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->environment_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->environment_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->environment_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->environment_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->environment_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->environment_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->environment_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->environment_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->environment_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->environment_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes environment_label_2
    ui->environment_label_2 = lv_label_create(ui->environment);
    lv_label_set_text(ui->environment_label_2, "C");
    lv_label_set_long_mode(ui->environment_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->environment_label_2, 70, 236);
    lv_obj_set_size(ui->environment_label_2, 22, 21);

    //Write style for environment_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->environment_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->environment_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->environment_label_2, lv_color_hex(0x878787), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->environment_label_2, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->environment_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->environment_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->environment_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->environment_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->environment_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->environment_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->environment_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->environment_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->environment_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->environment_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes environment_label_4
    ui->environment_label_4 = lv_label_create(ui->environment);
    lv_label_set_text(ui->environment_label_4, "%");
    lv_label_set_long_mode(ui->environment_label_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->environment_label_4, 180, 236);
    lv_obj_set_size(ui->environment_label_4, 21, 21);

    //Write style for environment_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->environment_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->environment_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->environment_label_4, lv_color_hex(0x878787), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->environment_label_4, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->environment_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->environment_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->environment_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->environment_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->environment_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->environment_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->environment_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->environment_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->environment_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->environment_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes environment_label_3
    ui->environment_label_3 = lv_label_create(ui->environment);
    lv_label_set_text(ui->environment_label_3, "67\n\n");
    lv_label_set_long_mode(ui->environment_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->environment_label_3, 155, 236);
    lv_obj_set_size(ui->environment_label_3, 29, 25);

    //Write style for environment_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->environment_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->environment_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->environment_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->environment_label_3, &lv_font_simsun_24, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->environment_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->environment_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->environment_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->environment_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->environment_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->environment_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->environment_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->environment_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->environment_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->environment_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes environment_bar_2
    ui->environment_bar_2 = lv_bar_create(ui->environment);
    lv_obj_set_style_anim_time(ui->environment_bar_2, 1000, 0);
    lv_bar_set_mode(ui->environment_bar_2, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->environment_bar_2, 0, 100);
    lv_bar_set_value(ui->environment_bar_2, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->environment_bar_2, 158, 101);
    lv_obj_set_size(ui->environment_bar_2, 24, 125);

    //Write style for environment_bar_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->environment_bar_2, 110, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->environment_bar_2, lv_color_hex(0x0500f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->environment_bar_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->environment_bar_2, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->environment_bar_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for environment_bar_2, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->environment_bar_2, 253, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->environment_bar_2, lv_color_hex(0x0500f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->environment_bar_2, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->environment_bar_2, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes environment_label_5
    ui->environment_label_5 = lv_label_create(ui->environment);
    lv_label_set_text(ui->environment_label_5, "" LV_SYMBOL_TINT "");
    lv_label_set_long_mode(ui->environment_label_5, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->environment_label_5, 151, 41);
    lv_obj_set_size(ui->environment_label_5, 42, 35);

    //Write style for environment_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->environment_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->environment_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->environment_label_5, lv_color_hex(0x004eff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->environment_label_5, &lv_font_simsun_32, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->environment_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->environment_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->environment_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->environment_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->environment_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->environment_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->environment_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->environment_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->environment_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->environment_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes environment_label_6
    ui->environment_label_6 = lv_label_create(ui->environment);
    lv_label_set_text(ui->environment_label_6, "");
    lv_label_set_long_mode(ui->environment_label_6, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->environment_label_6, 44, 41);
    lv_obj_set_size(ui->environment_label_6, 37, 34);

    //Write style for environment_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->environment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->environment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->environment_label_6, lv_color_hex(0xf04545), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->environment_label_6, &lv_font_icomoon_32, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->environment_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->environment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->environment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->environment_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->environment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->environment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->environment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->environment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->environment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->environment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of environment.


    // char text_buf[15];
    // snprintf(text_buf,sizeof(text_buf),"%d",(uint8_t)temperature);
    // lv_label_set_text(ui->environment_label_1, text_buf);
    // lv_bar_set_value(ui->environment_bar_1, (uint8_t)temperature, LV_ANIM_OFF);
    // snprintf(text_buf,sizeof(text_buf),"%d",(uint8_t)humidity);
    // lv_label_set_text(ui->environment_label_3, text_buf);
    // lv_bar_set_value(ui->environment_bar_2, (uint8_t)humidity, LV_ANIM_OFF);

    //Update current screen layout.
    lv_obj_update_layout(ui->environment);

    //Init events for screen.
    events_init_environment(ui);
}
