#ifndef POWERUP_H
#define	POWERUP_H

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