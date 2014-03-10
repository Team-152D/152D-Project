#ifndef PLAYER_H
#define	PLAYER_H

#include "Unit.h"
#include <string>
#include "Global.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include <cstdlib>
#include <cmath>
#include "Projectile.h"
#include "Enemy.h"

class Game;

using namespace std;

class Player : public Unit
{
public:
    Player(int,int);
    ~Player();
    void apply_surface( int, int, SDL_Surface*, SDL_Rect* );
    
    void input(char*);
    void shooting();
    bool hit(int, int, int);
    void update();
    void draw();
    
    int getX();
    int getY();
    int getXVel();
    int getYVel();
private:
    void set_clips();
    //The dimensions of the image
    const int PLAYER_WIDTH = 32;
    const int PLAYER_HEIGHT = 32;
    
    Projectile* shoot;
    vector<Projectile*>* projectiles;
    
    //The surfaces
    SDL_Surface *player_sprite_up = NULL;
    SDL_Surface *player_sprite_down = NULL;
    SDL_Surface *player_sprite_right = NULL;
    SDL_Surface *player_sprite_left = NULL;
    SDL_Surface *screen = NULL;

    //The event structure
    SDL_Event event;

    //The areas of the sprite sheet
    SDL_Rect spriteClips[ 4 ];

};

#endif