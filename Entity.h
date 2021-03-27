#ifndef ENTITY_H
#define ENTITY_H

#include "Component.h"
#include <vector>
#include <allegro5/allegro.h>

class Entity {
    public: 
        Entity(); 
        Entity(int x, int y, int w, int h);
        ~Entity(); 
       
        // valled every frame
        virtual void update(ALLEGRO_EVENT* event);
        // called at startup
        void init(); 
        
        void setNewPos(int x, int y); 
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
