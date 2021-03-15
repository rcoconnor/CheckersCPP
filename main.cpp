#include <iostream>
#include <iomanip> 
#include "Bitboard.h"
#include "Gameboard.h"

#include <allegro5/allegro.h>
//#include <allegro5/allegro_ttf.h>
//#include <allegro5/allegro_font.h>

using namespace std; 

int main(int argc, char** argv) {
    al_init();  
    //al_init_font_addon(); 
    //al_init_ttf_addon(); 

    ALLEGRO_DISPLAY * display = al_create_display(640, 480);  
    //ALLEGRO_FONT * font = al_load_ttf_font("YARDSALE.TTF", 64, 0); 

    std::cout << "Hello world!" << std::endl; 

    Gameboard board = Gameboard();  
    board.printBoard();

    while (true) {
        al_clear_to_color(al_map_rgb(255, 255, 255)); 
        //al_draw_text(font, al_map_rgb(0, 0, 0), 0, 0, 0, "Hello world"); 
        al_flip_display(); 
    }


    return 0; 
}




