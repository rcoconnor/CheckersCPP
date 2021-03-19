#include "SpriteManager.h"

int SpriteManager::SQUARE_HEIGHT = 64; 

// generic helper funciton 
ALLEGRO_BITMAP* load_bitmap_at_size(ALLEGRO_BITMAP* loaded, int w, int h); 

ALLEGRO_BITMAP* load_section_of_bmp(ALLEGRO_BITMAP* loaded, int sx, int sy, int w, int h);
 

void SpriteManager::init() {
    std::cout << "initting sprite manager" << std::endl; 
    square = al_load_bitmap("images/wood.png"); assert(square!=NULL); 
    pieces = al_load_bitmap("images/checker.png"); assert(pieces!=NULL);  

    darkSquare = load_bitmap_at_size( load_section_of_bmp(square, 0, 0, 32, 32), SQUARE_HEIGHT, SQUARE_HEIGHT);
    lightSquare = load_bitmap_at_size(load_section_of_bmp(square, 0, 64, 32, 32), SQUARE_HEIGHT, SQUARE_HEIGHT); 
}


SpriteManager::SpriteManager() {
    std::cout << "sprite manager constructor called" << std::endl;  
}



SpriteManager::~SpriteManager() {
    return;
}


ALLEGRO_BITMAP* SpriteManager::getSquare() {
    return square; 
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
