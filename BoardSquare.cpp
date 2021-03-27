#include "BoardSquare.h"
#include <iostream>
#include "Sprite.h"
#include "Clickable.h"

BoardSquare::BoardSquare() {
    std::cout << "constructor called" << std::endl; 
}


BoardSquare::BoardSquare(ALLEGRO_BITMAP* bmp, int x, int y, int w, int h): Entity(x, y, w, h) {
    //std::cout << "creating boardSquare" << std::endl;  
    Sprite* theSprite = new Sprite(bmp, x, y, w, h);
    addComponent(theSprite);
    //std::cout << "created sprite" << std::endl; 

    Clickable* clickBox = new Clickable(x, y, w, h);
    addComponent(clickBox); 
}

// Overwritten virtual function 
void BoardSquare::update(ALLEGRO_EVENT* event) {
    for (int i = 0; i < components.size(); i++) {
        components.at(i)->update(event);  
    }
}

