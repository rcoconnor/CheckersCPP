#ifndef ENTITY_H
#define ENTITY_H

#include "Component.h"
#include <vector>


class Entity {
    public: 
        Entity(); 
        ~Entity(); 
       
        // valled every frame
        void update();

        void addComponent(Component* newComponent); 
        float getX(); 
        float getY(); 
        int getWidth(); 
        int getHeight(); 

    protected: 
        std::vector<Component*> components;
        int xPos; 
        int yPos; 
        int width; 
        int height; 
};

#endif
