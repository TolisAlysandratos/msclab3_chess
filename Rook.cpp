/* Rook Class Implementation */

#include <iostream>
using namespace std;

#include "Rook.h"
#include "helper.h"

Rook::Rook(const string &clr) : Piece(clr) {
  type = "Rook";
}

void Rook::possibleMoves(Piece* brd[][NUM_COLUMNS],
			 const int &r_s, const int &c_s,
			 matrix &all_moves) {
  string piece_clr = brd[r_s][c_s]->getColour();
  // up moves
  int r = r_s + UP;
  while (r >= 0 && (brd[r][c_s] == NULL
		    || (brd[r][c_s] != NULL && brd[r][c_s]->getColour() != piece_clr))) {
    vector<int> pos;
    pos.push_back(r);
    pos.push_back(c_s);
    all_moves.push_back(pos);
    if (brd[r][c_s] != NULL)
      break;
    r += UP;
  }
  // down moves
  r = r_s + DOWN;
  while (r < NUM_RANKS && (brd[r][c_s] == NULL
			   || (brd[r][c_s] != NULL && brd[r][c_s]->getColour() != piece_clr))) {
    vector<int> pos;
    pos.push_back(r);
    pos.push_back(c_s);
    all_moves.push_back(pos);
    if (brd[r][c_s] != NULL)
      break;
    r += DOWN;
  }
  // left moves
  int c = c_s + LEFT;
  while (c >= 0 && (brd[r_s][c] == NULL
		    || (brd[r_s][c] != NULL && brd[r_s][c]->getColour() != piece_clr))) {
    vector<int> pos;
    pos.push_back(r_s);
    pos.push_back(c);
    all_moves.push_back(pos);
    if (brd[r_s][c] != NULL)
      break;
    c += LEFT;
  }
  // right moves
  c = c_s + RIGHT;
  while (c < NUM_COLUMNS && (brd[r_s][c] == NULL
			     || (brd[r_s][c] != NULL && brd[r_s][c]->getColour() != piece_clr))) {
    vector<int> pos;
    pos.push_back(r_s);
    pos.push_back(c);
    all_moves.push_back(pos);
    if (brd[r_s][c] != NULL)
      break;
    c += RIGHT;
  }
}  

Rook::~Rook() {}
