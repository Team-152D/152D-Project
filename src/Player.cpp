#include "Player.h"
#include "Game.h"

Player::Player(int x, int y)
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

    //Initialize animation variables
    frame = 0;
    direction = PLAYER_RIGHT;

    set_clips();

    //Load the sprite sheet
    player_sprite_up = Utility::loadImage("resources\\sprite_RedUp.png"); // move up
    player_sprite_right = Utility::loadImage("resources\\sprite_RedRight.png"); // move right
    player_sprite_down = Utility::loadImage("resources\\sprite_RedDown.png"); // move down
    player_sprite_left = Utility::loadImage("resources\\sprite_RedLeft.png"); // move left
    if ( player_sprite_up == NULL || player_sprite_right == NULL || player_sprite_down == NULL || player_sprite_left == NULL )
	cout << "Player sprite didn't load" << endl;
}

Player::~Player()
{
    //Free the surface
    SDL_FreeSurface(player_sprite_up);
    SDL_FreeSurface(player_sprite_right);
    SDL_FreeSurface(player_sprite_down);
    SDL_FreeSurface(player_sprite_left);

}

void Player::apply_surface(int x, int y, SDL_Surface* source, SDL_Rect* clip)
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = xOffset;
    offset.y = yOffset;

    //Blit
    SDL_BlitSurface(source, clip, mainScreenSurface, &offset);
}

void Player::input(char* cmd)
{
    if ( !strcmp(cmd, "Up") ) yVel -= speed;
    else if ( !strcmp(cmd, "Down") ) yVel += speed;
    else if ( !strcmp(cmd, "Left") ) xVel -= speed;
    else if ( !strcmp(cmd, "Right") ) xVel += speed;
    else if ( !strcmp(cmd, "Shoot") );
}

void Player::update()
{
    cout<<"updating x"<<endl;
    if ( xVel != 0 )
    {
	xOffset += xVel;
	if ( xOffset + 16 <= 0 ||
		xOffset + 16 >= GAME_WIDTH ||
		currentLevelGlobal->getGrid()->getTileAt(( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32) == 8 )
	    xOffset -= xVel;
	if ( xVel < 0 )
	    direction = PLAYER_LEFT;
	else if ( xVel > 0 )
	    direction = PLAYER_RIGHT;
    }
    cout<<"updating y"<<endl;
    if ( yVel != 0 )
    {
	yOffset += yVel;
	if ( yOffset + 16 <= 0 ||
		yOffset + 16 >= GAME_HEIGHT ||
		currentLevelGlobal->getGrid()->getTileAt(( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32) == 8 )
	    yOffset -= yVel;
	if ( yVel < 0 )
	    direction = PLAYER_UP;
	else if ( yVel > 0 )
	    direction = PLAYER_DOWN;
    }
    cout<<"checking tiles"<<endl;
    switch(currentLevelGlobal->getGrid()->getTileAt( (xOffset+16)/32,(yOffset+16)/32 ))
    {
	case 5: //lava
	    health--;
	    break;
	    //Other dmg tiles
    }
}

void Player::draw()
{
    int frameCounter = currentGameGlobal->getFrameCounter();
    if ( xVel == 0 && yVel == 0 )
	frame = 0;
    else if ( frameCounter == 15 || frameCounter == 30 )
	frame++;

    if ( frame > 3 )
	frame = 0;

    switch ( direction )
    {
	case PLAYER_UP:
	    apply_surface(xOffset - 16, yOffset - 16, player_sprite_up, &spriteClips[frame]);
	    break;
	case PLAYER_RIGHT:
	    apply_surface(xOffset - 16, yOffset - 16, player_sprite_right, &spriteClips[frame]);
	    break;
	case PLAYER_DOWN:
	    apply_surface(xOffset - 16, yOffset - 16, player_sprite_down, &spriteClips[frame]);
	    break;
	case PLAYER_LEFT:
	    apply_surface(xOffset - 16, yOffset - 16, player_sprite_left, &spriteClips[frame]);
	    break;

    }
}

int Player::getX()
{
    return xOffset + 16;
}

int Player::getY()
{
    return yOffset + 16;
}

void Player::set_clips()
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

int Player::getXVel()
{
    return xVel;
}

int Player::getYVel()
{
    return xVel;
}