#include "Entity.h"
#include <iostream>

using namespace std; 

Entity::Entity() {
    std::cout << "Entity Constructor not implemented yet" << std::endl; 
} 


Entity::Entity(int x, int y, int w, int h) {
    xPos = x; 
    yPos = y; 
    width = w; 
    height = h; 
    child = NULL; 

}

Entity::~Entity() {
    std::cout << "Entity Destructor not implemented yet" << std::endl;     
    child = NULL; 
}

void Entity::update() {
    //std::cout << "standard update called" << std::endl; 
    for (int i = 0; i < components.size(); i++) {
        components.at(i)->update();  
    }
}


void Entity::addComponent(Component* newComponent) {
    components.push_back(newComponent); 
}

float Entity::getX() {
    return xPos; 
} 


float Entity::getY() {
    return yPos; 
}


int Entity::getWidth() {
    return width; 
}


int Entity::getHeight() {
    return height; 
}
