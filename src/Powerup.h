#ifndef POWERUP_H
#define	POWERUP_H

#include "Global.h"
#include "Image.h"
#include "Unit.h"

using namespace std;

class Powerup
{
public:
    Powerup(){};
    ~Powerup(){};
    void apply_surface( int, int, SDL_Surface*, SDL_Rect* );
    string mytype(){return poweruptype;}
    bool status(){return obtained;}
    virtual void update() = 0;
    virtual void draw() = 0;
    
protected:
  
    int xOffset; //the x offset
    int yOffset; //the y offset
    int xPos;
    int yPos;
    bool obtained;
    string poweruptype;
};

#endif