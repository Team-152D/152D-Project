#include "Fixed_Switch.h"
#include "Game.h"
//
Fixed_Switch::Fixed_Switch(int x, int y, Gate* pair)
{
    status=false;
    switchtype="fixed";
    My_Gate=pair;
    
    xOffset = x;
    yOffset = y;
    xPos = xOffset+16;
    yPos = yOffset+16;

	fixed_switch_sprite_on = image->loadImage( "rsc\\game\\object_switchOn.bmp" ); // move up
	fixed_switch_sprite_off = image->loadImage( "rsc\\game\\object_switchOff.bmp" ); // move right
	if ( fixed_switch_sprite_on == NULL || fixed_switch_sprite_off == NULL)
		cout << "switch sprite didn't load" << endl;
}

Fixed_Switch::~Fixed_Switch()
{
    //Free the surface
    SDL_FreeSurface(fixed_switch_sprite_on);
    SDL_FreeSurface(fixed_switch_sprite_off);

}

void Fixed_Switch::update(){
    if(status==true)
        if(My_Gate->getstate()==false)
        My_Gate->open();
}

void Fixed_Switch::draw()
{
    if(status==true)
        image->drawSurface(xOffset,yOffset,fixed_switch_sprite_on);
    else
        image->drawSurface(xOffset,yOffset,fixed_switch_sprite_off);
}

