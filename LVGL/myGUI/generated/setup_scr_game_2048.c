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
//aaa
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "rtc.h"

// 自定义方向
#define MY_DIR_LEFT   1
#define MY_DIR_RIGHT  2
#define MY_DIR_UP     3
#define MY_DIR_DOWN   4

// 颜色函数
static lv_color_t get_tile_color(int value) {
    switch (value) {
    case 0:
        return lv_color_hex(0x003431);
    case 2:
        return lv_color_hex(0xeee4da);
    case 4:
        return lv_color_hex(0xede0c8);
    case 8:
        return lv_color_hex(0xf2b179);
    case 16:
        return lv_color_hex(0xf59563);
    case 32:
        return lv_color_hex(0xf67c5f);
    case 64:
        return lv_color_hex(0xf65e3b);
    case 128:
        return lv_color_hex(0xedcf72);
    case 256:
        return lv_color_hex(0xedcc61);
    case 512:
        return lv_color_hex(0xedc850);
    case 1024:
        return lv_color_hex(0xedc53f);
    case 2048:
        return lv_color_hex(0xedc22e);
    default:
        return lv_color_hex(0x3c3a32);
    }
}

// 全局变量
static int board[4][4] = {0};
static int current_score = 0;
static bool seeded = false;
static lv_obj_t* labels[16]; // 运行时初始化
static lv_obj_t* score_label = NULL;


// ========== 辅助函数（必须在函数外部！）==========

static void add_new_tile() {
    if (!seeded) {
        // srand((unsigned int)time(NULL));
        RTC_TimeTypeDef sTime = {0};
        RTC_DateTypeDef sDate = {0};
        HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
        HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
        uint32_t seed = (sDate.Date << 16) | (sTime.Seconds << 8) | sTime.Minutes;
        srand(seed);
        seeded = true;
    }

    int empty[16];
    int count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                empty[count++] = i * 4 + j;
            }
        }
    }
    if (count == 0) return;

    int pos = empty[rand() % count];
    board[pos / 4][pos % 4] = (rand() % 10 == 0) ? 4 : 2;
}

static void update_ui() {
    for (int i = 0; i < 16; i++) {
        int val = board[i / 4][i % 4];
        if (val == 0) {
            lv_label_set_text(labels[i], "");
        } else {
            lv_label_set_text_fmt(labels[i], "%d", val);
        }
        lv_obj_set_style_bg_color(labels[i], get_tile_color(val), LV_PART_MAIN | LV_STATE_DEFAULT);
    }

    lv_label_set_text_fmt(score_label, "Score:%d", current_score);
}

static int move_row_left(int row[4]) {
    int temp[4] = {0};
    int idx = 0;
    // 第一步：移除非零元素
    for (int i = 0; i < 4; i++) {
        if (row[i] != 0) temp[idx++] = row[i];
    }

    int score_gained = 0;
    // 第二步：从左到右合并
    for (int i = 0; i < 3; i++) {
        if (temp[i] != 0 && temp[i] == temp[i+1]) {
            temp[i] *= 2;
            score_gained += temp[i];  // 合并后的新值就是得分
            temp[i+1] = 0;
            i++; // 跳过下一个（已合并）
        }
    }

    // 第三步：再次压缩非零元素
    idx = 0;
    for (int i = 0; i < 4; i++) {
        if (temp[i] != 0) row[idx++] = temp[i];
    }
    while (idx < 4) row[idx++] = 0;

    return score_gained;
}

