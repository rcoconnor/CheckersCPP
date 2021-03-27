#include "Piece.h"
#include <iostream>


Piece::Piece() {
    std::cout << "piece constructor called" << std::endl;
}

Piece::Piece(ALLEGRO_BITMAP* bmp, int x, int y, int w, int h): Entity(x, y, w, h) {
    sprite = new Sprite(bmp, x, y, w, h);
    addComponent(sprite);
    
    clickComponent = new Clickable(x, y, w, h);
    addComponent(clickComponent); 
    wasClicked = false; 
}


void Piece::update(ALLEGRO_EVENT* event) {
    for (int i = 0; i < components.size(); i++) {
        components.at(i)->update(event); 
    } 
    if (clickComponent->getMouseIsOver() == true) {
        wasClicked = true; 
    } 
    if (wasClicked == true) {
        int x = clickComponent->getX(); 
        int y = clickComponent->getY(); 
        setNewPos(clickComponent->getX(), clickComponent->getY()); 
        sprite->setNewPos(x, y);  
    }
}

