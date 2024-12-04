/*
 * RNG.h
 *
 *  Created on: Dec 3, 2024
 *      Author: boony
 */

#ifndef INC_RNG_H_
#define INC_RNG_H_

#include "stm32f4xx_hal.h"
#include <stdint.h>



void RNG_Init();

uint32_t generateNumber7();

#endif /* INC_RNG_H_ */
