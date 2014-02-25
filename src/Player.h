#ifndef PLAYER_H
#define	PLAYER_H

#include "Unit.h"
#include <string>
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "Global.h"
#include <cstdlib>

class Game;

using namespace std;

class Player : public Unit
{
public:
    Player(int,int);
    ~Player();
    void apply_surface( int, int, SDL_Surface*, SDL_Rect* );
    
    void input(char*);
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