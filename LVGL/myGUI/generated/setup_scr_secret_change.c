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



void setup_scr_secret_change(lv_ui *ui)
{
    //Write codes secret_change
    ui->secret_change = lv_obj_create(NULL);
    lv_obj_set_size(ui->secret_change, 240, 320);
    lv_obj_set_scrollbar_mode(ui->secret_change, LV_SCROLLBAR_MODE_OFF);

    //Write style for secret_change, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->secret_change, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->secret_change, lv_color_hex(0xd0cbcb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->secret_change, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes secret_change_roller_1
    ui->secret_change_roller_1 = lv_roller_create(ui->secret_change);
    lv_roller_set_options(ui->secret_change_roller_1, "1\n2\n3\n4\n5\n6\n7\n8\n9\n0", LV_ROLLER_MODE_INFINITE);
    lv_obj_set_pos(ui->secret_change_roller_1, 0, 0);
    lv_obj_set_width(ui->secret_change_roller_1, 60);

    //Write style for secret_change_roller_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->secret_change_roller_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->secret_change_roller_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->secret_change_roller_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->secret_change_roller_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->secret_change_roller_1, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->secret_change_roller_1, &lv_font_simsun_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->secret_change_roller_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->secret_change_roller_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->secret_change_roller_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->secret_change_roller_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->secret_change_roller_1, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->secret_change_roller_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->secret_change_roller_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->secret_change_roller_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->secret_change_roller_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for secret_change_roller_1, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->secret_change_roller_1, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->secret_change_roller_1, lv_color_hex(0x2195f6), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->secret_change_roller_1, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->secret_change_roller_1, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->secret_change_roller_1, &lv_font_simsun_12, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->secret_change_roller_1, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);

    lv_roller_set_visible_row_count(ui->secret_change_roller_1, 6);
    //Write codes secret_change_roller_2
    ui->secret_change_roller_2 = lv_roller_create(ui->secret_change);
    lv_roller_set_options(ui->secret_change_roller_2, "1\n2\n3\n4\n5\n6\n7\n8\n9\n0", LV_ROLLER_MODE_INFINITE);
    lv_obj_set_pos(ui->secret_change_roller_2, 60, 0);
    lv_obj_set_width(ui->secret_change_roller_2, 60);

    //Write style for secret_change_roller_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->secret_change_roller_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->secret_change_roller_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->secret_change_roller_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->secret_change_roller_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->secret_change_roller_2, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->secret_change_roller_2, &lv_font_simsun_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->secret_change_roller_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->secret_change_roller_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->secret_change_roller_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->secret_change_roller_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->secret_change_roller_2, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->secret_change_roller_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->secret_change_roller_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->secret_change_roller_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->secret_change_roller_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for secret_change_roller_2, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->secret_change_roller_2, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->secret_change_roller_2, lv_color_hex(0x2195f6), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->secret_change_roller_2, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->secret_change_roller_2, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->secret_change_roller_2, &lv_font_simsun_12, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->secret_change_roller_2, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);

    lv_roller_set_visible_row_count(ui->secret_change_roller_2, 6);
    //Write codes secret_change_roller_3
    ui->secret_change_roller_3 = lv_roller_create(ui->secret_change);
    lv_roller_set_options(ui->secret_change_roller_3, "1\n2\n3\n4\n5\n6\n7\n8\n9\n0", LV_ROLLER_MODE_INFINITE);
    lv_obj_set_pos(ui->secret_change_roller_3, 120, 0);
    lv_obj_set_width(ui->secret_change_roller_3, 60);

    //Write style for secret_change_roller_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->secret_change_roller_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->secret_change_roller_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->secret_change_roller_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->secret_change_roller_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->secret_change_roller_3, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->secret_change_roller_3, &lv_font_simsun_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->secret_change_roller_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->secret_change_roller_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->secret_change_roller_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->secret_change_roller_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->secret_change_roller_3, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->secret_change_roller_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->secret_change_roller_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->secret_change_roller_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->secret_change_roller_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for secret_change_roller_3, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->secret_change_roller_3, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->secret_change_roller_3, lv_color_hex(0x2195f6), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->secret_change_roller_3, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->secret_change_roller_3, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->secret_change_roller_3, &lv_font_simsun_12, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->secret_change_roller_3, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);

    lv_roller_set_visible_row_count(ui->secret_change_roller_3, 6);
    //Write codes secret_change_roller_4
    ui->secret_change_roller_4 = lv_roller_create(ui->secret_change);
    lv_roller_set_options(ui->secret_change_roller_4, "1\n2\n3\n4\n5\n6\n7\n8\n9\n0", LV_ROLLER_MODE_INFINITE);
    lv_obj_set_pos(ui->secret_change_roller_4, 180, 0);
    lv_obj_set_width(ui->secret_change_roller_4, 60);

    //Write style for secret_change_roller_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->secret_change_roller_4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->secret_change_roller_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->secret_change_roller_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->secret_change_roller_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->secret_change_roller_4, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->secret_change_roller_4, &lv_font_simsun_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->secret_change_roller_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->secret_change_roller_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->secret_change_roller_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->secret_change_roller_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->secret_change_roller_4, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->secret_change_roller_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->secret_change_roller_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->secret_change_roller_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->secret_change_roller_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for secret_change_roller_4, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->secret_change_roller_4, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->secret_change_roller_4, lv_color_hex(0x2195f6), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->secret_change_roller_4, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->secret_change_roller_4, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->secret_change_roller_4, &lv_font_simsun_12, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->secret_change_roller_4, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);

    lv_roller_set_visible_row_count(ui->secret_change_roller_4, 6);
    //Write codes secret_change_btn_1
    ui->secret_change_btn_1 = lv_btn_create(ui->secret_change);
    ui->secret_change_btn_1_label = lv_label_create(ui->secret_change_btn_1);
    lv_label_set_text(ui->secret_change_btn_1_label, "退出");
    lv_label_set_long_mode(ui->secret_change_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->secret_change_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->secret_change_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->secret_change_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->secret_change_btn_1, 95, 177);
    lv_obj_set_size(ui->secret_change_btn_1, 53, 33);

    //Write style for secret_change_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->secret_change_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->secret_change_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->secret_change_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->secret_change_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->secret_change_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->secret_change_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->secret_change_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->secret_change_btn_1, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->secret_change_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->secret_change_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes secret_change_btn_2
    ui->secret_change_btn_2 = lv_btn_create(ui->secret_change);
    ui->secret_change_btn_2_label = lv_label_create(ui->secret_change_btn_2);
    lv_label_set_text(ui->secret_change_btn_2_label, "确定");
    lv_label_set_long_mode(ui->secret_change_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->secret_change_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->secret_change_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->secret_change_btn_2_label, LV_PCT(100));
    lv_obj_set_pos(ui->secret_change_btn_2, 173, 177);
    lv_obj_set_size(ui->secret_change_btn_2, 53, 33);

    //Write style for secret_change_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->secret_change_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->secret_change_btn_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->secret_change_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->secret_change_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->secret_change_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->secret_change_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->secret_change_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->secret_change_btn_2, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->secret_change_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->secret_change_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes secret_change_btn_3
    ui->secret_change_btn_3 = lv_btn_create(ui->secret_change);
    ui->secret_change_btn_3_label = lv_label_create(ui->secret_change_btn_3);
    lv_label_set_text(ui->secret_change_btn_3_label, "取消");
    lv_label_set_long_mode(ui->secret_change_btn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->secret_change_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->secret_change_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->secret_change_btn_3_label, LV_PCT(100));
    lv_obj_set_pos(ui->secret_change_btn_3, 18, 177);
    lv_obj_set_size(ui->secret_change_btn_3, 53, 33);

    //Write style for secret_change_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->secret_change_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->secret_change_btn_3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->secret_change_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->secret_change_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->secret_change_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->secret_change_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->secret_change_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->secret_change_btn_3, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->secret_change_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->secret_change_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes secret_change_msgbox_1
    static const char * secret_change_msgbox_1_btns[] = {"Apply","Close", ""};
    ui->secret_change_msgbox_1 = lv_msgbox_create(ui->secret_change, "", "是否修改密码?", secret_change_msgbox_1_btns, false);
    lv_obj_set_size(lv_msgbox_get_btns(ui->secret_change_msgbox_1), 120, 30);
    lv_obj_set_pos(ui->secret_change_msgbox_1, 32, 54);
    lv_obj_set_size(ui->secret_change_msgbox_1, 179, 98);

    //Write style for secret_change_msgbox_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->secret_change_msgbox_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->secret_change_msgbox_1, lv_color_hex(0xe6ff98), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->secret_change_msgbox_1, LV_GRAD_DIR_HOR, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui->secret_change_msgbox_1, lv_color_hex(0xecf2bb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui->secret_change_msgbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui->secret_change_msgbox_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->secret_change_msgbox_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->secret_change_msgbox_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->secret_change_msgbox_1, lv_color_hex(0xdef793), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->secret_change_msgbox_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->secret_change_msgbox_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->secret_change_msgbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_secret_change_msgbox_1_extra_content_main_default
    static lv_style_t style_secret_change_msgbox_1_extra_content_main_default;
    ui_init_style(&style_secret_change_msgbox_1_extra_content_main_default);

    lv_style_set_text_color(&style_secret_change_msgbox_1_extra_content_main_default, lv_color_hex(0x4e4e4e));
    lv_style_set_text_font(&style_secret_change_msgbox_1_extra_content_main_default, &lv_font_simsun_18);
    lv_style_set_text_opa(&style_secret_change_msgbox_1_extra_content_main_default, 255);
    lv_style_set_text_letter_space(&style_secret_change_msgbox_1_extra_content_main_default, 0);
    lv_style_set_text_line_space(&style_secret_change_msgbox_1_extra_content_main_default, 8);
    lv_obj_add_style(lv_msgbox_get_text(ui->secret_change_msgbox_1), &style_secret_change_msgbox_1_extra_content_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_secret_change_msgbox_1_extra_btns_items_default
    static lv_style_t style_secret_change_msgbox_1_extra_btns_items_default;
    ui_init_style(&style_secret_change_msgbox_1_extra_btns_items_default);

    lv_style_set_bg_opa(&style_secret_change_msgbox_1_extra_btns_items_default, 255);
    lv_style_set_bg_color(&style_secret_change_msgbox_1_extra_btns_items_default, lv_color_hex(0xe6e6e6));
    lv_style_set_bg_grad_dir(&style_secret_change_msgbox_1_extra_btns_items_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_secret_change_msgbox_1_extra_btns_items_default, 0);
    lv_style_set_radius(&style_secret_change_msgbox_1_extra_btns_items_default, 10);
    lv_style_set_text_color(&style_secret_change_msgbox_1_extra_btns_items_default, lv_color_hex(0x4e4e4e));
    lv_style_set_text_font(&style_secret_change_msgbox_1_extra_btns_items_default, &lv_font_simsun_12);
    lv_style_set_text_opa(&style_secret_change_msgbox_1_extra_btns_items_default, 255);
    lv_obj_add_style(lv_msgbox_get_btns(ui->secret_change_msgbox_1), &style_secret_change_msgbox_1_extra_btns_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write codes secret_change_msgbox_2
    static const char * secret_change_msgbox_2_btns[] = {"Apply","Close", ""};
    ui->secret_change_msgbox_2 = lv_msgbox_create(ui->secret_change, "", "是否取消密码?", secret_change_msgbox_2_btns, false);
    lv_obj_set_size(lv_msgbox_get_btns(ui->secret_change_msgbox_2), 120, 30);
    lv_obj_set_pos(ui->secret_change_msgbox_2, 32, 54);
    lv_obj_set_size(ui->secret_change_msgbox_2, 179, 98);

    //Write style for secret_change_msgbox_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->secret_change_msgbox_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->secret_change_msgbox_2, lv_color_hex(0xe6ff98), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->secret_change_msgbox_2, LV_GRAD_DIR_HOR, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui->secret_change_msgbox_2, lv_color_hex(0xecf2bb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui->secret_change_msgbox_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui->secret_change_msgbox_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->secret_change_msgbox_2, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->secret_change_msgbox_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->secret_change_msgbox_2, lv_color_hex(0xdef793), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->secret_change_msgbox_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->secret_change_msgbox_2, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->secret_change_msgbox_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_secret_change_msgbox_2_extra_content_main_default
    static lv_style_t style_secret_change_msgbox_2_extra_content_main_default;
    ui_init_style(&style_secret_change_msgbox_2_extra_content_main_default);

    lv_style_set_text_color(&style_secret_change_msgbox_2_extra_content_main_default, lv_color_hex(0x4e4e4e));
    lv_style_set_text_font(&style_secret_change_msgbox_2_extra_content_main_default, &lv_font_simsun_18);
    lv_style_set_text_opa(&style_secret_change_msgbox_2_extra_content_main_default, 255);
    lv_style_set_text_letter_space(&style_secret_change_msgbox_2_extra_content_main_default, 0);
    lv_style_set_text_line_space(&style_secret_change_msgbox_2_extra_content_main_default, 8);
    lv_obj_add_style(lv_msgbox_get_text(ui->secret_change_msgbox_2), &style_secret_change_msgbox_2_extra_content_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_secret_change_msgbox_2_extra_btns_items_default
    static lv_style_t style_secret_change_msgbox_2_extra_btns_items_default;
    ui_init_style(&style_secret_change_msgbox_2_extra_btns_items_default);

    lv_style_set_bg_opa(&style_secret_change_msgbox_2_extra_btns_items_default, 255);
    lv_style_set_bg_color(&style_secret_change_msgbox_2_extra_btns_items_default, lv_color_hex(0xe6e6e6));
    lv_style_set_bg_grad_dir(&style_secret_change_msgbox_2_extra_btns_items_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_secret_change_msgbox_2_extra_btns_items_default, 0);
    lv_style_set_radius(&style_secret_change_msgbox_2_extra_btns_items_default, 10);
    lv_style_set_text_color(&style_secret_change_msgbox_2_extra_btns_items_default, lv_color_hex(0x4e4e4e));
    lv_style_set_text_font(&style_secret_change_msgbox_2_extra_btns_items_default, &lv_font_simsun_12);
    lv_style_set_text_opa(&style_secret_change_msgbox_2_extra_btns_items_default, 255);
    lv_obj_add_style(lv_msgbox_get_btns(ui->secret_change_msgbox_2), &style_secret_change_msgbox_2_extra_btns_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //The custom code of secret_change.
    // 初始时隐藏msgbox
    lv_obj_add_flag(ui->secret_change_msgbox_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->secret_change_msgbox_2, LV_OBJ_FLAG_HIDDEN);

    //Update current screen layout.
    lv_obj_update_layout(ui->secret_change);

    //Init events for screen.
    events_init_secret_change(ui);
}
