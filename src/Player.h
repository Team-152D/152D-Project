#ifndef PLAYER_H
#define	PLAYER_H
//
#include "Unit.h"
#include "Global.h"

class Projectile;
class Game;

using namespace std;

class Player : public Unit
{
public:
    Player(int,int,int);
    ~Player();
    void apply_surface( int, int, SDL_Surface*, SDL_Rect* );
  
    void input(char*);
    void shooting();
    bool checkGates();
    bool checkCharacters();
    void checkSwitches();
    void update();
    void draw();
    
private:
    void set_clips();
    //The dimensions of the image
    const int PLAYER_WIDTH = 32;
    const int PLAYER_HEIGHT = 32;
    
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