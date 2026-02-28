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
#include "lcd_init.h"
#include "KT6328.h"
#include "FreeRTOS.h"
#include "usart.h"
#include "Tasks/SensorDataTask.h"
#include "Tasks/AppState.h"

static  bool g_is_measuring = false;

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

// btn_1（启动/停止按钮）事件处理函数（核心逻辑）
static void my_second_chronograph_btn_1_event_handler(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    if (code != LV_EVENT_CLICKED) return;  // 只处理点击事件

    // 从事件中获取界面对象（与GUI Guider生成的事件逻辑一致）
    lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
    if (ui == NULL) return;

    // 切换定时器状态：如果未运行则启动，已运行则停止
    if (rotate_timer == NULL) {
        // 启动定时器
        rotate_timer = lv_timer_create(rotate_timer_cb, 1000, ui);
    } else {
        // 停止定时器
        lv_timer_del(rotate_timer);
        rotate_timer = NULL;
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

static void scr1_slider_1_event_handler(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);

    switch (code) {
        case LV_EVENT_VALUE_CHANGED: {
            lv_obj_t *slider = lv_event_get_target(e);
            uint8_t new_value = (uint8_t)lv_slider_get_value(slider);
            g_app_state.scr1_slider_value = new_value;

            LCD_Set_Light(new_value);
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
        ui_load_scr_animation(&guider_ui, &guider_ui.settings, guider_ui.settings_del, &guider_ui.scr1_del, setup_scr_settings, LV_SCR_LOAD_ANIM_NONE, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void scr1_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_VALUE_CHANGED:
        {
            bool is_checked = lv_obj_has_state(lv_event_get_target(e),LV_STATE_CHECKED);
            g_app_state.scr1_btn_2_checked = is_checked;
            // if (is_checked) {
            //     // KT6328_Enable();
            // }
            // else {
            //     KT6328_Disable();
            // }
            break;
        }
        default:
            break;
    }
}

static void scr1_btn_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_VALUE_CHANGED:
        {
            bool is_checked = lv_obj_has_state(lv_event_get_target(e),LV_STATE_CHECKED);
            g_app_state.scr1_btn_4_checked = is_checked;
            break;
        }
        default:
            break;
    }
}

static void scr1_btn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED:
        {
            // 发送进入停止模式的消息
            uint8_t msg = 0;
            osMessageQueuePut(Stop_MessageQueueHandle, &msg, 0, 0);
            break;
        }
        default:
            break;
    }
}

void events_init_scr1 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->scr1, scr1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scr1_slider_1, scr1_slider_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scr1_btn_1, scr1_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scr1_btn_2, scr1_btn_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scr1_btn_3, scr1_btn_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scr1_btn_4, scr1_btn_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scr1,scr1_screen_loaded_event_handler, LV_EVENT_SCREEN_LOADED,ui);
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

static void menu2_btn_9_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED:
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.compass, guider_ui.compass_del, &guider_ui.menu2_del, setup_scr_compass, LV_SCR_LOAD_ANIM_NONE, 200, 50, true, true);
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

static void menu2_btn_11_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED:
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.settings, guider_ui.settings_del, &guider_ui.menu2_del, setup_scr_settings, LV_SCR_LOAD_ANIM_NONE, 200, 0, true, true);
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
    lv_obj_add_event_cb(ui->menu2_btn_9, menu2_btn_9_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menu2_btn_10, menu2_btn_10_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menu2_btn_11, menu2_btn_11_event_handler, LV_EVENT_ALL, ui);
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

