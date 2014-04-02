#ifndef MOVER_H
#define	MOVER_H

#include <iostream>
#include "SDL2/SDL.h"
#include "Timer.h"
#include <string>
using namespace std;

class Mover {
public:

    Mover() {
    }

    ~Mover() {
    }
    virtual void update() = 0;
    virtual void draw() = 0;

    int getX() {return xOffset + (size/2);}
    int getY() {return yOffset + (size/2);}
    int getXVel() {return xVel;}
    int getYVel() {return yVel;}
    bool checkhit() {return hitsomething;}
protected:
    int xOffset; //the x offset
    int yOffset; //the y offset
    int xPos;
    int yPos;
    int xVel; //the x velocity
    int yVel; //the y velocity
    int speed;
    int frame; //its current frame
    int direction; //its animation status
    bool hitsomething;
    int size;
    int teamID;
    int damage;
};

#endif
