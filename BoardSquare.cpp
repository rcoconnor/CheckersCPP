#include "BoardSquare.h"
#include <iostream>
#include "Sprite.h"

BoardSquare::BoardSquare() {
    std::cout << "constructor called" << std::endl; 
}


BoardSquare::BoardSquare(ALLEGRO_BITMAP* bmp, int x, int y, int w, int h): Entity(x, y, w, h) {
    //std::cout << "creating boardSquare" << std::endl;  
    Sprite* theSprite = new Sprite(bmp, x, y, w, h);
    addComponent(theSprite);
    //std::cout << "created sprite" << std::endl; 
}

void BoardSquare::update() {
    //std::cout << "BoardSquare update called" << std::endl; 
    for (int i = 0; i < components.size(); i++) {
        components.at(i)->update();  
    }
}

