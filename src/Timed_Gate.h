#ifndef TIMED_GATE_H
#define	TIMED_GATE_H
//
#include <string>
#include "Gate.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "Global.h"
#include "Image.h"
#include <cstdlib>
#include <cmath>

using namespace std;

class Timed_Gate : public Gate
{
public:
    Timed_Gate(int, int, int);
    ~Timed_Gate();
    void apply_surface( int, int, SDL_Surface*, SDL_Rect* );
    void update();
    void draw();
    
private:
    void set_clips();
    //The dimensions of the image
    const int TIMED_GATE_WIDTH = 32;
    const int TIMED_GATE_HEIGHT = 32;
    
    int gate_timer; //How long the gate stays open.
    
    //The surfaces
    SDL_Surface *timed_gate_sprite_up = NULL;
    SDL_Surface *timed_gate_sprite_down = NULL;
    SDL_Surface *timed_gate_sprite_right = NULL;
    SDL_Surface *timed_gate_sprite_left = NULL;
    SDL_Surface *screen = NULL;

    //The areas of the sprite sheet
    SDL_Rect spriteClips[ 4 ];
};

#endif