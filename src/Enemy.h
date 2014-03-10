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

class Player;
class Projectile;
class Game;

using namespace std;

class Enemy : public Unit
{
public:
    Enemy(int,int);
    ~Enemy();
    void apply_surface( int, int, SDL_Surface*, SDL_Rect* );
    
    void AI();
    bool hit(int, int, int);
    void shooting();
    void die();
    void update();
    void draw();
    
    int getX();
    int getY();
    int getXVel();
    int getYVel();
private:
    void set_clips();
    //The dimensions of the image
    const int ENEMY_WIDTH = 32;
    const int ENEMY_HEIGHT = 32;
    
    
    
    //whether the enemy is shooting at the player
    bool shootingnow;
    //whether the enemy can "see" the player
    bool seesPlayer;

    //current focus player
    Player* target;
    Projectile* shoot;
    vector<Projectile*>* projectiles;
    
    //The surfaces
    SDL_Surface *enemy_sprite_up = NULL;
    SDL_Surface *enemy_sprite_down = NULL;
    SDL_Surface *enemy_sprite_right = NULL;
    SDL_Surface *enemy_sprite_left = NULL;
    SDL_Surface *screen = NULL;

    //The event structure
    SDL_Event event;

    //The areas of the sprite sheet
    SDL_Rect spriteClips[ 4 ];

};

#endif