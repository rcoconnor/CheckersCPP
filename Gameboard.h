#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Bitboard.h"

class Gameboard {
    private: 
        Bitboard redPieces; 
        Bitboard blackPieces; 
    public:
        Gameboard();
        void printBoard();
        uint64_t getRedPieces();
};

#endif



