#include "cmsis_os2.h"
#include "key.h"
#include "FreeRTOS.h"

#include "Config/ov_project_config.h"
#include "Services/ProjectLog.h"
#include "Types/PageType.h"
#include "main.h"

int key_state = 0;

void StartKeyTask(void *argument)
{
    (void)argument;

    for (;;) {
        if (Key1_Scan() == 1) {
            uint8_t break_msg = 0;
            PageCommand command = {
                .type = PAGE_COMMAND_BACK
            };

            osMessageQueuePut(IdleBreak_MessageQueueHandle, &break_msg, 0, osPriorityRealtime);
            if (osMessageQueuePut(PageQueueHandle, &command, 0, 0) != osOK) {
                OV_LOGW("page", "drop page command from key task");
            }
        }

        osDelay(OV_KEY_SCAN_PERIOD_MS);
    }
}
