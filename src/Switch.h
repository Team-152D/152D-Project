#ifndef SWITCH_H
#define	SWITCH_H

#include <string>
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "Global.h"
#include "Image.h"
#include <cstdlib>
#include <cmath>
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
	if(x>(xOffset-radius) && x<(xPos+radius) && y>(yOffset-radius) && y<(yPos+radius))
            in=true;
        
        return in;
    }
    string mytype(){return switchtype;}
    virtual void update() = 0;
    virtual void draw() = 0;
    
protected:
  
    int xOffset; //the x offset
    int yOffset; //the y offset
    int xPos;
    int yPos;
    bool status;
    string switchtype;
};

#endif