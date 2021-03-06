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
#include "Board.h"

class GameManager {
    private: 
        //Entity boardSquare; 
        std::vector<Entity*> entities; 
        
        Gameboard gameboard; 
        ALLEGRO_DISPLAY * display;  
        ALLEGRO_EVENT_QUEUE * queue;
        ALLEGRO_TIMER* timer;  
        ALLEGRO_BITMAP* buffer; 
        SpriteManager spriteManager;
        void drawBitboardToScreen(uint64_t board); 

        Board* boardOnScreen; 
        //Piece* PiecesOnScreen;
    public: 
        GameManager();
        ~GameManager(); 

        void init();
        void startGame();  
        ALLEGRO_EVENT_QUEUE* getQueue(); 
        //void drawBitmapToBoard(ALLEGRO_BITMAP* bmp, uint64_t board); 
        void updateGame(ALLEGRO_EVENT* event); 
        void drawBoardStateToScreen(ALLEGRO_BITMAP* target);

        void createBoard();
        Entity* createGameSquare(ALLEGRO_BITMAP* bmp, int x, int y, int w);
        void placePieces(uint64_t darkPieces, uint64_t lightPieces); 

        static int WINDOW_WIDTH;
        static int WINDOW_HEIGHT;
}; 



#endif
