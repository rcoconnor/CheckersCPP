#include "Gameboard.h"
#include <string>
#include <iomanip>


Gameboard::Gameboard() {
    redPieces =   0x000000000055aa55;  
    blackPieces = 0xaa55aa0000000000;  
}


/* static helper function, prints the board*/ 
void Gameboard::printBoard() {
    uint64_t tempBoard = this->redPieces.getBoard() | this->blackPieces.getBoard();   
    uint64_t shift = tempBoard << 1;  
    std::cout << "temp : " << std::setfill('0') << std::setw(64) << std::bitset<64>( tempBoard ) << std::endl;  
    std::cout << "shift: " << std::setfill('0') << std::setw(64) << std::bitset<64>( shift ) << std::endl;  

    std::string buffer = " ";  
    for (int i = 0; i < 64; i++) {
        // get the first digit by masking it
        uint64_t firstDigit = tempBoard & 1;
        //std::cout << "first: " << firstDigit << std::endl;  
        if (i % 8 == 0 && i != 0) {
            buffer += "\n "; 
        } 
        
        if (firstDigit == 1) {
            buffer += "R "; 
        } else {
            buffer += "* "; 
        }
        
        tempBoard = tempBoard >> 1; 
    }
    std::cout << buffer << std::endl; 
}



