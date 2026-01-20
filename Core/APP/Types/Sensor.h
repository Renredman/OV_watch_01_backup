//
// Created by 侯力楷 on 2025/12/31.
//

#ifndef OV_WATCH_01_SENSOR_H
#define OV_WATCH_01_SENSOR_H

#include "rtc.h"
#include "gui_guider.h"

typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t data;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
}date_time;

typedef struct {
    float humidity;
    float temperature;
}EnvirMessage;

extern float humidity, temperature;
// extern date_time time;
extern RTC_DateTypeDef nowdate;
extern RTC_TimeTypeDef nowtime;

#endif //OV_WATCH_01_SENSOR_H