#ifndef LEVEL_H
#define	LEVEL_H

#include <vector>
#include <fstream>
#include <string>
#include <sstream>

#include "Enemy.h"
#include "Grid.h"
#include "Player.h"
#include "Projectile.h"
#include "Global.h"
#include "Game.h"

using namespace std;

class Level
{
public:
    Level(int);
    ~Level();
    void input(char*, char*);
    void update();
    void draw();
    
    Player* getPlayer(int);
    vector<Enemy*>* getEnemies();
    vector<Projectile*>* getProjectiles();
    bool isMultiplayer();
    
    Grid* getGrid();
    bool victoryCondition();
    vector<string>* getInfoBarData();
private:
    void loadLevel(int);
    bool multiplayer;
    Grid* grid;
    Player* player1;
    Player* player2;
    vector<Enemy*>* enemies;
    vector<Projectile*>* projectiles;
    
    SDL_Rect p1Spawn;
    SDL_Rect p2Spawn;
    SDL_Rect endzone;
};

#endif
