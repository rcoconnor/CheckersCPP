#ifndef PIECE_H
#define PIECE_H

#include "Sprite.h"
#include "Entity.h"
#include "Clickable.h"

class Piece: public Entity {
public: 
    Piece(); 
    Piece(ALLEGRO_BITMAP* bmp, int x, int y, int w, int h); 
    
    void update(ALLEGRO_EVENT* event);
    
protected:
    bool wasClicked; 
    Clickable* clickComponent; 
    Sprite* sprite; 
}; 


#endif
