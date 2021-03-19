#include "GameManager.h"
#include <iomanip>

/** constructor */ 
GameManager::GameManager() {
    //std::cout << "creating board " << std::endl;  
    board = Gameboard();
}

/* Destructor */ 
GameManager::~GameManager() {
    al_destroy_event_queue(queue);  
    al_destroy_timer(timer); 
    al_destroy_display(display);
    al_uninstall_keyboard();
    al_destroy_bitmap(buffer); 
}


/* Initializes all parts of allegro */
void GameManager::init() {
    //std::cout << "initting" << std::endl; 
    al_init(); 
    al_init_image_addon();
   
    spriteManager.init();
    

    display = al_create_display(WINDOW_WIDTH, WINDOW_HEIGHT);
    queue = al_create_event_queue(); 
    timer = al_create_timer(1.0 / 60.0);
   
    // fixme: have game write to buffer first //  
    buffer = al_create_bitmap(WINDOW_WIDTH, WINDOW_HEIGHT);

    al_install_keyboard();
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display)); 
    al_register_event_source(queue, al_get_timer_event_source(timer)); 
    //board.printBoard();
    //std::cout << "--------init done--------" << std::endl; 
} 

// start a game of checkers  
void GameManager::startGame(){
    bool running = true; 
    //std::cout << "Light: " << std::setfill('0') << std::setw(64) << std::bitset<64>(Bitboard::LIGHT_SQUARES) << std::endl;   
    //std::cout << "Dark : " << std::setfill('0') << std::setw(64) << std::bitset<64>(Bitboard::RED_SQUARES) << std::endl;   
    al_start_timer(timer);
    while (running) {
        al_clear_to_color(al_map_rgba_f(0, 0, 0, 1)); 
        //x += 0.1; 
        //al_draw_bitmap_region(spriteManager.getSquare(), 0, 0, 32,32, 0, 0, 0);      
        al_draw_bitmap(spriteManager.getGameBoard(), 0, 0, 0);  
        SpriteManager::drawSpriteOnBoard(spriteManager.getDarkPiece(), board.getRedPieces());  
        al_flip_display();
        ALLEGRO_EVENT event; 
        al_wait_for_event(queue, &event); 
        if (event.type == ALLEGRO_EVENT_TIMER) {
            std::cout << "timer ending" << std::endl;  
            al_flip_display();
        }
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false; 
        }
    }
}; 


// get the event queue 
ALLEGRO_EVENT_QUEUE* GameManager::getQueue() {
    return queue; 
} 


// static variables 
int GameManager::WINDOW_WIDTH = 540; 
int GameManager::WINDOW_HEIGHT = 540; 
