#include "GameManager.h"
#include <iomanip>
#include "Piece.h"


/** constructor */ 
GameManager::GameManager() {
    //std::cout << "creating board " << std::endl;  
    gameboard = Gameboard();
}

/* Destructor */ 
GameManager::~GameManager() {
    al_destroy_event_queue(queue);  
    al_destroy_timer(timer); 
    al_destroy_display(display);
    al_uninstall_keyboard();
    al_uninstall_mouse(); 
    al_destroy_bitmap(buffer); 
}


void GameManager::placePieces(uint64_t darkPieces, uint64_t lightPieces) {
    std::cout << "pLaceing pieces" << std::endl; 
    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            if (( darkPieces & 1 ) == 1 ) {
                Piece* piece = new Piece(spriteManager.getBlackPiece(), j * 64, i * 64, 64, 64);
                entities.push_back(piece);
            } else if((lightPieces & 1) == 1) {
                Piece* piece = new Piece(spriteManager.getLightPiece(), j * 64, i * 64, 64, 64);
                entities.push_back(piece);
            }
            lightPieces = lightPieces >> 1;
            darkPieces = darkPieces >> 1; 
        } 
    }
}


// FIXME: there are multiple memory leaks which will have to be cleaned up 
void GameManager::createBoard() {
    Board* board = new Board(spriteManager.getLightSquare(), spriteManager.getDarkSquare()); 
    boardOnScreen = board; 
    entities.push_back(board); 
}


/* Initializes all parts of allegro */
void GameManager::init() {
    std::cout << "initting" << std::endl; 
    al_init(); 
    al_init_image_addon();
   
    spriteManager.init();
    
    display = al_create_display(WINDOW_WIDTH, WINDOW_HEIGHT);
    queue = al_create_event_queue(); 
    timer = al_create_timer(1.0 / 60.0);
   
    // fixme: have game write to buffer first //  
    buffer = al_create_bitmap(WINDOW_WIDTH, WINDOW_HEIGHT);

    al_install_keyboard();
    al_install_mouse(); 
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display)); 
    al_register_event_source(queue, al_get_timer_event_source(timer)); 
    al_register_event_source(queue, al_get_mouse_event_source()); 

    createBoard(); 
    placePieces(gameboard.getBlackPieces(), gameboard.getLightPieces()); 
} 


// start a game of checkers  
void GameManager::startGame(){
    bool running = true; 
    al_start_timer(timer);
    al_clear_to_color(al_map_rgb(0, 0, 0));  

    //updateGame();
    //al_flip_display();
    while (running) {
        ALLEGRO_EVENT event; 
        al_wait_for_event(queue, &event);
        updateGame(&event); 
        if (event.type == ALLEGRO_EVENT_TIMER) {
            //std::cout << "val: " << ALLEGRO_EVENT_MOUSE_BUTTON_DOWN << std::endl; 
            //updateGame(&event);
            al_flip_display();
        }
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false; 
        } 
    } 
}; 


void GameManager::updateGame(ALLEGRO_EVENT* event) {
    for (int i = 0; i < entities.size(); i++) {
        entities.at(i)->update(event); 
    }
}


// Debug function to allow visualizing of bitboards
// prints a bitboard to the screen 
/*void GameManager::drawBitboardToScreen(uint64_t board) {
    al_clear_to_color(al_map_rgba_f(255, 255, 255, 1)); 
    al_draw_bitmap(spriteManager.getGameBoard(), 0, 0, 0); 
    SpriteManager::drawSpriteOnBoard(spriteManager.getBlackPiece(), board); 
}*/

// get the event queue 
ALLEGRO_EVENT_QUEUE* GameManager::getQueue() {
    return queue; 
} 


// static variables 
int GameManager::WINDOW_WIDTH = 540; 
int GameManager::WINDOW_HEIGHT = 540; 
