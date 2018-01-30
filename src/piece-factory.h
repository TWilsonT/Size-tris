#ifndef PIECE_FACTORY_H
#define PIECE_FACTORY_H
// piece.h
#include "board.h"
#include "piece.h"

class PieceFactory {
	Board* board;
	public:
		PieceFactory(Board* b);
		void dropActivePiece();

	private:
		int spawnRandomPiece();
		Piece* activePiece;
};

#endif