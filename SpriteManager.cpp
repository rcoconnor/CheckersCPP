#include "SpriteManager.h"

SpriteManager::SpriteManager() {
    piece = al_load_bitmap("images/image.png"); assert(piece != NULL); 
    square = al_load_bitmap("images/wood.png"); assert(square != NULL);   
}


SpriteManager::~SpriteManager() {
    return;
}

SpriteManager SpriteManager::createSpriteManager() {
    SpriteManager* spriteManagerPtr = new SpriteManager();
    return *spriteManagerPtr; 
}

ALLEGRO_BITMAP* SpriteManager::getSquare() {
    return square; 
}


ALLEGRO_BITMAP*  SpriteManager::getPiece() {
    return piece; 
}
