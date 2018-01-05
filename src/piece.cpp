// piece.cpp
#include <iostream>
#include "piece.h"

Piece::Piece(PieceType type) {
	std::cout << "Creating Piece of Type: " << type << "\n";

	switch(type){
		case square:
			std::cout << "Creating a Square Piece\n";

			break;
		case line:
			std::cout << "Creating a Line Piece\n";

			break;
		case tee:
			std::cout << "Creating a Tee Piece\n";

			break;
		case left_kink:
			std::cout << "Creating a Left Kink Piece\n";

			break;
		case right_kink:
			std::cout << "Creating a Right Kink Piece\n";

			break;
		case left_elbow:
			std::cout << "Creating a Left Elbow Piece\n";

			break;
		case right_elbow:
			std::cout << "Creating a Right Elbow Piece\n";

			break;
		default:
			std::cout << "Not a Valid Piece Type\n";

			break;
	}
}