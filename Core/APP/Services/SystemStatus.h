#ifndef OV_SYSTEM_STATUS_H
#define OV_SYSTEM_STATUS_H

#include <stdbool.h>
#include <stdint.h>

typedef enum {
    OV_MODULE_RTC = 0,
    OV_MODULE_BLUETOOTH,
    OV_MODULE_LCD,
    OV_MODULE_LVGL,
    OV_MODULE_TOUCH,
    OV_MODULE_KEY,
    OV_MODULE_AHT21,
    OV_MODULE_LSM303,
    OV_MODULE_SPL06,
    OV_MODULE_EM7028,
    OV_MODULE_WDOG,
    OV_MODULE_COUNT
} OvModuleId;

typedef enum {
    OV_MODULE_STATUS_UNKNOWN = 0,
    OV_MODULE_STATUS_OK,
    OV_MODULE_STATUS_ERROR
} OvModuleStatus;

typedef struct {
    OvModuleStatus modules[OV_MODULE_COUNT];
    bool heart_measurement_active;
    bool stop_resume_ok;
    uint32_t last_bluetooth_rx_length;
} SystemStatus;

extern SystemStatus g_system_status;

void SystemStatus_Init(void);
void SystemStatus_SetModule(OvModuleId module, OvModuleStatus status);
OvModuleStatus SystemStatus_GetModule(OvModuleId module);
void SystemStatus_SetHeartMeasurement(bool active);
void SystemStatus_SetStopResume(bool ok);
void SystemStatus_SetLastBluetoothRxLength(uint32_t length);

#endif /* OV_SYSTEM_STATUS_H */
