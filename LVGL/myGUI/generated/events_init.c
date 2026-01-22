/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include <stdlib.h>

#include "custom.h"
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

// 全局变量（移到函数内部或用 static）
static lv_point_t touch_start;
static int32_t panel_start_y;
static bool is_touch_start = false;

void my_ui_event_DropDownGesture(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);

    if (ui == NULL || ui->scr1_cont_1 == NULL || ui->scr1 == NULL) return;

    if (code == LV_EVENT_PRESSED) {
        lv_indev_get_point(lv_indev_get_act(), &touch_start);
        panel_start_y = lv_obj_get_y(ui->scr1_cont_1);
        is_touch_start = true;
    }
    else if (code == LV_EVENT_PRESSING && is_touch_start) {
        lv_point_t curr;
        lv_indev_get_point(lv_indev_get_act(), &curr);

        int32_t dx = curr.x - touch_start.x;
        int32_t dy = curr.y - touch_start.y;

        // ===== 右滑切换页面逻辑（替代 GESTURE）=====
        if (dx > 50 && dx > abs(dy) * 2) { // 右滑：x变化大，y变化小
            is_touch_start = false;
            ui_load_scr_animation(&guider_ui, &guider_ui.menu2, guider_ui.menu2_del, &guider_ui.scr1_del, setup_scr_menu2, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 10, true, true);
            return;
        }

        // ===== 下拉面板逻辑 =====
        int32_t new_y = panel_start_y + dy;
        if (new_y < -130) new_y = -130;
        if (new_y > 0) new_y = 0;
        lv_obj_set_y(ui->scr1_cont_1, new_y);
    }
    else if (code == LV_EVENT_RELEASED) {
        is_touch_start = false;
    }
}
// 计算工具函数（核心逻辑）
static int get_result(int old, int oper, int value) {
    int result = 0;
    switch (oper) {
    case 0:
        result = value;
        break;  // 首次输入直接取当前值
    case 3:
        result = old + value;
        break;
    case 7:
        result = old - value;
        break;
    case 11:
        result = old * value;
        break;
    case 15:
        result = (value != 0) ? (old / value) : 0;
        break;  // 避免除0崩溃
    default:
        break;
    }
    return result;
}

// 计算器事件处理函数（按钮点击逻辑）
static void my_calculator_event_handle(lv_event_t* e) {
    lv_ui* ui = lv_event_get_user_data(e);
    // 防御：确保UI指针和控件有效（避免空指针）
    if (ui == NULL || ui->calculator_btnm_1 == NULL || ui->calculator_label_1 == NULL) {
        return;
    }

    // 获取点击的按钮ID和文本
    uint32_t id = lv_btnmatrix_get_selected_btn(ui->calculator_btnm_1);
    const char* txt = lv_btnmatrix_get_btn_text(ui->calculator_btnm_1, id);
    if (txt == NULL) return;  // 文本无效则退出

    // 计算状态变量（跨事件保留值）
    static int old = 0;    // 上一次计算结果
    static int oper = 0;   // 运算符（0:无，3:+，7:-，11:*，15:/）
    static char num[10] = {0};  // 当前输入数字字符串
    int value = 0;         // 当前输入数字值

    switch (id) {
    // 处理运算符（+、-、*、/）
    case 3:
    case 7:
    case 11:
    case 15:
        // 读取当前输入数字（失败则设为0）
        if (sscanf(num, "%d", &value) != 1) value = 0;
        old = get_result(old, oper, value);  // 计算中间结果
        lv_label_set_text_fmt(ui->calculator_label_1, "%d", old);  // 更新显示
        oper = id;  // 记录当前运算符
        memset(num, 0, sizeof(num));  // 清空输入缓存
        break;

    // 处理等号（=）
    case 14:
        if (sscanf(num, "%d", &value) != 1) value = 0;
        old = get_result(old, oper, value);  // 计算最终结果
        lv_label_set_text_fmt(ui->calculator_label_1, "%d", old);
        // 重置状态（为下一次计算准备）
        oper = 0;
        old = 0;
        memset(num, 0, sizeof(num));
        break;

    // 处理清零（C）
    case 12:
        lv_label_set_text(ui->calculator_label_1, "");  // 清空显示
        oper = 0;
        old = 0;
        memset(num, 0, sizeof(num));
        break;

    // 处理数字键（0-9）
    default:
        // 确保数字字符串不越界（+1预留结束符位置）
        if (strlen(num) + strlen(txt) < sizeof(num)) {
            strcat(num, txt);
            lv_label_set_text(ui->calculator_label_1, num);  // 更新显示
        }
    }
}
static int current_angle = 0;
static lv_timer_t *rotate_timer = NULL;

