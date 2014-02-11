#ifndef UNIT_H
#define	UNIT_H

#include <iostream>
#include "SDL/SDL.h"
#include "Timer.h"
#include <string>
using namespace std;

// Unit (Global characteristics for players and enemies)

class Unit
{
public:
    Unit(){}
    ~Unit(){}
    virtual void update() = 0;
    virtual void draw() = 0;
    int getHealth() { return health; }
protected:
    int health;                   //unit health percentage
    int xOffset;                        //the x offset
    int yOffset;                        //the y offset
    int xPos;
    int yPos;
    int xVel;                     //the x velocity
    int yVel;                     //the y velocity
    int speed;
    int frame;                    //its current frame
    int direction;                   //its animation status
};

#endif
