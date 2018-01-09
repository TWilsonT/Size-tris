//piece-factory.cpp
#include "piece-factory.h"
#include "board.h"
#include <iostream>

PieceFactory::PieceFactory(Board b) {
	board = &b;
	std::cout << "Piece Factory Created" << "\n";
}