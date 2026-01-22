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



void setup_scr_about_watch(lv_ui *ui)
{
    //Write codes about_watch
    ui->about_watch = lv_obj_create(NULL);
    lv_obj_set_size(ui->about_watch, 240, 320);
    lv_obj_set_scrollbar_mode(ui->about_watch, LV_SCROLLBAR_MODE_OFF);

    //Write style for about_watch, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->about_watch, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->about_watch, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->about_watch, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes about_watch_spangroup_1
    ui->about_watch_spangroup_1 = lv_spangroup_create(ui->about_watch);
    lv_spangroup_set_align(ui->about_watch_spangroup_1, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->about_watch_spangroup_1, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->about_watch_spangroup_1, LV_SPAN_MODE_BREAK);
    //create span
    ui->about_watch_spangroup_1_span = lv_spangroup_new_span(ui->about_watch_spangroup_1);
    lv_span_set_text(ui->about_watch_spangroup_1_span, "                        ");
    lv_style_set_text_color(&ui->about_watch_spangroup_1_span->style, lv_color_hex(0x0093ff));
    lv_style_set_text_decor(&ui->about_watch_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->about_watch_spangroup_1_span->style, &lv_font_simsun_18);
    ui->about_watch_spangroup_1_span = lv_spangroup_new_span(ui->about_watch_spangroup_1);
    lv_span_set_text(ui->about_watch_spangroup_1_span, "手表类型                 ");
    lv_style_set_text_color(&ui->about_watch_spangroup_1_span->style, lv_color_hex(0x0093ff));
    lv_style_set_text_decor(&ui->about_watch_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->about_watch_spangroup_1_span->style, &lv_font_simsun_18);
    ui->about_watch_spangroup_1_span = lv_spangroup_new_span(ui->about_watch_spangroup_1);
    lv_span_set_text(ui->about_watch_spangroup_1_span, "OV-Watch                ");
    lv_style_set_text_color(&ui->about_watch_spangroup_1_span->style, lv_color_hex(0xffffff));
    lv_style_set_text_decor(&ui->about_watch_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->about_watch_spangroup_1_span->style, &lv_font_simsun_18);
    ui->about_watch_spangroup_1_span = lv_spangroup_new_span(ui->about_watch_spangroup_1);
    lv_span_set_text(ui->about_watch_spangroup_1_span, "固件芯片                 ");
    lv_style_set_text_color(&ui->about_watch_spangroup_1_span->style, lv_color_hex(0x0093ff));
    lv_style_set_text_decor(&ui->about_watch_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->about_watch_spangroup_1_span->style, &lv_font_simsun_18);
    ui->about_watch_spangroup_1_span = lv_spangroup_new_span(ui->about_watch_spangroup_1);
    lv_span_set_text(ui->about_watch_spangroup_1_span, "V1.0.0                  ");
    lv_style_set_text_color(&ui->about_watch_spangroup_1_span->style, lv_color_hex(0xffffff));
    lv_style_set_text_decor(&ui->about_watch_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->about_watch_spangroup_1_span->style, &lv_font_simsun_18);
    ui->about_watch_spangroup_1_span = lv_spangroup_new_span(ui->about_watch_spangroup_1);
    lv_span_set_text(ui->about_watch_spangroup_1_span, "主控芯片                 ");
    lv_style_set_text_color(&ui->about_watch_spangroup_1_span->style, lv_color_hex(0x0093ff));
    lv_style_set_text_decor(&ui->about_watch_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->about_watch_spangroup_1_span->style, &lv_font_simsun_18);
    ui->about_watch_spangroup_1_span = lv_spangroup_new_span(ui->about_watch_spangroup_1);
    lv_span_set_text(ui->about_watch_spangroup_1_span, "STM32F411CET6            ");
    lv_style_set_text_color(&ui->about_watch_spangroup_1_span->style, lv_color_hex(0xffffff));
    lv_style_set_text_decor(&ui->about_watch_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->about_watch_spangroup_1_span->style, &lv_font_simsun_18);
    ui->about_watch_spangroup_1_span = lv_spangroup_new_span(ui->about_watch_spangroup_1);
    lv_span_set_text(ui->about_watch_spangroup_1_span, "操作系统                 ");
    lv_style_set_text_color(&ui->about_watch_spangroup_1_span->style, lv_color_hex(0x0093ff));
    lv_style_set_text_decor(&ui->about_watch_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->about_watch_spangroup_1_span->style, &lv_font_simsun_18);
    ui->about_watch_spangroup_1_span = lv_spangroup_new_span(ui->about_watch_spangroup_1);
    lv_span_set_text(ui->about_watch_spangroup_1_span, "FreeRTOS                 ");
    lv_style_set_text_color(&ui->about_watch_spangroup_1_span->style, lv_color_hex(0xffffff));
    lv_style_set_text_decor(&ui->about_watch_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->about_watch_spangroup_1_span->style, &lv_font_simsun_18);
    ui->about_watch_spangroup_1_span = lv_spangroup_new_span(ui->about_watch_spangroup_1);
    lv_span_set_text(ui->about_watch_spangroup_1_span, "图形界面                 ");
    lv_style_set_text_color(&ui->about_watch_spangroup_1_span->style, lv_color_hex(0x0093ff));
    lv_style_set_text_decor(&ui->about_watch_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->about_watch_spangroup_1_span->style, &lv_font_simsun_18);
    ui->about_watch_spangroup_1_span = lv_spangroup_new_span(ui->about_watch_spangroup_1);
    lv_span_set_text(ui->about_watch_spangroup_1_span, "LVGL                     ");
    lv_style_set_text_color(&ui->about_watch_spangroup_1_span->style, lv_color_hex(0xffffff));
    lv_style_set_text_decor(&ui->about_watch_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->about_watch_spangroup_1_span->style, &lv_font_simsun_18);
    ui->about_watch_spangroup_1_span = lv_spangroup_new_span(ui->about_watch_spangroup_1);
    lv_span_set_text(ui->about_watch_spangroup_1_span, "硬件开发者              ");
    lv_style_set_text_color(&ui->about_watch_spangroup_1_span->style, lv_color_hex(0x0093ff));
    lv_style_set_text_decor(&ui->about_watch_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->about_watch_spangroup_1_span->style, &lv_font_simsun_18);
    ui->about_watch_spangroup_1_span = lv_spangroup_new_span(ui->about_watch_spangroup_1);
    lv_span_set_text(ui->about_watch_spangroup_1_span, "HLK                      ");
    lv_style_set_text_color(&ui->about_watch_spangroup_1_span->style, lv_color_hex(0xffffff));
    lv_style_set_text_decor(&ui->about_watch_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->about_watch_spangroup_1_span->style, &lv_font_simsun_18);
    ui->about_watch_spangroup_1_span = lv_spangroup_new_span(ui->about_watch_spangroup_1);
    lv_span_set_text(ui->about_watch_spangroup_1_span, "软件开发者              ");
    lv_style_set_text_color(&ui->about_watch_spangroup_1_span->style, lv_color_hex(0x0093ff));
    lv_style_set_text_decor(&ui->about_watch_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->about_watch_spangroup_1_span->style, &lv_font_simsun_18);
    ui->about_watch_spangroup_1_span = lv_spangroup_new_span(ui->about_watch_spangroup_1);
    lv_span_set_text(ui->about_watch_spangroup_1_span, "HLK                      ");
    lv_style_set_text_color(&ui->about_watch_spangroup_1_span->style, lv_color_hex(0xffffff));
    lv_style_set_text_decor(&ui->about_watch_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->about_watch_spangroup_1_span->style, &lv_font_simsun_18);
    ui->about_watch_spangroup_1_span = lv_spangroup_new_span(ui->about_watch_spangroup_1);
    lv_span_set_text(ui->about_watch_spangroup_1_span, "界面设计者              ");
    lv_style_set_text_color(&ui->about_watch_spangroup_1_span->style, lv_color_hex(0x0093ff));
    lv_style_set_text_decor(&ui->about_watch_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->about_watch_spangroup_1_span->style, &lv_font_simsun_18);
    ui->about_watch_spangroup_1_span = lv_spangroup_new_span(ui->about_watch_spangroup_1);
    lv_span_set_text(ui->about_watch_spangroup_1_span, "HLK                                      ");
    lv_style_set_text_color(&ui->about_watch_spangroup_1_span->style, lv_color_hex(0xffffff));
    lv_style_set_text_decor(&ui->about_watch_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->about_watch_spangroup_1_span->style, &lv_font_simsun_18);
    lv_obj_set_pos(ui->about_watch_spangroup_1, 0, 0);
    lv_obj_set_size(ui->about_watch_spangroup_1, 240, 300);


    //Write style state: LV_STATE_DEFAULT for &style_about_watch_spangroup_1_main_main_default
    static lv_style_t style_about_watch_spangroup_1_main_main_default;
    ui_init_style(&style_about_watch_spangroup_1_main_main_default);

    lv_style_set_border_width(&style_about_watch_spangroup_1_main_main_default, 0);
    lv_style_set_radius(&style_about_watch_spangroup_1_main_main_default, 0);
    lv_style_set_bg_opa(&style_about_watch_spangroup_1_main_main_default, 0);
    lv_style_set_pad_top(&style_about_watch_spangroup_1_main_main_default, 12);
    lv_style_set_pad_right(&style_about_watch_spangroup_1_main_main_default, 0);
    lv_style_set_pad_bottom(&style_about_watch_spangroup_1_main_main_default, 0);
    lv_style_set_pad_left(&style_about_watch_spangroup_1_main_main_default, 15);
    lv_style_set_shadow_width(&style_about_watch_spangroup_1_main_main_default, 0);
    lv_obj_add_style(ui->about_watch_spangroup_1, &style_about_watch_spangroup_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->about_watch_spangroup_1);

    //The custom code of about_watch.


    //Update current screen layout.
    lv_obj_update_layout(ui->about_watch);

    //Init events for screen.
    events_init_about_watch(ui);
}
