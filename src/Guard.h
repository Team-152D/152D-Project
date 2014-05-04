#ifndef GUARD_H
#define	GUARD_H
//
#include "Unit.h"
#include "Player.h"
#include "Global.h"
#include "Image.h"
#include "Sight.h"

class Game;

using namespace std;

class Guard : public Unit
{
public:
    Guard(int,int);
    ~Guard();
    void apply_surface( int, int, SDL_Surface*, SDL_Rect* );
    
    void AI();
    bool sight_check();
    bool checkGates();
    bool checkCharacters();
    void checkSwitches();
    void shooting();
    void update();
    void draw();
    
    
private:
    void set_clips();
    //The dimensions of the image
    const int GUARD_WIDTH = 32;
    const int GUARD_HEIGHT = 32;
    
    //whether the guard can "see" the player
    bool seesPlayer;
    bool knowsPlayerlocation;
    int losessighttimer;
    int patroldirection;
    int patrolsteps;
    
    int sightcooldown;

    //current focus player
    Player* player1;
    Player* player2;
    Unit* target;

    SDL_Surface *guard_sprite_up = NULL;
    SDL_Surface *guard_sprite_down = NULL;
    SDL_Surface *guard_sprite_right = NULL;
    SDL_Surface *guard_sprite_left = NULL;
    SDL_Surface *guard = NULL;
    
    //The areas of the sprite sheet
    SDL_Rect spriteClips[ 4 ];

};

#endif