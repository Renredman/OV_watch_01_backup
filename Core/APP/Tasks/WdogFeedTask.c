#include "cmsis_os2.h"
#include "FreeRTOS.h"
#include "stm32f4xx_hal.h"
#include "WDOG.h"

#include "Config/ov_project_config.h"
#include "Services/SystemStatus.h"

void WdogFeedTask(void *argument)
{
    (void)argument;

    WDOG_Port_Init();
    SystemStatus_SetModule(OV_MODULE_WDOG, OV_MODULE_STATUS_OK);

    for (;;) {
        WDOG_Feed();
        WDOG_Enable();
        osDelay(OV_WDOG_FEED_PERIOD_MS);
    }
}
