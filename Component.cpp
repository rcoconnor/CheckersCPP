#include "Component.h"

#include <iostream>



Component::Component() {
    //std::cout << "Component Constructor not implemented yet" << std::endl;  
    type = "Component"; 
} 

Component::~Component() {
    std::cout << "Component destructor called" << std::endl; 
}

std::string Component::getType() {
    return type; 
}

void Component::update(ALLEGRO_EVENT* event) {
    std::cout << "Component.render() not implemented yet" << std::endl; 
} 

void Component::start() {
    std::cout << "Component.start() not implemented yet" << std::endl; 
}


