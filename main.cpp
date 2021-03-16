#include <iostream>
#include <iomanip> 
#include "Bitboard.h"
#include "Gameboard.h"

#include "SpriteManager.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

using namespace std; 

int main(int argc, char** argv) {
    
    al_init();  
    al_init_image_addon(); 

    ALLEGRO_DISPLAY * display = al_create_display(640, 480); ;
    ALLEGRO_EVENT_QUEUE * queue = al_create_event_queue(); 
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0); // 60 frames per second 

    SpriteManager spriteManager = SpriteManager::createSpriteManager();
    

    al_install_keyboard();
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display)); 
    al_register_event_source(queue, al_get_timer_event_source(timer)); 
    
    bool running = true; 
    float x = 0.0;  
    while (running) {
        al_clear_to_color(al_map_rgba_f(1, 1, 1, 1)); 
        x += 0.1; 

        al_draw_bitmap(spriteManager.getSquare(), x, 0, 0);      
        al_flip_display();
        ALLEGRO_EVENT event; 
        al_wait_for_event(queue, &event); 
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false; 
        }
    }
    
    al_destroy_display(display); 
    al_uninstall_keyboard(); 
    
    std::cout << "Hello world!" << std::endl; 

    Gameboard board = Gameboard();  
    board.printBoard();
    return 0; 
}




