#ifndef SPRITE_MANAGER_H
#define SPRITE_MANAGER_H


#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class SpriteManager {
private: 
    ALLEGRO_BITMAP* pieces; 
    ALLEGRO_BITMAP* square; 
    ALLEGRO_BITMAP* darkSquare; 
    ALLEGRO_BITMAP* lightSquare; 
public: 
    SpriteManager(); 
    ~SpriteManager();  
    
    void init(); 

    ALLEGRO_BITMAP* getPiece(); 
    ALLEGRO_BITMAP* getSquare(); 

    ALLEGRO_BITMAP* getDarkSquare(); 
    ALLEGRO_BITMAP* getLightSquare();
    static int SQUARE_HEIGHT; 
};


#endif 
