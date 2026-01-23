#include "HrAlgorythm.h"
#include "string.h"

Queue datas;
Queue times;
Queue HR_List;

void HR_AlgoInit(void)
{
	initQueue(&datas);
	initQueue(&times);
	initQueue(&HR_List);
}

uint8_t Hr_Ave_Filter(uint32_t *HrList, uint8_t lenth)
{
	uint32_t ave;
	uint8_t i;
	for(i = 0;i<lenth;i++)
	{
		ave += HrList[i];
	}
	ave /= lenth;
}

uint16_t HR_Calculate(uint16_t present_dat,uint32_t present_time)
{

	static uint16_t peaks_time[]={0,0};
	static uint8_t HR=0;

	if(isQueueFull(&datas))
	{dequeue(&datas);}
	if(isQueueFull(&times))
	{dequeue(&times);}
	if(isQueueFull(&HR_List))
	{dequeue(&HR_List);}

	enqueue(&datas,present_dat);
	enqueue(&times,present_time);

	if((datas.data[3]>=datas.data[2]) && (datas.data[3]>=datas.data[1]) && (datas.data[3]>datas.data[0]) 
		&& (datas.data[3]>=datas.data[4]) && (datas.data[3]>=datas.data[5]) && (datas.data[3]>datas.data[6]))
	{
			if((times.data[3]-peaks_time[0])>425)
			{
					peaks_time[1] = peaks_time[0];
					peaks_time[0] = times.data[3];
					enqueue(&HR_List,60000/(peaks_time[0]-peaks_time[1]));
					if(HR_List.data[6]!=0)
					{HR = Hr_Ave_Filter(HR_List.data,7);}
			}
	}
	return HR;
}




// #define MIN_HR_BPM      40
// #define MAX_HR_BPM      180
// #define MIN_INTERVAL_MS (60000 / MAX_HR_BPM)  // ≈ 333ms
// #define MAX_INTERVAL_MS (60000 / MIN_HR_BPM)  // ≈ 1500ms

// static uint32_t last_peak_time = 0;
// static uint16_t baseline = 8000; // 初始基线（根据你的静息PPG调整）
// static uint16_t current_hr = 0;

// uint16_t Simple_HeartRate(uint16_t ppg, uint32_t timestamp_ms) {
// 	// 动态更新基线（滑动平均）
// 	baseline = (baseline * 9 + ppg) / 10;
//
// 	// 只有当 PPG 显著高于基线时才考虑峰值
// 	if (ppg > baseline + 5000) { // 阈值：比基线高 5000
//
// 		// 检查是否距离上次峰值足够远（防抖）
// 		if (last_peak_time == 0 ||
// 			(timestamp_ms - last_peak_time) >= MIN_INTERVAL_MS) {
//
// 			// 计算心率
// 			if (last_peak_time != 0) {
// 				uint32_t interval = timestamp_ms - last_peak_time;
// 				if (interval >= MIN_INTERVAL_MS && interval <= MAX_INTERVAL_MS) {
// 					current_hr = 60000 / interval;
// 				}
// 			}
// 			last_peak_time = timestamp_ms;
// 			}
// 	}
//
// 	return current_hr;
// }

uint16_t Simple_HeartRate(uint16_t ppg, uint32_t timestamp_ms, bool reset) {
#define MIN_HR_BPM 40
#define MAX_HR_BPM 180
#define MIN_INTERVAL_MS (60000 / MAX_HR_BPM) // 333ms
#define MAX_INTERVAL_MS (60000 / MIN_HR_BPM) // 1500ms

	static uint32_t last_peak_time = 0;
	static uint16_t ppg_history[5] = {0}; // 存储最近5个PPG值
	static uint8_t history_index = 0;
	static uint16_t current_hr = 0;

	if (reset) {
		last_peak_time = 0;
		memset(ppg_history, 0, sizeof(ppg_history));
		history_index = 0;
		current_hr = 0;
		return 0;
	}

	// 更新历史队列
	ppg_history[history_index] = ppg;
	history_index = (history_index + 1) % 5;

	// 至少需要5个点才能检测局部最大值
	if (ppg_history[0] == 0) return 0;

	// 检测中心点是否是局部最大值（索引2是中心）
	uint8_t center = (history_index + 2) % 5; // 当前最新点的前2个
	uint8_t prev1 = (center + 4) % 5;
	uint8_t prev2 = (center + 3) % 5;
	uint8_t next1 = (center + 1) % 5;
	uint8_t next2 = (center + 2) % 5;

	uint16_t center_val = ppg_history[center];

	// 局部最大值条件：比左右邻居都大，且显著高于基线
	if (center_val > 20000 &&
		center_val >= ppg_history[prev1] &&
		center_val >= ppg_history[prev2] &&
		center_val >= ppg_history[next1] &&
		center_val >= ppg_history[next2]) {

		// 防抖：距离上次峰值足够远
		if (last_peak_time == 0 || (timestamp_ms - last_peak_time) >= MIN_INTERVAL_MS) {
			if (last_peak_time != 0) {
				uint32_t interval = timestamp_ms - last_peak_time;
				if (interval >= MIN_INTERVAL_MS && interval <= MAX_INTERVAL_MS) {
					current_hr = 60000 / interval;
				}
			}
			last_peak_time = timestamp_ms;
		}
		}

	return current_hr;
}