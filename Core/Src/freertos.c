/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "delay.h"
#include "lcd.h"
#include "lcd_init.h"
#include "CST816.h"
#include "iic_hal.h"
#include "key.h"

#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "gui_guider.h"           // Gui Guider 生成的界面和控件的声明
#include "events_init.h"          // Gui Guider 生成的初始化事件、回调函数
#include "custom.h"
#include "Tasks//SensorDataTask.h"
#include "Tasks/user_PowerManager.h"
#include "Types/PageType.h"
#include "Types/Sensor.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
extern lv_ui  guider_ui;                     // 声明 界面对象
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for LvglTask */
osThreadId_t LvglTaskHandle;
const osThreadAttr_t LvglTask_attributes = {
  .name = "LvglTask",
  .stack_size = 512 * 4,
  .priority = (osPriority_t) osPriorityLow1,
};
/* Definitions for myKeyTask */
osThreadId_t myKeyTaskHandle;
const osThreadAttr_t myKeyTask_attributes = {
  .name = "myKeyTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for myPageTask */
osThreadId_t myPageTaskHandle;
const osThreadAttr_t myPageTask_attributes = {
  .name = "myPageTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow7,
};
/* Definitions for myFeedTask */
osThreadId_t myFeedTaskHandle;
const osThreadAttr_t myFeedTask_attributes = {
  .name = "myFeedTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityHigh,
};
/* Definitions for SensorDataTask */
osThreadId_t SensorDataTaskHandle;
const osThreadAttr_t SensorDataTask_attributes = {
  .name = "SensorDataTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow3,
};
/* Definitions for DataUpdateTask */
osThreadId_t DataUpdateTaskHandle;
const osThreadAttr_t DataUpdateTask_attributes = {
  .name = "DataUpdateTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow3,
};
/* Definitions for myTimeTask */
osThreadId_t myTimeTaskHandle;
const osThreadAttr_t myTimeTask_attributes = {
  .name = "myTimeTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow3,
};
/* Definitions for HeartDataTask */
osThreadId_t HeartDataTaskHandle;
const osThreadAttr_t HeartDataTask_attributes = {
  .name = "HeartDataTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow3,
};
/* Definitions for BluetoothTxtask */
osThreadId_t BluetoothTxtaskHandle;
const osThreadAttr_t BluetoothTxtask_attributes = {
  .name = "BluetoothTxtask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow3,
};
/* Definitions for BluetoothRxtask */
osThreadId_t BluetoothRxtaskHandle;
const osThreadAttr_t BluetoothRxtask_attributes = {
  .name = "BluetoothRxtask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow1,
};
/* Definitions for PageQueue */
osMessageQueueId_t PageQueueHandle;
const osMessageQueueAttr_t PageQueue_attributes = {
  .name = "PageQueue"
};
/* Definitions for EnvirQueue */
osMessageQueueId_t EnvirQueueHandle;
const osMessageQueueAttr_t EnvirQueue_attributes = {
  .name = "EnvirQueue"
};
/* Definitions for HeartQueue */
osMessageQueueId_t HeartQueueHandle;
const osMessageQueueAttr_t HeartQueue_attributes = {
  .name = "HeartQueue"
};
/* Definitions for HrCmdQueue */
osMessageQueueId_t HrCmdQueueHandle;
const osMessageQueueAttr_t HrCmdQueue_attributes = {
  .name = "HrCmdQueue"
};
/* Definitions for CommonQueue */
osMessageQueueId_t CommonQueueHandle;
const osMessageQueueAttr_t CommonQueue_attributes = {
  .name = "CommonQueue"
};
/* Definitions for Idle_MessageQueue */
osMessageQueueId_t Idle_MessageQueueHandle;
const osMessageQueueAttr_t Idle_MessageQueue_attributes = {
  .name = "Idle_MessageQueue"
};
/* Definitions for IdleBreak_MessageQueue */
osMessageQueueId_t IdleBreak_MessageQueueHandle;
const osMessageQueueAttr_t IdleBreak_MessageQueue_attributes = {
  .name = "IdleBreak_MessageQueue"
};
/* Definitions for Stop_MessageQueue */
osMessageQueueId_t Stop_MessageQueueHandle;
const osMessageQueueAttr_t Stop_MessageQueue_attributes = {
  .name = "Stop_MessageQueue"
};
/* Definitions for BluetoothTxQueue */
osMessageQueueId_t BluetoothTxQueueHandle;
const osMessageQueueAttr_t BluetoothTxQueue_attributes = {
  .name = "BluetoothTxQueue"
};
/* Definitions for BluetoothRxQueue */
osMessageQueueId_t BluetoothRxQueueHandle;
const osMessageQueueAttr_t BluetoothRxQueue_attributes = {
  .name = "BluetoothRxQueue"
};
/* Definitions for Idle_Timer */
osTimerId_t Idle_TimerHandle;
const osTimerAttr_t Idle_Timer_attributes = {
  .name = "Idle_Timer"
};
/* Definitions for EnvRefreshReqSem */
osSemaphoreId_t EnvRefreshReqSemHandle;
const osSemaphoreAttr_t EnvRefreshReqSem_attributes = {
  .name = "EnvRefreshReqSem"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartLvglTask(void *argument);
extern void StartKeyTask(void *argument);
extern void StartPageTask(void *argument);
extern void WdogFeedTask(void *argument);
extern void SensorDataRenewTask(void *argument);
extern void SensorDataUpdateTask(void *argument);
extern void TimeUpdateTask(void *argument);
extern void HeartDataRenewTask(void *argument);
extern void BluetoothTxTask(void *argument);
extern void BluetoothRxTask(void *argument);
extern void IdleTimerCallback(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* Hook prototypes */
void configureTimerForRunTimeStats(void);
unsigned long getRunTimeCounterValue(void);
void vApplicationIdleHook(void);
void vApplicationTickHook(void);

/* USER CODE BEGIN 1 */
/* Functions needed when configGENERATE_RUN_TIME_STATS is on */
__weak void configureTimerForRunTimeStats(void)
{

}

__weak unsigned long getRunTimeCounterValue(void)
{
return 0;
}
/* USER CODE END 1 */

/* USER CODE BEGIN 2 */
void vApplicationIdleHook( void )
{
   /* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
   to 1 in FreeRTOSConfig.h. It will be called on each iteration of the idle
   task. It is essential that code added to this hook function never attempts
   to block in any way (for example, call xQueueReceive() with a block time
   specified, or call vTaskDelay()). If the application makes use of the
   vTaskDelete() API function (as this demo application does) then it is also
   important that vApplicationIdleHook() is permitted to return to its calling
   function, because it is the responsibility of the idle task to clean up
   memory allocated by the kernel to any task that has since been deleted. */
}
/* USER CODE END 2 */

/* USER CODE BEGIN 3 */
void vApplicationTickHook( void )
{
   /* This function will be called by each tick interrupt if
   configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h. User code can be
   added here, but the tick hook is called from an interrupt context, so
   code must not attempt to block, and only the interrupt safe FreeRTOS API
   functions can be used (those that end in FromISR()). */
}
/* USER CODE END 3 */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* creation of EnvRefreshReqSem */
  EnvRefreshReqSemHandle = osSemaphoreNew(1, 0, &EnvRefreshReqSem_attributes);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* Create the timer(s) */
  /* creation of Idle_Timer */
  Idle_TimerHandle = osTimerNew(IdleTimerCallback, osTimerPeriodic, NULL, &Idle_Timer_attributes);

  /* USER CODE BEGIN RTOS_TIMERS */
  osTimerStart(Idle_TimerHandle,100);
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* creation of PageQueue */
  PageQueueHandle = osMessageQueueNew (16, sizeof(PageMessage*), &PageQueue_attributes);

  /* creation of EnvirQueue */
  EnvirQueueHandle = osMessageQueueNew (16, sizeof(EnvirMessage*), &EnvirQueue_attributes);

  /* creation of HeartQueue */
  HeartQueueHandle = osMessageQueueNew (16, sizeof(HeartMessage*), &HeartQueue_attributes);

  /* creation of HrCmdQueue */
  HrCmdQueueHandle = osMessageQueueNew (16, sizeof(hr_command_t), &HrCmdQueue_attributes);

  /* creation of CommonQueue */
  CommonQueueHandle = osMessageQueueNew (16, sizeof(CommonMessage*), &CommonQueue_attributes);

  /* creation of Idle_MessageQueue */
  Idle_MessageQueueHandle = osMessageQueueNew (1, sizeof(uint8_t), &Idle_MessageQueue_attributes);

  /* creation of IdleBreak_MessageQueue */
  IdleBreak_MessageQueueHandle = osMessageQueueNew (1, sizeof(uint8_t), &IdleBreak_MessageQueue_attributes);

  /* creation of Stop_MessageQueue */
  Stop_MessageQueueHandle = osMessageQueueNew (1, sizeof(uint8_t), &Stop_MessageQueue_attributes);

  /* creation of BluetoothTxQueue */
  BluetoothTxQueueHandle = osMessageQueueNew (8, 64, &BluetoothTxQueue_attributes);

  /* creation of BluetoothRxQueue */
  BluetoothRxQueueHandle = osMessageQueueNew (8, sizeof(char*), &BluetoothRxQueue_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of LvglTask */
  LvglTaskHandle = osThreadNew(StartLvglTask, NULL, &LvglTask_attributes);

  /* creation of myKeyTask */
  myKeyTaskHandle = osThreadNew(StartKeyTask, NULL, &myKeyTask_attributes);

  /* creation of myPageTask */
  myPageTaskHandle = osThreadNew(StartPageTask, NULL, &myPageTask_attributes);

  /* creation of myFeedTask */
  myFeedTaskHandle = osThreadNew(WdogFeedTask, NULL, &myFeedTask_attributes);

  /* creation of SensorDataTask */
  SensorDataTaskHandle = osThreadNew(SensorDataRenewTask, NULL, &SensorDataTask_attributes);

  /* creation of DataUpdateTask */
  DataUpdateTaskHandle = osThreadNew(SensorDataUpdateTask, NULL, &DataUpdateTask_attributes);

  /* creation of myTimeTask */
  myTimeTaskHandle = osThreadNew(TimeUpdateTask, NULL, &myTimeTask_attributes);

  /* creation of HeartDataTask */
  HeartDataTaskHandle = osThreadNew(HeartDataRenewTask, NULL, &HeartDataTask_attributes);

  /* creation of BluetoothTxtask */
  BluetoothTxtaskHandle = osThreadNew(BluetoothTxTask, NULL, &BluetoothTxtask_attributes);

  /* creation of BluetoothRxtask */
  BluetoothRxtaskHandle = osThreadNew(BluetoothRxTask, NULL, &BluetoothRxtask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  osThreadNew(IdleEnterTask,NULL,NULL);
  osThreadNew(StopEnterTask,NULL,NULL);
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartLvglTask */
/**
  * @brief  Function implementing the LvglTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartLvglTask */
void StartLvglTask(void *argument)
{
  /* USER CODE BEGIN StartLvglTask */
  setup_ui(&guider_ui);
  // events_init(&guider_ui);
  custom_init(&guider_ui);

  uint32_t last_wake_time = osKernelGetTickCount();
  const uint32_t lvgl_period_ms = 5;
  // char text_buf[10];
  static uint32_t last_tick = 0;
  /* Infinite loop */
  for(;;)
  {

    uint32_t now = osKernelGetTickCount();
    if (now - last_tick > 0) {
      lv_tick_inc(now - last_tick);
      // user_HR_timecount+=(now - last_tick);
      last_tick = now;
    }
    lv_timer_handler();
    last_wake_time += lvgl_period_ms;
    osDelayUntil(last_wake_time);
  }
  /* USER CODE END StartLvglTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

