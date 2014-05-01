#ifndef TIMED_GATE_H
#define	TIMED_GATE_H
//
#include "Gate.h"
#include "Global.h"
#include "Image.h"

using namespace std;

class Timed_Gate : public Gate
{
public:
    Timed_Gate(int, int, int);
    ~Timed_Gate();
    void update();
    void draw();
    
private:
    //The dimensions of the image
    const int TIMED_GATE_WIDTH = 32;
    const int TIMED_GATE_HEIGHT = 32;
    
    int gate_timer; //How long the gate stays open.
    
    //The surfaces
    SDL_Surface *timed_gate_sprite_open = NULL;
    SDL_Surface *timed_gate_sprite_closed = NULL;
};

#endif