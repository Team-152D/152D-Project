#ifndef LEVEL_H
#define	LEVEL_H

#include <vector>
#include <fstream>
#include <string>
#include <sstream>

#include "Guard.h"
#include "Grid.h"
#include "Player.h"
#include "Projectile.h"
#include "Global.h"
#include "Game.h"
#include "Unit.h"
#include "Mover.h"
#include "Gate.h"
#include "Switch.h"
#include "Powerup.h"

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
    vector<Mover*>* getMovers();
    vector<Unit*>* getCharacters();
    vector<Gate*>* getGates();
    vector<Switch*>* getSwitches();
    vector<Powerup*>* getPowerups();

    bool isMultiplayer();
    string getDifficulty();
    
    Grid* getGrid();
    bool victoryCondition();
    vector<string>* getInfoBarData();
private:
    void loadLevel(int);
    bool multiplayer;
    Grid* grid;
    Player* player1;
    Player* player2;
    vector<Unit*>* characters;
    vector<Mover*>* movers;
    vector<Gate*>* gates;
    vector<Switch*>* switches;
    vector<Powerup*>* powerups;
    
    string difficulty;
    
    SDL_Rect p1Spawn;
    SDL_Rect p2Spawn;
    SDL_Rect endzone;
    SDL_Rect espawn;
};

#endif
