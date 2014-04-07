#ifndef ENEMY_H
#define	ENEMY_H
//
#include "Unit.h"
#include <string>
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "Global.h"
#include "Image.h"
#include <cstdlib>
#include <cmath>
#include "Sight.h"

class Player;
class Projectile;
class Game;

using namespace std;

class Enemy : public Unit
{
public:
    Enemy(int,int,int);
    ~Enemy();
    void apply_surface( int, int, SDL_Surface*, SDL_Rect* );
    
    void AI();
    bool sight_check();
    bool hit(int, int, int);
    bool checkGates(int, int);
    void shooting();
    void update();
    void draw();
    
    
private:
    void set_clips();
    //The dimensions of the image
    const int ENEMY_WIDTH = 32;
    const int ENEMY_HEIGHT = 32;
    
    //whether the enemy can "see" the player
    bool seesPlayer;
    bool knowsPlayerlocation;
    int losessighttimer;
    int patroldirection;
    int patrolsteps;

    //current focus player
    Player* player1;
    Player* player2;
    Player* target;
    
    //The surfaces
    SDL_Surface *enemy_sprite_up = NULL;
    SDL_Surface *enemy_sprite_down = NULL;
    SDL_Surface *enemy_sprite_right = NULL;
    SDL_Surface *enemy_sprite_left = NULL;
    SDL_Surface *screen = NULL;

    //The areas of the sprite sheet
    SDL_Rect spriteClips[ 4 ];

};

#endif