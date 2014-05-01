#include "Projectile.h"
#include "Game.h"
//
Projectile::Projectile( int x, int y, int d, int ID )
{
	//Initialize movement variables
	xOffset = x;
	yOffset = y;
	speed = 8;
        radius=8;
        teamID = ID;
        damage= 10;
        
	//direction: 0: Up 1: Right 2: Down 3: Left
        switch (d)
	{
	    case 0:
		yVel = -1*speed;
                xVel = 0;
	        break;
	    case 1:
		xVel = speed;
                yVel = 0;
		break;
	    case 2:
		yVel = speed;
                xVel = 0;
		break;
	    case 3:
		xVel = -1*speed;
                yVel = 0;
		break;
	}

	PROJECTILE_WIDTH = 16;
	PROJECTILE_HEIGHT = 16;
        
        hitsomething=false;

	//Initialize animation variables
	frame = 0;
	direction = DIR_RIGHT;

	set_clips( );

	//Load the sprite sheet
	projectile_sprite_up = image->loadImage( "rsc\\game\\object_Shot.bmp" ); // move up
	projectile_sprite_right = image->loadImage( "rsc\\game\\object_Shot.bmp" ); // move right
	projectile_sprite_down = image->loadImage( "rsc\\game\\object_Shot.bmp" );// move down
	projectile_sprite_left = image->loadImage( "rsc\\game\\object_Shot.bmp" ); // move left
	if ( projectile_sprite_up == NULL || projectile_sprite_right == NULL || projectile_sprite_down == NULL || projectile_sprite_left == NULL )
		cout << "Projectile sprite didn't load" << endl;
}

Projectile::~Projectile( )
{
	//Free the surface
	SDL_FreeSurface( projectile_sprite_up );
	SDL_FreeSurface( projectile_sprite_right );
	SDL_FreeSurface( projectile_sprite_down );
	SDL_FreeSurface( projectile_sprite_left );

}

void Projectile::apply_surface( int x, int y, SDL_Surface* source, SDL_Rect* clip )
{
	//Holds offsets
	SDL_Rect offset;

	//Get offsets
	offset.x = xOffset;
	offset.y = yOffset;

	//Blit
	SDL_BlitSurface( source, clip, screenSurface, &offset );
}

void Projectile::hit(){
    bool has_hit;
    vector<Unit*>* characters = currentLevelGlobal->getCharacters();
    Unit* Upointer;
    
    for(int i=0;i<characters->size();i++){
        Upointer=characters->at(i);
        if(teamID!=Upointer->myside()){
            has_hit=Upointer->hit(xOffset,yOffset,damage,radius);
            if(has_hit==true)
                hitsomething=true;
        }
    }
}

void Projectile::update( )
{  
    if(hitsomething==true) return;
        hit();
        //0: Up 1: Right 2: Down 3: Left
       
    if ( xVel != 0 )
    {
	xOffset += xVel;
	if ( xOffset + 8 <= 0 ||
		xOffset + 8 >= Global::GAME_WIDTH){
            hitsomething=true;
        }
	if ( xVel < 0 )
	    direction = DIR_LEFT;
	else if ( xVel > 0 )
	    direction = DIR_RIGHT;
    }
    if ( yVel != 0 )
    {
	yOffset += yVel;
	if ( yOffset + 8 <= 0 ||
		yOffset + 8 >= Global::GAME_HEIGHT){
            hitsomething=true;
        }
	if ( yVel < 0 )
	    direction = DIR_UP;
	else if ( yVel > 0 )
	    direction = DIR_DOWN;
    }
}

void Projectile::draw( )
{
	int frameCounter = currentGameGlobal->getFrameCounter( );
	if ( xVel == 0 && yVel == 0 )
		frame = 0;
	else if ( frameCounter == 15 || frameCounter == 30 )
		frame++;

	if ( frame > 3 )
		frame = 0;

	switch ( direction )
	{
		case DIR_UP:
			apply_surface( xOffset - 4, yOffset - 4, projectile_sprite_up, &spriteClips[frame] );
			break;
		case DIR_RIGHT:
			apply_surface( xOffset - 4, yOffset - 4, projectile_sprite_right, &spriteClips[frame] );
			break;
		case DIR_DOWN:
			apply_surface( xOffset - 4, yOffset - 4, projectile_sprite_down, &spriteClips[frame] );
			break;
		case DIR_LEFT:
			apply_surface( xOffset - 4, yOffset - 4, projectile_sprite_left, &spriteClips[frame] );
			break;

	}
}

void Projectile::set_clips( )
{
	//Clip the sprites Right move
	spriteClips[ 0 ].x = PROJECTILE_WIDTH;
	spriteClips[ 0 ].y = 0;
	spriteClips[ 0 ].w = PROJECTILE_WIDTH;
	spriteClips[ 0 ].h = PROJECTILE_HEIGHT;

	spriteClips[ 1 ].x = 0;
	spriteClips[ 1 ].y = 0;
	spriteClips[ 1 ].w = PROJECTILE_WIDTH;
	spriteClips[ 1 ].h = PROJECTILE_HEIGHT;

	spriteClips[ 2 ].x = PROJECTILE_WIDTH;
	spriteClips[ 2 ].y = 0;
	spriteClips[ 2 ].w = PROJECTILE_WIDTH;
	spriteClips[ 2 ].h = PROJECTILE_HEIGHT;

	spriteClips[ 3 ].x = PROJECTILE_WIDTH * 2;
	spriteClips[ 3 ].y = 0;
	spriteClips[ 3 ].w = PROJECTILE_WIDTH;
	spriteClips[ 3 ].h = PROJECTILE_HEIGHT;
}