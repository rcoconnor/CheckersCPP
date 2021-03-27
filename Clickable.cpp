#include "Clickable.h"
#include <iostream>

Clickable::Clickable() {
    std::cout << "not implemented yet" << std::endl;  
}


Clickable::Clickable(int x, int y, int w, int h) {
    xPos = x; 
    yPos = y; 
    width = w; 
    height = h; 
}

void Clickable::update(ALLEGRO_EVENT* event) {
    //std::cout << "Clickable update called" << std::endl; 
    //`std::cout << "type: " << event->type << std::endl; 
    if (event->type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
        //std::cout << "we are detecting that it is pushed!" << std::endl; 
        if ( (event->mouse.x >= xPos) && ( event->mouse.x <= xPos + width ) &&
                (event->mouse.y >= yPos) && ( event->mouse.y <= yPos + height)) {
            mouseIsOver = true; 
        } else {
            mouseIsOver = false; 
        }
        if (mouseIsOver == true) { 
            xPos = event->mouse.x; 
            yPos = event->mouse.y;
            std::cout << "mouse has been clicked: " << xPos << ", " << yPos << std::endl;  
        }
    }
}

bool Clickable::getMouseIsOver() {
    return mouseIsOver; 
} 

int Clickable::getX() {
    return xPos; 
}

int Clickable::getY() {
    return yPos; 
}

int Clickable::getWidth() {
    return width; 
}

int Clickable::getHeight() {
    return height; 
}

void Clickable::setX(int newX) {
    xPos = newX; 
}

void Clickable::setY(int newY) {
    yPos = newY; 
}

void Clickable::setWidth(int newWidth) {
    width = newWidth; 
}

void Clickable::setHeight(int newHeight) {
    height = newHeight; 
}