static void heart_btn_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED)
    {
        // 【1. 隐藏按钮】
        lv_obj_add_flag(guider_ui.heart_btn_1, LV_OBJ_FLAG_HIDDEN);

        // 【2. 显示其他标签】
        lv_obj_clear_flag(guider_ui.heart_label_2, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(guider_ui.heart_label_3, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(guider_ui.heart_label_4, LV_OBJ_FLAG_HIDDEN);

        // 【3. 更新Label4为“正在测量...”】
        lv_label_set_text(guider_ui.heart_label_4, "正在测量...");

        // 【4. 发送开始测量命令】
        hr_command_t cmd = HR_CMD_START;
        osMessageQueuePut(HrCmdQueueHandle, &cmd, 0, 0);

        g_is_measuring = true;
    }
}

void heart_update_callback_from_data_task(HeartMessage *msg)
{
    if (lv_scr_act() == guider_ui.heart)
    {
        if (msg->status == 1) {
            // 更新实时心率
            char hr_str[10];
            snprintf(hr_str, sizeof(hr_str), "%d", msg->heart);
            lv_label_set_text(guider_ui.heart_label_2, hr_str);
        }
        else if (msg->status == 2) {
            // 测量完成
            lv_label_set_text(guider_ui.heart_label_4, "测量完成");
            g_is_measuring = false;
        }
    }
}

void events_init_heart (lv_ui *ui)
{
    // lv_obj_add_event_cb(ui->heart, heart_event_handler, LV_EVENT_ALL, ui);
    // lv_obj_add_event_cb(ui->heart_label_2, heart_label_2_event_handler, LV_EVENT_ALL, ui);

    // 【初始化UI状态】
    // 刚进入页面时，只有btn_1和label_1可见
    lv_obj_clear_flag(ui->heart_btn_1, LV_OBJ_FLAG_HIDDEN); // 确保按钮可见
    lv_obj_add_flag(ui->heart_label_2, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->heart_label_3, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->heart_label_4, LV_OBJ_FLAG_HIDDEN);

    // 【绑定事件】
    lv_obj_add_event_cb(ui->heart, heart_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->heart_btn_1, heart_btn_1_event_handler, LV_EVENT_CLICKED, ui);

    // 【重置状态】
    g_is_measuring = false;
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

static void game_btn_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED:
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.story, guider_ui.story_del, &guider_ui.game_del, setup_scr_story, LV_SCR_LOAD_ANIM_NONE, 200, 50, true, true);
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

static void game_btn_5_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED:
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.chat, guider_ui.chat_del, &guider_ui.game_del, setup_scr_chat, LV_SCR_LOAD_ANIM_NONE, 200, 50, true, true);
            break;
        }
        default:
            break;
    }
}

void events_init_game (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->game, game_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->game_btn_4, game_btn_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->game_btn_1, game_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->game_btn_5, game_btn_5_event_handler, LV_EVENT_ALL, ui);
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

static void settings_event_handler (lv_event_t *e)
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
                    ui_load_scr_animation(&guider_ui, &guider_ui.menu2, guider_ui.menu2_del, &guider_ui.settings_del, setup_scr_menu2, LV_SCR_LOAD_ANIM_OVER_RIGHT, 50, 10, true, true);
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

static void settings_sw_1_event_handler (lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_VALUE_CHANGED: {
            bool is_on = lv_obj_has_state(lv_event_get_target(e),LV_STATE_CHECKED);
            g_app_state.settings_sw_1_state = is_on;
            break;
        }
        default:
            break;
    }

}

static void settings_btn_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED:
        {
            lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
            if (ui == NULL) {
                return;
            }
            lv_obj_t * sw = ui->settings_sw_1;

            bool is_currently_on = lv_obj_has_state(sw, LV_STATE_CHECKED);
            // bool new_state = !is_currently_on;

            if (is_currently_on) {
                lv_obj_clear_state(sw, LV_STATE_CHECKED);
            } else {
                lv_obj_add_state(sw, LV_STATE_CHECKED);
            }
            // g_app_state.settings_sw_1_state = !is_currently_on;
            //
            lv_event_send(sw,LV_EVENT_VALUE_CHANGED,NULL);
            break;
        }
        default:
            break;
    }
}

static void settings_btn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
        case LV_EVENT_CLICKED:
        {
            ui_load_scr_animation(&guider_ui, &guider_ui.time_date, guider_ui.time_date_del, &guider_ui.settings_del, setup_scr_time_date, LV_SCR_LOAD_ANIM_NONE, 200, 50, true, true);
            break;
        }
        default:
            break;
    }
}

void events_init_settings (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->settings, settings_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->settings_sw_1, settings_sw_1_event_handler, LV_EVENT_VALUE_CHANGED, ui);
    lv_obj_add_event_cb(ui->settings_btn_4, settings_btn_4_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->settings_btn_3, settings_btn_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->settings,setting_screen_loaded_event_handler, LV_EVENT_SCREEN_LOADED,ui);
}

