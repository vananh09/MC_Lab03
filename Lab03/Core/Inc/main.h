/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
// Define for Led display
#define LED0_Pin GPIO_PIN_1
#define LED0_GPIO_Port GPIOA
#define LED1_Pin GPIO_PIN_2
#define LED1_GPIO_Port GPIOA
#define LED2_Pin GPIO_PIN_3
#define LED2_GPIO_Port GPIOA
#define LED3_Pin GPIO_PIN_4
#define LED3_GPIO_Port GPIOA
#define LED4_Pin GPIO_PIN_5
#define LED4_GPIO_Port GPIOA
#define LED5_Pin GPIO_PIN_6
#define LED5_GPIO_Port GPIOA
// Define for Led7seg display Value
#define VAL0_Pin GPIO_PIN_8
#define VAL0_GPIO_Port GPIOB
#define VAL1_Pin GPIO_PIN_9
#define VAL1_GPIO_Port GPIOB
#define VAL2_Pin GPIO_PIN_10
#define VAL2_GPIO_Port GPIOB
#define VAL3_Pin GPIO_PIN_11
#define VAL3_GPIO_Port GPIOB
#define VAL4_Pin GPIO_PIN_12
#define VAL4_GPIO_Port GPIOB
#define VAL5_Pin GPIO_PIN_13
#define VAL5_GPIO_Port GPIOB
#define VAL6_Pin GPIO_PIN_14
#define VAL6_GPIO_Port GPIOB
#define VAL7_Pin GPIO_PIN_15
#define VAL7_GPIO_Port GPIOB
//Define for Led7seg display Mode
#define MODE0_Pin GPIO_PIN_0
#define MODE0_GPIO_Port GPIOB
#define MODE1_Pin GPIO_PIN_1
#define MODE1_GPIO_Port GPIOB
#define MODE2_Pin GPIO_PIN_2
#define MODE2_GPIO_Port GPIOB
#define MODE3_Pin GPIO_PIN_3
#define MODE3_GPIO_Port GPIOB
#define MODE4_Pin GPIO_PIN_4
#define MODE4_GPIO_Port GPIOB
#define MODE5_Pin GPIO_PIN_5
#define MODE5_GPIO_Port GPIOB
#define MODE6_Pin GPIO_PIN_6
#define MODE6_GPIO_Port GPIOB
#define MODE7_Pin GPIO_PIN_7
#define MODE7_GPIO_Port GPIOB
//Define for button
#define BUTTON0_Pin GPIO_PIN_13
#define BUTTON0_GPIO_Port GPIOA
#define BUTTON1_Pin GPIO_PIN_14
#define BUTTON1_GPIO_Port GPIOA
#define BUTTON2_Pin GPIO_PIN_15
#define BUTTON2_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */
int press[3];
int timeRed, timeGreen, timeAmber;
int time_buffer[3];
int flagPressButton3;
int timeTotal;
int state_mode;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
