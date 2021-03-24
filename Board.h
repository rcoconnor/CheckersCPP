#ifndef BOARD_H
#define BOARD_H

#include "Entity.h"
#include "BoardSquare.h"
#include <allegro5/allegro.h>

class Board: public Entity {
    public: 
        Board(ALLEGRO_BITMAP* light, ALLEGRO_BITMAP* dark);
        void update(); 
    protected:  
        BoardSquare** squares; 
     
}; 

#endif
