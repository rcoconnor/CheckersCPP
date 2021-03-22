#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

class Component {
    public: 
        Component(); 
        virtual ~Component();  

        virtual void start(); 
        virtual void update(); // called every frame 
        virtual std::string getType(); 
    private: 
        std::string type; 
};

#endif
