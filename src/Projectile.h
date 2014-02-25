#ifndef PROJECTILE_H
#define	PROJECTILE_H

#include "Unit.h"
#include "Global.h"
#include <string>
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "Global.h"
#include <vector>
#include <cstdlib>

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
    
    int shooting_direction;
    int teamID;

    //The surfaces
    SDL_Surface *projectile_sprite_up = NULL;
    SDL_Surface *projectile_sprite_down = NULL;
    SDL_Surface *projectile_sprite_right = NULL;
    SDL_Surface *projectile_sprite_left = NULL;
    SDL_Surface *screen = NULL;
    
    //The event structure
    SDL_Event event;

    //The areas of the sprite sheet
    SDL_Rect spriteClips[ 4 ];
};

#endif