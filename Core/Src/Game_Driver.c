/*
 * Game_Driver.c
 *
 *  Created on: Dec 3, 2024
 *      Author: boony
 */

#include "Game_Driver.h"
static uint32_t gameMatrix[numRow][numCol];
static uint32_t movingBlock[4][2];
static uint16_t currentBlock;
static uint16_t colorMatrix[7] = {LCD_COLOR_YELLOW, LCD_COLOR_CYAN, LCD_COLOR_RED, LCD_COLOR_GREEN, LCD_COLOR_ORANGE, LCD_COLOR_MAGENTA, LCD_COLOR_PURPLE};
static uint32_t gameTimeMs;
char numToChar[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
static uint32_t initialGameTime;
static uint32_t finalGameTime;


void Game_Init() {
	playScreen();
	for (int i = 0; i < numRow; i++) {
		for (int j = 0; j < numCol; j++) {
			gameMatrix[i][j] = 0;
		}
	}
	// Game_DrawBoard();

}
void Game_NewBlock() {
	uint32_t num = generateNumber7();

	Game_PlaceBlock(1,4,num);
}

void Game_PlaceBlock(uint16_t x, uint16_t y, uint16_t block) {

	Game_PlaceBlockMatrix(x,y,block);
	currentBlock = block;
	for (int i = 0; i < 4; i++) {
		Game_PlaceSquare(movingBlock[i][0],movingBlock[i][1], colorMatrix[currentBlock]);

	}
//	if (block == OBlock) {
//		drawO(20 + y * 20 + 10, x * 20 + 10);
//	} else if (block == IBlock) {
//		drawI(20 + y * 20 + 10, x * 20 + 10);
//
//	} else if (block == SBlock) {
//		drawS(20 + y * 20 + 10, x * 20 + 10);
//	}else if (block == ZBlock) {
//		drawZ(20 + y * 20 + 10, x * 20 + 10);
//	}else if (block == LBlock) {
//		drawL(20 + y * 20 + 10, x * 20 + 10);
//	} else if (block == JBlock) {
//		drawJ(20 + y * 20 + 10, x * 20 + 10);
//	} else if (block == TBlock) {
//		drawT(20 + y * 20 + 10, x * 20 + 10);
//	}
}

void Game_PlaceBlockMatrix(uint16_t x, uint16_t y, uint16_t block) {
	if (block == OBlock) {
		movingBlock[0][0] = x;
		movingBlock[0][1] = y;
		movingBlock[1][0] = x - 1;
		movingBlock[1][1] = y;
		movingBlock[2][0] = x - 1;
		movingBlock[2][1] = y + 1;
		movingBlock[3][0] = x;
		movingBlock[3][1] = y + 1;
	} else if (block == IBlock) {
		movingBlock[0][0] = x;
		movingBlock[0][1] = y;
		movingBlock[1][0] = x;
		movingBlock[1][1] = y - 1;
		movingBlock[2][0] = x;
		movingBlock[2][1] = y + 1;
		movingBlock[3][0] = x;
		movingBlock[3][1] = y + 2;
	} else if (block == SBlock) {
		movingBlock[0][0] = x;
		movingBlock[0][1] = y;
		movingBlock[1][0] = x - 1;
		movingBlock[1][1] = y;
		movingBlock[2][0] = x - 1;
		movingBlock[2][1] = y + 1;
		movingBlock[3][0] = x;
		movingBlock[3][1] = y - 1;
	} else if (block == ZBlock) {
		movingBlock[0][0] = x;
		movingBlock[0][1] = y;
		movingBlock[1][0] = x - 1;
		movingBlock[1][1] = y;
		movingBlock[2][0] = x - 1;
		movingBlock[2][1] = y - 1;
		movingBlock[3][0] = x;
		movingBlock[3][1] = y + 1;
	} else if (block == LBlock) {
		movingBlock[0][0] = x;
		movingBlock[0][1] = y;
		movingBlock[1][0] = x;
		movingBlock[1][1] = y - 1;
		movingBlock[2][0] = x;
		movingBlock[2][1] = y - 2;
		movingBlock[3][0] = x - 1;
		movingBlock[3][1] = y;
	} else if (block == JBlock) {
		movingBlock[0][0] = x;
		movingBlock[0][1] = y;
		movingBlock[1][0] = x - 1;
		movingBlock[1][1] = y;
		movingBlock[2][0] = x;
		movingBlock[2][1] = y + 1;
		movingBlock[3][0] = x;
		movingBlock[3][1] = y + 2;
	} else if (block == TBlock) {
		movingBlock[0][0] = x;
		movingBlock[0][1] = y;
		movingBlock[1][0] = x;
		movingBlock[1][1] = y - 1;
		movingBlock[2][0] = x;
		movingBlock[2][1] = y + 1;
		movingBlock[3][0] = x - 1;
		movingBlock[3][1] = y;			}
}

void Game_PlaceSquare(uint16_t x, uint16_t y, uint16_t color) {
	LCD_Draw_Square_Fill(20 + y * 20 + 10, x * 20 + 10, 10, LCD_COLOR_BLACK);
	LCD_Draw_Square_Fill(20 + y * 20 + 10, x * 20 + 10, 9, color);

}

void Game_PlaceBlank(uint16_t x, uint16_t y){
	LCD_Draw_Square_Fill(20 + y * 20 + 10, x * 20 + 10, 10, LCD_COLOR_WHITE);
}
/*
void Game_DrawBoard() {
	for (int i = 0; i < numRow; i++) {
		for (int j = 0; j < numCol; j++) {
			Game_PlaceBlank(i,j);
		}
	}
}
*/
bool overlap(uint32_t newArray[4][2]) {
	for (int i = 0; i < 4; i++) {
		if (newArray[i][0] < 0 || newArray[i][0] >= numRow) {
			return true;
		}
		if (newArray[i][1] < 0 || newArray[i][1] >= numCol) {
			return true;
		}
		if (gameMatrix[newArray[i][0]][newArray[i][1]]) {
			return true;
		}

	}

	return false;
}
bool Game_MoveDown() {
	uint32_t newLocation[4][2];
	for (int i = 0; i < 4; i++) {
		newLocation[i][0] = movingBlock[i][0] + 1;
		newLocation[i][1] = movingBlock[i][1];
	}
	if (!overlap(newLocation)) {
		for (int i = 0; i < 4; i++) {
			Game_PlaceBlank(movingBlock[i][0],movingBlock[i][1]);

		}
		for (int i = 0; i < 4; i++) {
			Game_PlaceSquare(newLocation[i][0],newLocation[i][1], colorMatrix[currentBlock]);

		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 2; j++) {
				movingBlock[i][j] = newLocation[i][j];
			}
		}


		return true;
	} else {
		return false;
	}
}

