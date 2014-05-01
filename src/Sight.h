#ifndef SIGHT_H
#define	SIGHT_H
//
#include "Unit.h"
#include "Global.h"
#include "Mover.h"
#include "Global.h"

class Game;

using namespace std;

class Sight : public Mover
{
public:
    //starting locations, direction and team ID
    Sight(int, int, int, int);
    ~Sight();
    
    string hit();
    void update();
    void draw();
    string look();
private:
    
    int max_length;
    int min_length;
    int max_height;
    int min_height;
    
    string result;
    
    int shooting_direction;
};

#endif


