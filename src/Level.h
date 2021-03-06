#ifndef LEVEL_H
#define	LEVEL_H

#include <vector>
#include <fstream>
#include <string>
#include <sstream>

#include "Guard.h"
#include "Monster.h"
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
#include "Object.h"
#include "Fixed_Switch.h"
#include "Timed_Gate.h"
#include "Ammobox.h"
#include "DetTile.h"
#include "MobileBoxes.h"

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
    vector<Object*>* getObjects(){return objects;}
    bool isMultiplayer();
    string getDifficulty();
    
    Grid* getGrid();
    bool victoryCondition();
    vector<string>* getInfoBarData();
	
	void loadLevel();
private:
    int levelNumber;
    bool multiplayer;
	string difficulty;
	
    Grid* grid;
	SDL_Rect endzone;
	
    Player* player1;
    Player* player2;
    vector<Unit*>* characters;
    vector<Mover*>* movers;
    vector<Gate*>* gates;
    vector<Switch*>* switches;
    vector<Powerup*>* powerups;
    vector<Object*>* objects;
};

#endif
