// board.cpp
#include "board.h"
#include <iostream>
#include <stdio.h>

Board::Board(){
	printf("CREATING GAME BOARD\n");
	gameBoard = new CellContents[BOARD_WIDTH * BOARD_HEIGHT];
	for(int i = 0; i < BOARD_WIDTH * BOARD_HEIGHT; i++){
		gameBoard[i] = empty;
	}
}

Board::~Board(){
	printf("DELETING GAME BOARD\n");
	if (gameBoard != NULL){
		delete[] gameBoard;
	}
}

int Board::squareIsFilled(int xPos, int yPos){
	int map = xPos * BOARD_HEIGHT + yPos;
	if(gameBoard[map] == empty){
		return -1;
	} else {
		return 0;
	}
}

int Board::getBoardHeight(){
	return BOARD_HEIGHT;
}

int Board::getBoardWidth(){
	return BOARD_WIDTH;
}

void Board::setFilled(int xPos, int yPos){
	int map = xPos * BOARD_HEIGHT + yPos;
	gameBoard[map] = filled;
}

void Board::setEmpty(int xPos, int yPos){
	int map = xPos * BOARD_HEIGHT + yPos;
	gameBoard[map] = empty;
}