static void story_event_handler (lv_event_t *e)
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
                    ui_load_scr_animation(&guider_ui, &guider_ui.game, guider_ui.game_del, &guider_ui.story_del, setup_scr_game, LV_SCR_LOAD_ANIM_OVER_RIGHT, 50, 10, true, true);
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

void events_init_story (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->story, story_event_handler, LV_EVENT_ALL, ui);
}

static void chat_event_handler (lv_event_t *e)
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
                    ui_load_scr_animation(&guider_ui, &guider_ui.game, guider_ui.game_del, &guider_ui.chat_del, setup_scr_game, LV_SCR_LOAD_ANIM_OVER_RIGHT, 50, 10, true, true);
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

static void chat_screen_unload_start_handler(lv_event_t *e) {
    // 隐藏全局键盘
    lv_obj_add_flag(guider_ui.g_kb_top_layer, LV_OBJ_FLAG_HIDDEN);

    // 解绑 textarea，防止后续操作访问野指针
    lv_keyboard_set_textarea(guider_ui.g_kb_top_layer, NULL);
}

static void chat_ta_focused_handler(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);

    if (code == LV_EVENT_FOCUSED) {
        // 键盘即将弹出：缩小聊天窗口，移动输入框和按钮
        lv_obj_set_height(ui->chat_win_1, 97);
        lv_obj_set_y(ui->chat_ta_1, 97);
        lv_obj_set_y(ui->chat_btn_1, 97);
        // 可选：确保键盘可见（如果未自动弹出）
#if LV_USE_KEYBOARD
        lv_keyboard_set_textarea(guider_ui.g_kb_top_layer, ui->chat_ta_1);
        lv_obj_clear_flag(guider_ui.g_kb_top_layer, LV_OBJ_FLAG_HIDDEN);
#endif
    }
    else if (code == LV_EVENT_DEFOCUSED) {
        // 键盘已关闭：恢复原状
        lv_obj_set_height(ui->chat_win_1, 240);
        lv_obj_set_y(ui->chat_ta_1, 240);
        lv_obj_set_y(ui->chat_btn_1, 240);
        // 隐藏键盘（安全起见）
#if LV_USE_KEYBOARD
        lv_obj_add_flag(guider_ui.g_kb_top_layer, LV_OBJ_FLAG_HIDDEN);
        lv_keyboard_set_textarea(guider_ui.g_kb_top_layer, NULL);
#endif
    }
}

static void chat_btn_send_handler(lv_event_t *e) {
    lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
    const char *input = lv_textarea_get_text(ui->chat_ta_1);
    if (!input || strlen(input) == 0) return;

    // 1. 发送蓝牙数据（非阻塞）
    char msg[64];
    strncpy(msg, input, sizeof(msg) - 1);
    msg[sizeof(msg) - 1] = '\0';
    osMessageQueuePut(BluetoothTxQueueHandle, msg, 0, 0);

    // 2. 添加新消息到历史（格式："> 你好"）
    char new_line[MAX_LINE_LENGTH];
    snprintf(new_line, sizeof(new_line), "> %s", input);

    if (history_count < MAX_CHAT_LINES) {
        // 还有空间，直接添加
        strcpy(chat_history[history_count], new_line);
        history_count++;
    } else {
        // 已满，移除最旧的（第 0 条），其余上移
        for (int i = 0; i < MAX_CHAT_LINES - 1; i++) {
            strcpy(chat_history[i], chat_history[i + 1]);
        }
        strcpy(chat_history[MAX_CHAT_LINES - 1], new_line);
    }

    // 3. 拼接所有消息（用 \n 分隔）
    static char full_text[1024] = {0}; // 10*64 + 10 个换行符 ≈ 650 字节
    full_text[0] = '\0';
    for (int i = 0; i < history_count; i++) {
        strcat(full_text, chat_history[i]);
        strcat(full_text, "\n");
    }

    // 4. 更新 label 文本
    lv_label_set_text(ui->chat_win_1_label, full_text);

    // 5. 【可选】滚动到底部（LVGL v8 兼容）
    lv_obj_t *content = lv_win_get_content(ui->chat_win_1);
    lv_coord_t content_h = lv_obj_get_content_height(content);
    lv_coord_t win_h = lv_obj_get_height(ui->chat_win_1);
    lv_coord_t scroll_y = (content_h > win_h) ? (content_h - win_h) : 0;
    lv_obj_scroll_to_y(content, scroll_y, LV_ANIM_ON);

    // 6. 清空输入框
    lv_textarea_set_text(ui->chat_ta_1, "");
}

