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
    xPos = xOffset+32;
    yPos = yOffset+32;
    
    set_clips();

	fixed_switch_sprite_up = image->loadImage( "rsc\\game\\sprite_SwitchUp.bmp" ); // move up
	fixed_switch_sprite_right = image->loadImage( "rsc\\game\\sprite_SwitchRight.bmp" ); // move right
	fixed_switch_sprite_down = image->loadImage( "rsc\\game\\sprite_SwitchDown.bmp" ); // move down
	fixed_switch_sprite_left = image->loadImage( "rsc\\game\\sprite_SwitchLeft.bmp" ); // move left
	if ( fixed_switch_sprite_up == NULL || fixed_switch_sprite_right == NULL || fixed_switch_sprite_down == NULL || fixed_switch_sprite_left == NULL )
		cout << "switch sprite didn't load" << endl;
}

Fixed_Switch::~Fixed_Switch()
{
    //Free the surface
    SDL_FreeSurface(fixed_switch_sprite_up);
    SDL_FreeSurface(fixed_switch_sprite_right);
    SDL_FreeSurface(fixed_switch_sprite_down);
    SDL_FreeSurface(fixed_switch_sprite_left);

}

void Fixed_Switch::apply_surface(int x, int y, SDL_Surface* source, SDL_Rect* clip)
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = xOffset;
    offset.y = yOffset;

    //Blit
    SDL_BlitSurface(source, clip, screenSurface, &offset);
}

void Fixed_Switch::update(){
    if(status==true)
        if(My_Gate->getstate()==false)
        My_Gate->open();
}

void Fixed_Switch::draw()
{/*
    int frameCounter = currentGameGlobal->getFrameCounter();
    if ( xVel == 0 && yVel == 0 )
	frame = 0;
    else if ( frameCounter == 15 || frameCounter == 30 )
	frame++;

    if ( frame > 3 )
	frame = 0;

    switch ( direction )
    {
	case DIR_UP:
	    apply_surface(xOffset - 16, yOffset - 16, enemy_sprite_up, &spriteClips[frame]);
	    break;
	case DIR_RIGHT:
	    apply_surface(xOffset - 16, yOffset - 16, enemy_sprite_right, &spriteClips[frame]);
	    break;
	case DIR_DOWN:
	    apply_surface(xOffset - 16, yOffset - 16, enemy_sprite_down, &spriteClips[frame]);
	    break;
	case DIR_LEFT:
	    apply_surface(xOffset - 16, yOffset - 16, enemy_sprite_left, &spriteClips[frame]);
	    break;

    }*/
}

void Fixed_Switch::set_clips()
{/*
    //Clip the sprites Right move
    spriteClips[ 0 ].x = ENEMY_WIDTH;
    spriteClips[ 0 ].y = 0;
    spriteClips[ 0 ].w = ENEMY_WIDTH;
    spriteClips[ 0 ].h = ENEMY_HEIGHT;

    spriteClips[ 1 ].x = 0;
    spriteClips[ 1 ].y = 0;
    spriteClips[ 1 ].w = ENEMY_WIDTH;
    spriteClips[ 1 ].h = ENEMY_HEIGHT;

    spriteClips[ 2 ].x = ENEMY_WIDTH;
    spriteClips[ 2 ].y = 0;
    spriteClips[ 2 ].w = ENEMY_WIDTH;
    spriteClips[ 2 ].h = ENEMY_HEIGHT;

    spriteClips[ 3 ].x = ENEMY_WIDTH * 2;
    spriteClips[ 3 ].y = 0;
    spriteClips[ 3 ].w = ENEMY_WIDTH;
    spriteClips[ 3 ].h = ENEMY_HEIGHT;
*/}

