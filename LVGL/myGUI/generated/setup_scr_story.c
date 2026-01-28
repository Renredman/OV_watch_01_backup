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



void setup_scr_story(lv_ui *ui)
{
    //Write codes story
    ui->story = lv_obj_create(NULL);
    lv_obj_set_size(ui->story, 240, 320);
    lv_obj_set_scrollbar_mode(ui->story, LV_SCROLLBAR_MODE_OFF);

    //Write style for story, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->story, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->story, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->story, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes story_stor
    ui->story_stor = lv_menu_create(ui->story);

    //Create sidebar page for menu story_stor
    ui->story_stor_sidebar_page = lv_menu_page_create(ui->story_stor, "type");
    lv_menu_set_sidebar_page(ui->story_stor, ui->story_stor_sidebar_page);
    lv_obj_set_scrollbar_mode(ui->story_stor_sidebar_page, LV_SCROLLBAR_MODE_OFF);

    //Create subpage for story_stor
    ui->story_stor_subpage_1 = lv_menu_page_create(ui->story_stor, NULL);
    ui->story_stor_cont_1 = lv_menu_cont_create(ui->story_stor_sidebar_page);
    ui->story_stor_label_1 = lv_label_create(ui->story_stor_cont_1);
    lv_label_set_text(ui->story_stor_label_1, "PIO");
    lv_obj_set_size(ui->story_stor_label_1, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_set_scrollbar_mode(ui->story_stor_subpage_1, LV_SCROLLBAR_MODE_OFF);
    lv_menu_set_load_page_event(ui->story_stor, ui->story_stor_cont_1, ui->story_stor_subpage_1);

    //Create subpage for story_stor
    ui->story_stor_subpage_2 = lv_menu_page_create(ui->story_stor, NULL);
    ui->story_stor_cont_2 = lv_menu_cont_create(ui->story_stor_sidebar_page);
    ui->story_stor_label_2 = lv_label_create(ui->story_stor_cont_2);
    lv_label_set_text(ui->story_stor_label_2, "git");
    lv_obj_set_size(ui->story_stor_label_2, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_set_scrollbar_mode(ui->story_stor_subpage_2, LV_SCROLLBAR_MODE_OFF);
    lv_menu_set_load_page_event(ui->story_stor, ui->story_stor_cont_2, ui->story_stor_subpage_2);

    //Create subpage for story_stor
    ui->story_stor_subpage_3 = lv_menu_page_create(ui->story_stor, NULL);
    ui->story_stor_cont_3 = lv_menu_cont_create(ui->story_stor_sidebar_page);
    ui->story_stor_label_3 = lv_label_create(ui->story_stor_cont_3);
    lv_label_set_text(ui->story_stor_label_3, "RTOS");
    lv_obj_set_size(ui->story_stor_label_3, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_set_scrollbar_mode(ui->story_stor_subpage_3, LV_SCROLLBAR_MODE_OFF);
    lv_menu_set_load_page_event(ui->story_stor, ui->story_stor_cont_3, ui->story_stor_subpage_3);
    lv_event_send(ui->story_stor_cont_1, LV_EVENT_CLICKED, NULL);
    lv_obj_set_pos(ui->story_stor, -2, 1);
    lv_obj_set_size(ui->story_stor, 238, 268);
    lv_obj_set_scrollbar_mode(ui->story_stor, LV_SCROLLBAR_MODE_OFF);

    //Write style for story_stor, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->story_stor, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->story_stor, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->story_stor, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->story_stor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->story_stor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_story_stor_extra_sidebar_page_main_default
    static lv_style_t style_story_stor_extra_sidebar_page_main_default;
    ui_init_style(&style_story_stor_extra_sidebar_page_main_default);

    lv_style_set_bg_opa(&style_story_stor_extra_sidebar_page_main_default, 255);
    lv_style_set_bg_color(&style_story_stor_extra_sidebar_page_main_default, lv_color_hex(0xdaf2f8));
    lv_style_set_bg_grad_dir(&style_story_stor_extra_sidebar_page_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_radius(&style_story_stor_extra_sidebar_page_main_default, 0);
    lv_obj_add_style(ui->story_stor_sidebar_page, &style_story_stor_extra_sidebar_page_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_story_stor_extra_option_btns_main_default
    static lv_style_t style_story_stor_extra_option_btns_main_default;
    ui_init_style(&style_story_stor_extra_option_btns_main_default);

    lv_style_set_text_color(&style_story_stor_extra_option_btns_main_default, lv_color_hex(0x151212));
    lv_style_set_text_font(&style_story_stor_extra_option_btns_main_default, &lv_font_simsun_18);
    lv_style_set_text_opa(&style_story_stor_extra_option_btns_main_default, 255);
    lv_style_set_text_align(&style_story_stor_extra_option_btns_main_default, LV_TEXT_ALIGN_CENTER);
    lv_style_set_pad_top(&style_story_stor_extra_option_btns_main_default, 10);
    lv_style_set_pad_bottom(&style_story_stor_extra_option_btns_main_default, 10);
    lv_obj_add_style(ui->story_stor_cont_3, &style_story_stor_extra_option_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_stor_cont_2, &style_story_stor_extra_option_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_stor_cont_1, &style_story_stor_extra_option_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_story_stor_extra_option_btns_main_checked
    static lv_style_t style_story_stor_extra_option_btns_main_checked;
    ui_init_style(&style_story_stor_extra_option_btns_main_checked);

    lv_style_set_text_color(&style_story_stor_extra_option_btns_main_checked, lv_color_hex(0x9ab700));
    lv_style_set_text_font(&style_story_stor_extra_option_btns_main_checked, &lv_font_simsun_18);
    lv_style_set_text_opa(&style_story_stor_extra_option_btns_main_checked, 255);
    lv_style_set_text_align(&style_story_stor_extra_option_btns_main_checked, LV_TEXT_ALIGN_CENTER);
    lv_style_set_border_width(&style_story_stor_extra_option_btns_main_checked, 0);
    lv_style_set_radius(&style_story_stor_extra_option_btns_main_checked, 0);
    lv_style_set_bg_opa(&style_story_stor_extra_option_btns_main_checked, 60);
    lv_style_set_bg_color(&style_story_stor_extra_option_btns_main_checked, lv_color_hex(0x00e0b8));
    lv_style_set_bg_grad_dir(&style_story_stor_extra_option_btns_main_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->story_stor_cont_3, &style_story_stor_extra_option_btns_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_add_style(ui->story_stor_cont_2, &style_story_stor_extra_option_btns_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_add_style(ui->story_stor_cont_1, &style_story_stor_extra_option_btns_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_story_stor_extra_main_title_main_default
    static lv_style_t style_story_stor_extra_main_title_main_default;
    ui_init_style(&style_story_stor_extra_main_title_main_default);

    lv_style_set_text_color(&style_story_stor_extra_main_title_main_default, lv_color_hex(0x41485a));
    lv_style_set_text_font(&style_story_stor_extra_main_title_main_default, &lv_font_simsun_18);
    lv_style_set_text_opa(&style_story_stor_extra_main_title_main_default, 255);
    lv_style_set_text_align(&style_story_stor_extra_main_title_main_default, LV_TEXT_ALIGN_CENTER);
    lv_style_set_bg_opa(&style_story_stor_extra_main_title_main_default, 255);
    lv_style_set_bg_color(&style_story_stor_extra_main_title_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_story_stor_extra_main_title_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_pad_top(&style_story_stor_extra_main_title_main_default, 0);
    lv_style_set_pad_bottom(&style_story_stor_extra_main_title_main_default, 0);
    lv_menu_t * story_stor_menu= (lv_menu_t *)ui->story_stor;
    lv_obj_t * story_stor_title = story_stor_menu->sidebar_header_title;
    lv_obj_set_size(story_stor_title, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_add_style(lv_menu_get_sidebar_header(ui->story_stor), &style_story_stor_extra_main_title_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);



    //Write codes story_list_1
    ui->story_list_1 = lv_list_create(ui->story_stor_subpage_1);
    ui->story_list_1_item0 =lv_list_add_text(ui->story_list_1, "pio device monitor");
    ui->story_list_1_item1 =lv_list_add_text(ui->story_list_1, "pio device monitor -b ");
    ui->story_list_1_item2 =lv_list_add_text(ui->story_list_1, " 115200 -p COM3");
    ui->story_list_1_item3 =lv_list_add_text(ui->story_list_1, "pio update");
    ui->story_list_1_item4 =lv_list_add_text(ui->story_list_1, "pio upgrade");
    ui->story_list_1_item5 =lv_list_add_text(ui->story_list_1, "pio home");
    ui->story_list_1_item6 =lv_list_add_text(ui->story_list_1, "pio run -t upload -e");
    ui->story_list_1_item7 =lv_list_add_text(ui->story_list_1, "leonardo");
    ui->story_list_1_item8 =lv_list_add_text(ui->story_list_1, "pio check");
    lv_obj_set_pos(ui->story_list_1, 75, 31);
    lv_obj_set_size(ui->story_list_1, 158, 261);
    lv_obj_set_scrollbar_mode(ui->story_list_1, LV_SCROLLBAR_MODE_OFF);

    //Write style state: LV_STATE_DEFAULT for &style_story_list_1_main_main_default
    static lv_style_t style_story_list_1_main_main_default;
    ui_init_style(&style_story_list_1_main_main_default);

    lv_style_set_pad_top(&style_story_list_1_main_main_default, 5);
    lv_style_set_pad_left(&style_story_list_1_main_main_default, 5);
    lv_style_set_pad_right(&style_story_list_1_main_main_default, 5);
    lv_style_set_pad_bottom(&style_story_list_1_main_main_default, 5);
    lv_style_set_bg_opa(&style_story_list_1_main_main_default, 255);
    lv_style_set_bg_color(&style_story_list_1_main_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_story_list_1_main_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_story_list_1_main_main_default, 1);
    lv_style_set_border_opa(&style_story_list_1_main_main_default, 255);
    lv_style_set_border_color(&style_story_list_1_main_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_story_list_1_main_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_story_list_1_main_main_default, 3);
    lv_style_set_shadow_width(&style_story_list_1_main_main_default, 0);
    lv_obj_add_style(ui->story_list_1, &style_story_list_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_story_list_1_main_scrollbar_default
    static lv_style_t style_story_list_1_main_scrollbar_default;
    ui_init_style(&style_story_list_1_main_scrollbar_default);

    lv_style_set_radius(&style_story_list_1_main_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_story_list_1_main_scrollbar_default, 255);
    lv_style_set_bg_color(&style_story_list_1_main_scrollbar_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_story_list_1_main_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->story_list_1, &style_story_list_1_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_story_list_1_extra_btns_main_default
    static lv_style_t style_story_list_1_extra_btns_main_default;
    ui_init_style(&style_story_list_1_extra_btns_main_default);

    lv_style_set_pad_top(&style_story_list_1_extra_btns_main_default, 5);
    lv_style_set_pad_left(&style_story_list_1_extra_btns_main_default, 5);
    lv_style_set_pad_right(&style_story_list_1_extra_btns_main_default, 5);
    lv_style_set_pad_bottom(&style_story_list_1_extra_btns_main_default, 5);
    lv_style_set_border_width(&style_story_list_1_extra_btns_main_default, 0);
    lv_style_set_text_color(&style_story_list_1_extra_btns_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_story_list_1_extra_btns_main_default, &lv_font_simsun_18);
    lv_style_set_text_opa(&style_story_list_1_extra_btns_main_default, 255);
    lv_style_set_radius(&style_story_list_1_extra_btns_main_default, 3);
    lv_style_set_bg_opa(&style_story_list_1_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_story_list_1_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_story_list_1_extra_btns_main_default, LV_GRAD_DIR_NONE);

    //Write style state: LV_STATE_DEFAULT for &style_story_list_1_extra_texts_main_default
    static lv_style_t style_story_list_1_extra_texts_main_default;
    ui_init_style(&style_story_list_1_extra_texts_main_default);

    lv_style_set_pad_top(&style_story_list_1_extra_texts_main_default, 5);
    lv_style_set_pad_left(&style_story_list_1_extra_texts_main_default, 5);
    lv_style_set_pad_right(&style_story_list_1_extra_texts_main_default, 5);
    lv_style_set_pad_bottom(&style_story_list_1_extra_texts_main_default, 5);
    lv_style_set_border_width(&style_story_list_1_extra_texts_main_default, 0);
    lv_style_set_text_color(&style_story_list_1_extra_texts_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_story_list_1_extra_texts_main_default, &lv_font_simsun_12);
    lv_style_set_text_opa(&style_story_list_1_extra_texts_main_default, 255);
    lv_style_set_radius(&style_story_list_1_extra_texts_main_default, 3);
    lv_style_set_transform_width(&style_story_list_1_extra_texts_main_default, 0);
    lv_style_set_bg_opa(&style_story_list_1_extra_texts_main_default, 255);
    lv_style_set_bg_color(&style_story_list_1_extra_texts_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_story_list_1_extra_texts_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->story_list_1_item8, &style_story_list_1_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_list_1_item7, &style_story_list_1_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_list_1_item6, &style_story_list_1_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_list_1_item5, &style_story_list_1_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_list_1_item4, &style_story_list_1_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_list_1_item3, &style_story_list_1_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_list_1_item2, &style_story_list_1_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_list_1_item1, &style_story_list_1_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_list_1_item0, &style_story_list_1_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);



    //Write codes story_list_2
    ui->story_list_2 = lv_list_create(ui->story_stor_subpage_2);
    ui->story_list_2_item0 =lv_list_add_text(ui->story_list_2, "git status");
    ui->story_list_2_item1 =lv_list_add_text(ui->story_list_2, "git add .");
    ui->story_list_2_item2 =lv_list_add_text(ui->story_list_2, "git commit -m msg");
    ui->story_list_2_item3 =lv_list_add_text(ui->story_list_2, "git push");
    ui->story_list_2_item4 =lv_list_add_text(ui->story_list_2, "git config --list");
    ui->story_list_2_item5 =lv_list_add_text(ui->story_list_2, "git init");
    ui->story_list_2_item6 =lv_list_add_text(ui->story_list_2, "git config --global ");
    ui->story_list_2_item7 =lv_list_add_text(ui->story_list_2, "user.name Your Name");
    ui->story_list_2_item8 =lv_list_add_text(ui->story_list_2, "git clone https://git");
    ui->story_list_2_item9 =lv_list_add_text(ui->story_list_2, "hub.com/user/repo.git");
    lv_obj_set_pos(ui->story_list_2, 4, 0);
    lv_obj_set_size(ui->story_list_2, 158, 261);
    lv_obj_set_scrollbar_mode(ui->story_list_2, LV_SCROLLBAR_MODE_OFF);

    //Write style state: LV_STATE_DEFAULT for &style_story_list_2_main_main_default
    static lv_style_t style_story_list_2_main_main_default;
    ui_init_style(&style_story_list_2_main_main_default);

    lv_style_set_pad_top(&style_story_list_2_main_main_default, 5);
    lv_style_set_pad_left(&style_story_list_2_main_main_default, 5);
    lv_style_set_pad_right(&style_story_list_2_main_main_default, 5);
    lv_style_set_pad_bottom(&style_story_list_2_main_main_default, 5);
    lv_style_set_bg_opa(&style_story_list_2_main_main_default, 255);
    lv_style_set_bg_color(&style_story_list_2_main_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_story_list_2_main_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_story_list_2_main_main_default, 1);
    lv_style_set_border_opa(&style_story_list_2_main_main_default, 255);
    lv_style_set_border_color(&style_story_list_2_main_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_story_list_2_main_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_story_list_2_main_main_default, 3);
    lv_style_set_shadow_width(&style_story_list_2_main_main_default, 0);
    lv_obj_add_style(ui->story_list_2, &style_story_list_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_story_list_2_main_scrollbar_default
    static lv_style_t style_story_list_2_main_scrollbar_default;
    ui_init_style(&style_story_list_2_main_scrollbar_default);

    lv_style_set_radius(&style_story_list_2_main_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_story_list_2_main_scrollbar_default, 255);
    lv_style_set_bg_color(&style_story_list_2_main_scrollbar_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_story_list_2_main_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->story_list_2, &style_story_list_2_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_story_list_2_extra_btns_main_default
    static lv_style_t style_story_list_2_extra_btns_main_default;
    ui_init_style(&style_story_list_2_extra_btns_main_default);

    lv_style_set_pad_top(&style_story_list_2_extra_btns_main_default, 5);
    lv_style_set_pad_left(&style_story_list_2_extra_btns_main_default, 5);
    lv_style_set_pad_right(&style_story_list_2_extra_btns_main_default, 5);
    lv_style_set_pad_bottom(&style_story_list_2_extra_btns_main_default, 5);
    lv_style_set_border_width(&style_story_list_2_extra_btns_main_default, 0);
    lv_style_set_text_color(&style_story_list_2_extra_btns_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_story_list_2_extra_btns_main_default, &lv_font_simsun_18);
    lv_style_set_text_opa(&style_story_list_2_extra_btns_main_default, 255);
    lv_style_set_radius(&style_story_list_2_extra_btns_main_default, 3);
    lv_style_set_bg_opa(&style_story_list_2_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_story_list_2_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_story_list_2_extra_btns_main_default, LV_GRAD_DIR_NONE);

    //Write style state: LV_STATE_DEFAULT for &style_story_list_2_extra_texts_main_default
    static lv_style_t style_story_list_2_extra_texts_main_default;
    ui_init_style(&style_story_list_2_extra_texts_main_default);

    lv_style_set_pad_top(&style_story_list_2_extra_texts_main_default, 5);
    lv_style_set_pad_left(&style_story_list_2_extra_texts_main_default, 5);
    lv_style_set_pad_right(&style_story_list_2_extra_texts_main_default, 5);
    lv_style_set_pad_bottom(&style_story_list_2_extra_texts_main_default, 5);
    lv_style_set_border_width(&style_story_list_2_extra_texts_main_default, 0);
    lv_style_set_text_color(&style_story_list_2_extra_texts_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_story_list_2_extra_texts_main_default, &lv_font_simsun_12);
    lv_style_set_text_opa(&style_story_list_2_extra_texts_main_default, 255);
    lv_style_set_radius(&style_story_list_2_extra_texts_main_default, 3);
    lv_style_set_transform_width(&style_story_list_2_extra_texts_main_default, 0);
    lv_style_set_bg_opa(&style_story_list_2_extra_texts_main_default, 255);
    lv_style_set_bg_color(&style_story_list_2_extra_texts_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_story_list_2_extra_texts_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->story_list_2_item9, &style_story_list_2_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_list_2_item8, &style_story_list_2_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_list_2_item7, &style_story_list_2_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_list_2_item6, &style_story_list_2_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_list_2_item5, &style_story_list_2_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_list_2_item4, &style_story_list_2_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_list_2_item3, &style_story_list_2_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_list_2_item2, &style_story_list_2_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_list_2_item1, &style_story_list_2_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_list_2_item0, &style_story_list_2_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);



    //Write codes story_list_3
    ui->story_list_3 = lv_list_create(ui->story_stor_subpage_3);
    ui->story_list_3_item0 =lv_list_add_text(ui->story_list_3, "osMessageQueueGet");
    ui->story_list_3_item1 =lv_list_add_text(ui->story_list_3, "osMessageQueuePut");
    ui->story_list_3_item2 =lv_list_add_text(ui->story_list_3, "pvPortMalloc");
    ui->story_list_3_item3 =lv_list_add_text(ui->story_list_3, "vPortFree");
    ui->story_list_3_item4 =lv_list_add_text(ui->story_list_3, "lv_label_set_text");
    ui->story_list_3_item5 =lv_list_add_text(ui->story_list_3, "lv_scr_act()");
    ui->story_list_3_item6 =lv_list_add_text(ui->story_list_3, "lv_async_call");
    ui->story_list_3_item7 =lv_list_add_text(ui->story_list_3, "RTC_TimeTypeDef nowtime");
    ui->story_list_3_item8 =lv_list_add_text(ui->story_list_3, "ui_load_scr_animation");
    ui->story_list_3_item9 =lv_list_add_text(ui->story_list_3, "memset strncpy");
    lv_obj_set_pos(ui->story_list_3, 2, 0);
    lv_obj_set_size(ui->story_list_3, 160, 261);
    lv_obj_set_scrollbar_mode(ui->story_list_3, LV_SCROLLBAR_MODE_OFF);

    //Write style state: LV_STATE_DEFAULT for &style_story_list_3_main_main_default
    static lv_style_t style_story_list_3_main_main_default;
    ui_init_style(&style_story_list_3_main_main_default);

    lv_style_set_pad_top(&style_story_list_3_main_main_default, 5);
    lv_style_set_pad_left(&style_story_list_3_main_main_default, 5);
    lv_style_set_pad_right(&style_story_list_3_main_main_default, 5);
    lv_style_set_pad_bottom(&style_story_list_3_main_main_default, 5);
    lv_style_set_bg_opa(&style_story_list_3_main_main_default, 255);
    lv_style_set_bg_color(&style_story_list_3_main_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_story_list_3_main_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_story_list_3_main_main_default, 1);
    lv_style_set_border_opa(&style_story_list_3_main_main_default, 255);
    lv_style_set_border_color(&style_story_list_3_main_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_story_list_3_main_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_story_list_3_main_main_default, 3);
    lv_style_set_shadow_width(&style_story_list_3_main_main_default, 0);
    lv_obj_add_style(ui->story_list_3, &style_story_list_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_story_list_3_main_scrollbar_default
    static lv_style_t style_story_list_3_main_scrollbar_default;
    ui_init_style(&style_story_list_3_main_scrollbar_default);

    lv_style_set_radius(&style_story_list_3_main_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_story_list_3_main_scrollbar_default, 255);
    lv_style_set_bg_color(&style_story_list_3_main_scrollbar_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_story_list_3_main_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->story_list_3, &style_story_list_3_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_story_list_3_extra_btns_main_default
    static lv_style_t style_story_list_3_extra_btns_main_default;
    ui_init_style(&style_story_list_3_extra_btns_main_default);

    lv_style_set_pad_top(&style_story_list_3_extra_btns_main_default, 5);
    lv_style_set_pad_left(&style_story_list_3_extra_btns_main_default, 5);
    lv_style_set_pad_right(&style_story_list_3_extra_btns_main_default, 5);
    lv_style_set_pad_bottom(&style_story_list_3_extra_btns_main_default, 5);
    lv_style_set_border_width(&style_story_list_3_extra_btns_main_default, 0);
    lv_style_set_text_color(&style_story_list_3_extra_btns_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_story_list_3_extra_btns_main_default, &lv_font_simsun_18);
    lv_style_set_text_opa(&style_story_list_3_extra_btns_main_default, 255);
    lv_style_set_radius(&style_story_list_3_extra_btns_main_default, 3);
    lv_style_set_bg_opa(&style_story_list_3_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_story_list_3_extra_btns_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_story_list_3_extra_btns_main_default, LV_GRAD_DIR_NONE);

    //Write style state: LV_STATE_DEFAULT for &style_story_list_3_extra_texts_main_default
    static lv_style_t style_story_list_3_extra_texts_main_default;
    ui_init_style(&style_story_list_3_extra_texts_main_default);

    lv_style_set_pad_top(&style_story_list_3_extra_texts_main_default, 5);
    lv_style_set_pad_left(&style_story_list_3_extra_texts_main_default, 5);
    lv_style_set_pad_right(&style_story_list_3_extra_texts_main_default, 5);
    lv_style_set_pad_bottom(&style_story_list_3_extra_texts_main_default, 5);
    lv_style_set_border_width(&style_story_list_3_extra_texts_main_default, 0);
    lv_style_set_text_color(&style_story_list_3_extra_texts_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_story_list_3_extra_texts_main_default, &lv_font_simsun_12);
    lv_style_set_text_opa(&style_story_list_3_extra_texts_main_default, 255);
    lv_style_set_radius(&style_story_list_3_extra_texts_main_default, 3);
    lv_style_set_transform_width(&style_story_list_3_extra_texts_main_default, 0);
    lv_style_set_bg_opa(&style_story_list_3_extra_texts_main_default, 255);
    lv_style_set_bg_color(&style_story_list_3_extra_texts_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_story_list_3_extra_texts_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(ui->story_list_3_item9, &style_story_list_3_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_list_3_item8, &style_story_list_3_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_list_3_item7, &style_story_list_3_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_list_3_item6, &style_story_list_3_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_list_3_item5, &style_story_list_3_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_list_3_item4, &style_story_list_3_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_list_3_item3, &style_story_list_3_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_list_3_item2, &style_story_list_3_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_list_3_item1, &style_story_list_3_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui->story_list_3_item0, &style_story_list_3_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of story.


    //Update current screen layout.
    lv_obj_update_layout(ui->story);

    //Init events for screen.
    events_init_story(ui);
}
