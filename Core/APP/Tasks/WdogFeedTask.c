#include "cmsis_os2.h"
#include "FreeRTOS.h"
#include "stm32f4xx_hal.h"
#include "WDOG.h"

// uint8_t cnt=0;
void WdogFeedTask(void *argument) {
    WDOG_Port_Init();
    for (;;) {
        WDOG_Feed();
        WDOG_Enable();
        // cnt++;
        // if (cnt>=50) {
        //
        //     HAL_Delay(10000);
        // }

        osDelay(100);
    }
}
