#ifndef ENTITY_H
#define ENTITY_H

#include "Component.h"
#include <vector>


class Entity {
    public: 
        Entity(); 
        Entity(int x, int y, int w, int h);
        ~Entity(); 
       
        // valled every frame
        virtual void update();
        // called at startup
        void init(); 

        void addComponent(Component* newComponent); 
        float getX(); 
        float getY(); 
        int getWidth(); 
        int getHeight(); 
        
        Entity* child; 
    protected: 
        std::vector<Component*> components;
        int xPos; 
        int yPos; 
        int width; 
        int height; 
};

#endif
