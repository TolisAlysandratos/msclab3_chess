/* King Class */

#include "helper.h"
#include "Piece.h"

#ifndef KING_H
#define KING_H

class King : public Piece {
 public:
  /* Constructor of the derived class King which initialises the type attribute */
  King(const string &clr);
  void possibleMoves(Piece* brd[][NUM_COLUMNS],
		     const int &r_s, const int &c_s,
		     matrix &all_moves);

  /* Deconstructor for derived class King */
  virtual ~King();

};

#endif
