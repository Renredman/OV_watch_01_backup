#include "cmsis_os2.h"
#include "main.h"
#include "FreeRTOS.h"
#include "gui_guider.h"

#include "Services/PageRouter.h"
#include "Services/ProjectLog.h"
#include "Types/PageType.h"

extern int key_state;
static osStatus_t queue_status;

static void page_command_callback(void *user_data)
{
    lv_ui *ui = &guider_ui;
    PageCommand *command = (PageCommand *)user_data;
    PageMessage route;
    lv_obj_t *current_scr;

    if (command == NULL) {
        return;
    }

    current_scr = lv_scr_act();
    if (command->type != PAGE_COMMAND_BACK) {
        OV_LOGW("page", "unknown page command: %d", (int)command->type);
        vPortFree(command);
        return;
    }

    if (!PageRouter_BuildBackNavigation(ui, current_scr, &route)) {
        OV_LOGW("page", "unable to resolve page route");
        vPortFree(command);
        return;
    }

    PageRouter_Apply(ui, &route);
    vPortFree(command);
}

void StartPageTask(void *argument)
{
    (void)argument;

    for (;;) {
        PageCommand command;

        queue_status = osMessageQueueGet(PageQueueHandle, &command, 0, osWaitForever);
        if (queue_status == osOK) {
            PageCommand *async_command = pvPortMalloc(sizeof(*async_command));
            if (async_command == NULL) {
                OV_LOGE("page", "failed to allocate async page command");
                continue;
            }

            *async_command = command;
            key_state += 5;
            lv_async_call(page_command_callback, async_command);
        }
    }
}
