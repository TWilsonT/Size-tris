#ifndef PIECE_FACTORY_H
#define PIECE_FACTORY_H
// piece.h
#include "board.h"

class PieceFactory {
	Board* board;
	public:
		PieceFactory(Board* b);
};

#endif