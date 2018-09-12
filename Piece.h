/* Piece Class */

#include "helper.h"

#ifndef PIECE_H
#define PIECE_H

class Piece {
  
 public:
  /* Constructor of the abstract class Piece which initialises the attribute colour */
  Piece(const string &clr);
  string getType();
  string getColour();

  /* Function which finds all the possible moves of a piece on a given board configuration;
     note that the output moves may also include (illegal) moves that put the piece's King in-check */
  virtual void possibleMoves(Piece* brd[][NUM_COLUMNS],
			     const int &r_s, const int &c_s,
			     matrix &all_moves) = 0;

  /* Destructor for abstract class Piece */
  virtual ~Piece();
 protected:
  string type;
  string colour;
};

#endif
