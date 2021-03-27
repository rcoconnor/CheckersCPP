#include "Board.h"
#include "Sprite.h" 
#include "Bitboard.h"

//const int BOARD_SIZE = 64;


Board::Board(ALLEGRO_BITMAP* light, ALLEGRO_BITMAP* dark) {
    std::cout << "creating board" << std::endl; 
    
    squares = new BoardSquare*[64];
    uint64_t darkSquares = Bitboard::DARK_SQUARES;  
    int count = 0;  
    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            if (( darkSquares & 1 ) == 1) {
                squares[count] = new BoardSquare(dark, j * 64, i * 64, 64, 64); 
            } else { 
                squares[count] = new BoardSquare(light, j * 64, i * 64, 64, 64);  
            }
            darkSquares = darkSquares >> 1; 
            count++; 
        }
    }
    std::cout << "created the frist square" << std::endl;
}


void Board::update(ALLEGRO_EVENT* event) {
    //std::cout << "update board called" << std::endl;
    for (int i = 0; i < 64; i++) {
        squares[i]->update(event); 
    }
}




