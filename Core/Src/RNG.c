/*
 * RNG.c
 *
 *  Created on: Dec 3, 2024
 *      Author: boony
 */
#include "RNG.h"
static RNG_HandleTypeDef hrng;
void RNG_Init() {
	//__HAL_RCC_RNG_CLK_ENABLE();
	//__HAL_RCC_RNG_FORCE_RESET();
	//__HAL_RCC_RNG_RELEASE_RESET();

	hrng.Instance = RNG;
//	hrng.State = HAL_RNG_STATE_READY;
	if(HAL_RNG_Init(&hrng) != HAL_OK) {
		Error_Handler();
	}
}

uint32_t generateNumber7() {
	hrng.Instance = RNG;
	//	hrng.State = HAL_RNG_STATE_READY;
	if(HAL_RNG_Init(&hrng) != HAL_OK) {
		Error_Handler();
	}
	uint32_t volatile randomNum = HAL_RNG_GetRandomNumber(&hrng);
//	hrng.State = HAL_RNG_STATE_READY;
//
//	HAL_RNG_GenerateRandomNumber(&hrng, &randomNum);
//	hrng.State = HAL_RNG_STATE_READY;
//	HAL_RNG_GenerateRandomNumber(&hrng, &randomNum);
//	hrng.State = HAL_RNG_STATE_READY;
//	HAL_RNG_GenerateRandomNumber(&hrng, &randomNum);
//	hrng.State = HAL_RNG_STATE_READY;
//	HAL_RNG_GenerateRandomNumber(&hrng, &randomNum);
//	HAL_RNG_GenerateRandomNumber(&hrng, &randomNum);
//	HAL_RNG_GenerateRandomNumber(&hrng, &randomNum);
	//HAL_RNG_GenerateRandomNumber(&hrng, &randomNum);

	return randomNum % 7;

	//return HAL_RNG_GetRandomNumber(&hrng) % 7;

}

//idk man


