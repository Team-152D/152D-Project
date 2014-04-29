#ifndef OBJECT_H
#define	OBJECT_H

#include "SDL2/SDL.h"

class Object{
public:
    virtual void update(){};
    virtual void draw(){};
    SDL_Rect getCord(){return bounds;};
protected:
    SDL_Rect bounds;
};

#endif	/* OBJECT_H */