static void rotate_timer_cb(lv_timer_t *timer) {
    // 获取界面对象（兼容旧版本LVGL的参数获取函数）
    lv_ui *ui =(lv_ui *)timer->user_data;
    if (ui == NULL) return;

    // 角度递增（0-60循环，匹配仪表盘刻度范围）
    current_angle = (current_angle + 1) % 60;

    // 更新指针角度（使用正确的指针名称）
    lv_meter_set_indicator_value(
        ui->second_chronograph_meter_1,  // 仪表盘容器
        ui->second_chronograph_meter_1_scale_0_ndline_0,  // 正确的指针名称
        current_angle
    );
}

// btn_1（启动按钮）事件处理函数（核心逻辑）
static void my_second_chronograph_btn_1_event_handler(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    if (code != LV_EVENT_CLICKED) return;  // 只处理点击事件

    // 从事件中获取界面对象（与GUI Guider生成的事件逻辑一致）
    lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
    if (ui == NULL) return;

    // 启动定时器（避免重复创建）
    if (rotate_timer == NULL) {
        // 创建1000ms定时器，传递ui作为用户数据（供回调函数使用）
        rotate_timer = lv_timer_create(rotate_timer_cb, 1000, ui);
    }
}
static void my_second_chronograph_btn_3_event_handler(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    if (code != LV_EVENT_CLICKED) return;

    lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
    if (ui == NULL) return;

    // 停止定时器
    if (rotate_timer != NULL) {
        lv_timer_del(rotate_timer);
        rotate_timer = NULL;
    }

    // 重置角度为0并更新指针
    current_angle = 0;
    lv_meter_set_indicator_value(
        ui->second_chronograph_meter_1,
        ui->second_chronograph_meter_1_scale_0_ndline_0,
        current_angle
    );
}

static void scr1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        my_ui_event_DropDownGesture(e);
        break;
    }
    case LV_EVENT_PRESSING:
    {
        my_ui_event_DropDownGesture(e);
        break;
    }
    case LV_EVENT_RELEASED:
    {
        my_ui_event_DropDownGesture(e);
        break;
    }
    default:
        break;
    }
}

static void scr1_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        break;
    }
    default:
        break;
    }
}

void events_init_scr1 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->scr1, scr1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scr1_btn_1, scr1_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scr1,scr1_screen_loaded_event_handler, LV_EVENT_SCREEN_LOADED,NULL);
}

static void menu_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.scr1, guider_ui.scr1_del, &guider_ui.menu_del, setup_scr_scr1, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void menu_list_1_item0_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.calendar, guider_ui.calendar_del, &guider_ui.menu_del, setup_scr_calendar, LV_SCR_LOAD_ANIM_NONE, 10, 10, true, true);
        break;
    }
    default:
        break;
    }
}

static void menu_list_1_item1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.calculator, guider_ui.calculator_del, &guider_ui.menu_del, setup_scr_calculator, LV_SCR_LOAD_ANIM_NONE, 10, 10, true, true);
        break;
    }
    default:
        break;
    }
}

static void menu_list_1_item2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.second_chronograph, guider_ui.second_chronograph_del, &guider_ui.menu_del, setup_scr_second_chronograph, LV_SCR_LOAD_ANIM_NONE, 10, 10, true, true);
        break;
    }
    default:
        break;
    }
}

static void menu_list_1_item3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.card_bag, guider_ui.card_bag_del, &guider_ui.menu_del, setup_scr_card_bag, LV_SCR_LOAD_ANIM_NONE, 10, 10, true, true);
        break;
    }
    default:
        break;
    }
}