static bool move_board(int dir) {
    int temp[4];
    bool moved = false;

    switch (dir) {
    case MY_DIR_LEFT:
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) temp[j] = board[i][j];
            int score = move_row_left(temp);
            if (score > 0 || memcmp(temp, &board[i][0], sizeof(temp)) != 0) {
                for (int j = 0; j < 4; j++) board[i][j] = temp[j];
                current_score += score;
                moved = true;
            }
        }
        break;
    case MY_DIR_RIGHT:
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) temp[j] = board[i][3-j];
            int score = move_row_left(temp);
            if (score > 0 || memcmp(temp, (int[]) {
            board[i][3], board[i][2], board[i][1], board[i][0]
            }, sizeof(temp)) != 0) {
                for (int j = 0; j < 4; j++) board[i][3-j] = temp[j];
                current_score += score;
                moved = true;
            }
        }
        break;
    case MY_DIR_UP:
        for (int j = 0; j < 4; j++) {
            for (int i = 0; i < 4; i++) temp[i] = board[i][j];
            int score = move_row_left(temp);
            if (score > 0 || memcmp(temp, (int[]) {
            board[0][j], board[1][j], board[2][j], board[3][j]
            }, sizeof(temp)) != 0) {
                for (int i = 0; i < 4; i++) board[i][j] = temp[i];
                current_score += score;
                moved = true;
            }
        }
        break;
    case MY_DIR_DOWN:
        for (int j = 0; j < 4; j++) {
            for (int i = 0; i < 4; i++) temp[i] = board[3-i][j];
            int score = move_row_left(temp);
            if (score > 0 || memcmp(temp, (int[]) {
            board[3][j], board[2][j], board[1][j], board[0][j]
            }, sizeof(temp)) != 0) {
                for (int i = 0; i < 4; i++) board[3-i][j] = temp[i];
                current_score += score;
                moved = true;
            }
        }
        break;
    }
    return moved;
}

static bool can_move() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) return true;
            if (j < 3 && board[i][j] == board[i][j+1]) return true;
            if (i < 3 && board[i][j] == board[i+1][j]) return true;
        }
    return false;
}

static void reset_game() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            board[i][j] = 0;
    current_score = 0;
    add_new_tile();
    add_new_tile();
    update_ui();
}

// 手势事件处理函数
static void game_2048_gesture_handler(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    if (code != LV_EVENT_GESTURE) return;

    lv_dir_t dir_val = lv_indev_get_gesture_dir(lv_indev_get_act());
    bool moved = false;

    if (dir_val == 1)      moved = move_board(MY_DIR_LEFT);   // LV_DIR_LEFT
    else if (dir_val == 2) moved = move_board(MY_DIR_RIGHT);  // LV_DIR_RIGHT
    else if (dir_val == 4) moved = move_board(MY_DIR_UP);     // LV_DIR_TOP
    else if (dir_val == 8) moved = move_board(MY_DIR_DOWN);   // LV_DIR_BOTTOM
    else return;

    if (moved) {
        add_new_tile();
        update_ui();

        if (!can_move()) {
            lv_obj_t* msg = lv_label_create(lv_event_get_target(e));
            lv_label_set_text(msg, "Game Over!");
            lv_obj_align(msg, LV_ALIGN_CENTER, 0, 0);
        }
    }
}

// 按钮事件：短按重玩，长按返回
static void game_2048_btn_handler(lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_SHORT_CLICKED) {
        reset_game();
    } else if (code == LV_EVENT_LONG_PRESSED) {
        ui_load_scr_animation(&guider_ui, &guider_ui.game, guider_ui.game_del, &guider_ui.game_2048_del, setup_scr_game, LV_SCR_LOAD_ANIM_NONE, 200, 0, true, true);
    }
}