// static void chat_btn_send_handler(lv_event_t *e) {
//     lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
//     const char *input = lv_textarea_get_text(ui->chat_ta_1);
//     if (!input || strlen(input) == 0) return;
//
//     // 1. 发送数据
//     char msg[64];
//     strncpy(msg, input, sizeof(msg)-1);
//     msg[sizeof(msg)-1] = '\0';
//     osMessageQueuePut(BluetoothTxQueueHandle, msg, 0, 0);
//
//     // 2. 【关键】只显示最新消息，不拼接历史！
//     static char display_text[128];
//     snprintf(display_text, sizeof(display_text), "> %s", input);
//     lv_label_set_text(ui->chat_win_1_label, display_text);
//
//     // 3. 清空输入框
//     lv_textarea_set_text(ui->chat_ta_1, "");
// }


void events_init_chat (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->chat, chat_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->chat, chat_screen_unload_start_handler, LV_EVENT_SCREEN_UNLOAD_START, NULL);
    lv_obj_add_event_cb(ui->chat_ta_1, chat_ta_focused_handler, LV_EVENT_FOCUSED | LV_EVENT_DEFOCUSED, ui);
    lv_obj_add_event_cb(ui->chat_btn_1, chat_btn_send_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->chat, chat_screen_loaded_handler, LV_EVENT_SCREEN_LOADED, NULL);
}

static void compass_event_handler (lv_event_t *e)
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
                    ui_load_scr_animation(&guider_ui, &guider_ui.menu2, guider_ui.menu2_del, &guider_ui.compass_del, setup_scr_menu2, LV_SCR_LOAD_ANIM_OVER_RIGHT, 50, 10, true, true);
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

static void compass_screen_loaded_handler(lv_event_t *e)
{
    // 进入compass页面时立即更新环境数据（包括高度）
    trigger_immediate_envir_update();
}

void events_init_compass (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->compass, compass_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->compass, compass_screen_loaded_handler, LV_EVENT_SCREEN_LOADED, NULL);
}

static RTC_TimeTypeDef td_time_init;
static RTC_DateTypeDef td_date_init;
static RTC_TimeTypeDef td_time_edit;
static RTC_DateTypeDef td_date_edit;
static bool td_dirty = false;

static uint8_t time_date_days_in_month(uint8_t year, uint8_t month)
{
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2: {
            bool leap = ((year % 4) == 0);
            return leap ? 29 : 28;
        }
        default:
            return 31;
    }
}

static void time_date_sync_from_rtc(lv_ui *ui)
{
    HAL_RTC_GetTime(&hrtc, &td_time_init, RTC_FORMAT_BIN);
    HAL_RTC_GetDate(&hrtc, &td_date_init, RTC_FORMAT_BIN);

    td_time_edit = td_time_init;
    td_date_edit = td_date_init;
    td_dirty = false;

    // 更新 label
    lv_label_set_text_fmt(ui->time_date_label_2, "%04d", 2000 + td_date_edit.Year);
    lv_label_set_text_fmt(ui->time_date_label_4, "%02d", td_date_edit.Month);
    lv_label_set_text_fmt(ui->time_date_label_6, "%02d", td_date_edit.Date);
    lv_label_set_text_fmt(ui->time_date_label_8, "%02d", td_time_edit.Hours);
    lv_label_set_text_fmt(ui->time_date_label_10, "%02d", td_time_edit.Minutes);
    lv_label_set_text_fmt(ui->time_date_label_12, "%02d", td_time_edit.Seconds);
}

static void time_date_screen_loaded_handler(lv_event_t *e)
{
    lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
    if (ui == NULL) return;

    time_date_sync_from_rtc(ui);
    lv_obj_add_flag(ui->time_date_msgbox_1, LV_OBJ_FLAG_HIDDEN);
}

static void time_date_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_ui *ui = lv_event_get_user_data(e);

    if (code == LV_EVENT_GESTURE) {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        if (dir == LV_DIR_RIGHT) {
            lv_indev_wait_release(lv_indev_get_act());

            if (td_dirty) {
                lv_obj_clear_flag(ui->time_date_msgbox_1, LV_OBJ_FLAG_HIDDEN);
            } else {
                ui_load_scr_animation(&guider_ui, &guider_ui.settings, guider_ui.settings_del,
                                      &guider_ui.time_date_del, setup_scr_settings,
                                      LV_SCR_LOAD_ANIM_OVER_RIGHT, 50, 10, true, true);
            }
        }
    }
}