static void menu_list_1_item5_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        break;
    }
    default:
        break;
    }
}

static void menu_list_1_item6_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        break;
    }
    default:
        break;
    }
}

static void menu_list_1_item7_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.environment, guider_ui.environment_del, &guider_ui.menu_del, setup_scr_environment, LV_SCR_LOAD_ANIM_NONE, 10, 10, false, true);
        break;
    }
    default:
        break;
    }
}

static void menu_list_1_item8_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        break;
    }
    default:
        break;
    }
}

static void menu_list_1_item9_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        break;
    }
    default:
        break;
    }
}

static void menu_list_1_item10_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        break;
    }
    default:
        break;
    }
}

static void menu_list_1_item11_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        break;
    }
    default:
        break;
    }
}

void events_init_menu (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->menu, menu_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menu_list_1_item0, menu_list_1_item0_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menu_list_1_item1, menu_list_1_item1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menu_list_1_item2, menu_list_1_item2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menu_list_1_item3, menu_list_1_item3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menu_list_1_item5, menu_list_1_item5_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menu_list_1_item6, menu_list_1_item6_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menu_list_1_item7, menu_list_1_item7_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menu_list_1_item8, menu_list_1_item8_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menu_list_1_item9, menu_list_1_item9_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menu_list_1_item10, menu_list_1_item10_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menu_list_1_item11, menu_list_1_item11_event_handler, LV_EVENT_ALL, ui);
}

static void calendar_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.menu2, guider_ui.menu2_del, &guider_ui.calendar_del, setup_scr_menu2, LV_SCR_LOAD_ANIM_OVER_RIGHT, 50, 10, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_calendar (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->calendar, calendar_event_handler, LV_EVENT_ALL, ui);
}

static void calculator_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.menu2, guider_ui.menu2_del, &guider_ui.calculator_del, setup_scr_menu2, LV_SCR_LOAD_ANIM_OVER_RIGHT, 50, 10, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void calculator_btnm_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        lv_obj_t * obj = lv_event_get_target(e);
        uint32_t id = lv_btnmatrix_get_selected_btn(obj);
        my_calculator_event_handle(e);
        break;
    }
    default:
        break;
    }
}

void events_init_calculator (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->calculator, calculator_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->calculator_btnm_1, calculator_btnm_1_event_handler, LV_EVENT_ALL, ui);
}

static void second_chronograph_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.menu2, guider_ui.menu2_del, &guider_ui.second_chronograph_del, setup_scr_menu2, LV_SCR_LOAD_ANIM_OVER_RIGHT, 50, 10, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void second_chronograph_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        my_second_chronograph_btn_1_event_handler(e);
        break;
    }
    default:
        break;
    }
}

static void second_chronograph_btn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        my_second_chronograph_btn_3_event_handler(e);
        break;
    }
    default:
        break;
    }
}

void events_init_second_chronograph (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->second_chronograph, second_chronograph_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->second_chronograph_btn_1, second_chronograph_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->second_chronograph_btn_3, second_chronograph_btn_3_event_handler, LV_EVENT_ALL, ui);
}

static void environment_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.menu2, guider_ui.menu2_del, &guider_ui.environment_del, setup_scr_menu2, LV_SCR_LOAD_ANIM_OVER_RIGHT, 50, 10, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_environment (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->environment, environment_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(guider_ui.environment, environment_screen_loaded_cb, LV_EVENT_SCREEN_LOADED, NULL);
}

static void card_bag_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.menu2, guider_ui.menu2_del, &guider_ui.card_bag_del, setup_scr_menu2, LV_SCR_LOAD_ANIM_OVER_RIGHT, 50, 10, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_card_bag (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->card_bag, card_bag_event_handler, LV_EVENT_ALL, ui);
}

static void menu2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.scr1, guider_ui.scr1_del, &guider_ui.menu2_del, setup_scr_scr1, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 10, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void menu2_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.calendar, guider_ui.calendar_del, &guider_ui.menu2_del, setup_scr_calendar, LV_SCR_LOAD_ANIM_NONE, 200, 50, true, true);
        break;
    }
    default:
        break;
    }
}

