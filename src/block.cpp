// block.cpp
#include <SDL2/SDL.h>
#include <iostream>
#include "block.h"

Block::Block(int x, int y) {
	xPos = x;
	yPos = y;
}

Block::Block(){
	xPos = -1;
	yPos = -1;
}