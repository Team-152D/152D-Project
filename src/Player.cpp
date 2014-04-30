#include "Player.h"
#include "Game.h"

Player::Player( int x, int y )
{
	//Initialize movement variables
	health = 100;
	xOffset = x;
	yOffset = y;
	xVel = 0;
	yVel = 0;
	speed = 8;
	cooldown = 0;
	alive = true;
	radius=16;
	teamID = 0;
	ammo = 15;

	//Initialize animation variables
	frame = 0;
	direction = DIR_RIGHT;

	set_clips( );

	//Load the sprite sheet
	player_sprite_up = image->loadImage( "rsc\\game\\sprite_RedUp.bmp" ); // move up
	player_sprite_right = image->loadImage( "rsc\\game\\sprite_RedRight.bmp" ); // move right
	player_sprite_down = image->loadImage( "rsc\\game\\sprite_RedDown.bmp" ); // move down
	player_sprite_left = image->loadImage( "rsc\\game\\sprite_RedLeft.bmp" ); // move left
	if ( player_sprite_up == NULL || player_sprite_right == NULL || player_sprite_down == NULL || player_sprite_left == NULL )
		cout << "Player sprite didn't load" << endl;
}

Player::~Player( )
{
	//Free the surface
	SDL_FreeSurface( player_sprite_up );
	SDL_FreeSurface( player_sprite_right );
	SDL_FreeSurface( player_sprite_down );
	SDL_FreeSurface( player_sprite_left );

}

void Player::apply_surface( int x, int y, SDL_Surface* source, SDL_Rect* clip )
{
	//Holds offsets
	SDL_Rect offset;

	//Get offsets
	offset.x = xOffset;
	offset.y = yOffset;

	//Blit
	SDL_BlitSurface( source, clip, screenSurface, &offset );
}

void Player::input( char* cmd )
{
	if ( !strcmp( cmd, "Up" ) )
	{
		if ( yVel > ( 0 - speed ) )
			yVel -= speed;
	}
	else if ( !strcmp( cmd, "Down" ) )
	{
		if ( yVel < speed )
			yVel += speed;
	}
	else if ( !strcmp( cmd, "Left" ) )
	{
		if ( xVel > ( 0 - speed ) )
			xVel -= speed;
	}
	else if ( !strcmp( cmd, "Right" ) )
	{
		if ( xVel < speed )
			xVel += speed;
	}
	else if ( !strcmp( cmd, "Shoot" ) )
	{
		shooting( );
	}
}

void Player::shooting( )
{
	if ( cooldown > 0 )
	{
		cooldown--;
		return;
	}
	else if ( ammo <= 0 )
	{
		return;
	}
	int shoot_direction;
	switch ( direction )
	{
		case DIR_UP:
			shoot_direction = 0;
			break;
		case DIR_RIGHT:
			shoot_direction = 1;
			break;
		case DIR_DOWN:
			shoot_direction = 2;
			break;
		case DIR_LEFT:
			shoot_direction = 3;
			break;
	}

	int myX = getXoffset( );
	int myY = getYoffset( );
	Projectile* shoot;
	shoot = new Projectile( myX, myY, direction, 0 );
	vector<Mover*>*  projectiles = currentLevelGlobal->getMovers( );
	projectiles->push_back( shoot );
	cooldown = 15;
	ammo--;
}

bool Player::checkGates( )
{
	bool stop = false;
	vector<Gate*>* gates = currentLevelGlobal->getGates( );
	Gate* gpointer;
	for ( int i = 0; i < gates->size( ); i++ )
	{
		gpointer = gates->at( i );
		if ( gpointer->collision(xOffset, yOffset, radius) == true )
			stop = true;
	}
	return stop;
}

void Player::checkSwitches( )
{
	vector<Switch*>* switches = currentLevelGlobal->getSwitches( );
	Switch* spointer;
	for ( int i = 0; i < switches->size( ); i++ )
	{
		spointer = switches->at( i );
		if ( spointer->collision(xOffset, yOffset, radius) == true )
			spointer->down( );
	}
}

void Player::update( )
{
        //begin object collision detection
        vector<Object*> impact= objsAhead(*currentLevelGlobal->getObjects());
        vector<Object*>::iterator it= impact.begin();
        //while(it!=impact.end()) impact.collide(this);    
		
        checkSwitches( );
        //end object collision detection
        
	//cout << "updating x" << endl;
	if ( xVel != 0 )
	{
		xOffset += xVel;
		if ( xOffset + 16 <= 0 ||
			 xOffset + 16 >= Global::GAME_WIDTH ||
			 currentLevelGlobal->getGrid( )->getTileAt( ( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32 ) == 8 ||
			 checkGates( ) )
			xOffset -= xVel;
		if ( xVel < 0 )
			direction = DIR_LEFT;
		else if ( xVel > 0 )
			direction = DIR_RIGHT;
	}
	//cout << "updating y" << endl;
	if ( yVel != 0 )
	{
		yOffset += yVel;
		if ( yOffset + 16 <= 0 ||
			 yOffset + 16 >= Global::GAME_HEIGHT ||
			 currentLevelGlobal->getGrid( )->getTileAt( ( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32 ) == 8 ||
			 checkGates( ) )
			yOffset -= yVel;
		if ( yVel < 0 )
			direction = DIR_UP;
		else if ( yVel > 0 )
			direction = DIR_DOWN;
	}
	//cout << "checking tiles" << endl;
	switch ( currentLevelGlobal->getGrid( )->getTileAt( ( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32 ) )
	{
		case 5: //lava
			health--;
			break;
			//Other dmg tiles
	}
	//cout << "testing..." << endl;
}

void Player::draw( )
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
			apply_surface( xOffset - 16, yOffset - 16, player_sprite_up, &spriteClips[frame] );
			break;
		case DIR_RIGHT:
			apply_surface( xOffset - 16, yOffset - 16, player_sprite_right, &spriteClips[frame] );
			break;
		case DIR_DOWN:
			apply_surface( xOffset - 16, yOffset - 16, player_sprite_down, &spriteClips[frame] );
			break;
		case DIR_LEFT:
			apply_surface( xOffset - 16, yOffset - 16, player_sprite_left, &spriteClips[frame] );
			break;

	}
}

void Player::set_clips( )
{
	//Clip the sprites Right move
	spriteClips[ 0 ].x = PLAYER_WIDTH;
	spriteClips[ 0 ].y = 0;
	spriteClips[ 0 ].w = PLAYER_WIDTH;
	spriteClips[ 0 ].h = PLAYER_HEIGHT;

	spriteClips[ 1 ].x = 0;
	spriteClips[ 1 ].y = 0;
	spriteClips[ 1 ].w = PLAYER_WIDTH;
	spriteClips[ 1 ].h = PLAYER_HEIGHT;

	spriteClips[ 2 ].x = PLAYER_WIDTH;
	spriteClips[ 2 ].y = 0;
	spriteClips[ 2 ].w = PLAYER_WIDTH;
	spriteClips[ 2 ].h = PLAYER_HEIGHT;

	spriteClips[ 3 ].x = PLAYER_WIDTH * 2;
	spriteClips[ 3 ].y = 0;
	spriteClips[ 3 ].w = PLAYER_WIDTH;
	spriteClips[ 3 ].h = PLAYER_HEIGHT;
}
