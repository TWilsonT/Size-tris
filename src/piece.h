#ifndef PIECE_H
#define PIECE_H

// piece.h
#include "block.h"
enum PieceType {
	square, // O-block
	line, // I-block
	tee, // T-block
	left_kink, // Z-block
	right_kink, // S-block
	left_elbow, // J-block
	right_elbow // L-block
};

class Piece {
	public:
		Piece(PieceType type);

	private:
		Block blocks[4];
};

#endif