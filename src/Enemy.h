#ifndef ENEMY_H
#define	ENEMY_H

#include "Unit.h"
#include "Global.h"
#include <string>
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
using namespace std;

class Enemy : public Unit
{
public:
    Enemy();
    ~Enemy();
    void update();
    void draw();
private:
    //The dimensions of the image
    const int ENEMY_WIDTH = 32;
    const int ENEMY_HEIGHT = 32;
    //the direction status of the stick figure
    const int ENEMY_RIGHT = 0;
    const int ENEMY_LEFT = 1;

};

#endif