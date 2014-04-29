#ifndef TIMED_GATE_H
#define	TIMED_GATE_H
//
#include "Powerup.h"
#include "Global.h"
#include "Image.h"
#include "Unit.h"

using namespace std;

class Ammobox : public Powerup
{
public:
    Ammobox(int, int, int);
    ~Ammobox();
    void apply_surface( int, int, SDL_Surface*, SDL_Rect* );
    void update();
    void draw();
    void pickup();
    
private:
    void set_clips();
    //The dimensions of the image
    const int AMMOBOX_WIDTH = 32;
    const int AMMOBOX_HEIGHT = 32;
    
    int contents; //How many rounds this box contains

    //The areas of the sprite sheet
    SDL_Rect spriteClips[ 4 ];
};

#endif