#ifndef BOARD_SQUARE_H
#define BOARD_SQUARE_H

#include "Entity.h"
#include <allegro5/allegro.h>

class BoardSquare: public Entity{
    public: 
        BoardSquare();
        BoardSquare(ALLEGRO_BITMAP* bmp, int x, int y, int w, int h); 
        void update(ALLEGRO_EVENT* event);  
                
}; 

#endif
