#ifndef OV_WATCH_01_PAGETYPE_H
#define OV_WATCH_01_PAGETYPE_H

#include "gui_guider.h"

typedef struct {
    lv_obj_t **new_screen;
    bool new_scr_del;
    bool *old_scr_del;
    ui_setup_scr_t setup_cb;
    lv_scr_load_anim_t anim;
} PageMessage;

typedef enum {
    PAGE_COMMAND_BACK = 0
} PageCommandType;

typedef struct {
    PageCommandType type;
} PageCommand;

typedef enum {
    scr1_index = 0,
    menu2_index = 1,
    calculator_index = 2,
    card_bag_index = 2,
    calendar_index = 2,
    environment_index = 2,
    second_chronograph_index = 2
} Interface_index;

typedef enum {
    TARGET_SCR1,
    TARGET_MENU2
} TargetScreen;

#endif //OV_WATCH_01_PAGETYPE_H