void setup_scr_game_2048(lv_ui *ui)
{
    //Write codes game_2048
    ui->game_2048 = lv_obj_create(NULL);
    lv_obj_set_size(ui->game_2048, 240, 320);
    lv_obj_set_scrollbar_mode(ui->game_2048, LV_SCROLLBAR_MODE_OFF);

    //Write style for game_2048, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->game_2048, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->game_2048, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->game_2048, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes game_2048_btn_1
    ui->game_2048_btn_1 = lv_btn_create(ui->game_2048);
    ui->game_2048_btn_1_label = lv_label_create(ui->game_2048_btn_1);
    lv_label_set_text(ui->game_2048_btn_1_label, "重玩");
    lv_label_set_long_mode(ui->game_2048_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->game_2048_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->game_2048_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->game_2048_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->game_2048_btn_1, 0, 0);
    lv_obj_set_size(ui->game_2048_btn_1, 85, 35);

    //Write style for game_2048_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->game_2048_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->game_2048_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->game_2048_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->game_2048_btn_1, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->game_2048_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->game_2048_btn_1, lv_color_hex(0x2990e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->game_2048_btn_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->game_2048_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->game_2048_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->game_2048_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->game_2048_btn_1, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->game_2048_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->game_2048_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes game_2048_label_score
    ui->game_2048_label_score = lv_label_create(ui->game_2048);
    lv_label_set_text(ui->game_2048_label_score, "Score:");
    lv_label_set_long_mode(ui->game_2048_label_score, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->game_2048_label_score, 128, 15);
    lv_obj_set_size(ui->game_2048_label_score, 100, 32);

    //Write style for game_2048_label_score, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->game_2048_label_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->game_2048_label_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->game_2048_label_score, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->game_2048_label_score, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->game_2048_label_score, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->game_2048_label_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->game_2048_label_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->game_2048_label_score, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->game_2048_label_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->game_2048_label_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->game_2048_label_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->game_2048_label_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->game_2048_label_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->game_2048_label_score, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes game_2048_label_1
    ui->game_2048_label_1 = lv_label_create(ui->game_2048);
    lv_label_set_text(ui->game_2048_label_1, "2048");
    lv_label_set_long_mode(ui->game_2048_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->game_2048_label_1, 12, 50);
    lv_obj_set_size(ui->game_2048_label_1, 45, 45);

    //Write style for game_2048_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->game_2048_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->game_2048_label_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->game_2048_label_1, lv_color_hex(0x30ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->game_2048_label_1, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->game_2048_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->game_2048_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->game_2048_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->game_2048_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->game_2048_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->game_2048_label_1, lv_color_hex(0x003431), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->game_2048_label_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->game_2048_label_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->game_2048_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->game_2048_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->game_2048_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->game_2048_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes game_2048_label_2
    ui->game_2048_label_2 = lv_label_create(ui->game_2048);
    lv_label_set_text(ui->game_2048_label_2, "Label");
    lv_label_set_long_mode(ui->game_2048_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->game_2048_label_2, 70, 50);
    lv_obj_set_size(ui->game_2048_label_2, 45, 45);

    //Write style for game_2048_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->game_2048_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->game_2048_label_2, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->game_2048_label_2, lv_color_hex(0x30ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->game_2048_label_2, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->game_2048_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->game_2048_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->game_2048_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->game_2048_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->game_2048_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->game_2048_label_2, lv_color_hex(0x003431), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->game_2048_label_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->game_2048_label_2, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->game_2048_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->game_2048_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->game_2048_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->game_2048_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes game_2048_label_3
    ui->game_2048_label_3 = lv_label_create(ui->game_2048);
    lv_label_set_text(ui->game_2048_label_3, "0");
    lv_label_set_long_mode(ui->game_2048_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->game_2048_label_3, 128, 50);
    lv_obj_set_size(ui->game_2048_label_3, 45, 45);

    //Write style for game_2048_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->game_2048_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->game_2048_label_3, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->game_2048_label_3, lv_color_hex(0x30ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->game_2048_label_3, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->game_2048_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->game_2048_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->game_2048_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->game_2048_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->game_2048_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->game_2048_label_3, lv_color_hex(0x003431), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->game_2048_label_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->game_2048_label_3, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->game_2048_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->game_2048_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->game_2048_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->game_2048_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes game_2048_label_4
    ui->game_2048_label_4 = lv_label_create(ui->game_2048);
    lv_label_set_text(ui->game_2048_label_4, "Label");
    lv_label_set_long_mode(ui->game_2048_label_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->game_2048_label_4, 184, 50);
    lv_obj_set_size(ui->game_2048_label_4, 45, 45);

    //Write style for game_2048_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->game_2048_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->game_2048_label_4, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->game_2048_label_4, lv_color_hex(0x30ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->game_2048_label_4, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->game_2048_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->game_2048_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->game_2048_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->game_2048_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->game_2048_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->game_2048_label_4, lv_color_hex(0x003431), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->game_2048_label_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->game_2048_label_4, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->game_2048_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->game_2048_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->game_2048_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->game_2048_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes game_2048_label_5
    ui->game_2048_label_5 = lv_label_create(ui->game_2048);
    lv_label_set_text(ui->game_2048_label_5, "Label");
    lv_label_set_long_mode(ui->game_2048_label_5, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->game_2048_label_5, 12, 108);
    lv_obj_set_size(ui->game_2048_label_5, 45, 45);

    //Write style for game_2048_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->game_2048_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->game_2048_label_5, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->game_2048_label_5, lv_color_hex(0x30ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->game_2048_label_5, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->game_2048_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->game_2048_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->game_2048_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->game_2048_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->game_2048_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->game_2048_label_5, lv_color_hex(0x003431), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->game_2048_label_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->game_2048_label_5, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->game_2048_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->game_2048_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->game_2048_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->game_2048_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes game_2048_label_6
    ui->game_2048_label_6 = lv_label_create(ui->game_2048);
    lv_label_set_text(ui->game_2048_label_6, "Label");
    lv_label_set_long_mode(ui->game_2048_label_6, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->game_2048_label_6, 70, 108);
    lv_obj_set_size(ui->game_2048_label_6, 45, 45);

    //Write style for game_2048_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->game_2048_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->game_2048_label_6, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->game_2048_label_6, lv_color_hex(0x30ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->game_2048_label_6, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->game_2048_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->game_2048_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->game_2048_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->game_2048_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->game_2048_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->game_2048_label_6, lv_color_hex(0x003431), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->game_2048_label_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->game_2048_label_6, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->game_2048_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->game_2048_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->game_2048_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->game_2048_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes game_2048_label_7
    ui->game_2048_label_7 = lv_label_create(ui->game_2048);
    lv_label_set_text(ui->game_2048_label_7, "Label");
    lv_label_set_long_mode(ui->game_2048_label_7, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->game_2048_label_7, 128, 108);
    lv_obj_set_size(ui->game_2048_label_7, 45, 45);

    //Write style for game_2048_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->game_2048_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->game_2048_label_7, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->game_2048_label_7, lv_color_hex(0x30ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->game_2048_label_7, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->game_2048_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->game_2048_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->game_2048_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->game_2048_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->game_2048_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->game_2048_label_7, lv_color_hex(0x003431), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->game_2048_label_7, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->game_2048_label_7, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->game_2048_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->game_2048_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->game_2048_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->game_2048_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes game_2048_label_8
    ui->game_2048_label_8 = lv_label_create(ui->game_2048);
    lv_label_set_text(ui->game_2048_label_8, "Label");
    lv_label_set_long_mode(ui->game_2048_label_8, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->game_2048_label_8, 184, 108);
    lv_obj_set_size(ui->game_2048_label_8, 45, 45);

    //Write style for game_2048_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->game_2048_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->game_2048_label_8, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->game_2048_label_8, lv_color_hex(0x30ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->game_2048_label_8, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->game_2048_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->game_2048_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->game_2048_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->game_2048_label_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->game_2048_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->game_2048_label_8, lv_color_hex(0x003431), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->game_2048_label_8, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->game_2048_label_8, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->game_2048_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->game_2048_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->game_2048_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->game_2048_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes game_2048_label_9
    ui->game_2048_label_9 = lv_label_create(ui->game_2048);
    lv_label_set_text(ui->game_2048_label_9, "Label");
    lv_label_set_long_mode(ui->game_2048_label_9, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->game_2048_label_9, 12, 166);
    lv_obj_set_size(ui->game_2048_label_9, 45, 45);

    //Write style for game_2048_label_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->game_2048_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->game_2048_label_9, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->game_2048_label_9, lv_color_hex(0x30ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->game_2048_label_9, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->game_2048_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->game_2048_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->game_2048_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->game_2048_label_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->game_2048_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->game_2048_label_9, lv_color_hex(0x003431), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->game_2048_label_9, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->game_2048_label_9, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->game_2048_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->game_2048_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->game_2048_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->game_2048_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes game_2048_label_10
    ui->game_2048_label_10 = lv_label_create(ui->game_2048);
    lv_label_set_text(ui->game_2048_label_10, "Label");
    lv_label_set_long_mode(ui->game_2048_label_10, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->game_2048_label_10, 70, 166);
    lv_obj_set_size(ui->game_2048_label_10, 45, 45);

    //Write style for game_2048_label_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->game_2048_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->game_2048_label_10, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->game_2048_label_10, lv_color_hex(0x30ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->game_2048_label_10, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->game_2048_label_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->game_2048_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->game_2048_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->game_2048_label_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->game_2048_label_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->game_2048_label_10, lv_color_hex(0x003431), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->game_2048_label_10, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->game_2048_label_10, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->game_2048_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->game_2048_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->game_2048_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->game_2048_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes game_2048_label_11
    ui->game_2048_label_11 = lv_label_create(ui->game_2048);
    lv_label_set_text(ui->game_2048_label_11, "Label");
    lv_label_set_long_mode(ui->game_2048_label_11, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->game_2048_label_11, 128, 166);
    lv_obj_set_size(ui->game_2048_label_11, 45, 45);

    //Write style for game_2048_label_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->game_2048_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->game_2048_label_11, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->game_2048_label_11, lv_color_hex(0x30ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->game_2048_label_11, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->game_2048_label_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->game_2048_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->game_2048_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->game_2048_label_11, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->game_2048_label_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->game_2048_label_11, lv_color_hex(0x003431), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->game_2048_label_11, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->game_2048_label_11, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->game_2048_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->game_2048_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->game_2048_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->game_2048_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes game_2048_label_12
    ui->game_2048_label_12 = lv_label_create(ui->game_2048);
    lv_label_set_text(ui->game_2048_label_12, "Label");
    lv_label_set_long_mode(ui->game_2048_label_12, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->game_2048_label_12, 184, 166);
    lv_obj_set_size(ui->game_2048_label_12, 45, 45);

    //Write style for game_2048_label_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->game_2048_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->game_2048_label_12, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->game_2048_label_12, lv_color_hex(0x30ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->game_2048_label_12, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->game_2048_label_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->game_2048_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->game_2048_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->game_2048_label_12, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->game_2048_label_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->game_2048_label_12, lv_color_hex(0x003431), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->game_2048_label_12, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->game_2048_label_12, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->game_2048_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->game_2048_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->game_2048_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->game_2048_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes game_2048_label_13
    ui->game_2048_label_13 = lv_label_create(ui->game_2048);
    lv_label_set_text(ui->game_2048_label_13, "Label");
    lv_label_set_long_mode(ui->game_2048_label_13, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->game_2048_label_13, 12, 224);
    lv_obj_set_size(ui->game_2048_label_13, 45, 45);

    //Write style for game_2048_label_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->game_2048_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->game_2048_label_13, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->game_2048_label_13, lv_color_hex(0x30ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->game_2048_label_13, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->game_2048_label_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->game_2048_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->game_2048_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->game_2048_label_13, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->game_2048_label_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->game_2048_label_13, lv_color_hex(0x003431), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->game_2048_label_13, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->game_2048_label_13, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->game_2048_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->game_2048_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->game_2048_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->game_2048_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes game_2048_label_14
    ui->game_2048_label_14 = lv_label_create(ui->game_2048);
    lv_label_set_text(ui->game_2048_label_14, "Label");
    lv_label_set_long_mode(ui->game_2048_label_14, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->game_2048_label_14, 70, 224);
    lv_obj_set_size(ui->game_2048_label_14, 45, 45);

    //Write style for game_2048_label_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->game_2048_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->game_2048_label_14, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->game_2048_label_14, lv_color_hex(0x30ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->game_2048_label_14, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->game_2048_label_14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->game_2048_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->game_2048_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->game_2048_label_14, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->game_2048_label_14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->game_2048_label_14, lv_color_hex(0x003431), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->game_2048_label_14, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->game_2048_label_14, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->game_2048_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->game_2048_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->game_2048_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->game_2048_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes game_2048_label_15
    ui->game_2048_label_15 = lv_label_create(ui->game_2048);
    lv_label_set_text(ui->game_2048_label_15, "Label");
    lv_label_set_long_mode(ui->game_2048_label_15, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->game_2048_label_15, 128, 224);
    lv_obj_set_size(ui->game_2048_label_15, 45, 45);

    //Write style for game_2048_label_15, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->game_2048_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->game_2048_label_15, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->game_2048_label_15, lv_color_hex(0x30ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->game_2048_label_15, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->game_2048_label_15, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->game_2048_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->game_2048_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->game_2048_label_15, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->game_2048_label_15, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->game_2048_label_15, lv_color_hex(0x003431), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->game_2048_label_15, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->game_2048_label_15, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->game_2048_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->game_2048_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->game_2048_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->game_2048_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes game_2048_label_16
    ui->game_2048_label_16 = lv_label_create(ui->game_2048);
    lv_label_set_text(ui->game_2048_label_16, "Label");
    lv_label_set_long_mode(ui->game_2048_label_16, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->game_2048_label_16, 184, 224);
    lv_obj_set_size(ui->game_2048_label_16, 45, 45);

    //Write style for game_2048_label_16, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->game_2048_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->game_2048_label_16, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->game_2048_label_16, lv_color_hex(0x30ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->game_2048_label_16, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->game_2048_label_16, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->game_2048_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->game_2048_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->game_2048_label_16, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->game_2048_label_16, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->game_2048_label_16, lv_color_hex(0x003431), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->game_2048_label_16, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->game_2048_label_16, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->game_2048_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->game_2048_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->game_2048_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->game_2048_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of game_2048.
    lv_obj_clear_flag(ui->game_2048_label_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->game_2048_label_2, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->game_2048_label_3, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->game_2048_label_4, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->game_2048_label_5, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->game_2048_label_6, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->game_2048_label_7, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->game_2048_label_8, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->game_2048_label_9, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->game_2048_label_10, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->game_2048_label_11, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->game_2048_label_12, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->game_2048_label_13, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->game_2048_label_14, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->game_2048_label_15, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui->game_2048_label_16, LV_OBJ_FLAG_CLICKABLE);

//The custom code of game_2048.

// 初始化 labels 数组
    labels[0] = ui->game_2048_label_1;
    labels[1] = ui->game_2048_label_2;
    labels[2] = ui->game_2048_label_3;
    labels[3] = ui->game_2048_label_4;
    labels[4] = ui->game_2048_label_5;
    labels[5] = ui->game_2048_label_6;
    labels[6] = ui->game_2048_label_7;
    labels[7] = ui->game_2048_label_8;
    labels[8] = ui->game_2048_label_9;
    labels[9] = ui->game_2048_label_10;
    labels[10] = ui->game_2048_label_11;
    labels[11] = ui->game_2048_label_12;
    labels[12] = ui->game_2048_label_13;
    labels[13] = ui->game_2048_label_14;
    labels[14] = ui->game_2048_label_15;
    labels[15] = ui->game_2048_label_16;

    score_label = ui->game_2048_label_score;
// 绑定事件（只绑 LV_EVENT_GESTURE）
    lv_obj_add_event_cb(ui->game_2048, game_2048_gesture_handler, LV_EVENT_GESTURE, NULL);
// 绑定按钮
    lv_obj_add_event_cb(ui->game_2048_btn_1, game_2048_btn_handler, LV_EVENT_SHORT_CLICKED, NULL);
    lv_obj_add_event_cb(ui->game_2048_btn_1, game_2048_btn_handler, LV_EVENT_LONG_PRESSED, NULL);

// 启动游戏
    reset_game();

    //Update current screen layout.
    lv_obj_update_layout(ui->game_2048);

    //Init events for screen.
    events_init_game_2048(ui);
}
