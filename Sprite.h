#ifndef SPRITE_H
#define SPRITE_H

#include "Component.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Sprite: public Component {

    public: 
        Sprite(ALLEGRO_BITMAP* newSprite, int newX, int newY, int w, int h); 
        void start(); 
        void update(); 
        std::string getType(); 
        void setSprite(ALLEGRO_BITMAP* newSprite);  
 
    protected: 
        int xPos; 
        int yPos; 
        int width; 
        int height;
        std::string type; 
        ALLEGRO_BITMAP* sprite; 
}; 

#endif 



