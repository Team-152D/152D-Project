#include "Projectile.h"
#include "Game.h"

Projectile::Projectile( int x, int y, int d, int ID )
{
	//Initialize movement variables
	xOffset = x;
	yOffset = y;
	xPos = xOffset + 16;
	yPos = yOffset + 16;
	xVel = 0;
	yVel = 0;
	speed = 8;

	//ID: 0=player, 1=enemy
	teamID = ID;
	//direction: 0: Up 1: Right 2: Down 3: Left
	shooting_direction = d;

	PROJECTILE_WIDTH = 32;
	PROJECTILE_HEIGHT = 32;

	//Initialize animation variables
	frame = 0;
	direction = DIR_RIGHT;

	set_clips( );

	//Load the sprite sheet
	projectile_sprite_up = image->loadImage( "resources\\sprite_RedUp.png" ); // move up
	projectile_sprite_right = image->loadImage( "resources\\sprite_RedRight.png" ); // move right
	projectile_sprite_down = image->loadImage( "resources\\sprite_RedDown.png" ); // move down
	projectile_sprite_left = image->loadImage( "resources\\sprite_RedLeft.png" ); // move left
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
    int myX=getX();
    int myY=getY();
    bool has_hit;
    
    if(teamID=1){
        Player* current = currentLevelGlobal->getPlayer(1);
        has_hit=current->hit(myX,myY,damage);
        if(has_hit==true)
            delete this;
        
        bool multiplayer=currentLevelGlobal->isMultiplayer();
        if (multiplayer){
            Player* current = currentLevelGlobal->getPlayer(2);
            has_hit=current->hit(myX,myY,damage);
            if(has_hit==true)
            delete this;
        }
        
    }
    else if (teamID=0){
        enemies=currentLevelGlobal->getEnemies();
        for(int i=0; i<enemies->size();i++){
            has_hit=enemies->at(i)->hit(myX,myY,damage);
            if(has_hit==true)
                delete this;
        }
    }
}

void Projectile::update( )
{
        hit();
	//0: Up 1: Right 2: Down 3: Left
	switch ( direction )
	{
		case 0:
			yVel -= speed;
			break;
		case 1:
			xVel += speed;
			break;
		case 2:
			yVel += speed;
			break;
		case 3:
			xVel -= speed;
			break;
	}

	cout << "updating x" << endl;
	if ( xVel != 0 )
	{
		xOffset += xVel;
		if ( xOffset + 16 <= 0 ||
			 xOffset + 16 >= Global::GAME_WIDTH ||
			 currentLevelGlobal->getGrid( )->getTileAt( ( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32 ) == 8 )
			delete this;
		if ( xVel < 0 )
			direction = DIR_LEFT;
		else if ( xVel > 0 )
			direction = DIR_RIGHT;
	}
	cout << "updating y" << endl;
	if ( yVel != 0 )
	{
		yOffset += yVel;
		if ( yOffset + 16 <= 0 ||
			 yOffset + 16 >= Global::GAME_HEIGHT ||
			 currentLevelGlobal->getGrid( )->getTileAt( ( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32 ) == 8 )
			delete this;
		if ( yVel < 0 )
			direction = DIR_UP;
		else if ( yVel > 0 )
			direction = DIR_DOWN;
	}
	cout << "checking tiles" << endl;

	//    switch(currentLevelGlobal->getGrid()->getTileAt( (xOffset+16)/32,(yOffset+16)/32 ))
	//    {
	//	case 5: //lava
	//	    health--;
	//	    break;
	//	    //Other dmg tiles
	//    }
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
			apply_surface( xOffset - 16, yOffset - 16, projectile_sprite_up, &spriteClips[frame] );
			break;
		case DIR_RIGHT:
			apply_surface( xOffset - 16, yOffset - 16, projectile_sprite_right, &spriteClips[frame] );
			break;
		case DIR_DOWN:
			apply_surface( xOffset - 16, yOffset - 16, projectile_sprite_down, &spriteClips[frame] );
			break;
		case DIR_LEFT:
			apply_surface( xOffset - 16, yOffset - 16, projectile_sprite_left, &spriteClips[frame] );
			break;

	}
}

int Projectile::getX( )
{
	return xOffset + 16;
}

int Projectile::getY( )
{
	return yOffset + 16;
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

int Projectile::getXVel( )
{
	return xVel;
}

int Projectile::getYVel( )
{
	return xVel;
}