#ifndef PROJECTILE_H
#define	PROJECTILE_H

#include <iostream>
#include "SDL/SDL.h"
#include <string>
#include <vector>
using namespace std;

class Projectile {
public:
    Projectile();
    ~Projectile();
    
    void update();
    void draw();
private:
};

#endif