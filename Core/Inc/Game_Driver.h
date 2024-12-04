/*
 * Game_Driver.h
 *
 *  Created on: Dec 3, 2024
 *      Author: boony
 */

#ifndef INC_GAME_DRIVER_H_
#define INC_GAME_DRIVER_H_

#include <stdint.h>
#include <stdbool.h>
#include "RNG.h"
#include "LCD_Driver.h"
#include "stm32f4xx_hal.h"


#define numRow 16
#define numCol 10

#define OBlock 0
#define IBlock 1
#define SBlock 2
#define ZBlock 3
#define LBlock 4
#define JBlock 5
#define TBlock 6

#define blockSize 10

void Game_Init();
void Game_NewBlock();
void Game_PlaceBlock(uint16_t x, uint16_t y, uint16_t block);
bool Game_CanMoveDown();
bool Game_MoveDown();
void Game_PlaceSquare(uint16_t x, uint16_t y, uint16_t color);

void Game_PlaceBlank(uint16_t x, uint16_t y);
void Game_Merge();

void Game_Left();
void Game_Right();
void Game_Rotate();



#endif /* INC_GAME_DRIVER_H_ */
