/*
 * Button_Driver.c
 *
 *  Created on: Sep 24, 2024
 *      Author: boony
 */
#include "Button_Driver.h"



void Button_Init() {
	GPIO_InitTypeDef button;
	button.Pin = GPIO_PIN_0;
	button.Mode = GPIO_MODE_INPUT;
	button.Speed = GPIO_SPEED_FREQ_MEDIUM;
	button.Pull = GPIO_NOPULL;
	Button_EnableClock();
	HAL_GPIO_Init(GPIOA, &button);
}

void Button_EnableClock() {
	__HAL_RCC_GPIOA_CLK_ENABLE();
}

bool IsButtonPressed() {
	if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == buttonPressed) {
		return true;
	} else {
		return false;
	}
}

void Button_Interrupt_Init() {

	GPIO_InitTypeDef button;
	button.Pin = GPIO_PIN_0;
	button.Mode = GPIO_MODE_IT_RISING;
	button.Speed = GPIO_SPEED_FREQ_MEDIUM;
	button.Pull = GPIO_NOPULL;
	Button_EnableClock();
	HAL_GPIO_Init(GPIOA, &button);
	IRQEnableInterrupt(EXTI0_IRQ_NUMBER);
}
//done