void Game_Merge() {
	for (int i = 0; i < 4; i++) {
		gameMatrix[movingBlock[i][0]][movingBlock[i][1]] = 1;
	}
}

void Game_Left() {
	uint32_t newLocation[4][2];
	for (int i = 0; i < 4; i++) {
		newLocation[i][0] = movingBlock[i][0];
		newLocation[i][1] = movingBlock[i][1] - 1;
	}
	if (!overlap(newLocation)) {
		for (int i = 0; i < 4; i++) {
			Game_PlaceBlank(movingBlock[i][0],movingBlock[i][1]);

		}
		for (int i = 0; i < 4; i++) {
			Game_PlaceSquare(newLocation[i][0],newLocation[i][1], colorMatrix[currentBlock]);

		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 2; j++) {
				movingBlock[i][j] = newLocation[i][j];
			}
		}



	}

}
void Game_Right() {
	uint32_t newLocation[4][2];
	for (int i = 0; i < 4; i++) {
		newLocation[i][0] = movingBlock[i][0];
		newLocation[i][1] = movingBlock[i][1] + 1;
	}
	if (!overlap(newLocation)) {
		for (int i = 0; i < 4; i++) {
			Game_PlaceBlank(movingBlock[i][0],movingBlock[i][1]);

		}
		for (int i = 0; i < 4; i++) {
			Game_PlaceSquare(newLocation[i][0],newLocation[i][1], colorMatrix[currentBlock]);

		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 2; j++) {
				movingBlock[i][j] = newLocation[i][j];
			}
		}


	}
}

void Game_Rotate() {
	uint32_t newLocation[4][2];
	newLocation[0][0] = movingBlock[0][0];
	newLocation[0][1] = movingBlock[0][1];
	for (int i = 1; i < 4; i++) {
		newLocation[i][0] = movingBlock[i][0] - movingBlock[0][0];
		newLocation[i][1] = movingBlock[i][1] - movingBlock[0][1];
		uint32_t temp = newLocation[i][1];
		newLocation[i][1] = newLocation[i][0];
		newLocation[i][0] = -temp;
		newLocation[i][0] = newLocation[i][0] + movingBlock[0][0];
		newLocation[i][1] = newLocation[i][1] + movingBlock[0][1];
	}
	if (!overlap(newLocation)) {
		for (int i = 0; i < 4; i++) {
			Game_PlaceBlank(movingBlock[i][0],movingBlock[i][1]);

		}
		for (int i = 0; i < 4; i++) {
			Game_PlaceSquare(newLocation[i][0],newLocation[i][1], colorMatrix[currentBlock]);

		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 2; j++) {
				movingBlock[i][j] = newLocation[i][j];
			}
		}



	}
}
void incrementGameTime() {
	gameTimeMs++;
}

void displayGameTime() {
	LCD_SetTextColor(LCD_COLOR_BLACK);
	LCD_SetFont(&Font16x24);
	//uint32_t temp = gameTimeMs;
	uint32_t temp = getTotalTime();

	LCD_DisplayChar(72,250,numToChar[temp / 100000]);
	temp = temp - ((temp / 100000) * 100000);

	LCD_DisplayChar(96,250,numToChar[temp / 10000]);
	temp = temp - ((temp / 10000) * 10000);

	LCD_DisplayChar(120,250,numToChar[temp / 1000]);
	temp = temp - ((temp / 1000) * 1000);

	LCD_DisplayChar(144,250,numToChar[temp / 100]);
	temp = temp - ((temp / 100) * 100);

	LCD_DisplayChar(168,250,numToChar[temp / 10]);
	temp = temp - ((temp / 10) * 10);

	LCD_DisplayChar(192,250,numToChar[temp]);

}

void setInitialTime() {
	initialGameTime = HAL_GetTick();
}

void setFinalTime() {
	finalGameTime = HAL_GetTick();
}

uint32_t getTotalTime() {
	return (uint32_t) ((initialGameTime < finalGameTime) ? (finalGameTime - initialGameTime) : ((65535 - initialGameTime) + finalGameTime));
}

bool Game_Lost();
