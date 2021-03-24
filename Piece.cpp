#include "Piece.h"
#include <iostream>


Piece::Piece() {
    std::cout << "piece constructor called" << std::endl;
}

Piece::Piece(ALLEGRO_BITMAP* bmp, int x, int y, int w, int h): Entity(x, y, w, h) {
    Sprite* sprite = new Sprite(bmp, x, y, w, h);
    addComponent(sprite); 
}



