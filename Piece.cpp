/* Piece Class Implementation */

#include <iostream> 
#include "Piece.h"
using namespace std;

Piece::Piece(const string &clr) {
  if (clr == "white" || clr == "White")
    colour = "White";
  if (clr == "black" || clr == "Black")
    colour = "Black";  
}

string Piece::getType() {
  return type;
}
string Piece::getColour() {
  return colour;
}

Piece::~Piece() {}
