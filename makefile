

checkers: main.o Bitboard.o SpriteManager.o Gameboard.o GameManager.o 
	g++ main.o Bitboard.o GameBoard.o GameManager.o SpriteManager.o -Wall -o checkers -lallegro -lallegro_main -lallegro_image -lallegro_font -lallegro_ttf

main.o: main.cpp Bitboard.o Gameboard.o SpriteManager.o GameManager.o 
	g++ main.cpp -Wall -c 

GameManager.o: GameManager.cpp GameManager.h  GameBoard.o SpriteManager.o 
	g++ GameManager.cpp -Wall -c 

Gameboard.o: Gameboard.cpp Gameboard.h Bitboard.o
	g++ GameBoard.cpp -Wall -c 	

SpriteManager.o: SpriteManager.cpp SpriteManager.h Bitboard.o
	g++ SpriteManager.cpp -Wall -c 

Bitboard.o: Bitboard.cpp Bitboard.h
	g++ Bitboard.cpp -Wall -c 

clean: 
	$(RM) checkers *.o
