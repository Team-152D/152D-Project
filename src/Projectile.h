#ifndef PROJECTILE_H
#define	PROJECTILE_H
//
#include "Unit.h"
#include "Mover.h"
#include "Global.h"

class Game;

using namespace std;

class Projectile : public Mover
{
public:
    //starting locations, direction and team ID
    Projectile(int, int, int, int);
    ~Projectile();
    
    void hit();
    void update();
    void draw();
private:
    //The dimensions of the image
    int PROJECTILE_WIDTH;
    int PROJECTILE_HEIGHT;

    //The surfaces
    SDL_Surface *projectile_sprite = NULL;
};

#endif