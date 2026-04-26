#include <string.h>

#include "Services/PageRouter.h"

#include "Config/ov_project_config.h"
#include "Services/ProjectLog.h"
#include "Tasks/AppState.h"

static void PageRouter_ClearMessage(PageMessage *message)
{
    memset(message, 0, sizeof(*message));
}

bool PageRouter_BuildBackNavigation(lv_ui *ui, lv_obj_t *current_scr, PageMessage *message)
{
    if (ui == NULL || current_scr == NULL || message == NULL) {
        return false;
    }

    PageRouter_ClearMessage(message);

    if (current_scr == ui->scr1) {
        message->new_screen = &ui->menu2;
        message->new_scr_del = ui->menu2_del;
        message->old_scr_del = &ui->scr1_del;
        message->setup_cb = setup_scr_menu2;
        message->anim = LV_SCR_LOAD_ANIM_MOVE_RIGHT;
        return true;
    }

    if (current_scr == ui->menu2) {
        message->new_screen = &ui->scr1;
        message->new_scr_del = ui->scr1_del;
        message->old_scr_del = &ui->menu2_del;
        message->setup_cb = setup_scr_scr1;
        message->anim = LV_SCR_LOAD_ANIM_MOVE_LEFT;
        return true;
    }

    if (current_scr == ui->game_2048 || current_scr == ui->story || current_scr == ui->chat) {
        message->new_screen = &ui->game;
        message->new_scr_del = ui->game_del;
        message->setup_cb = setup_scr_game;
        message->anim = LV_SCR_LOAD_ANIM_MOVE_RIGHT;

        if (current_scr == ui->game_2048) {
            message->old_scr_del = &ui->game_2048_del;
        } else if (current_scr == ui->story) {
            message->old_scr_del = &ui->story_del;
        } else {
            message->old_scr_del = &ui->chat_del;
        }

        return true;
    }

    if (current_scr == ui->time_date || current_scr == ui->secret_change) {
        message->new_screen = &ui->settings;
        message->new_scr_del = ui->settings_del;
        message->setup_cb = setup_scr_settings;
        message->anim = LV_SCR_LOAD_ANIM_MOVE_RIGHT;

        if (current_scr == ui->time_date) {
            message->old_scr_del = &ui->time_date_del;
        } else {
            message->old_scr_del = &ui->secret_change_del;
        }

        return true;
    }

    if (current_scr == ui->secret) {
        message->new_screen = &ui->scr1;
        message->new_scr_del = ui->scr1_del;
        message->old_scr_del = &ui->secret_del;
        message->setup_cb = setup_scr_scr1;
        message->anim = LV_SCR_LOAD_ANIM_MOVE_LEFT;
        return true;
    }

    message->new_screen = &ui->menu2;
    message->new_scr_del = ui->menu2_del;
    message->setup_cb = setup_scr_menu2;
    message->anim = LV_SCR_LOAD_ANIM_OVER_RIGHT;

    if (current_scr == ui->calculator) {
        message->old_scr_del = &ui->calculator_del;
    } else if (current_scr == ui->calendar) {
        message->old_scr_del = &ui->calendar_del;
    } else if (current_scr == ui->card_bag) {
        message->old_scr_del = &ui->card_bag_del;
    } else if (current_scr == ui->second_chronograph) {
        message->old_scr_del = &ui->second_chronograph_del;
    } else if (current_scr == ui->environment) {
        message->old_scr_del = &ui->environment_del;
    } else if (current_scr == ui->heart) {
        message->old_scr_del = &ui->heart_del;
    } else if (current_scr == ui->compass) {
        message->old_scr_del = &ui->compass_del;
    } else if (current_scr == ui->game) {
        message->old_scr_del = &ui->game_del;
    } else if (current_scr == ui->settings) {
        message->old_scr_del = &ui->settings_del;
    } else if (current_scr == ui->about_watch) {
        message->old_scr_del = &ui->about_watch_del;
    }

    return true;
}

void PageRouter_Apply(lv_ui *ui, const PageMessage *message)
{
    lv_obj_t *current_scr;

    if (ui == NULL || message == NULL || message->new_screen == NULL || message->setup_cb == NULL) {
        OV_LOGW("page", "skip invalid navigation request");
        return;
    }

    current_scr = lv_scr_act();
    if (current_scr == ui->scr1 &&
        message->new_screen == &ui->menu2 &&
        g_app_state.password_set &&
        !g_app_state.password_verified) {
        ui_load_scr_animation(
            ui,
            &ui->secret,
            ui->secret_del,
            &ui->scr1_del,
            setup_scr_secret,
            message->anim,
            OV_PAGE_LOAD_TIME_MS,
            OV_PAGE_LOAD_DELAY_MS,
            true,
            true
        );
        return;
    }

    ui_load_scr_animation(
        ui,
        message->new_screen,
        message->new_scr_del,
        message->old_scr_del,
        message->setup_cb,
        message->anim,
        OV_PAGE_LOAD_TIME_MS,
        OV_PAGE_LOAD_DELAY_MS,
        true,
        true
    );
}
