#ifndef BOARD_H
#define BOARD_H
// board.h
#include <vector>


class Board {
	public:
		Board();
		~Board();
		int testIntegrity();
		int getBoardHeight();
		int getBoardWidth();
		void setFilled(int xPos, int yPos);
		void setEmpty(int xPos, int yPos);
		int squareIsFilled(int xPos, int yPos);

		enum CellContents {
			empty,
			filled,
		};

	private:
		CellContents* gameBoard; // board must be super tall for the big version of straight piece
		// game board sizes
		const static int BOARD_WIDTH = 12;
		const static int BOARD_HEIGHT = 22;
		const static int TOP_PADDING = 16;

};

#endif