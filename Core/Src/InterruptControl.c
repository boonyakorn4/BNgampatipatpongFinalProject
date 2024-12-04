/*
 * InterruptControl.c
 *
 *  Created on: Oct 1, 2024
 *      Author: boony
 */

#include "InterruptControl.h"

void IRQEnableInterrupt(uint8_t IRQNumber) {
	if (IRQNumber == EXTI0_IRQ_NUMBER) {
		IRQn_Type buttonIRQNum = EXTI0_IRQn;
		HAL_NVIC_EnableIRQ(buttonIRQNum);
	}



}
void IRQDisableInterrupt(uint8_t IRQNumber) {
	if (IRQNumber == EXTI0_IRQ_NUMBER) {
		IRQn_Type buttonIRQNum = EXTI0_IRQn;
		HAL_NVIC_DisableIRQ(buttonIRQNum);
	}


}
void IRQClearPendingInterrupt(uint8_t IRQNumber){
	if (IRQNumber == EXTI0_IRQ_NUMBER) {
		IRQn_Type buttonIRQNum = EXTI0_IRQn;
		HAL_NVIC_ClearPendingIRQ(buttonIRQNum);
	}
}
void IRQSetPendingInterrupt(uint8_t IRQNumber) {
	if (IRQNumber == EXTI0_IRQ_NUMBER) {
		IRQn_Type buttonIRQNum = EXTI0_IRQn;
		HAL_NVIC_SetPendingIRQ(buttonIRQNum);
	}
}
void IRQClearInterruptPendingBit(uint8_t pinNumber) {
	EXTI_HandleTypeDef pinNum;
	pinNum.Line = pinNumber;
	HAL_EXTI_ClearPending(&pinNum, EXTI_TRIGGER_RISING_FALLING);
}
