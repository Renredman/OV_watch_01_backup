#include "cmsis_os2.h"
#include "FreeRTOS.h"
#include "WDOG.h"

void WdogFeedTask(void *argument) {
    WDOG_Port_Init();
    for (;;) {
        WDOG_Feed();
        WDOG_Enable();
        osDelay(100);
    }
}
