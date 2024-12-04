/*
 * Button_Driver.h
 *
 *  Created on: Sep 24, 2024
 *      Author: boony
 */

#ifndef BUTTON_DRIVER_H_
#define BUTTON_DRIVER_H_

#include "InterruptControl.h"
#include <stdbool.h>
#include "stm32f4xx_hal.h"

#define buttonPortValue A
#define buttonPinNumber 0
#define buttonPressed 1
#define buttonUnpressed 0

void Button_Init();
void Button_EnableClock(); //?
void Button_DisableClock(); //?
bool IsButtonPressed();
void Button_Interrupt_Init();

#endif /* BUTTON_DRIVER_H_ */
