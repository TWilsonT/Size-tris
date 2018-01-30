#ifndef BLOCK_H
#define BLOCK_H

// block.h
#include <SDL2/SDL.h>

class Block {
	public:
		Block(int x, int y);
		Block();
		int moveLeft();
		int moveRight();
		int moveDown();
		int moveUp();
		int xPos;
		int yPos;

	private:
		SDL_Surface* blockBMP;
 		SDL_Texture* texture;

};

#endif