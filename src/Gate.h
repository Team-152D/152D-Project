#ifndef GATE_H
#define	GATE_H
//
#include "Global.h"
#include "Image.h"

using namespace std;

class Gate
{
public:
    Gate(){};
    ~Gate(){};
    void apply_surface( int, int, SDL_Surface*, SDL_Rect* );
    
    void open(){status=true;}
    void shut(){status=false;}
    bool getstate(){return status;}
    bool collision(int x, int y, int radius){
        if(status==true)
            return false;
        
        bool in=false;
        
	if(x+radius>=(xOffset) || x-radius<=(xPos) || y+radius>=(yOffset) || y-radius<=(yPos))
            in=true;
        
        return in;
    }
    string mytype(){return gatetype;}
    virtual void update() = 0;
    virtual void draw() = 0;
    
protected:
  
    int xOffset; //the x offset
    int yOffset; //the y offset
    int size;
    int xPos;
    int yPos;
    bool status;
    string gatetype;
};

#endif