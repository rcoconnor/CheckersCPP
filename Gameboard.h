#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Bitboard.h"

class Gameboard {
    private: 
        Bitboard lightPieces; 
        Bitboard blackPieces; 
    public:
        Gameboard();
        void printBoard();
        uint64_t getBlackPieces();
        uint64_t getLightPieces();
        static uint64_t ComputeBlackPieceValidMoves(uint64_t pieceLocation, uint64_t ownSide); 
        static uint64_t ComputeWhitePieceValidMoves(uint64_t pieceLocatoin, uint64_t ownSide); 
};

#endif



