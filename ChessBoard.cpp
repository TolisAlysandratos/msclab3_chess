/* ChessBoard Class Implementation */

#include <iostream>
#include <cassert>
#include <string>
using namespace std;

#include "ChessBoard.h"
#include "helper.h"

ChessBoard::ChessBoard() {
  game_end = false;
  w_turn = true;
  w_incheck = false;
  b_incheck = false;
  for (int r=0; r < NUM_RANKS; r++) {
    for(int c=0; c < NUM_COLUMNS; c++) {
      board[r][c] = NULL;
    }
  }
  board[0][0] = new Rook("Black");
  board[0][1] = new Knight("Black");
  board[0][2] = new Bishop("Black");
  board[0][3] = new Queen("Black");
  board[0][4] = new King("Black");
  board[0][5] = new Bishop("Black");
  board[0][6] = new Knight("Black");
  board[0][7] = new Rook("Black");
  for (int c=0; c < NUM_COLUMNS; c++)
    board[1][c] = new Pawn("Black");
  for (int c=0; c < NUM_COLUMNS; c++)
    board[6][c] = new Pawn("White");
  board[7][0] = new Rook("White");
  board[7][1] = new Knight("White");
  board[7][2] = new Bishop("White");
  board[7][3] = new Queen("White");
  board[7][4] = new King("White");
  board[7][5] = new Bishop("White");
  board[7][6] = new Knight("White");
  board[7][7] = new Rook("White");  
  cout << "A new chess game is started!" << endl;
}

void ChessBoard::resetBoard() {
  game_end = false;
  w_turn = true;
  w_incheck = false;
  b_incheck = false;  
  for (int r=0; r < NUM_RANKS; r++) {
    for(int c=0; c < NUM_COLUMNS; c++) {
      delete board[r][c];
    }
  }
  for (int r=0; r < NUM_RANKS; r++) {
    for(int c=0; c < NUM_COLUMNS; c++) {
      board[r][c] = NULL;
    }
  }
  board[0][0] = new Rook("Black");
  board[0][1] = new Knight("Black");
  board[0][2] = new Bishop("Black");
  board[0][3] = new Queen("Black");
  board[0][4] = new King("Black");
  board[0][5] = new Bishop("Black");
  board[0][6] = new Knight("Black");
  board[0][7] = new Rook("Black");
  for (int c=0; c < NUM_COLUMNS; c++)
    board[1][c] = new Pawn("Black");
  for (int c=0; c < NUM_COLUMNS; c++)
    board[6][c] = new Pawn("White");
  board[7][0] = new Rook("White");
  board[7][1] = new Knight("White");
  board[7][2] = new Bishop("White");
  board[7][3] = new Queen("White");
  board[7][4] = new King("White");
  board[7][5] = new Bishop("White");
  board[7][6] = new Knight("White");
  board[7][7] = new Rook("White");  
  cout << "A new chess game has started!" << endl;
}

