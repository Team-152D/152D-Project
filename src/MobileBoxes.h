#ifndef MOBILEBOXES_H
#define	MOBILEBOXES_H

#include "Object.h"

class PushBox: public Object{
    SDL_Surface *bg;
    int xVel, yVel;
public:
    PushBox(int, int);
    ~PushBox(){SDL_FreeSurface(bg);}
    void draw();
    void collide(Unit*);
};


#endif	/* MOBILEBOXES_H */

