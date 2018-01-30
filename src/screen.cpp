// screen.cpp
#include <SDL2/SDL.h>
#include <iostream>
#include <string>

#include "screen.h"
#include "board.h"

Screen::Screen(std::string windowName, Board* b){
	board = b;

    window = NULL;
    screenSurface = NULL;
    renderer = NULL;

    // initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    } else   {
        // create window
        window = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL ){
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }   else {
            // get window surface
            screenSurface = SDL_GetWindowSurface( window );

            // fill the surface white
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
            
            // update the surface
            SDL_UpdateWindowSurface( window );

            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );

            if(renderer == NULL ) {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
            }
        }
    }
}

Screen::~Screen(){
    // destroy window
    SDL_DestroyWindow(window);

    // quit SDL subsystems
    SDL_Quit();

}

void Screen::drawGridLines(){
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

	int xCurr = 100;
	int yCurr = 50;

	int y1 = yCurr;
	int y2 = y1 + board->getBoardHeight() * grid_size;

	int x1 = xCurr;
	int x2 = x1 + board->getBoardWidth() * grid_size;

	while (xCurr <= x2){
		SDL_RenderDrawLine(renderer, xCurr, y1, xCurr, y2);

		xCurr += grid_size;
	}

	while (yCurr <= y2){
		SDL_RenderDrawLine(renderer, x1, yCurr, x2, yCurr);

		yCurr += grid_size;
	}

	SDL_RenderPresent(renderer);


}

int Screen::drawPieces(){
	int numRows = board->getBoardWidth();
	int numCols = board->getBoardHeight();

	for(int i = 0; i < numRows; i++){
		for(int j = 0; j < numCols; j++){
			if (board->squareIsFilled(i,j) == 0){
				fillSquare(i,j);
			}
		}
	}

	return 0;
}

int Screen::fillSquare(int xPos, int yPos){
	if(xPos > board->getBoardWidth() || yPos > board->getBoardHeight() || xPos < 0 || yPos < 0){
		printf("Error: Board Coordinates must be in the range:\n\tX: %d to %d\n\tY: %d to %d\n", 0, board->getBoardWidth(), 0, board->getBoardHeight());
		return -1;
	 }

	// choose the destination for the sprite
    int xTranslation = 101 + xPos * grid_size;
    int yTranslation = 51 + yPos * grid_size;
    SDL_Rect destination = {xTranslation, yTranslation, grid_size - 2, grid_size - 2}; // the rectangle

    // load the sprite
	SDL_Surface* blockBMP = SDL_LoadBMP("img/pink-block.bmp");
 	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, blockBMP );

 	// apply to scren
	SDL_RenderCopy(renderer, texture, NULL, &destination);
	SDL_RenderPresent(renderer); // copy to screen

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(blockBMP);

	return 0;
}