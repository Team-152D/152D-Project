#ifndef OBJECT_H
#define	OBJECT_H

#include <string>
#include "SDL2/SDL.h"
using namespace std;

class Unit;

class Object{
public:
    virtual void update(){}
    virtual void draw(){}
    /*the intention is that objects are told that they have
     * been collided with, and the collide is the result */
    virtual void collide(Unit*){}
    SDL_Rect getCord(){return bounds;}
    string getType(){return otype;}
protected:
    SDL_Rect bounds;
    string otype;
};

#endif	/* OBJECT_H */