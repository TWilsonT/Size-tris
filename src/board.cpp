// board.cpp
#include "board.h"
#include <iostream>

Board::Board(){
	for(int i = 0; i < BOARD_HEIGHT;i++){
		for (int j = 0; j < BOARD_WIDTH; j++){
			gameBoard[i][j] = empty;
			std::cout << gameBoard[i][j];
		}
		std::cout << "\n";
	}
}