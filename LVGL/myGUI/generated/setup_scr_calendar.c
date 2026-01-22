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
#include "rtc.h"

lv_calendar_date_t calendar_calendar_1_today;
lv_calendar_date_t calendar_calendar_1_highlihted_days[1];
void setup_scr_calendar(lv_ui *ui)
{
    RTC_TimeTypeDef nowtime;
    RTC_DateTypeDef nowdate;

    HAL_RTC_GetTime(&hrtc, &nowtime, RTC_FORMAT_BIN);
    HAL_RTC_GetDate(&hrtc, &nowdate, RTC_FORMAT_BIN);

    //Write codes calendar
    ui->calendar = lv_obj_create(NULL);
    lv_obj_set_size(ui->calendar, 240, 320);
    lv_obj_set_scrollbar_mode(ui->calendar, LV_SCROLLBAR_MODE_OFF);

    //Write style for calendar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->calendar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes calendar_calendar_1
    ui->calendar_calendar_1 = lv_calendar_create(ui->calendar);
    calendar_calendar_1_today.year = (2000+nowdate.Year);
    calendar_calendar_1_today.month = nowdate.Month;
    calendar_calendar_1_today.day = nowdate.Date;
    lv_calendar_set_today_date(ui->calendar_calendar_1, calendar_calendar_1_today.year, calendar_calendar_1_today.month, calendar_calendar_1_today.day);
    lv_calendar_set_showed_date(ui->calendar_calendar_1, calendar_calendar_1_today.year, calendar_calendar_1_today.month);
    // calendar_calendar_1_highlihted_days[0].year = 2025;
    // calendar_calendar_1_highlihted_days[0].month = 12;
    // calendar_calendar_1_highlihted_days[0].day = 26;
    // lv_calendar_set_highlighted_dates(ui->calendar_calendar_1, calendar_calendar_1_highlihted_days, 1);
    lv_obj_t *calendar_calendar_1_header = lv_calendar_header_arrow_create(ui->calendar_calendar_1);
    lv_calendar_t *calendar_calendar_1 = (lv_calendar_t *)ui->calendar_calendar_1;
    lv_obj_add_event_cb(calendar_calendar_1->btnm, calendar_calendar_1_draw_part_begin_event_cb, LV_EVENT_DRAW_PART_BEGIN, NULL);
    lv_obj_add_event_cb(ui->calendar_calendar_1, calendar_calendar_1_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_set_pos(ui->calendar_calendar_1, 0, 0);
    lv_obj_set_size(ui->calendar_calendar_1, 240, 320);

    //Write style state: LV_STATE_DEFAULT for &style_calendar_calendar_1_main_main_default
    static lv_style_t style_calendar_calendar_1_main_main_default;
    ui_init_style(&style_calendar_calendar_1_main_main_default);

    lv_style_set_border_width(&style_calendar_calendar_1_main_main_default, 1);
    lv_style_set_border_opa(&style_calendar_calendar_1_main_main_default, 255);
    lv_style_set_border_color(&style_calendar_calendar_1_main_main_default, lv_color_hex(0xc0c0c0));
    lv_style_set_border_side(&style_calendar_calendar_1_main_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_bg_opa(&style_calendar_calendar_1_main_main_default, 255);
    lv_style_set_bg_color(&style_calendar_calendar_1_main_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_calendar_calendar_1_main_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_shadow_width(&style_calendar_calendar_1_main_main_default, 0);
    lv_style_set_radius(&style_calendar_calendar_1_main_main_default, 0);
    lv_obj_add_style(ui->calendar_calendar_1, &style_calendar_calendar_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_calendar_calendar_1_extra_header_main_default
    static lv_style_t style_calendar_calendar_1_extra_header_main_default;
    ui_init_style(&style_calendar_calendar_1_extra_header_main_default);

    lv_style_set_text_color(&style_calendar_calendar_1_extra_header_main_default, lv_color_hex(0xffffff));
    lv_style_set_text_font(&style_calendar_calendar_1_extra_header_main_default, &lv_font_simsun_12);
    lv_style_set_text_opa(&style_calendar_calendar_1_extra_header_main_default, 255);
    lv_style_set_bg_opa(&style_calendar_calendar_1_extra_header_main_default, 255);
    lv_style_set_bg_color(&style_calendar_calendar_1_extra_header_main_default, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_calendar_calendar_1_extra_header_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(calendar_calendar_1_header, &style_calendar_calendar_1_extra_header_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_calendar_calendar_1_main_items_default
    static lv_style_t style_calendar_calendar_1_main_items_default;
    ui_init_style(&style_calendar_calendar_1_main_items_default);

    lv_style_set_bg_opa(&style_calendar_calendar_1_main_items_default, 0);
    lv_style_set_border_width(&style_calendar_calendar_1_main_items_default, 1);
    lv_style_set_border_opa(&style_calendar_calendar_1_main_items_default, 255);
    lv_style_set_border_color(&style_calendar_calendar_1_main_items_default, lv_color_hex(0xc0c0c0));
    lv_style_set_border_side(&style_calendar_calendar_1_main_items_default, LV_BORDER_SIDE_FULL);
    lv_style_set_text_color(&style_calendar_calendar_1_main_items_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_calendar_calendar_1_main_items_default, &lv_font_simsun_12);
    lv_style_set_text_opa(&style_calendar_calendar_1_main_items_default, 255);
    lv_obj_add_style(lv_calendar_get_btnmatrix(ui->calendar_calendar_1), &style_calendar_calendar_1_main_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //The custom code of calendar.


    //Update current screen layout.
    lv_obj_update_layout(ui->calendar);

    //Init events for screen.
    events_init_calendar(ui);
}
