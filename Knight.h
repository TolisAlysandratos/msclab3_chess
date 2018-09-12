/* Knight Class */

#include "helper.h"
#include "Piece.h"

#ifndef KNIGHT_H
#define KNIGHT_H

class Knight : public Piece {
 public:
  /* Constructor of the derived class Kinght that initialises the type attibute */
  Knight(const string &clr);
  void possibleMoves(Piece* brd[][NUM_COLUMNS],
		     const int &r_s, const int &c_s,
		     matrix &all_moves);

  /* Deconstructor for the derived class Knight */
  virtual ~Knight();

};

#endif
