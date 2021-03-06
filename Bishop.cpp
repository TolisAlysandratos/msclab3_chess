/* Bishop Class Implementation */

#include <iostream>
using namespace std;

#include "Bishop.h"
#include "helper.h"

Bishop::Bishop(const string &clr) : Piece(clr) {
  type = "Bishop";
}

void Bishop::possibleMoves(Piece* brd[][NUM_COLUMNS],
			   const int &r_s, const int &c_s,
			   matrix &all_moves) {
  string piece_clr = brd[r_s][c_s]->getColour();
  // up left moves
  int r = r_s + UP;
  int c = c_s + LEFT;
  while (r >= 0 && c >= 0 && (brd[r][c] == NULL
			      || (brd[r][c] != NULL && brd[r][c]->getColour() != piece_clr))) {
    vector<int> pos;
    pos.push_back(r);
    pos.push_back(c);
    all_moves.push_back(pos);
    if (brd[r][c] != NULL)
      break;
    r += UP;
    c += LEFT;
  }
  // up right moves
  r = r_s + UP;
  c = c_s + RIGHT;
  while (r >= 0 && c < NUM_COLUMNS && (brd[r][c] == NULL
				       || (brd[r][c] != NULL && brd[r][c]->getColour() != piece_clr))) {
    vector<int> pos;
    pos.push_back(r);
    pos.push_back(c);
    all_moves.push_back(pos);
    if (brd[r][c] != NULL)
      break;
    r += UP;
    c += RIGHT;
  }
  // down left moves
  r = r_s + DOWN;
  c = c_s + LEFT;
  while (r < NUM_RANKS && c >= 0 && (brd[r][c] == NULL
				     || (brd[r][c] != NULL && brd[r][c]->getColour() != piece_clr))) {
    vector<int> pos;
    pos.push_back(r);
    pos.push_back(c);
    all_moves.push_back(pos);
    if (brd[r][c] != NULL)
      break;
    r += DOWN;
    c += LEFT;
  }  
  // down right moves
  r = r_s + DOWN;
  c = c_s + RIGHT;
  while (r < NUM_RANKS && c < NUM_COLUMNS && (brd[r][c] == NULL
					      || (brd[r][c] != NULL && brd[r][c]->getColour() != piece_clr))) {
    vector<int> pos;
    pos.push_back(r);
    pos.push_back(c);
    all_moves.push_back(pos);
    if (brd[r][c] != NULL)
      break;
    r += DOWN;
    c += RIGHT;
  }
}

Bishop::~Bishop() {}
