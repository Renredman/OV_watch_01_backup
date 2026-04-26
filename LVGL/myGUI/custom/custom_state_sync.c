#include "custom.h"

#include "Tasks/AppState.h"
#include "Tasks/TimeUpdateTask.h"

void scr1_screen_loaded_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_SCREEN_LOADED) {
        lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
        refresh_current_time_on_scr1();

        if (ui != NULL) {
            AppState_SyncToScr1(ui);
        }
    }
}

void setting_screen_loaded_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_SCREEN_LOADED) {
        lv_ui *ui = (lv_ui *)lv_event_get_user_data(e);
        if (ui != NULL) {
            AppState_SyncToSettings(ui);
        }
    }
}
