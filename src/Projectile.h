#ifndef PROJECTILE_H
#define	PROJECTILE_H
//
#include "Unit.h"
#include "Global.h"
#include <string>
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "Global.h"
#include <vector>
#include <cstdlib>
class Enemy;
class Player;

class Game;

using namespace std;

class Projectile : public Unit
{
public:
    //starting locations, direction and team ID
    Projectile(int, int, int, int);
    ~Projectile();
    void apply_surface( int, int, SDL_Surface*, SDL_Rect* );
    
    void hit();
    bool checkhit();
    void update();
    void draw();
    
    int getX();
    int getY();
    int getXVel();
    int getYVel();
private:
    void set_clips();
    //The dimensions of the image
    int PROJECTILE_WIDTH;
    int PROJECTILE_HEIGHT;
    
    int teamID;
    int damage;
    
    bool hitsomething;
    
    vector<Enemy*>* enemies;

    //The surfaces
    SDL_Surface *projectile_sprite;
    SDL_Surface *screen;

    //The areas of the sprite sheet
    SDL_Rect spriteClips[ 4 ];
};

#endif