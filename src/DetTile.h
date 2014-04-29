#ifndef DETTILE_H
#define	DETTILE_H

#include "Object.h"
#include "Unit.h"
#include "Text.h"

//A tile that, after cntMax collisions, detonates and harms above units
class DetTile: public Object{
    vector<Unit*> above;
    int cntMax, cntCur;
    Text number;
    SDL_Surface *blast_1, *blast_2;
public:
    DetTile(int, int, int);
    ~DetTile(){
        SDL_FreeSurface(blast_1);
        SDL_FreeSurface(blast_2);
    }
    void draw();
    void update();
    void collide(Unit*);
};

#endif	/* DETTILE_H */

