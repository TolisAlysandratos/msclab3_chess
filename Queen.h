/* Queen Class */

#include "helper.h"
#include "Piece.h"

#ifndef QUEEN_H
#define QUEEN_H

class Queen : public Piece {
 public:
  /* Constructor for the derived class Queen which initialises the type attribute */
  Queen(const string &clr);
  void possibleMoves(Piece* brd[][NUM_COLUMNS],
		     const int &r_s, const int &c_s,
		     matrix &all_moves);
  
  /* Deconstructor for the derived class Queen */
  virtual ~Queen();

};

#endif
