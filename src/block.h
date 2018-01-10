#ifndef BLOCK_H
#define BLOCK_H

// block.h
#include <SDL2/SDL.h>

class Block {
	int xPos;
	int yPos;
	public:
		Block(int x, int y);
		int moveLeft();
		int moveRight();
		int moveDown();
		int moveUp();

	private:
		SDL_Surface* blockBMP;
 		SDL_Texture* texture;
};

#endif