int ChessBoard::submitMove(const string &source, const string &dest) {

  // checks if the game is over
  if (game_end) {
    cerr << "Game has ended. Reset board to start a new game." << endl;
    return GAME_END;
  }
  
  // checks source and destination input strings
  if (!isValidString(source)) {
    cerr << "(invalid source position string)" << endl;
    return INVALID_INPUT;
  }
  if (!isValidString(dest)) {
    cerr << "(invalid destination position string)" << endl;
    return INVALID_INPUT;
  }
  
  // converts input string to coordinates for the 2D array 'board'
  int s_pos[2];
  int d_pos[2];
  strToPos(source, s_pos);
  strToPos(dest, d_pos);
  
  // checks if source position is empty
  if (board[s_pos[0]][s_pos[1]] == NULL) {
    cerr << "There is no piece at position " << source << "!" << endl;
    return NO_PIECE;
  }  
  
  Piece* s_piece = board[s_pos[0]][s_pos[1]];
  string s_colour = s_piece->getColour();
  string s_type = s_piece->getType();
  
  // checks which team's turn it is to move
  if ((s_colour == "Black" && w_turn)
      || (s_colour == "White" && !w_turn)) {
    cerr << "It is not " << s_colour << "'s turn to move!" << endl;
    return NOT_TURN;
  }

  // checks if the source position is the same as the destination
  if (source == dest) {
    cerr << "Destination position same as source!" << endl;
    return ILLEGAL_MOVE;
  }

  // check if submitted move is possible
  matrix s_possible_mvs;
  board[s_pos[0]][s_pos[1]]->possibleMoves(board, s_pos[0], s_pos[1], s_possible_mvs);
  bool is_possible = false;
  for (int i=0; i < (int)s_possible_mvs.size(); i++) {
    if (d_pos[0] == s_possible_mvs[i][0] && d_pos[1] == s_possible_mvs[i][1]) {
      is_possible = true;
    }
  }
  if (!is_possible) {
    cerr << s_colour << "'s " << s_type
	 << " cannot move to " << dest << "!" << endl;
    return ILLEGAL_MOVE;
  }
  
  updateKingsPos();

  matrix s_illegal_mvs;
  areLegalMoves(s_pos, s_illegal_mvs);
  if (game_end)
    return GAME_END;
  
  // check if submitted move is legal
  for (int i=0; i < (int)s_illegal_mvs.size(); i++) {
    if (d_pos[0] == s_illegal_mvs[i][0] && d_pos[1] == s_illegal_mvs[i][1]) {
      cerr << s_colour << "'s " << s_type
	   << " cannot move to " << dest << "!" << endl;
      return ILLEGAL_MOVE;
    }
  }

  makeMove(board, s_pos[0], s_pos[1], d_pos[0], d_pos[1]);
  updateInCheck();
  
  // if moving piece was a king, update its position on the board
  if (s_type == "King") {
    updateKingsPos();
  }

  switchTurn();

  // checks for game end condition after the submitted move is completed
  int af_pos[2];
  for (int r=0; r < NUM_RANKS; r++) {
    for (int c=0; c < NUM_COLUMNS; c++) {
      if (board[r][c] != NULL
	  && board[r][c]->getColour() != s_colour) {
	af_pos[0] = r;
	af_pos[1] = c;
	break;
      }
    }
  }

  // checks if there are legal moves for the team whose turn is next
  matrix af_s_illegal_mvs;
  areLegalMoves(af_pos, af_s_illegal_mvs);
  if (game_end)
    return GAME_END;
  if (w_incheck)
    cout << "White is in check" << endl;
  if (b_incheck)
    cout << "Black is in check" << endl;
  return NO_ERROR;
}

bool ChessBoard::isValidString(const string &str_pos) {
  if (str_pos.length() < POS_LEN) {
    cerr << "Error: input string too short! ";
    return false;
  }
  if (str_pos.length() > POS_LEN) {
    cerr << "Error: input string too long! ";
    return false;
  }
  if (!(str_pos[0] >= 65 && str_pos[0] <= 72)) {
    cerr << "Error: first character needs to be a letter between A-H!";
    return false;
  }
  if (!(str_pos[1] >= 48 && str_pos[1] <= 56)) {
    cerr << "Error: second character needs to be a digit between 1-8!";
    return false;
  }
  
  return true;
}

void ChessBoard::strToPos(const string &str_pos, int pos[]) {
  for (int r=0; r < NUM_RANKS; r++) {
    for (int c=0; c < NUM_COLUMNS; c++) {
      if (RANKS[r] == str_pos[1])
	pos[0] = r;
      if (FILES[c] == str_pos[0])
	pos[1] = c;
    }
  } 
}

void ChessBoard::updateKingsPos() {
  for (int r=0; r < NUM_RANKS; r++) {
    for(int c=0; c < NUM_COLUMNS; c++) {
      if (board[r][c] != NULL
	  && board[r][c]->getType() == "King") {
	if (board[r][c]->getColour() == "White") {
	  wking_pos[0] = r;
	  wking_pos[1] = c;
	}
	if (board[r][c]->getColour() == "Black") {
	  bking_pos[0] = r;
	  bking_pos[1] = c;
	}
      }
    }
  }
}

