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
    //Status True = gate OPEN.
    //Status False = gate CLOSED.
    bool collision(int x, int y, int radius){
        if(status==true)
            return false;
        
        bool in=false;
        
	if(x>(xOffset-radius) && x<(xPos+radius) && y>(yOffset-radius) && y<(yPos+radius))
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