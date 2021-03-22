#include "Entity.h"
#include <iostream>

using namespace std; 

Entity::Entity() {
    std::cout << "Entity Constructor not implemented yet" << std::endl; 
} 


Entity::~Entity() {
    std::cout << "Entity Destructor not implemented yet" << std::endl;     
}

void Entity::update() {
    std::string curType;  
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
