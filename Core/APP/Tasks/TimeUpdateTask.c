#include <stdio.h>
// #include <time.h>
#include <time.h>

#include "string.h"
#include "cmsis_os2.h"
#include "rtc.h"
#include "FreeRTOS.h"
#include "gui_guider.h"



extern lv_ui guider_ui;
void refresh_current_time_on_scr1(void);

typedef struct {
    char time_str[10];
    char data_str[10];
    char week_str[10];
}time_update_data_t;

static void time_update_callback(void *data) {
    time_update_data_t *p_data = (time_update_data_t *)data;

    if (lv_scr_act() == guider_ui.scr1) {
        lv_label_set_text(guider_ui.scr1_label_4,p_data->time_str);
        lv_label_set_text(guider_ui.scr1_label_2,p_data->data_str);
        lv_label_set_text(guider_ui.scr1_label_3,p_data->week_str);
    }


    vPortFree(p_data);
}

void TimeUpdateTask(void *argument) {
    for (;;) {
        refresh_current_time_on_scr1();
        osDelay(60000);
    }
}

void refresh_current_time_on_scr1(void) {
    RTC_TimeTypeDef nowtime;
    RTC_DateTypeDef nowdate;

    HAL_RTC_GetTime(&hrtc, &nowtime, RTC_FORMAT_BIN);
    HAL_RTC_GetDate(&hrtc, &nowdate, RTC_FORMAT_BIN);

    time_update_data_t *p_data = (time_update_data_t *)pvPortMalloc(sizeof(time_update_data_t));
    if (p_data == NULL) {
        osDelay(60000);
        return;
    }
    memset(p_data,0,sizeof(time_update_data_t));
    snprintf(p_data->time_str,sizeof(p_data->time_str),"%02d:%02d",nowtime.Hours,nowtime.Minutes);
    snprintf(p_data->data_str,sizeof(p_data->data_str),"%02d-%02d",nowdate.Month,nowdate.Date);

    const char* weekdays[] ={"","Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    if (nowdate.WeekDay>=1 && nowdate.WeekDay<=7) {
        strncpy(p_data->week_str,weekdays[nowdate.WeekDay],sizeof(p_data->week_str)-1);
        p_data->week_str[sizeof(p_data->week_str)-1] = '\0';
    }
    else {
        strcpy(p_data->week_str,"Err");
    }

    lv_async_call(time_update_callback,p_data);
}



