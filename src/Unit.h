#ifndef UNIT_H
#define	UNIT_H

#include "Timer.h"
#include "Mover.h"
#include "Gate.h"
#include "Switch.h"
#include "Object.h"
#include <math.h>
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

    bool hit(int x, int y, int rin, int damage) {
        bool hit = false;
        int distance = sqrt(pow(x - xOffset, 2) + pow(y - yOffset, 2));
        if (distance <= (radius + rin))
            hit = true;
        cout<<distance;

        if (hit == true) {
            health -= damage;
            if (health <= 0)
                alive = false;
        }
        return hit;
    };
    /*objs ahead returns any objects about to collide
     * with the unit. Must run after speed is determined
     * but before any actual update to position.  Takes as 
     * its argument the list of objects to check collisions 
     * against. */
    vector<Object*> objsAhead(vector<Object*> check){
        int x = xOffset + xVel, y = yOffset + yVel;
        vector<Object*> impact;
        vector<Object*>::iterator it = check.begin();
        while (it != check.end())
            if (x + radius >= ((*it)->getCord().x) && y + radius >= ((*it)->getCord().y)
                    && x - radius <= ((*it)->getCord().x + (*it)->getCord().w)
                    && y - radius <= ((*it)->getCord().y + (*it)->getCord().h))
                impact.push_back(*it);
        return impact;
    }
    void stop(){xVel= 0; yVel= 0;}
    
    int getHealth(){return health;}
    int getXoffset() {return xOffset;}
    int getYoffset() {return yOffset;}
    int getXVel() {return xVel;}
    int getYVel() {return yVel;}
    int getammo() {return ammo;}
    int addammo(int in) {ammo += in;}
    bool isAlive() {return alive;}
    int myside() {return teamID;}
    int myradius() {return radius;}  
    int mynum() {return num;}
protected:
    int health; //unit health percentage
    int xOffset; //the x offset
    int yOffset; //the y offset (actually location))
    int xVel; //the x velocity
    int yVel; //the y velocity
    int speed;
    int frame; //its current frame
    int direction; //its animation status
    int cooldown;
    bool alive;
    int radius;
    int teamID;
    int ammo;
    int size;
    int num;
};

#endif