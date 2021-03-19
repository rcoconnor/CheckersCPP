#include "GameManager.h"
#include <iomanip>

/** constructor */ 
GameManager::GameManager() {
    std::cout << "creating board " << std::endl;  
    board = Gameboard();
}

/* Destructor */ 
GameManager::~GameManager() {
    al_destroy_display(display);
    al_uninstall_keyboard();
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
    
    al_install_keyboard();
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display)); 
    al_register_event_source(queue, al_get_timer_event_source(timer)); 
    board.printBoard();
    std::cout << "--------init done--------" << std::endl; 
} 

// start a game of checkers  
void GameManager::startGame(){
    bool running = true; 
    while (running) {
        al_clear_to_color(al_map_rgba_f(0, 0, 0, 1)); 
        //x += 0.1; 

        //al_draw_bitmap_region(spriteManager.getSquare(), 0, 0, 32,32, 0, 0, 0);      
        //drawBitmapToBoard(spriteManager.getLightSquare(), Bitboard::LIGHT_SQUARES); 
        drawBitmapToBoard(spriteManager.getDarkSquare(), Bitboard::RED_SQUARES);  
        al_flip_display();
        ALLEGRO_EVENT event; 
        al_wait_for_event(queue, &event); 
        if (event.type == ALLEGRO_EVENT_TIMER) {
            al_flip_display();
        }
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false; 
        }
        

    }
}; 

/*draw bitmap */
void GameManager::drawBitmapToBoard(ALLEGRO_BITMAP* bmp, uint64_t board) {
    uint64_t squares = Bitboard::RED_SQUARES; 
    //std::cout << "red squares: " << std::setfill('0') << std::setw(64) << std::bitset<64>(squares) << std::endl;  
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            uint64_t firstDigit = squares & 1;  
            if ( firstDigit == 1 ) {
                al_draw_bitmap(bmp, 
                    j * SpriteManager::SQUARE_HEIGHT, 
                    i * SpriteManager::SQUARE_HEIGHT, 
                    0
                );
            }   
            squares = squares >> 1; 
        }
    }   
}



ALLEGRO_EVENT_QUEUE* GameManager::getQueue() {
    return queue; 
} 

int GameManager::WINDOW_WIDTH = 540; 
int GameManager::WINDOW_HEIGHT = 540; 
