//piece-factory.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "piece-factory.h"
#include "board.h"
#include "piece.h"



PieceFactory::PieceFactory(Board* b) {
	board = b;
	srand(time(NULL));
	printf("Piece Factory Created\n");

	spawnRandomPiece();
}

int PieceFactory::spawnRandomPiece(){
	PieceType p = static_cast<PieceType>(rand() % NUM_PIECES);
	activePiece = new Piece(p, board);


    return 0;
}


void PieceFactory::dropActivePiece(){
	activePiece->moveDown();
}