static void menu2_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.calculator, guider_ui.calculator_del, &guider_ui.menu2_del, setup_scr_calculator, LV_SCR_LOAD_ANIM_NONE, 200, 50, true, true);
        break;
    }
    default:
        break;
    }
}

static void menu2_btn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.second_chronograph, guider_ui.second_chronograph_del, &guider_ui.menu2_del, setup_scr_second_chronograph, LV_SCR_LOAD_ANIM_NONE, 200, 50, true, true);
        break;
    }
    default:
        break;
    }
}

static void menu2_btn_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.card_bag, guider_ui.card_bag_del, &guider_ui.menu2_del, setup_scr_card_bag, LV_SCR_LOAD_ANIM_NONE, 200, 50, true, true);
        break;
    }
    default:
        break;
    }
}

static void menu2_btn_6_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED:
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.heart, guider_ui.heart_del, &guider_ui.menu2_del, setup_scr_heart, LV_SCR_LOAD_ANIM_NONE, 200, 50, true, true);
            break;
        }
        default:
            break;
    }
}

static void menu2_btn_8_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.environment, guider_ui.environment_del, &guider_ui.menu2_del, setup_scr_environment, LV_SCR_LOAD_ANIM_NONE, 200, 50, true, true);
        break;
    }
    default:
        break;
    }
}

static void menu2_btn_10_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED:
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.game, guider_ui.game_del, &guider_ui.menu2_del, setup_scr_game, LV_SCR_LOAD_ANIM_NONE, 200, 0, true, true);
            break;
        }
        default:
            break;
    }
}

static void menu2_btn_12_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED:
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.about_watch, guider_ui.about_watch_del, &guider_ui.menu2_del, setup_scr_about_watch, LV_SCR_LOAD_ANIM_NONE, 200, 0, true, true);
            break;
        }
        default:
            break;
    }
}

void events_init_menu2 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->menu2, menu2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menu2_btn_1, menu2_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menu2_btn_2, menu2_btn_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menu2_btn_3, menu2_btn_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menu2_btn_4, menu2_btn_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menu2_btn_6, menu2_btn_6_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menu2_btn_8, menu2_btn_8_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menu2_btn_10, menu2_btn_10_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menu2_btn_12, menu2_btn_12_event_handler, LV_EVENT_ALL, ui);
}


static void about_watch_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_GESTURE:
        {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
            switch(dir) {
                case LV_DIR_RIGHT:
                {
                    lv_indev_wait_release(lv_indev_get_act());
                    ui_load_scr_animation(&guider_ui, &guider_ui.menu2, guider_ui.menu2_del, &guider_ui.about_watch_del, setup_scr_menu2, LV_SCR_LOAD_ANIM_OVER_RIGHT, 50, 10, true, true);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

void events_init_about_watch (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->about_watch, about_watch_event_handler, LV_EVENT_ALL, ui);
}

static void heart_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_GESTURE:
        {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
            switch(dir) {
                case LV_DIR_RIGHT:
                {
                    lv_indev_wait_release(lv_indev_get_act());
                    ui_load_scr_animation(&guider_ui, &guider_ui.menu2, guider_ui.menu2_del, &guider_ui.heart_del, setup_scr_menu2, LV_SCR_LOAD_ANIM_OVER_RIGHT, 50, 10, true, true);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

static void heart_label_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED:
        {

            break;
        }
        default:
            break;
    }
}

void events_init_heart (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->heart, heart_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->heart_label_2, heart_label_2_event_handler, LV_EVENT_ALL, ui);
}

static void game_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.menu2, guider_ui.menu2_del, &guider_ui.game_del, setup_scr_menu2, LV_SCR_LOAD_ANIM_OVER_RIGHT, 50, 10, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void game_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.game_2048, guider_ui.game_2048_del, &guider_ui.game_del, setup_scr_game_2048, LV_SCR_LOAD_ANIM_NONE, 200, 50, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_game (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->game, game_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->game_btn_1, game_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void game_2048_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());

            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());

            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_get_act());

            break;
        }
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_get_act());

            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_game_2048 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->game_2048, game_2048_event_handler, LV_EVENT_ALL, ui);
}

void events_init(lv_ui *ui)
{

}
