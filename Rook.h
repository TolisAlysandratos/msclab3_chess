/* Rook Class */

#include "helper.h"
#include "Piece.h"

#ifndef ROOK_H
#define ROOK_H

class Rook : public Piece {
 public:
  /* Deconstructor for the derived class Rook that initialises the type attribute */
  Rook(const string &clr);
  void possibleMoves(Piece* brd[][NUM_COLUMNS],
		     const int &r_s, const int &c_s,
		     matrix &all_moves);
  
  /* Deconstructor for the derive class Rook */
  virtual ~Rook();
  
};

#endif
