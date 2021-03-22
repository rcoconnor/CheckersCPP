#include "Component.h"

class Clickable: public Component {
    public: 
        Clickable();  
        
        int getX(); 
        int getY(); 
        int getWidth(); 
        int getHeight();

    protected: 
        int xPos; 
        int yPos; 
        int width; 
        int height; 

}; 


