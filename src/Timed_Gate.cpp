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
    
    set_clips();

	timed_gate_sprite_up = image->loadImage( "rsc\\game\\sprite_GateUp.bmp" ); // move up
	timed_gate_sprite_right = image->loadImage( "rsc\\game\\sprite_GateRight.bmp" ); // move right
	timed_gate_sprite_down = image->loadImage( "rsc\\game\\sprite_GateDown.bmp" ); // move down
	timed_gate_sprite_left = image->loadImage( "rsc\\game\\sprite_GateLeft.bmp" ); // move left
	if ( timed_gate_sprite_up == NULL || timed_gate_sprite_right == NULL || timed_gate_sprite_down == NULL || timed_gate_sprite_left == NULL )
		cout << "Gate sprite didn't load" << endl;
}

Timed_Gate::~Timed_Gate()
{
    //Free the surface
    SDL_FreeSurface(timed_gate_sprite_up);
    SDL_FreeSurface(timed_gate_sprite_right);
    SDL_FreeSurface(timed_gate_sprite_down);
    SDL_FreeSurface(timed_gate_sprite_left);

}

void Timed_Gate::apply_surface(int x, int y, SDL_Surface* source, SDL_Rect* clip)
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = xOffset;
    offset.y = yOffset;

    //Blit
    SDL_BlitSurface(source, clip, screenSurface, &offset);
}

void Timed_Gate::update(){
    gate_timer-=30;
    if(gate_timer<=0)
        status=false;
}

void Timed_Gate::draw()
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

void Timed_Gate::set_clips()
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

