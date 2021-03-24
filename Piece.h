#ifndef PIECE_H
#define PIECE_H

#include "Sprite.h"
#include "Entity.h"

class Piece: public Entity {
public: 
    Piece(); 
    Piece(ALLEGRO_BITMAP* bmp, int x, int y, int w, int h); 

protected: 
}; 


#endif
