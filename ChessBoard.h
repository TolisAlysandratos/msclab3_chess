/* ChessBoard Class */

#include "Piece.h"
#include "King.h"
#include "Pawn.h"
#include "Knight.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

class ChessBoard {

 public:
  /* Constructor for Chessboard class that initialises 'board',
     a 2D array of pointers to Piece class objects  */
  ChessBoard();

  /* Resets pointers of 2D array 'board' to it's initial positions 
     after deleting the previous pointers */
  void resetBoard();

  /* Main function which takes two strings representing the source position 
     and destination position of a piece on a chessboard (rank and file), 
     and re-assigns or deletes the corresponding pointers to simulate the move of a chess piece;
     returns appropriate error codes when input or move are not valid or legal */
  int submitMove(const string &source, const string &dest);

  /* Deconstructor for the Chessboard class */
  virtual ~ChessBoard();

 private:
  Piece* board[NUM_RANKS][NUM_COLUMNS];
  Piece* h_board[NUM_RANKS][NUM_COLUMNS];
  bool game_end;
  bool w_turn;
  int wking_pos[2];
  int bking_pos[2];
  int h_king_pos[2];
  bool w_incheck;
  bool b_incheck;

  /* Helper function checks the validity of the input strings in submitMove function */
  bool isValidString(const string &str_pos);

  /* Helper function which convert the position input string of submitMove function
     to the corresponding coordinates in the 2D array 'board' */
  void strToPos(const string &str_pos, int pos[]);

  /* Helper function which scans through the 2D array 'board', locates the current
     positions of the two King pieces and updates the values of 'wking_pos' and
     'bking_pos' accordingly */
  void updateKingsPos();

  /* Function which scans through the current 'board' positions and checks whether the two kings are
     in-check or not; it updates the values of 'w_incheck' and 'b_incheck' accordingly */
  void updateInCheck();
  
  /* Helper function which takes as input the position of a piece of the team whose turn is
     and a reference to a matrix where it stores any illegal moves of that piece found in the function;
     If that piece has no legal moves, it also check 
     whether there are any legal moves for the other pieces of that team as well */
  void areLegalMoves(const int src_pos[], matrix &src_ill_mvs);

  /* Function called by 'areLegalMoves' to determine the legality of a hypothetical move;
     return true if the move is legal and false otherwise */
  bool isMoveLegal();

  /* Helper function that makes a copy of 'board' by assigning its current values to 'h_board';
     the latter is a hypothetical board which simulates possible moves to determine their legality 
     before completing a submitted move is function 'areLegalMoves' */
  void cloneBoard();

  /* Helper function which scans through the hypothetical board 'h_board' and stores the position
     of one of the kings in 'h_king_pos', depending on the colour specified in the input string */
  void updateHypKingPos(const string &colour);

  /* Helper function which takes as input the position of a piece of the team whose turn is
     and a reference to a matrix. After scanning through the 'board' it finds the positions
     of the team's pieces and stores them in the matrix (for reasons of efficiency in 'submitMove'
     it stores the input piece's position in the 0th index of the matrix) */
  void setPiecesPos(const int src_pos[], matrix &pcs_pos);

  /* Function which takes as input either 'board' or' h_board', the source and destination coordinates
     of a move and completes a real or hypothetical move accordingly */
  void makeMove(Piece* brd[][NUM_COLUMNS], int src_row, int src_col, int dst_row, int dst_col);

  /* Function which swaps the value of 'w_turn' which is true when Whites are taking their turn
     and false otherwise */
  void switchTurn();

  /* Fuction which takes as input the number of pieces which currently have no moves in a team and
     compares it with the overall number of pieces of that team which are currently in play;
     it then sets the value of game_end accordingly and outputs an appropriate end game message */
  void endGame(const int &no_mv_pcs, const int &num_pcs);

};

#endif
