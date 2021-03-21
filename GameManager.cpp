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
    //int index = 0; 
    FILES curFile = FILE_A; 
    int index = 0;  
    while (running) {
        ALLEGRO_EVENT event; 
        al_wait_for_event(queue, &event);
        /*if (event.type == ALLEGRO_EVENT_TIMER) {
            drawBoardStateToScreen(al_get_target_bitmap());  
            al_flip_display();
        }*/ 
        if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
            //drawBitboardToScreen(Bitboard::ClearFile[curFile]);
            if(index == 0){ drawBoardStateToScreen(al_get_target_bitmap()); index++; }
            else if (index == 1) { drawBitboardToScreen(Bitboard::Piece[A3]); index++; }
            else if (index == 2) { 
                drawBitboardToScreen(
                    Gameboard::ComputePieceValidMoves(
                        Bitboard::Piece[A3], 
                        board.getBlackPieces()
                    )
                ); 
            }
            al_flip_display(); 
            curFile = (FILES)((int)curFile+1); 
            //index++;
        }
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false; 
        }
    }
}; 

// Debug function to allow visualizing of bitboards
// prints a bitboard to the screen 
void GameManager::drawBitboardToScreen(uint64_t board) {
    al_clear_to_color(al_map_rgba_f(255, 255, 255, 1)); 
    al_draw_bitmap(spriteManager.getGameBoard(), 0, 0, 0); 
    SpriteManager::drawSpriteOnBoard(spriteManager.getBlackPiece(), board); 
}


void GameManager::drawBoardStateToScreen(ALLEGRO_BITMAP* target) {
    ALLEGRO_BITMAP* prev = al_get_target_bitmap(); 
    al_set_target_bitmap(target); 
    
    al_clear_to_color(al_map_rgba_f(255, 255, 255, 1)); 
    al_draw_bitmap(spriteManager.getGameBoard(), 0, 0, 0);  
    SpriteManager::drawSpriteOnBoard(spriteManager.getBlackPiece(), board.getBlackPieces());  
    SpriteManager::drawSpriteOnBoard(spriteManager.getLightPiece(), board.getLightPieces()); 

    al_set_target_bitmap(prev); 
}


// get the event queue 
ALLEGRO_EVENT_QUEUE* GameManager::getQueue() {
    return queue; 
} 


// static variables 
int GameManager::WINDOW_WIDTH = 540; 
int GameManager::WINDOW_HEIGHT = 540; 
