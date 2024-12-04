/*
 * InterruptControl.h
 *
 *  Created on: Oct 1, 2024
 *      Author: boony
 */

#ifndef INTERRUPTCONTROL_H_
#define INTERRUPTCONTROL_H_

#define EXTI0_IRQ_NUMBER 6
#include <stdint.h>
#include "stm32f4xx_hal.h"


void IRQEnableInterrupt(uint8_t);
void IRQDisableInterrupt(uint8_t);
void IRQClearPendingInterrupt(uint8_t);
void IRQSetPendingInterrupt(uint8_t);
void IRQClearInterruptPendingBit(uint8_t);


#endif /* INTERRUPTCONTROL_H_ */