void ChessBoard::updateInCheck() {
  b_incheck = false;
  for (int r=0; r<NUM_RANKS; r++) {
    for (int c=0; c<NUM_COLUMNS; c++) {
      if (board[r][c] != NULL
	  && board[r][c]->getColour() == "White") {
	matrix possible_mvs;
	board[r][c]->possibleMoves(board, r, c, possible_mvs);
	for (int i=0; i < (int)possible_mvs.size(); i++) {
	  if (possible_mvs[i][0] == bking_pos[0]
	      && possible_mvs[i][1] == bking_pos[1]) {
	    b_incheck = true;
	  }
	}
      }
    }
  }
  w_incheck = false;
  for (int r=0; r<NUM_RANKS; r++) {
    for (int c=0; c<NUM_COLUMNS; c++) {
      if (board[r][c] != NULL
	  && board[r][c]->getColour() == "Black") {
	matrix possible_mvs;
	board[r][c]->possibleMoves(board, r, c, possible_mvs);
	for (int i=0; i < (int)possible_mvs.size(); i++) {
	  if (possible_mvs[i][0] == wking_pos[0]
	      && possible_mvs[i][1] == wking_pos[1]) {
	    w_incheck = true;
	  }
	}
      }
    }
  }
}

void ChessBoard::areLegalMoves(const int src_pos[], matrix &src_ill_mvs) {
  string src_clr = board[src_pos[0]][src_pos[1]]->getColour();
  matrix pcs_pos;
  setPiecesPos(src_pos, pcs_pos);
  int num_pcs = (int)pcs_pos.size();
  int no_mv_pcs = 0;
  // for every piece in the moving team, find if there are any legal moves
  for (int p=0; p < num_pcs; p++) {
    int p_r = pcs_pos[p][0];
    int p_f = pcs_pos[p][1];
    string p_typ = board[p_r][p_f]->getType();
    matrix p_poss_mvs;
    board[p_r][p_f]->possibleMoves(board, p_r, p_f, p_poss_mvs);
    int num_poss_mvs = (int)p_poss_mvs.size();
    matrix p_ill_mvs;
    int num_p_ill_mvs = 0;
    for (int i=0; i < num_poss_mvs; i++) {
      cloneBoard();
      updateHypKingPos(src_clr);
      makeMove(h_board, p_r, p_f, p_poss_mvs[i][0], p_poss_mvs[i][1]);
      if (p_typ == "King") {
	updateHypKingPos(src_clr);
      }
      if (!isMoveLegal()) {
	num_p_ill_mvs++;
	p_ill_mvs.push_back(p_poss_mvs[i]);
      }
    }
    // check if all possible moves of a piece are illegal
    if (num_poss_mvs != num_p_ill_mvs) {
      // store any illegal moves of the source piece submitted for move
      if (p == 0)
	src_ill_mvs = p_ill_mvs;
      // no need to check the rest of the pieces if the source piece has legal moves
      break;
    }
    // if the source piece has no legal moves, check the other pieces of the team for legal moves
    no_mv_pcs += 1;
  }
  // if no piece of the source piece's team has legal moves, check for the end game conditions
  endGame(no_mv_pcs, num_pcs);
}

bool ChessBoard::isMoveLegal() {
  string colour = h_board[h_king_pos[0]][h_king_pos[1]]->getColour();
  /* Finds the oppenent's pieces possible moves and compares with the moving team's
     King's position on the hypothetical board */
  for (int r=0; r < NUM_RANKS; r++) {
    for (int c=0; c < NUM_COLUMNS; c++) {
      if (h_board[r][c] != NULL && h_board[r][c]->getColour() != colour) {
	matrix opp_possible_mvs;
	h_board[r][c]->possibleMoves(h_board, r, c, opp_possible_mvs);
	int num_opp_mvs = (int)opp_possible_mvs.size();
	for (int i=0; i < num_opp_mvs; i++) {
	  // case where an oppenent's possible move matches the moving team's King position */
	  if (opp_possible_mvs[i][0] == h_king_pos[0] && opp_possible_mvs[i][1] == h_king_pos[1]) {
	    return false;
	  }
	}      
      }
    }
  }
  // case where non of the oppenent's possible moves matches the moving team's King position*/
  return true;
}

