#ifndef UNIT_H
#define	UNIT_H

#include <iostream>
#include "SDL2/SDL.h"
#include "Timer.h"
#include <string>
#include "Mover.h"
#include "Gate.h"
#include "Switch.h"
using namespace std;

// Unit (Global characteristics for players and enemies)

const int DIR_UP = 1200;
const int DIR_RIGHT = 300;
const int DIR_DOWN = 600;
const int DIR_LEFT = 900;

class Unit {
public:

    Unit() {
    }

    ~Unit() {
    }
    virtual void update() = 0;
    virtual void draw() = 0;
    bool hit(int x, int y, int radius, int damage){
        bool hit=false;
	if(x>(xOffset-radius) && x<(xPos+radius) && y>(yOffset-radius) && y<(yPos+radius))
            hit=true;
    
        if(hit==true){
            health-=damage;
            if(health<=0)
                alive=false;
            }
        return hit;
};

    int getHealth() {return health;}
    int getXoffset() {return xOffset;}
    int getYoffset() {return yOffset;}
    int getXpos() {return xPos;}
    int getYpos() {return yPos;}
    int getXVel() {return xVel;}
    int getYVel() {return yVel;}
    int getammo() {return ammo;}
    int addammo(int in) {ammo+=in;}
    bool isAlive() {return alive;}
    int myside() {return teamID;}
    int mysize() {return size;}
protected:
    int health; //unit health percentage
    int xOffset; //the x offset
    int yOffset; //the y offset
    int xPos;
    int yPos;
    int xVel; //the x velocity
    int yVel; //the y velocity
    int speed;
    int frame; //its current frame
    int direction; //its animation status
    int cooldown;
    bool alive;
    int size;
    int teamID;
    int ammo;
};

#endif
