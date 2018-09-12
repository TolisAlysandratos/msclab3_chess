chess: ChessMain.o ChessBoard.o Piece.o King.o Pawn.o Knight.o Rook.o Bishop.o Queen.o
	g++ ChessMain.o ChessBoard.o Piece.o King.o Pawn.o Knight.o Rook.o Bishop.o Queen.o -o chess

ChessMain.o: ChessMain.cpp ChessBoard.h helper.h
	g++ -Wall -g -c ChessMain.cpp

ChessBoard.o: ChessBoard.cpp ChessBoard.h helper.h
	g++ -Wall -g -c ChessBoard.cpp

Piece.o: Piece.cpp Piece.h helper.h
	g++ -Wall -g -c Piece.cpp

King.o: King.cpp King.h helper.h
	g++ -Wall -g -c King.cpp

Pawn.o: Pawn.cpp Pawn.h helper.h
	g++ -Wall -g -c Pawn.cpp

Knight.o: Knight.cpp Knight.h helper.h
	g++ -Wall -g -c Knight.cpp

Rook.o: Rook.cpp Rook.h helper.h
	g++ -Wall -g -c Rook.cpp

Bishop.o: Bishop.cpp Bishop.h helper.h
	g++ -Wall -g -c Bishop.cpp

Queen.o: Queen.cpp Queen.h helper.h
	g++ -Wall -g -c Queen.cpp