void ChessBoard::cloneBoard() {
  for (int r=0; r<NUM_RANKS; r++) {
    for(int c=0; c<NUM_COLUMNS; c++) {
      h_board[r][c] = board[r][c];
    }
  }
}

void ChessBoard::updateHypKingPos(const string &colour) {
  for (int r=0; r < NUM_RANKS; r++) {
    for(int c=0; c < NUM_COLUMNS; c++) {
      if (h_board[r][c] != NULL
	  && h_board[r][c]->getType() == "King") {
	if (h_board[r][c]->getColour() == colour) {
	  h_king_pos[0] = r;
	  h_king_pos[1] = c;
	}
      }
    }
  }
}

void ChessBoard::setPiecesPos(const int src_pos[], matrix &pcs_pos) {
  // adds source piece in 0th index of pcs_pos
  vector<int> pos_0;
  pos_0.push_back(src_pos[0]);
  pos_0.push_back(src_pos[1]);
  pcs_pos.push_back(pos_0);
  string colour = board[src_pos[0]][src_pos[1]]->getColour();
  // then adds the rest of the pieces
  for (int r=0; r < NUM_RANKS; r++) {
    for(int c=0; c < NUM_COLUMNS; c++) {
      if (board[r][c] != NULL
	  && board[r][c]->getColour() == colour
	  && !(r == src_pos[0] && c == src_pos[1])) {
	vector<int> pos;
	pos.push_back(r);
	pos.push_back(c);
	pcs_pos.push_back(pos);
      }
    }
  }
}

void ChessBoard::makeMove(Piece* brd[][NUM_COLUMNS],
			  int src_row, int src_col,
			  int dst_row, int dst_col) {
  string src_type = brd[src_row][src_col]->getType();
  string src_colour = brd[src_row][src_col]->getColour();
  stringstream ss;
  if (brd[dst_row][dst_col] != NULL) {
    string dest_colour = brd[dst_row][dst_col]->getColour();
    string dest_type = brd[dst_row][dst_col]->getType();
    ss << " taking " << dest_colour << "'s " << dest_type;
    if (brd == board) {
      delete brd[dst_row][dst_col];
    }
  }
  if (brd == board) {
    cout << src_colour << "'s " << src_type
	 << " moves from " << FILES[src_col] <<  RANKS[src_row]
	 << " to " << FILES[dst_col] << RANKS[dst_row] << ss.str() << endl;
  }
  brd[dst_row][dst_col] = brd[src_row][src_col];
  brd[src_row][src_col] = NULL;
}

void ChessBoard::endGame(const int &no_mv_pcs, const int &num_pcs) {
  if (no_mv_pcs == num_pcs) {
    game_end = true;
    if (w_turn && w_incheck) {
      cout << "White is in checkmate" << endl;
    }
    if (!w_turn && b_incheck) {
      cout << "Black is in checkmate" << endl;
    }
    if (w_turn && !w_incheck) {
      cout << "White has no legal move left. Game ends in stalemate." << endl;
    }
    if (!w_turn && !b_incheck) {
      cout << "Black has no legal moves left. Game ends in stalemate." << endl;
    }
  }
}


void ChessBoard::switchTurn() {
  if (w_turn) {
    w_turn = false;
    return;
  }
  w_turn = true;
  return;
}

ChessBoard::~ChessBoard() {
  for (int r=0; r<NUM_RANKS; r++) {
    for(int c=0; c<NUM_COLUMNS; c++) {
      delete board[r][c];
    }
  }
}
