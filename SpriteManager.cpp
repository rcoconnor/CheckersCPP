#include "SpriteManager.h"
#include "Bitboard.h"
int SpriteManager::SQUARE_HEIGHT = 64;

int LIGHT_SQUARE_SOURCE_X = 0; 
int LIGHT_SQUARE_SOURCE_Y = 0; 
int LIGHT_SQUARE_SOURCE_WIDTH = 32; 

int DARK_SQUARE_SOURCE_X = 0; 
int DARK_SQUARE_SOURCE_Y = 64; 
int DARK_SQUARE_SOURCE_WIDTH = 32; 

// generic helper funciton 
ALLEGRO_BITMAP* load_bitmap_at_size(ALLEGRO_BITMAP* loaded, int w, int h); 
ALLEGRO_BITMAP* load_section_of_bmp(ALLEGRO_BITMAP* loaded, int sx, int sy, int w, int h);
ALLEGRO_BITMAP* create_game_board(ALLEGRO_BITMAP *dark, ALLEGRO_BITMAP *light); 

void SpriteManager::init() {
    //std::cout << "initting sprite manager" << std::endl; 
    square = al_load_bitmap("images/wood.png"); assert(square!=NULL); 
    pieces = al_load_bitmap("images/checker.png"); assert(pieces!=NULL);  

    lightSquare = load_bitmap_at_size( 
            load_section_of_bmp(
                    square, 
                    LIGHT_SQUARE_SOURCE_X, 
                    LIGHT_SQUARE_SOURCE_Y, 
                    LIGHT_SQUARE_SOURCE_WIDTH,  // width 
                    LIGHT_SQUARE_SOURCE_WIDTH), // height 
                SQUARE_HEIGHT, 
                SQUARE_HEIGHT);

    darkSquare = load_bitmap_at_size(
            load_section_of_bmp(
                square, 
                DARK_SQUARE_SOURCE_X, 
                DARK_SQUARE_SOURCE_Y, 
                DARK_SQUARE_SOURCE_WIDTH, 
                DARK_SQUARE_SOURCE_WIDTH), 
            SQUARE_HEIGHT, 
            SQUARE_HEIGHT);
    gameBoard = create_game_board(darkSquare, lightSquare); 
    
    darkPiece = load_bitmap_at_size(
            load_section_of_bmp(
                pieces, 
                0,
                32, 
                32, 
                32),
            64, 
            64); 
    lightPiece = load_bitmap_at_size(load_section_of_bmp(pieces, 32, 32, 32, 32), 64, 64); 
    al_convert_mask_to_alpha(darkPiece, al_map_rgb(255, 0, 255));
    al_convert_mask_to_alpha(lightPiece, al_map_rgb(255, 0, 255)); 
}

/* draws the sprites in the positions given by board_state to the current target */ 
void SpriteManager::drawSpriteOnBoard(ALLEGRO_BITMAP* sprite, uint64_t board_state) {
    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            uint64_t firstDigit = board_state & 1;  
            if ( firstDigit == 1 ) {
                al_draw_bitmap(sprite, 
                    j * SpriteManager::SQUARE_HEIGHT, 
                    i * SpriteManager::SQUARE_HEIGHT, 
                    0
                );
            }  
            board_state = board_state >> 1; 
        }
    } 
}


SpriteManager::SpriteManager() {
    //std::cout << "sprite manager constructor called" << std::endl;  
}



SpriteManager::~SpriteManager() {
    al_destroy_bitmap(darkSquare);  
    al_destroy_bitmap(lightSquare);  
    al_destroy_bitmap(gameBoard);  
    al_destroy_bitmap(square);  
    
    al_destroy_bitmap(lightPiece); 
    al_destroy_bitmap(darkPiece); 
    al_destroy_bitmap(pieces);  
    return;
}


ALLEGRO_BITMAP* SpriteManager::getSquare() {
    return square; 
}


ALLEGRO_BITMAP* SpriteManager::getGameBoard() {
    return gameBoard; 
}


ALLEGRO_BITMAP* SpriteManager::getDarkSquare(){
    return darkSquare;  
}

ALLEGRO_BITMAP* SpriteManager::getLightSquare() {
    return lightSquare; 
}

ALLEGRO_BITMAP*  SpriteManager::getPiece() {
    return pieces; 
}

ALLEGRO_BITMAP* SpriteManager::getBlackPiece() {
    return darkPiece; 
}


ALLEGRO_BITMAP* SpriteManager::getLightPiece() {
    return lightPiece; 
}


ALLEGRO_BITMAP* create_game_board(ALLEGRO_BITMAP *dark, ALLEGRO_BITMAP *light) {
    // create the sprite in memory 
    ALLEGRO_BITMAP *prev, *boardSprite;
    boardSprite = al_create_bitmap(8 * SpriteManager::SQUARE_HEIGHT, 8 * SpriteManager::SQUARE_HEIGHT); 
    if (!boardSprite) { return NULL; }
   
    // store the previous target and set our new target 
    prev = al_get_target_bitmap(); 
    al_set_target_bitmap(boardSprite); 
    
    // Draw the sprite to the bitmap
    SpriteManager::drawSpriteOnBoard(light, Bitboard::LIGHT_SQUARES); 
    SpriteManager::drawSpriteOnBoard(dark, Bitboard::DARK_SQUARES); 
   
    // set the target to the previous one and return the bitmap
    al_set_target_bitmap(prev); 
    return boardSprite; 
}


/* Helper function which creates a copy of a bitmap at the specified number of pixels*/ 
ALLEGRO_BITMAP* load_bitmap_at_size(ALLEGRO_BITMAP* loaded, int w, int h) {
    ALLEGRO_BITMAP *resized, *prev;
    resized = al_create_bitmap(w, h); 
    if(!resized) { return NULL; }
    
    // set the target and store the previous one 
    prev = al_get_target_bitmap(); 
    al_set_target_bitmap(resized); 

    // copy the bitmap 
    al_draw_scaled_bitmap(loaded, 
            0, 0, 
            al_get_bitmap_width(loaded), 
            al_get_bitmap_height(loaded), 
            0, 0, 
            w, h, 
            0
    );
    // restore the prev target and then cleanup 
    al_set_target_bitmap(prev); 
    return resized; 
}

/** creates copy of the specified section of the bitmap */ 
ALLEGRO_BITMAP* load_section_of_bmp(ALLEGRO_BITMAP* loaded, int sx, int sy, int w, int h) {
    ALLEGRO_BITMAP *section, *prev;
    section = al_create_bitmap(w, h); 
    if(!section) { return NULL; }
    
    // load the bmp at the original size
    prev = al_get_target_bitmap(); 
    al_set_target_bitmap(section); 

    al_draw_bitmap_region(loaded, 
            sx, sy, 
            w, h,
            0, 0, 
            0
    );  

    al_set_target_bitmap(prev);
    return section; 
}
