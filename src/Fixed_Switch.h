#ifndef FIXED_SWITCH_H
#define	FIXED_SWITCH_H
//
#include <string>
#include "Switch.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "Global.h"
#include "Image.h"
#include <cstdlib>
#include <cmath>
#include "Gate.h"

using namespace std;

class Fixed_Switch : public Switch
{
public:
    Fixed_Switch(int, int, Gate*);
    ~Fixed_Switch();
    void apply_surface( int, int, SDL_Surface*, SDL_Rect* );
    void update();
    void draw();
    
private:
    void set_clips();
    //The dimensions of the image
    const int FIXED_SWITCH_WIDTH = 32;
    const int FIXED_SWITCH_HEIGHT = 32;
    
    Gate* My_Gate; //Gate paired to this switch
    
    //The surfaces
    SDL_Surface *fixed_switch_sprite_up = NULL;
    SDL_Surface *fixed_switch_sprite_down = NULL;
    SDL_Surface *fixed_switch_sprite_right = NULL;
    SDL_Surface *fixed_switch_sprite_left = NULL;
    SDL_Surface *screen = NULL;

    //The areas of the sprite sheet
    SDL_Rect spriteClips[ 4 ];
};

#endif