#include <iostream>
#include <iomanip> 
#include "Bitboard.h"
#include "Gameboard.h"



using namespace std; 

int main(int argc, char** argv) {
    std::cout << "Hello world!" << std::endl; 

    Gameboard board = Gameboard();  
    board.printBoard();

    return 0; 
}




