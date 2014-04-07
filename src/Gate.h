#ifndef GATE_H
#define	GATE_H
//
#include <string>
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "Global.h"
#include "Image.h"
#include <cstdlib>
#include <cmath>

using namespace std;

class Gate
{
public:
    Gate(){};
    ~Gate(){};
    void apply_surface( int, int, SDL_Surface*, SDL_Rect* );
    
    void open(){status=true;}
    void shut(){status=false;}
    bool collision(int x, int y){
        if(status==true)
            return false;
        
        bool in=false;
        int distance;
        distance= sqrt( pow( x - xOffset , 2 ) + pow( y - yOffset , 2 ));
        if (distance<=16)
            in=true;
        
        return in;
    }
    string mytype(){return gatetype;}
    virtual void update() = 0;
    virtual void draw() = 0;
    
protected:
  
    int xOffset; //the x offset
    int yOffset; //the y offset
    int xPos;
    int yPos;
    bool status;
    string gatetype;
};

#endif