#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <vector>

#include "Gameboard.h"
#include "SpriteManager.h"
#include "Entity.h"
#include "Sprite.h"

class GameManager {
    private: 
        //Entity boardSquare; 
        std::vector<Entity*> entities; 
        
        Gameboard board; 
        ALLEGRO_DISPLAY * display;  
        ALLEGRO_EVENT_QUEUE * queue;
        ALLEGRO_TIMER* timer;  
        ALLEGRO_BITMAP* buffer; 
        SpriteManager spriteManager;
        void drawBitboardToScreen(uint64_t board); 
        
    public: 
        GameManager();
        ~GameManager(); 

        void init();
        void startGame();  
        ALLEGRO_EVENT_QUEUE* getQueue(); 
        //void drawBitmapToBoard(ALLEGRO_BITMAP* bmp, uint64_t board); 
        void updateGame(); 
        void drawBoardStateToScreen(ALLEGRO_BITMAP* target);

        void createBoard();


        static int WINDOW_WIDTH;
        static int WINDOW_HEIGHT;
}; 



#endif
