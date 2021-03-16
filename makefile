

checkers: main.o Bitboard.o SpriteManager.o 
	g++ main.o Bitboard.o GameBoard.o SpriteManager.o -Wall -o checkers -lallegro -lallegro_main -lallegro_image -lallegro_font -lallegro_ttf

main.o: main.cpp Bitboard.o GameBoard.o SpriteManager.o   
	g++ main.cpp -Wall -c 


GameBoard.o: GameBoard.cpp GameBoard.h Bitboard.o
	g++ GameBoard.cpp -Wall -c 	

Bitboard.o: Bitboard.cpp Bitboard.h
	g++ Bitboard.cpp -Wall -c 

SpriteManager.o: SpriteManager.cpp SpriteManager.h
	g++ SpriteManager.cpp -Wall -c 


clean: 
	$(RM) checkers *.o
