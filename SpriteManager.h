#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class SpriteManager {
private: 
    ALLEGRO_BITMAP* piece; 
    ALLEGRO_BITMAP* square; 
public: 
    SpriteManager(); 
    ~SpriteManager();  
    static SpriteManager createSpriteManager();  
    

    ALLEGRO_BITMAP* getPiece(); 
    ALLEGRO_BITMAP* getSquare(); 
};



