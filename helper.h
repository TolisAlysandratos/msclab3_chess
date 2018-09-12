/* Helper header */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

#ifndef HELPER_H
#define HELPER_H

#define NUM_RANKS 8
#define NUM_COLUMNS 8
#define POS_LEN 2
#define W_PAWN_RANK 6
#define B_PAWN_RANK 1
#define LEFT -1
#define RIGHT 1
#define UP -1
#define DOWN 1

#define NO_ERROR 0
#define INVALID_INPUT -1
#define NO_PIECE -2
#define ILLEGAL_MOVE -3
#define NOT_TURN -4
#define END_STALEMATE -5
#define GAME_END -6

const string RANKS = "87654321";
const string FILES = "ABCDEFGH";

typedef vector< vector<int> > matrix;

#endif
