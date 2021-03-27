#include "Component.h"

class Clickable: public Component {
    public: 
        Clickable();  
        Clickable(int x, int y, int w, int h);         
        
        // Overwritten virtual function
        void update(ALLEGRO_EVENT* event);  
        
        bool getMouseIsOver(); 
        int getX(); 
        int getY(); 
        int getWidth(); 
        int getHeight();
        
        void setX(int); 
        void setY(int); 
        void setWidth(int); 
        void setHeight(int); 

    protected: 
        int xPos; 
        int yPos; 
        int width; 
        int height; 

        bool mouseIsOver; 

}; 


