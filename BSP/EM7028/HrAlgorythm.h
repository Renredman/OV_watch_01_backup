#ifndef __HRALGORYTHM_H__
#define __HRALGORYTHM_H__

#include "main.h"
#include "user_Queue.h"

void HR_AlgoInit(void);
uint16_t HR_Calculate(uint16_t present_dat,uint32_t present_time);
// uint16_t Simple_HeartRate(uint16_t ppg, uint32_t timestamp_ms);
uint16_t Simple_HeartRate(uint16_t ppg, uint32_t timestamp_ms, bool reset);
#endif