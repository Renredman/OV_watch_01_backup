#include "custom.h"

#include "Tasks/SensorDataTask.h"

void environment_screen_loaded_cb(lv_event_t *e)
{
    (void)e;
    trigger_immediate_envir_update();
}