static void time_date_apply_and_refresh(lv_ui *ui)
{
    // 更新 label
    lv_label_set_text_fmt(ui->time_date_label_2, "%04d", 2000 + td_date_edit.Year);
    lv_label_set_text_fmt(ui->time_date_label_4, "%02d", td_date_edit.Month);
    lv_label_set_text_fmt(ui->time_date_label_6, "%02d", td_date_edit.Date);
    lv_label_set_text_fmt(ui->time_date_label_8, "%02d", td_time_edit.Hours);
    lv_label_set_text_fmt(ui->time_date_label_10, "%02d", td_time_edit.Minutes);
    lv_label_set_text_fmt(ui->time_date_label_12, "%02d", td_time_edit.Seconds);

    // 判断是否真正修改
    td_dirty = (memcmp(&td_time_edit, &td_time_init, sizeof(td_time_init)) != 0) ||
               (memcmp(&td_date_edit, &td_date_init, sizeof(td_date_init)) != 0);
}

static void time_date_btn_1_event_handler(lv_event_t *e)
{
    if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
        td_date_edit.Year = (td_date_edit.Year + 99) % 100; // 00-99
        uint8_t max_day = time_date_days_in_month(td_date_edit.Year, td_date_edit.Month);
        if (td_date_edit.Date > max_day) {
            td_date_edit.Date = max_day;
        }
        time_date_apply_and_refresh(lv_event_get_user_data(e));
    }
}

static void time_date_btn_2_event_handler(lv_event_t *e)
{
    if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
        td_date_edit.Year = (td_date_edit.Year + 1) % 100; // 00-99
        uint8_t max_day = time_date_days_in_month(td_date_edit.Year, td_date_edit.Month);
        if (td_date_edit.Date > max_day) {
            td_date_edit.Date = max_day;
        }
        time_date_apply_and_refresh(lv_event_get_user_data(e));
    }
}

static void time_date_btn_3_event_handler(lv_event_t *e)  // 月 +
{
    if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
        if (td_date_edit.Month < 12) {
            td_date_edit.Month++;
        } else {
            td_date_edit.Month = 1;
        }
        uint8_t max_day = time_date_days_in_month(td_date_edit.Year, td_date_edit.Month);
        if (td_date_edit.Date > max_day) {
            td_date_edit.Date = max_day;
        }
        time_date_apply_and_refresh(lv_event_get_user_data(e));
    }
}

static void time_date_btn_4_event_handler(lv_event_t *e)  // 月 -
{
    if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
        if (td_date_edit.Month > 1) {
            td_date_edit.Month--;
        } else {
            td_date_edit.Month = 12;
        }
        uint8_t max_day = time_date_days_in_month(td_date_edit.Year, td_date_edit.Month);
        if (td_date_edit.Date > max_day) {
            td_date_edit.Date = max_day;
        }
        time_date_apply_and_refresh(lv_event_get_user_data(e));
    }
}

static void time_date_btn_5_event_handler(lv_event_t *e)  // 日 +
{
    if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
        uint8_t max_day = time_date_days_in_month(td_date_edit.Year, td_date_edit.Month);
        if (td_date_edit.Date < max_day) {
            td_date_edit.Date++;
        } else {
            td_date_edit.Date = 1;
        }
        time_date_apply_and_refresh(lv_event_get_user_data(e));
    }
}

static void time_date_btn_6_event_handler(lv_event_t *e)  // 日 -
{
    if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
        uint8_t max_day = time_date_days_in_month(td_date_edit.Year, td_date_edit.Month);
        if (td_date_edit.Date > 1) {
            td_date_edit.Date--;
        } else {
            td_date_edit.Date = max_day;
        }
        time_date_apply_and_refresh(lv_event_get_user_data(e));
    }
}

static void time_date_btn_7_event_handler(lv_event_t *e)  // 时 +
{
    if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
        if (td_time_edit.Hours < 23) {
            td_time_edit.Hours++;
        } else {
            td_time_edit.Hours = 0;
        }
        time_date_apply_and_refresh(lv_event_get_user_data(e));
    }
}

