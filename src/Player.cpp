#include "Player.h"
#include "Game.h"

Player::Player( int x, int y )
{
	//Initialize movement variables
	health = 100;
	xOffset = x;
	yOffset = y;
	xPos = xOffset + 16;
	yPos = yOffset + 16;
	xVel = 0;
	yVel = 0;
	speed = 8;
        
        shoot=NULL;
        projectiles=NULL;
        dead=false;

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

void Player::input(char* cmd)
{
    if ( !strcmp(cmd, "Up") ) yVel -= speed;
    else if ( !strcmp(cmd, "Down") ) yVel += speed;
    else if ( !strcmp(cmd, "Left") ) xVel -= speed;
    else if ( !strcmp(cmd, "Right") ) xVel += speed;
    else if ( !strcmp(cmd, "Shoot") ) shooting();
}

void Player::shooting(){
    int shoot_direction;
    switch ( direction ){
	case DIR_UP:
	    shoot_direction=0;
	    break;
	case DIR_RIGHT:
	    shoot_direction=1;
	    break;
	case DIR_DOWN:
	    shoot_direction=2;
	    break;
	case DIR_LEFT:
	    shoot_direction=3;
	    break;
    }
    
    int myX=getX();
    int myY=getY();
    shoot;
    shoot=new Projectile(myX,myY,direction,0);
    projectiles=currentLevelGlobal->getProjectiles();
    projectiles->push_back(shoot);
}

bool Player::hit( int x, int y , int damage){
    bool hit=false;
    int distance;
    distance= sqrt( pow( x - xOffset , 2 ) + pow( y - yOffset , 2 ));
    if (distance<=16)
        hit=true;
    
    if(hit==true){
        health-=damage;
        cout<<"ouch";
        if(health<=0)
            dead=true;
        }
    return hit;
}

void Player::update( )
{
	//cout << "updating x" << endl;
	if ( xVel != 0 )
	{
		xOffset += xVel;
		if ( xOffset + 16 <= 0 ||
			 xOffset + 16 >= Global::GAME_WIDTH ||
			 currentLevelGlobal->getGrid( )->getTileAt( ( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32 ) == 8 )
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
			 currentLevelGlobal->getGrid( )->getTileAt( ( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32 ) == 8 )
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

int Player::getX( )
{
	return xOffset + 16;
}

int Player::getY( )
{
	return yOffset + 16;
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

int Player::getXVel( )
{
	return xVel;
}

int Player::getYVel( )
{
	return xVel;
}

int Player::getHP(){
    return health;
}

bool Player::isAlive(){
    return dead;
}