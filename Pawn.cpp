/* Pawn Class Implementation */

#include <iostream>
using namespace std;

#include "Pawn.h"
#include "helper.h"

Pawn::Pawn(const string &clr) : Piece(clr) {
  type = "Pawn";
}

void Pawn::possibleMoves(Piece* brd[][NUM_COLUMNS],
			 const int &r_s, const int &c_s,
			 matrix &all_moves) {
  int hor_moves;
  int ver_moves;
  string pawn_col = brd[r_s][c_s]->getColour();
  // moves for white pawn
  if (pawn_col == "White") {
    for (int r=0; r<NUM_RANKS; r++) {
      ver_moves = r - r_s;
      for (int c=0; c<NUM_COLUMNS; c++) {
	hor_moves = c - c_s;
	// case one square forwards
	if ((ver_moves == UP && hor_moves == 0 && brd[r_s + UP][c_s] == NULL)
	    // case two squares forwards
	    || (ver_moves == UP*2 && hor_moves == 0 && r_s == W_PAWN_RANK
		&& brd[r_s + UP][c_s] == NULL && brd[r_s + UP*2][c_s] == NULL)
	    // case left diagonally
	    || (ver_moves == UP && hor_moves == LEFT
		&& brd[r_s + UP][c_s + LEFT] != NULL && brd[r_s + UP][c_s + LEFT]->getColour() != "White")
	    // case right diagonally
	    || (ver_moves == UP && hor_moves == RIGHT
		&& brd[r_s + UP][c_s + RIGHT] != NULL && brd[r_s + UP][c_s + RIGHT]->getColour() != "White")) {
	  vector<int> pos;
	  pos.push_back(r);
	  pos.push_back(c);
	  all_moves.push_back(pos);	  
	}
      }
    }
    // moves for black pawn
  } else if (pawn_col == "Black") {
    for (int r=0; r<NUM_RANKS; r++) {
      ver_moves = r - r_s;
      for (int c=0; c<NUM_COLUMNS; c++) {
	hor_moves = c - c_s;
	// case one square forwards
	if ((ver_moves == DOWN && hor_moves == 0 && brd[r_s + DOWN][c] == NULL)
	    // case two squares forwards
	    || (ver_moves == DOWN*2 && hor_moves == 0 && r_s == B_PAWN_RANK
		&& brd[r_s + DOWN][c] == NULL && brd[r_s + DOWN*2][c] == NULL)
	    // case left diagonally
	    || (ver_moves == DOWN && hor_moves == LEFT
		&& brd[r_s + DOWN][c_s + LEFT] != NULL && brd[r_s + DOWN][c_s + LEFT]->getColour() != "Black")
	    // case right diagonally
	    || (ver_moves == DOWN && hor_moves == RIGHT
		&& brd[r_s + DOWN][c_s + RIGHT] != NULL && brd[r_s + DOWN][c_s + RIGHT]->getColour() != "Black")) {
	  vector<int> pos;
	  pos.push_back(r);
	  pos.push_back(c);
	  all_moves.push_back(pos);	  
	}
      }
    }
  }
}

Pawn::~Pawn() {}
