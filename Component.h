#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <allegro5/allegro.h>
class Component {
    public: 
        Component(); 
        virtual ~Component();  

        virtual void start(); 
        virtual void update(ALLEGRO_EVENT* event); // called every frame 
        virtual std::string getType(); 
    private: 
        std::string type; 
};

#endif
