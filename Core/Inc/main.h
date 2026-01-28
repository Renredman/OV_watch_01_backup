/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "cmsis_os2.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
extern osMessageQueueId_t PageQueueHandle;
extern osMessageQueueId_t EnvirQueueHandle;
extern osMessageQueueId_t HeartQueueHandle;
extern osMessageQueueId_t HrCmdQueueHandle;
extern osMessageQueueId_t CommonQueueHandle;
extern osMessageQueueId_t Idle_MessageQueueHandle;
extern osMessageQueueId_t IdleBreak_MessageQueueHandle;
extern osMessageQueueId_t Stop_MessageQueueHandle;
extern osTimerId_t Idle_TimerHandle;

extern uint8_t Sensor_LSM303_Erro;
extern uint8_t Sensor_AHT21_Erro;
extern uint8_t Sensor_SPL_Erro;
extern uint8_t Sensor_EM_Erro;
extern uint8_t Sensor_MPU_Erro;
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
void SystemClock_Config(void);
/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
