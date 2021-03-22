
# 
# 'make depend' uses makedepend to automatically generate dependencies 
#               (dependencies are added to end of Makefile) 
# 'make' 		build executable file 'checkers'
# 'make clean'  removes all .o and executable files

# define the compiler to use
CC=g++ 

CFLAGS = -Wall

LIBS = -lallegro -lallegro_main -lallegro_image -lallegro_font -lallegro_ttf

SRCS = main.cpp GameManager.cpp Gameboard.cpp SpriteManager.cpp Bitboard.cpp Entity.cpp Component.cpp Sprite.cpp 
OBJS = GameManager.o Gameboard.o SpriteManager.o Bitboard.o Entity.o Component.o Sprite.o 
MAIN = checkers

checkers: main.o GameManager.o Gameboard.o SpriteManager.o Bitboard.o
	$(CC) $(CFLAGS) main.o $(OBJS) -o $(MAIN) $(LIBS) 

main.o: main.cpp $(OBJS)
	$(CC) $(CFLAGS) -c main.cpp 

GameManager.o: GameManager.h GameManager.cpp Entity.o Gameboard.o SpriteManager.o Sprite.o 
	$(CC) $(CFLAGS) -c GameManager.cpp 

Entity.o: Entity.h Entity.cpp Component.o 
	$(CC) $(CFLAGS) -c Entity.cpp 

Component.o: Component.h Component.cpp
	$(CC) $(CFLAGS) -c Component.cpp

Sprite.o: Component.o Sprite.cpp Sprite.h  
	$(CC) $(CFLAGS) -c Sprite.cpp

Gameboard.o: Gameboard.h Gameboard.cpp Bitboard.o
	$(CC) $(CFLAGS) -c Gameboard.cpp 

Bitboard.o: Bitboard.h Bitboard.cpp 
	$(CC) $(CFLAGS) -c Bitboard.cpp

SpriteManager.o: SpriteManager.h SpriteManager.cpp 
	$(CC) $(CFLAGS) -c SpriteManager.cpp

clean: 
	$(RM) *.o $(MAIN) 


# DO NOT DELETE THIS LINE -- makedepend needs it 
