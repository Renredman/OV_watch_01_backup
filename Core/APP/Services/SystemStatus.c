#include "Services/SystemStatus.h"

SystemStatus g_system_status = {0};

void SystemStatus_Init(void)
{
    uint32_t i;

    for (i = 0; i < OV_MODULE_COUNT; ++i) {
        g_system_status.modules[i] = OV_MODULE_STATUS_UNKNOWN;
    }

    g_system_status.heart_measurement_active = false;
    g_system_status.stop_resume_ok = true;
    g_system_status.last_bluetooth_rx_length = 0U;
}

void SystemStatus_SetModule(OvModuleId module, OvModuleStatus status)
{
    if (module >= OV_MODULE_COUNT) {
        return;
    }

    g_system_status.modules[module] = status;
}

OvModuleStatus SystemStatus_GetModule(OvModuleId module)
{
    if (module >= OV_MODULE_COUNT) {
        return OV_MODULE_STATUS_UNKNOWN;
    }

    return g_system_status.modules[module];
}

void SystemStatus_SetHeartMeasurement(bool active)
{
    g_system_status.heart_measurement_active = active;
}

void SystemStatus_SetStopResume(bool ok)
{
    g_system_status.stop_resume_ok = ok;
}

void SystemStatus_SetLastBluetoothRxLength(uint32_t length)
{
    g_system_status.last_bluetooth_rx_length = length;
}
