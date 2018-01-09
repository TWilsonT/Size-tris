#include <iostream>
#include <stdio.h>
#include <string>

#include <SDL2/SDL.h>

#include "src/board.h"
#include "src/piece.h"
#include "src/piece-factory.h"
#include "src/block.h"
#include "src/screen.h"

int main(int argc, char* args[]){
	Board gameBoard;
	PieceFactory factory(gameBoard);

	std::string windowName = "Size-tris";
	Screen screen(windowName, gameBoard);
	screen.drawGridLines();

	for(int i = 0; i < 12; i++){
		for(int j = 0; j < 22; j++){
			screen.fillSquare(i,j);
		}
	}

    return 0;
}