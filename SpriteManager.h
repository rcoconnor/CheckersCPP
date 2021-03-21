#ifndef SPRITE_MANAGER_H
#define SPRITE_MANAGER_H


#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class SpriteManager {
private: 
    ALLEGRO_BITMAP* square; 
    ALLEGRO_BITMAP* darkSquare; 
    ALLEGRO_BITMAP* lightSquare; 
    ALLEGRO_BITMAP* gameBoard; 
    
    ALLEGRO_BITMAP* pieces; 
    ALLEGRO_BITMAP* darkPiece;
    ALLEGRO_BITMAP* lightPiece; 

public: 
    SpriteManager(); 
    ~SpriteManager();  
    
    void init(); 

    ALLEGRO_BITMAP* getPiece(); 
    ALLEGRO_BITMAP* getSquare(); 
    
    ALLEGRO_BITMAP* getGameBoard(); 
    ALLEGRO_BITMAP* getDarkSquare(); 
    ALLEGRO_BITMAP* getLightSquare();
    
    ALLEGRO_BITMAP* getBlackPiece(); 
    ALLEGRO_BITMAP* getLightPiece(); 

    static int SQUARE_HEIGHT; 

   static void drawSpriteOnBoard(ALLEGRO_BITMAP* sprite, uint64_t board_state); 
};


#endif 
