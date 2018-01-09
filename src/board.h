#ifndef BOARD_H
#define BOARD_H
// board.h

enum CellContents {
	empty,
	red,
	blue
};

class Board {
	public:
		Board();
		int getBoardHeight();
		int getBoardWidth();

	private:
		// game board sizes
		const static int BOARD_WIDTH = 12;
		const static int BOARD_HEIGHT = 22;
		const static int TOP_PADDING = 16;

		int gameBoard[BOARD_HEIGHT * 2][BOARD_WIDTH * 2 + TOP_PADDING]; // board must be super tall for the big version of straight piece

};

#endif