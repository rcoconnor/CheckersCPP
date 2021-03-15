

checkers: main.o Bitboard.o 
	g++ main.o Bitboard.o GameBoard.o -Wall -o checkers

main.o: main.cpp Bitboard.o GameBoard.o  
	g++ main.cpp -Wall -c 


GameBoard.o: GameBoard.cpp GameBoard.h Bitboard.o
	g++ GameBoard.cpp -Wall -c 	

Bitboard.o: Bitboard.cpp Bitboard.h
	g++ Bitboard.cpp -Wall -c 


clean: 
	$(RM) checkers *.o
