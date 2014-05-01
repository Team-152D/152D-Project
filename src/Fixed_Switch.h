#ifndef FIXED_SWITCH_H
#define	FIXED_SWITCH_H
//
#include "Switch.h"
#include "Global.h"
#include "Image.h"
#include "Gate.h"

using namespace std;

class Fixed_Switch : public Switch
{
public:
    Fixed_Switch(int, int, Gate*);
    ~Fixed_Switch();
    void update();
    void draw();
    
private:
    void set_clips();
    //The dimensions of the image
    const int FIXED_SWITCH_WIDTH = 32;
    const int FIXED_SWITCH_HEIGHT = 32;
    
    Gate* My_Gate; //Gate paired to this switch
    
    //The surfaces
    SDL_Surface *fixed_switch_sprite_on = NULL;
    SDL_Surface *fixed_switch_sprite_off = NULL;
};

#endif