#ifndef BOARD_H
#define BOARD_H
// board.h

// game board sizes
const int BOARD_WIDTH = 24;
const int BOARD_HEIGHT = 44 + 16;

enum CellContents {
	empty,
	red,
	blue
};

class Board {
	int gameBoard[BOARD_HEIGHT][BOARD_WIDTH]; // board must be super tall for the big version of straight piece

	public:
		Board();
};

#endif