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



void setup_scr_chat(lv_ui *ui)
{
    //Write codes chat
    ui->chat = lv_obj_create(NULL);
    lv_obj_set_size(ui->chat, 240, 320);
    lv_obj_set_scrollbar_mode(ui->chat, LV_SCROLLBAR_MODE_OFF);

    //Write style for chat, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->chat, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->chat, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->chat, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes chat_ta_1
    ui->chat_ta_1 = lv_textarea_create(ui->chat);
    lv_textarea_set_text(ui->chat_ta_1, "Hello World");
    lv_textarea_set_placeholder_text(ui->chat_ta_1, "");
    lv_textarea_set_password_bullet(ui->chat_ta_1, "*");
    lv_textarea_set_password_mode(ui->chat_ta_1, false);
    lv_textarea_set_one_line(ui->chat_ta_1, false);
    lv_textarea_set_accepted_chars(ui->chat_ta_1, "");
    lv_textarea_set_max_length(ui->chat_ta_1, 50);
#if LV_USE_KEYBOARD != 0 || LV_USE_ZH_KEYBOARD != 0
    lv_obj_add_event_cb(ui->chat_ta_1, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif
    lv_obj_set_pos(ui->chat_ta_1, 3, 240);
    lv_obj_set_size(ui->chat_ta_1, 180, 30);

    //Write style for chat_ta_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->chat_ta_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->chat_ta_1, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->chat_ta_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->chat_ta_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->chat_ta_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->chat_ta_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->chat_ta_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->chat_ta_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->chat_ta_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->chat_ta_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->chat_ta_1, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->chat_ta_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->chat_ta_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->chat_ta_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->chat_ta_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->chat_ta_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->chat_ta_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for chat_ta_1, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->chat_ta_1, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->chat_ta_1, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->chat_ta_1, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->chat_ta_1, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes chat_btn_1
    ui->chat_btn_1 = lv_btn_create(ui->chat);
    ui->chat_btn_1_label = lv_label_create(ui->chat_btn_1);
    lv_label_set_text(ui->chat_btn_1_label, "发送");
    lv_label_set_long_mode(ui->chat_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->chat_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->chat_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->chat_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->chat_btn_1, 185, 240);
    lv_obj_set_size(ui->chat_btn_1, 54, 32);

    //Write style for chat_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->chat_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->chat_btn_1, lv_color_hex(0x96caf6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->chat_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->chat_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->chat_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->chat_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->chat_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->chat_btn_1, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->chat_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->chat_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes chat_win_1
    ui->chat_win_1 = lv_win_create(ui->chat, 1);
    lv_obj_t * chat_win_1_title = lv_win_add_title(ui->chat_win_1, "");
    // lv_obj_t *chat_win_1_label = lv_label_create(lv_win_get_content(ui->chat_win_1));
    // lv_label_set_text(chat_win_1_label, "this is a \nlong text \nto show \nscrollbar. \nif \nit \nis not \nlong enough, \nadd more content\n123");
    ui->chat_win_1_label = lv_label_create(lv_win_get_content(ui->chat_win_1));
    lv_label_set_text(ui->chat_win_1_label, "123");
    lv_obj_set_scrollbar_mode(lv_win_get_content(ui->chat_win_1), LV_SCROLLBAR_MODE_ACTIVE);
    lv_obj_set_pos(ui->chat_win_1, 0, 0);
    lv_obj_set_size(ui->chat_win_1, 237, 240);
    lv_obj_set_scrollbar_mode(ui->chat_win_1, LV_SCROLLBAR_MODE_ACTIVE);

    //Write style for chat_win_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->chat_win_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->chat_win_1, lv_color_hex(0xeeeef6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->chat_win_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->chat_win_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->chat_win_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_chat_win_1_extra_content_main_default
    static lv_style_t style_chat_win_1_extra_content_main_default;
    ui_init_style(&style_chat_win_1_extra_content_main_default);

    lv_style_set_bg_opa(&style_chat_win_1_extra_content_main_default, 255);
    lv_style_set_bg_color(&style_chat_win_1_extra_content_main_default, lv_color_hex(0xeeeef6));
    lv_style_set_bg_grad_dir(&style_chat_win_1_extra_content_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_text_color(&style_chat_win_1_extra_content_main_default, lv_color_hex(0x000000));
    lv_style_set_text_font(&style_chat_win_1_extra_content_main_default, &lv_font_simsun_12);
    lv_style_set_text_opa(&style_chat_win_1_extra_content_main_default, 255);
    lv_style_set_text_letter_space(&style_chat_win_1_extra_content_main_default, 0);
    lv_style_set_text_line_space(&style_chat_win_1_extra_content_main_default, 1);
    lv_obj_add_style(lv_win_get_content(ui->chat_win_1), &style_chat_win_1_extra_content_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of chat.


    //Update current screen layout.
    lv_obj_update_layout(ui->chat);

    //Init events for screen.
    events_init_chat(ui);
}
