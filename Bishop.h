/* Bishop Class */

#include "helper.h"
#include "Piece.h"

#ifndef BISHOP_H
#define BISHOP_H

class Bishop : public Piece {
 public:
  /* Deconstructor for the derived class Bishop that initialises the type attribute */
  Bishop(const string &clr);
  void possibleMoves(Piece* brd[][NUM_COLUMNS],
		     const int &r_s, const int &c_s,
		     matrix &all_moves);

  /* deconstructor for the derive class Bishop */
  virtual ~Bishop();

};

#endif
