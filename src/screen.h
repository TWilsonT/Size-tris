#ifndef SCREEN_H
#define SCREEN_H
// screen.h
#include <string>
#include "board.h"

class Screen {
	public:
		Screen(std::string windowName, Board board);
		~Screen();

		void drawGridLines();

	private:
		// screen dimension constants
		const static int SCREEN_WIDTH = 800;
		const static int SCREEN_HEIGHT = 600;

		const static int grid_size = 20;

		Board* board;
		// the window we'll be rendering to
    	SDL_Window* window;
    
    	// the surface contained by the window
    	SDL_Surface* screenSurface;

    	SDL_Renderer* renderer;
};

#endif