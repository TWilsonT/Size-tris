// screen.cpp
#include <SDL2/SDL.h>
#include <iostream>
#include <string>

#include "screen.h"
#include "board.h"

Screen::Screen(std::string windowName, Board b){
	board = &b;

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
   
    // wait two seconds
    SDL_Delay(2000);	
}