/* ChessMain */

#include <iostream>
#include <string>

using namespace std;

#include "helper.h"
#include "ChessBoard.h"

int main() {

  cout << "===========================" << endl;
  cout << "Testing the Chess Engine" << endl;
  cout << "===========================" << endl;
  cout << endl;
  ChessBoard cb;
  cout << endl;
  /*
  cout << "===========================" << endl;
  cout << "Stalemate test" << endl;
  cout << "===========================" << endl;
  cout << endl;
  
  ChessBoard cb;
  cout << endl;
  //cb.submitMove("E1", "F1");

  cb.submitMove("E2", "E3");
  cout << endl;
  cb.submitMove("A7", "A5");
  cout << endl;
  cb.submitMove("D1", "H5");
  cout << endl;
  cb.submitMove("A8", "A6");
  cout << endl;
  cb.submitMove("H5", "A5");
  cout << endl;
  cb.submitMove("H7", "H5");
  cout << endl;
  cb.submitMove("H2", "H4");
  cout << endl;
  cb.submitMove("A6", "H6");
  cout << endl;
  cb.submitMove("A5", "C7");
  cout << endl;
  cb.submitMove("F7", "F6");
  cout << endl;
  cb.submitMove("C7", "D7");
  cout << endl;
  cb.submitMove("E8", "F7");
  cout << endl;
  cb.submitMove("D7", "B7");
  cout << endl;
  cb.submitMove("D8", "D3");
  cout << endl;
  cb.submitMove("B7", "B8");
  cout << endl;
  cb.submitMove("D3", "H7");
  cout << endl;
  cb.submitMove("B8", "C8");
  cout << endl;
  cb.submitMove("F7", "G6");
  cout << endl;
  cb.submitMove("C8", "E6");
  cout << endl;

  */
  

  
  /*
  cout << "Testing strToPos()..." << endl;
  int pos[2];
  strToPos("A1", pos);
  cout << "A1-> (" << pos[0] << ", " << pos[1] << ")" << endl;
  strToPos("A8",  pos);
  cout << "A8-> (" << pos[0] << ", " << pos[1] << ")" << endl;
  strToPos("H1", pos);
  cout << "H1-> (" << pos[0] << ", " << pos[1] << ")" << endl;
  strToPos("H8", pos);
  cout << "H8-> (" << pos[0] << ", " << pos[1] << ")" << endl;
  strToPos("D5", pos);
  cout << "D5-> (" << pos[0] << ", " << pos[1] << ")" << endl;
  cout << endl;
  */
  /*
  cout << "Testing validString() in ChessBoard::sumbitMove(s,d)..." << endl;
  cb.submitMove("D13", "D2");
  cb.submitMove("D1", "D22");
  cb.submitMove("D", "D2");
  cb.submitMove("A2", "2");
  cout << endl;
  cb.submitMove("21", "D2");
  cb.submitMove("D@", "D1");
  cb.submitMove("D8", "/2");
  cb.submitMove("A2", "AI");
  cout << endl;

  cout << "test abs: " << abs(-7) << endl;
  cout << endl;
  cout << "Test error: No piece at position..." << endl;
  cb.submitMove("A3", "E7");
  cb.submitMove("A6", "D4");
  cb.submitMove("H6", "D4");
  cb.submitMove("H3", "D4");
  cout << endl;
  cout << "Test error: Destination same as source..." << endl;
  cb.submitMove("E1", "E1");
  cout << endl;
  cout << "Test error: Not turn..." << endl;
  cb.submitMove("E8", "E8");
  cout << endl;
  cout << "Test error: Cannot move to (piece cannot do that type of move)..." << endl;
  cb.submitMove("E1", "E3");
  cb.submitMove("E2", "F2");
  cb.submitMove("A2", "A5");
  cout << endl;
*/
  /*
  cout << "Test capturing an opponent's piece and HYPOBOARD!..." << endl;
  cb.printBoard();
  cout << endl;
  //cb.submitMove("E1", "D2"); for w king at position 7 4
  // cb.submitMove("F1", "E1"); TEST 1
  //TEST 2 STALEMATE 3 CHECKMATE
  cb.submitMove("E7", "E8");
  cb.submitMove("G3", "G2");
  cb.submitMove("H1", "G2"); // TEST 2 STALEMATE
  */
  // TEST knight
  //cb.submitMove("E5", "C4");
  //cb.submitMove("E5", "C5");// test wrong move
  //cb.submitMove("F7", "G1");// test rook
  //cb.submitMove("D3", "C4"); // bishop 1
  //cb.submitMove("E4", "B1"); // bishop 2
  //cb.submitMove("G4", "C8"); // queen 1
  /*
  cb.submitMove("E5", "C6");
  cb.submitMove("E5", "D7");
  cb.submitMove("E5", "F7");
  cb.submitMove("E5", "G6");
  cb.submitMove("E5", "G4");
  cb.submitMove("E5", "D3");
  cb.submitMove("E5", "F3");
    
  cb.printBoard();
  cout << endl;
  */  

  /*
  

  cout << "Test ChessBoard::getKingPos()..." << endl;
  int r,c;
  cb.getKingPos("White", r, c);
  cout << "King's new pos " << r << " " << c << endl;
  cout << "Testing ChessBoard::printBoard()..." << endl;
  cb.printBoard();
  cout << endl;

  // this next!
  cout << "Testing king in-check functionality..." << endl;
  cb.submitMove("C4", "C3");
  cout << "Testing ChessBoard::printBoard()..." << endl;
  cb.printBoard();
  cout << endl;
    
  cout << "Test error: Cannot move to (dest occupied by same col{our)..." << endl;
  cb.submitMove("D2", "E2");
  cout << "Testing ChessBoard::printBoard()..." << endl;
  cb.printBoard();
  cout << endl;

  cb.submitMove("E2", "E3");
  cout << "Testing ChessBoard::printBoard()..." << endl;
  cb.printBoard();
  cout << endl;
  
  cout << "Test black king move..." << endl;
  cb.submitMove("E8", "F8");
  cout << "Testing ChessBoard::printBoard()..." << endl;
  cb.printBoard();
  cout << endl;


  cout << "TEST CHESSBOARD POINTER!!" << endl;
  */
  //++++++++++++++++++++++++++++++++++++++++++
    
  
    cb.submitMove("D7", "D6");
    cout << endl;

    cb.submitMove("D4", "H6");
    cout << endl;

    cb.submitMove("D2", "D4");
    cout << endl;

    cb.submitMove("F8", "B4");
    cout << endl;

    cout << "===========================" << endl;
    cout << "Alekhine vs. Vasic (1931)" << endl;
    cout << "===========================" << endl;
    cout << endl;

    //cb.printBoard();
    cb.resetBoard();
    cout << endl;

    cb.submitMove("E2", "E4");
    cb.submitMove("E7", "E6");
    cout << endl;

    cb.submitMove("D2", "D4");
    cb.submitMove("D7", "D5");
    cout << endl;

    cb.submitMove("B1", "C3");
    cb.submitMove("F8", "B4");
    cout << endl;

    cb.submitMove("F1", "D3");
    cb.submitMove("B4", "C3");
    cout << endl;

    cb.submitMove("B2", "C3");
    cb.submitMove("H7", "H6");
    cout << endl;

    cb.submitMove("C1", "A3");
    cb.submitMove("B8", "D7");
    cout << endl;

    cb.submitMove("D1", "E2");
    cb.submitMove("D5", "E4");
    cout << endl;

    cb.submitMove("D3", "E4");
    cb.submitMove("G8", "F6");
    cout << endl;

    cb.submitMove("E4", "D3");
    cb.submitMove("B7", "B6");
    cout << endl;

    cb.submitMove("E2", "E6");
    cb.submitMove("F7", "E6");
    cout << endl;

    cb.submitMove("D3", "G6");
    cout << endl;

    //cb.printBoard();
    //  */
 
    
  //*/
  return 0;
}
