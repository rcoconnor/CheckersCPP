#include "Sprite.h"
#include <iostream>

Sprite::Sprite(ALLEGRO_BITMAP* newSprite, int newX, int newY, int w, int h) {
    //std::cout << "Sprite constructor not implemeted yet" << std::endl; 
    sprite = newSprite; 
    xPos = newX; 
    yPos = newY; 
    height = h; 
    width = w; 
    type = "Sprite";     
}

void Sprite::setSprite(ALLEGRO_BITMAP* newSprite) {
    std::cout << "setting sprite" << std::endl; 
    if (sprite != NULL) {
        ALLEGRO_BITMAP* prev = sprite; 
        al_destroy_bitmap(prev);     
    } 
    sprite = newSprite; 
}

void Sprite::start() {
    std::cout << "not implemented yet" << std::endl; 
}

std::string Sprite::getType() {
    return type; 
}

void Sprite::setNewPos(int x, int y) {
    xPos = x; 
    yPos = y; 
}

void Sprite::update(ALLEGRO_EVENT* event) {
    al_draw_bitmap(sprite, xPos, yPos, 0); 
}


