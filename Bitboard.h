#ifndef BITBOARD_H 
#define BITBOARD_H

#include <iostream>
#include <stdint.h>

enum RANK {
    RANK_1,
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8
}; 

enum FILES {
    FILE_1,
    FILE_2,
    FILE_3,
    FILE_4,
    FILE_5,
    FILE_6,
    FILE_7,
    FILE_8
}; 



class Bitboard {
    private:     
    uint64_t board; 

    public: 
    Bitboard();
    Bitboard(uint64_t);  
    uint64_t getBoard(); 

    static uint64_t ClearRank[8];  
    static uint64_t ClearFile[8]; 
    static uint64_t MaskRank[8]; 
    static uint64_t MaskFile[8]; 

    static uint64_t Piece[64]; 

}; 



#endif
