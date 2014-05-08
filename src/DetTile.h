#ifndef DETTILE_H
#define	DETTILE_H

#include <cstdlib>
#include "Object.h"
#include "Unit.h"
#include "Text.h"

//A tile that, after cntMax collisions, detonates and harms above units
class DetTile: public Object{
    vector<Unit*> above;
    int cntMax, cntCur;
    Text number;
    SDL_Surface *blast_1, *blast_2, *bg;
public:
    DetTile(int, int, int);
    ~DetTile(){
        SDL_FreeSurface(blast_1);
        SDL_FreeSurface(blast_2);
        SDL_FreeSurface(bg);
    }
    void draw();
    void update();
    void collide(Unit*);
};

#endif	/* DETTILE_H */

