#ifndef PROJECTILE_H
#define	PROJECTILE_H
//
#include "Unit.h"
#include "Mover.h"
#include "Global.h"
#include <string>
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "Global.h"
#include <vector>
#include <cstdlib>

class Game;

using namespace std;

class Projectile : public Mover
{
public:
    //starting locations, direction and team ID
    Projectile(int, int, int, int);
    ~Projectile();
    void apply_surface( int, int, SDL_Surface*, SDL_Rect* );
    
    void hit();
    void update();
    void draw();
private:
    void set_clips();
    //The dimensions of the image
    int PROJECTILE_WIDTH;
    int PROJECTILE_HEIGHT;

    //The surfaces
    SDL_Surface *projectile_sprite_up = NULL;
    SDL_Surface *projectile_sprite_down = NULL;
    SDL_Surface *projectile_sprite_right = NULL;
    SDL_Surface *projectile_sprite_left = NULL;
    SDL_Surface *screen = NULL;

    //The areas of the sprite sheet
    SDL_Rect spriteClips[ 4 ];
};

#endif