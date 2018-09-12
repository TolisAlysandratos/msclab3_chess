/* Knight Class Implementation */

#include <iostream>
using namespace std;

#include "Knight.h"
#include "helper.h"

Knight::Knight(const string &clr) : Piece(clr) {
  type = "Knight";
}

void Knight::possibleMoves(Piece* brd[][NUM_COLUMNS],
			   const int &r_s, const int &c_s,
			   matrix &all_moves) {
  int hor_moves;
  int ver_moves;
  string piece_col = brd[r_s][c_s]->getColour();
  for (int r=0; r<NUM_RANKS; r++) {
    ver_moves = r - r_s;
    for (int c=0; c<NUM_COLUMNS; c++) {
      hor_moves = c - c_s;
      // upwards moves
      if (ver_moves == UP*2) {
	if (hor_moves == LEFT
	    && (brd[r_s + UP*2][c_s + LEFT] == NULL
		|| (brd[r_s + UP*2][c_s + LEFT] != NULL
		    && brd[r_s + UP*2][c_s + LEFT]->getColour() == "Black"))) {
	  vector<int> pos;
	  pos.push_back(r);
	  pos.push_back(c);
	  all_moves.push_back(pos);	  
	}
	if (hor_moves == RIGHT
	    && (brd[r_s + UP*2][c_s + RIGHT] == NULL
		|| (brd[r_s + UP*2][c_s + RIGHT] != NULL
		    && brd[r_s + UP*2][c_s + RIGHT]->getColour() != piece_col))) {
	  vector<int> pos;
	  pos.push_back(r);
	  pos.push_back(c);
	  all_moves.push_back(pos);	  
	}
      }
      // downwards moves
      if (ver_moves == DOWN*2) {
	if (hor_moves == LEFT
	    && (brd[r_s + DOWN*2][c_s + LEFT] == NULL
		|| (brd[r_s + DOWN*2][c_s + LEFT] != NULL
		    && brd[r_s + DOWN*2][c_s + LEFT]->getColour() != piece_col))) {
	  vector<int> pos;
	  pos.push_back(r);
	  pos.push_back(c);
	  all_moves.push_back(pos);	  
	}
	if (hor_moves == RIGHT
	    && (brd[r_s + DOWN*2][c_s + RIGHT] == NULL
		|| (brd[r_s + DOWN*2][c_s + RIGHT] != NULL
		    && brd[r_s + DOWN*2][c_s + RIGHT]->getColour() != piece_col))) {
	  vector<int> pos;
	  pos.push_back(r);
	  pos.push_back(c);
	  all_moves.push_back(pos);	  
	}
      }
      // leftwards move
      if (hor_moves == LEFT*2) {
	if (ver_moves == UP
	    && (brd[r_s + UP][c_s + LEFT*2] == NULL
		|| (brd[r_s + UP][c_s + LEFT*2] != NULL
		    && brd[r_s + UP][c_s + LEFT*2]->getColour() != piece_col))) {
	  vector<int> pos;
	  pos.push_back(r);
	  pos.push_back(c);
	  all_moves.push_back(pos);	  
	}
	if (ver_moves == DOWN
	    && (brd[r_s + DOWN][c_s + LEFT*2] == NULL
		|| (brd[r_s + DOWN][c_s + LEFT*2] != NULL
		    && brd[r_s + DOWN][c_s + LEFT*2]->getColour() != piece_col))) {
	  vector<int> pos;
	  pos.push_back(r);
	  pos.push_back(c);
	  all_moves.push_back(pos);	  
	}
      }
      // rightwards move
      if (hor_moves == RIGHT*2) {
	if (ver_moves == UP
	    && (brd[r_s + UP][c_s + RIGHT*2] == NULL
		|| (brd[r_s + UP][c_s + RIGHT*2] != NULL
		    && brd[r_s + UP][c_s + RIGHT*2]->getColour() != piece_col))) {
	  vector<int> pos;
	  pos.push_back(r);
	  pos.push_back(c);
	  all_moves.push_back(pos);	  
	}
	if (ver_moves == DOWN
	    && (brd[r_s + DOWN][c_s + RIGHT*2] == NULL
		|| (brd[r_s + DOWN][c_s + RIGHT*2] != NULL
		    && brd[r_s + DOWN][c_s + RIGHT*2]->getColour() != piece_col))) {
	  vector<int> pos;
	  pos.push_back(r);
	  pos.push_back(c);
	  all_moves.push_back(pos);	  
	}
      }
    }
  }
}

Knight::~Knight() {}
