#ifndef SWITCH_H
#define	SWITCH_H

#include "Global.h"
#include "Image.h"
#include "Unit.h"

using namespace std;

class Switch
{
public:
    Switch(){};
    ~Switch(){};
    void apply_surface( int, int, SDL_Surface*, SDL_Rect* );
    
    void down(){status=true;}
    bool collision(int x, int y, int radius){
        if(status==true)
            return false;
        
        bool in=false;
	if(x+radius>=(xOffset) || x-radius<=(xPos) || y+radius>=(yOffset) || y-radius<=(yPos))
            in=true;
        
        return in;
    }
    string mytype(){return switchtype;}
    virtual void update() = 0;
    virtual void draw() = 0;
    
protected:
  
    int xOffset; //the x offset
    int yOffset; //the y offset
    int size;
    int xPos;
    int yPos;
    bool status;
    string switchtype;
};

#endif