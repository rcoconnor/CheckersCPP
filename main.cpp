#include <iostream>
#include <iomanip> 

#include "GameManager.h"

//using namespace std; 

int main(int argc, char** argv) {
    std::cout << "creating game manager" << std::endl; 
    GameManager manager = GameManager();
    manager.init(); 
    
    std::cout << "calling start game" << std::endl;
    manager.startGame(); 
    
    std::cout << "Hello world!" << std::endl; 

    return 0; 
}




