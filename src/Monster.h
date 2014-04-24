#ifndef MONSTER_H
#define	MONSTER_H
//
#include "Unit.h"
#include "Player.h"
#include <string>
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "Global.h"
#include "Image.h"
#include <cstdlib>
#include <cmath>
#include "Sight.h"

class Game;

using namespace std;

class Monster : public Unit
{
public:
    Monster(int,int);
    ~Monster();
    void apply_surface( int, int, SDL_Surface*, SDL_Rect* );
    
    void AI();
    bool sight_check();
    bool checkGates();
    void attack();
    void update();
    void draw();
    
    
private:
    void set_clips();
    //The dimensions of the image
    const int MONSTER_WIDTH = 32;
    const int MONSTER_HEIGHT = 32;
    
    //whether the guard can "see" the player
    bool seesPlayer;
    bool knowsPlayerlocation;
    int losessighttimer;
    int patroldirection;
    int patrolsteps;
    int damage;
    int sightcooldown;

    //current focus player
    Player* player1;
    Player* player2;
    Unit* target;
    
    //The surfaces
    SDL_Surface *monster_sprite_up = NULL;
    SDL_Surface *monster_sprite_down = NULL;
    SDL_Surface *monster_sprite_right = NULL;
    SDL_Surface *monster_sprite_left = NULL;
    SDL_Surface *screen = NULL;

    //The areas of the sprite sheet
    SDL_Rect spriteClips[ 4 ];

};

#endif