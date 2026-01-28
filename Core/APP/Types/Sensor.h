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

typedef struct {
    uint8_t status;
    uint16_t heart;
}HeartMessage;

typedef enum {
    HR_CMD_STOP,
    HR_CMD_START
} hr_command_t;

typedef struct {
    bool WiFI_state;
    uint8_t Bluetooth_state;
    bool Light_value;
    bool wrist_state;
}CommonMessage;

// extern  uint16_t heart;
// extern uint16_t raw_ppg;
// extern uint32_t current_time;
// extern uint16_t heart_rate;
// extern uint32_t user_HR_timecount;
// extern float humidity, temperature;
// extern date_time time;
// extern RTC_DateTypeDef nowdate;
// extern RTC_TimeTypeDef nowtime;

#endif //OV_WATCH_01_SENSOR_H