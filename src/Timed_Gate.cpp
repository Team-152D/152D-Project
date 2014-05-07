#include "Timed_Gate.h"
#include "Game.h"
//
Timed_Gate::Timed_Gate(int x, int y, int timer, int id)
{
    xOffset=x;
    yOffset=y;
    xPos = xOffset+16;
    yPos = yOffset+16;
	this->id = id;
    status=false;
    gatetype="timed";
    seconds=timer;
    gate_timer=seconds*30;

	timed_gate_sprite_open = image->loadImage( "rsc\\game\\object_GateOpen.bmp" ); // move up
	timed_gate_sprite_closed = image->loadImage( "rsc\\game\\object_GateClosed.bmp" ); // move right
	if ( timed_gate_sprite_open == NULL || timed_gate_sprite_closed == NULL)
		cout << "Gate sprite didn't load" << endl;
	
	cout << "timed gate constructor end" << endl;
}

Timed_Gate::~Timed_Gate()
{
    //Free the surface
    SDL_FreeSurface(timed_gate_sprite_open);
    SDL_FreeSurface(timed_gate_sprite_closed);

}

void Timed_Gate::update(){
    if(status==true){
        gate_timer--;
        if(gate_timer<=0){
            status=false;
            gate_timer = seconds*30;
        }
    }
}

void Timed_Gate::draw()
{
    if(status==true)
        image->drawSurface(xOffset+8,yOffset+8,timed_gate_sprite_open);
    else
        image->drawSurface(xOffset+8,yOffset+8,timed_gate_sprite_closed);
}

