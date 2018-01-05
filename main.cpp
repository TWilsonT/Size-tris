#include <iostream>
#include <stdio.h>

#include <SDL2/SDL.h>

#include "src/board.h"
#include "src/piece.h"
#include "src/piece-factory.h"
#include "src/block.h"

// screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]){
	Board gameBoard;
	PieceFactory factory(gameBoard);
}