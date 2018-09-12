/* Pawn Class */

#include "helper.h"
#include "Piece.h"

#ifndef PAWN_H
#define PAWN_H

class Pawn : public Piece {
 public:
  /* Constructor of the derived class Pawn which initialises the type attribute */
  Pawn(const string &clr);
  void possibleMoves(Piece* brd[][NUM_COLUMNS],
		     const int &r_s, const int &c_s,
		     matrix &all_moves);
  
  /* Deconstructor for derived class Pawn */
  virtual ~Pawn();
 
};

#endif
