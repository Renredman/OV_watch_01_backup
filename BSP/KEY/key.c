#include "key.h"
#include "delay.h"
// #include "user_TasksInit.h"
#include <stdio.h>

#include "cmsis_os.h"
#include "gui_guider.h"


void Key_Port_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin : PA5 */
  GPIO_InitStruct.Pin = KEY1_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(KEY1_PORT, &GPIO_InitStruct);

	/*Configure GPIO pin : PA4 */
  GPIO_InitStruct.Pin = GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	
  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

  HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI4_IRQn);
}

uint8_t KeyScan(uint8_t mode)
{
	static uint8_t key_up = 1;
	uint8_t keyvalue=0;
	if(mode) key_up = 1;
	if( key_up && ((!KEY1) || KEY2))
	{
		//delay_ms(3);//ensure the key is down
		osDelay(3);
		if(!KEY1) keyvalue = 1;
		else if(KEY2) keyvalue = 2;
		if(keyvalue) key_up = 0;
	}
	else
	{
		//delay_ms(3);//ensure the key is up
		osDelay(3);
		if(KEY1 && (!KEY2))
			key_up = 1;
	}
	return keyvalue;
}

// 只处理 KEY1（低电平有效）
uint8_t Key1_Scan(void)
{
	static uint8_t key1_state = 0; // 0: released, 1: pressed
	static uint32_t last_debounce_time = 0;
	const uint32_t DEBOUNCE_DELAY_MS = 20;

	uint32_t now = osKernelGetTickCount(); // 获取系统 tick（单位：ms）

	if (!KEY1) { // 按下（低电平）
		if (key1_state == 0) { // 之前是释放状态
			if ((now - last_debounce_time) >= DEBOUNCE_DELAY_MS) {
				key1_state = 1; // 标记为已按下
				last_debounce_time = now;
				return 1; // 返回“有效按下”
			}
		}
	} else { // 释放（高电平）
		key1_state = 0;
	}

	return 0; // 无有效事件
}

typedef enum {
	KEY_IDLE,
	KEY_DEBOUNCE,
	KEY_PRESSED,
	KEY_LONG_PRESS
}KeyState;

#define DEBOUNCE_TIME_MS	20
#define LONG_PRESS_TIME_MS	1000

static  KeyState key1_state = KEY_IDLE;
static  uint32_t key1_press_start_time = 0;
// 返回值：
// 0 = 无事件
// 1 = 短按
// 2 = 长按开始（可选）
// 3 = 长按持续（可选，一般不需要）

uint8_t Key1_Scan_With_Long_Press(void) {
	uint32_t now = osKernelGetTickCount();

	switch(key1_state) {
		case KEY_IDLE:
			if (!KEY1) {
				key1_state = KEY_DEBOUNCE;
				key1_press_start_time = now;
			}
			break;

			case KEY_DEBOUNCE:
			if (!KEY1) {
				if ((now-key1_press_start_time) > DEBOUNCE_TIME_MS) {
					key1_state = KEY_PRESSED;
					key1_press_start_time = now;
					return 1;
				}
			}
			else {
				key1_state = KEY_IDLE;
			}
			break;

			case KEY_PRESSED:
			if (!KEY1) {
				if ((now-key1_press_start_time) > LONG_PRESS_TIME_MS) {
					key1_state = KEY_LONG_PRESS;
					return 2;
				}
			}
			else {
				key1_state = KEY_IDLE;
			}

		case KEY_LONG_PRESS:
			if (!KEY1) {
				//持续返回长按
				//return 3;
			}
			else {
				key1_state = KEY_IDLE;
			}
	}
	return 0;
}





