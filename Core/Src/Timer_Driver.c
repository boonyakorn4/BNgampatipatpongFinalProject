/*
 * Timer_Driver.c
 *
 *  Created on: Dec 10, 2024
 *      Author: boony
 */

#include "Timer_Driver.h"

TIM_HandleTypeDef htim7;

void Timer7_Init() {

	__HAL_RCC_TIM7_CLK_ENABLE();
	HAL_TIM_Base_MspInit(&htim7);


	/* USER CODE BEGIN TIM7_Init 0 */
	 /* USER CODE END TIM7_Init 0 */
	 TIM_MasterConfigTypeDef sMasterConfig = {0};
	 /* USER CODE BEGIN TIM7_Init 1 */
	 /* USER CODE END TIM7_Init 1 */
	 htim7.Instance = TIM7;
	 htim7.Instance -> DIER = 1;
	 htim7.Init.Prescaler = 12500;
	 htim7.Init.CounterMode = TIM_COUNTERMODE_UP;
	 htim7.Init.Period = 65535; // Was 65535
	 htim7.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE; // Was disabled
	 if (HAL_TIM_Base_Init(&htim7) != HAL_OK)
	 {
	   Error_Handler();
	 }

	 // Added this:
	 //htim7.Instance -> DIER |= 1;
	 TIM7 -> DIER |= 0x1;
	 //HAL_NVIC_EnableIRQ(TIM7_IRQn);


	 sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	 sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	 if (HAL_TIMEx_MasterConfigSynchronization(&htim7, &sMasterConfig) != HAL_OK)
	 {
	   Error_Handler();
	 }
	 /* USER CODE BEGIN TIM7_Init 2 */
	 /* USER CODE END TIM7_Init 2 */
}

void Timer7_Interrupt() {
	htim7.Instance -> DIER |= 1;
	htim7.Instance -> CNT = RESET;
	htim7.Instance -> SR &= ~(1);
}


void Timer7_Start() {
	HAL_TIM_Base_Start_IT(&htim7);
}
void Timer7_Stop() {
	HAL_TIM_Base_Stop_IT(&htim7);
}
uint32_t Timer7_ReturnValue() {
	return htim7.Instance->CNT;
}

