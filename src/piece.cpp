// piece.cpp
#include <iostream>
#include <stdio.h>
#include "piece.h"
#include "board.h"

Piece::Piece(PieceType type, Board* b) {
	board = b;
	switch(type){
		case square:
			/*
			*	++
			*	++
			*/
			std::cout << "Creating a Square Piece\n";
			blocks[0] = new Block(0,0);
			blocks[1] = new Block(0,1);
			blocks[2] = new Block(1,0);
			blocks[3] = new Block(1,1);

			board->setFilled(0,0);
			board->setFilled(0,1);
			board->setFilled(1,0);
			board->setFilled(1,1);

			break;
		case line:
			/*
			*	++++
			*/
			std::cout << "Creating a Line Piece\n";
			blocks[0] = new Block(0,0);
			blocks[1] = new Block(0,1);
			blocks[2] = new Block(0,2);
			blocks[3] = new Block(0,3);

			board->setFilled(0,0);
			board->setFilled(0,1);
			board->setFilled(0,2);
			board->setFilled(0,3);

			break;
		case tee:
			/*
			*	 +
			*	+++
			*/
			std::cout << "Creating a Tee Piece\n";
			blocks[0] = new Block(0,1);
			blocks[1] = new Block(1,0);
			blocks[2] = new Block(1,1);
			blocks[3] = new Block(1,2);

			board->setFilled(0,1);
			board->setFilled(1,0);
			board->setFilled(1,1);
			board->setFilled(1,2);

			break;
		case left_kink:
			/*
			*	 ++
			*	++
			*/
			std::cout << "Creating a Left Kink Piece\n";
			blocks[0] = new Block(0,1);
			blocks[1] = new Block(0,2);
			blocks[2] = new Block(1,0);
			blocks[3] = new Block(1,1);

			board->setFilled(0,1);
			board->setFilled(0,2);
			board->setFilled(1,0);
			board->setFilled(1,1);

			break;
		case right_kink:
			/*
			*	++
			*	 ++
			*/
			std::cout << "Creating a Right Kink Piece\n";
			blocks[0] = new Block(0,0);
			blocks[1] = new Block(0,1);
			blocks[2] = new Block(1,1);
			blocks[3] = new Block(1,2);

			board->setFilled(0,0);
			board->setFilled(0,1);
			board->setFilled(1,1);
			board->setFilled(1,2);

			break;
		case left_elbow:
			/*
			*	+
			*	+++
			*/
			std::cout << "Creating a Left Elbow Piece\n";
			blocks[0] = new Block(0,0);
			blocks[1] = new Block(1,0);
			blocks[2] = new Block(1,1);
			blocks[3] = new Block(1,2);

			board->setFilled(0,0);
			board->setFilled(1,0);
			board->setFilled(1,1);
			board->setFilled(1,2);

			break;
		case right_elbow:
			/*
			*	  +
			*	+++
			*/
			std::cout << "Creating a Right Elbow Piece\n";
			blocks[0] = new Block(0,2);
			blocks[1] = new Block(1,0);
			blocks[2] = new Block(1,1);
			blocks[3] = new Block(1,2);

			board->setFilled(0,2);
			board->setFilled(1,0);
			board->setFilled(1,1);
			board->setFilled(1,2);

			break;
		default:
			std::cout << "Not a Valid Piece Type\n";

			break;
	}
}

Piece::~Piece(){
	printf("DELETING A PIECE\n");
	for(int i = 0; i < 4; i++){
		if(blocks[i] != NULL){
			delete blocks[i];
		}
	}
}

void Piece::moveDown(){
	for(int i = 0; i < 4; i++){
		if (blocks[i] != NULL){
			board->setEmpty(blocks[i]->xPos, blocks[i]->yPos);
			blocks[i]->yPos++;
		}
	}

	for(int i = 0; i < 4; i++){
		if (blocks[i] != NULL){
			board->setFilled(blocks[i]->xPos, blocks[i]->yPos);
		}
	}
}