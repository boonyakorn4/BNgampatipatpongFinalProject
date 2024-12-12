/*
 * Timer_Driver.h
 *
 *  Created on: Dec 10, 2024
 *      Author: boony
 */

#ifndef INC_TIMER_DRIVER_H_
#define INC_TIMER_DRIVER_H_

#include "stm32f4xx_hal.h"
#include <stdint.h>

void Timer7_Init(void);
void Timer7_Start(void);
void Timer7_Stop(void);
uint32_t Timer7_ReturnValue(void);

void Timer7_Interrupt();


#endif /* INC_TIMER_DRIVER_H_ */
