#include "Timed_Gate.h"
#include "Game.h"
//
Timed_Gate::Timed_Gate(int x, int y, int timer)
{
    xOffset=x;
    yOffset=y;
    xPos = xOffset+16;
    yPos = yOffset+16;
    status=false;
    gatetype="timed";
    gate_timer=(timer*30);

	timed_gate_sprite_open = image->loadImage( "rsc\\game\\sprite_GateUp.bmp" ); // move up
	timed_gate_sprite_closed = image->loadImage( "rsc\\game\\sprite_GateRight.bmp" ); // move right
	if ( timed_gate_sprite_open == NULL || timed_gate_sprite_closed == NULL)
		cout << "Gate sprite didn't load" << endl;
}

Timed_Gate::~Timed_Gate()
{
    //Free the surface
    SDL_FreeSurface(timed_gate_sprite_open);
    SDL_FreeSurface(timed_gate_sprite_closed);

}

void Timed_Gate::update(){
    gate_timer-=30;
    if(gate_timer<=0)
        status=false;
}

void Timed_Gate::draw()
{
    if(status==true)
        image->drawSurface(xOffset,yOffset,timed_gate_sprite_open);
    else
        image->drawSurface(xOffset,yOffset,timed_gate_sprite_closed);
}

