#include <iostream>
#include <iomanip> 
#include "Bitboard.h"
#include "Gameboard.h"

#include <allegro5/allegro.h>

using namespace std; 

int main(int argc, char** argv) {
    al_init();  
    std::cout << "Hello world!" << std::endl; 

    Gameboard board = Gameboard();  
    board.printBoard();

    return 0; 
}




