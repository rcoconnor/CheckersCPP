#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

#include "Gameboard.h"
#include "SpriteManager.h"

class GameManager {
    private: 
        Gameboard board; 
        ALLEGRO_DISPLAY * display;  
        ALLEGRO_EVENT_QUEUE * queue;
        ALLEGRO_TIMER* timer;  
        ALLEGRO_BITMAP* buffer; 

        SpriteManager spriteManager; 
        
    public: 
        GameManager();
        ~GameManager(); 

        void init();
        void startGame();  
        ALLEGRO_EVENT_QUEUE* getQueue(); 
        //void drawBitmapToBoard(ALLEGRO_BITMAP* bmp, uint64_t board); 

        static int WINDOW_WIDTH;
        static int WINDOW_HEIGHT;
}; 



#endif
