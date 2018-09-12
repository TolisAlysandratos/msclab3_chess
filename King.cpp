/* King Class Implementation */

#include <iostream>
using namespace std;

#include "King.h"
#include "helper.h"
#include "ChessBoard.h"

King::King(const string &clr) : Piece(clr) {
  type = "King";
}

void King::possibleMoves(Piece* brd[][NUM_COLUMNS],
			 const int &r_s, const int &c_s,
			 matrix &all_moves) {
  string piece_clr = brd[r_s][c_s]->getColour();
  int hor_moves;
  int ver_moves;
  for (int r=0; r<NUM_RANKS; r++) {
    ver_moves = abs(r - r_s);
    for (int c=0; c<NUM_COLUMNS; c++) {
      hor_moves = abs(c - c_s);
      if (hor_moves <= 1 && ver_moves <= 1
	  && !(r==r_s && c==c_s)
	  && ((brd[r][c] == NULL)
	      || (brd[r][c] != NULL
		  && brd[r][c]->getColour() != piece_clr))) {	
	vector<int> pos;
	pos.push_back(r);
	pos.push_back(c);
	all_moves.push_back(pos);
      }
    }
  }
}

King::~King() {}