static void time_date_btn_8_event_handler(lv_event_t *e)  // 时 -
{
    if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
        if (td_time_edit.Hours > 0) {
            td_time_edit.Hours--;
        } else {
            td_time_edit.Hours = 23;
        }
        time_date_apply_and_refresh(lv_event_get_user_data(e));
    }
}

static void time_date_btn_9_event_handler(lv_event_t *e)  // 分 +
{
    if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
        if (td_time_edit.Minutes < 59) {
            td_time_edit.Minutes++;
        } else {
            td_time_edit.Minutes = 0;
        }
        time_date_apply_and_refresh(lv_event_get_user_data(e));
    }
}

static void time_date_btn_10_event_handler(lv_event_t *e)  // 分 -
{
    if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
        if (td_time_edit.Minutes > 0) {
            td_time_edit.Minutes--;
        } else {
            td_time_edit.Minutes = 59;
        }
        time_date_apply_and_refresh(lv_event_get_user_data(e));
    }
}

static void time_date_btn_11_event_handler(lv_event_t *e)  // 秒 +
{
    if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
        if (td_time_edit.Seconds < 59) {
            td_time_edit.Seconds++;
        } else {
            td_time_edit.Seconds = 0;
        }
        time_date_apply_and_refresh(lv_event_get_user_data(e));
    }
}

static void time_date_btn_12_event_handler(lv_event_t *e)  // 秒 -
{
    if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
        if (td_time_edit.Seconds > 0) {
            td_time_edit.Seconds--;
        } else {
            td_time_edit.Seconds = 59;
        }
        time_date_apply_and_refresh(lv_event_get_user_data(e));
    }
}

static void time_date_msgbox_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *btnm = lv_event_get_target(e);
        uint16_t btn_id = lv_btnmatrix_get_selected_btn(btnm);
        const char *btn_txt = lv_btnmatrix_get_btn_text(btnm, btn_id);
        lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);

        if (btn_txt == NULL || ui == NULL) {
            return;
        }

        if (strcmp(btn_txt, "Apply") == 0) {
            HAL_RTC_SetTime(&hrtc, &td_time_edit, RTC_FORMAT_BIN);
            HAL_RTC_SetDate(&hrtc, &td_date_edit, RTC_FORMAT_BIN);

            ui_load_scr_animation(&guider_ui, &guider_ui.settings, guider_ui.settings_del,
                                  &guider_ui.time_date_del, setup_scr_settings,
                                  LV_SCR_LOAD_ANIM_OVER_RIGHT, 50, 10, true, true);
        } else if (strcmp(btn_txt, "Close") == 0) {
            td_time_edit = td_time_init;
            td_date_edit = td_date_init;
            td_dirty = false;
            time_date_apply_and_refresh(ui);

            ui_load_scr_animation(&guider_ui, &guider_ui.settings, guider_ui.settings_del,
                                  &guider_ui.time_date_del, setup_scr_settings,
                                  LV_SCR_LOAD_ANIM_OVER_RIGHT, 50, 10, true, true);
        }
    }
}

void events_init_time_date(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->time_date, time_date_screen_loaded_handler, LV_EVENT_SCREEN_LOADED, ui);
    lv_obj_add_event_cb(ui->time_date, time_date_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(lv_msgbox_get_btns(ui->time_date_msgbox_1), time_date_msgbox_event_handler, LV_EVENT_VALUE_CHANGED, ui);

    lv_obj_add_event_cb(ui->time_date_btn_1, time_date_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->time_date_btn_2, time_date_btn_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->time_date_btn_3, time_date_btn_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->time_date_btn_4, time_date_btn_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->time_date_btn_5, time_date_btn_5_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->time_date_btn_6, time_date_btn_6_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->time_date_btn_7, time_date_btn_7_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->time_date_btn_8, time_date_btn_8_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->time_date_btn_9, time_date_btn_9_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->time_date_btn_10, time_date_btn_10_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->time_date_btn_11, time_date_btn_11_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->time_date_btn_12, time_date_btn_12_event_handler, LV_EVENT_ALL, ui);

    // 页面加载时同步 RTC
    time_date_sync_from_rtc(ui);
}

void events_init(lv_ui *ui)
{

}
