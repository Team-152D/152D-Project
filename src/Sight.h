#ifndef SIGHT_H
#define	SIGHT_H
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

class Sight : public Unit
{
public:
    //starting locations, direction and team ID
    Sight(int, int, int, int);
    ~Sight();
    
    string hit();
    void update();
    void draw();
    string look();
    
    int getX();
    int getY();
    int getXVel();
    int getYVel();
private:
    //The dimensions of the image
    int SIGHT_WIDTH;
    int SIGHT_HEIGHT;
    
    int max_length;
    int min_length;
    int max_height;
    int min_height;
    
    bool hit_something;
    bool hit_player;
    
    string result;
    
    int damage;
    
    int shooting_direction;
    int teamID;
};

#endif


