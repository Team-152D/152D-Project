#include "Enemy.h"
#include "Game.h"

Enemy::Enemy(int x, int y)
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
    direction = ENEMY_RIGHT;
    
    target = Level->getPlayer(1);

    seesPlayer=false;
    shooting=false;
    
    set_clips();

    //Load the sprite sheet
    enemy_sprite_up = Utility::loadImage("resources\\sprite_RedUp.png"); // move up
    enemy_sprite_right = Utility::loadImage("resources\\sprite_RedRight.png"); // move right
    enemy_sprite_down = Utility::loadImage("resources\\sprite_RedDown.png"); // move down
    enemy_sprite_left = Utility::loadImage("resources\\sprite_RedLeft.png"); // move left
    if ( enemy_sprite_up == NULL || enemy_sprite_right == NULL || enemy_sprite_down == NULL || enemy_sprite_left == NULL )
	cout << "Enemy sprite didn't load" << endl;
}

Enemy::~Enemy()
{
    //Free the surface
    SDL_FreeSurface(enemy_sprite_up);
    SDL_FreeSurface(enemy_sprite_right);
    SDL_FreeSurface(enemy_sprite_down);
    SDL_FreeSurface(enemy_sprite_left);

}

void Enemy::apply_surface(int x, int y, SDL_Surface* source, SDL_Rect* clip)
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = xOffset;
    offset.y = yOffset;

    //Blit
    SDL_BlitSurface(source, clip, mainScreenSurface, &offset);
}


void Enemy::AI(){
    
    //If something happens to make AI change target;
    //target = Level->getPlayer(1);
    //or
    //target = Level->getPlayer(2);
    //skip this if not multiplayer.
    
    int playerX=target->getX();
    int playerY=target->getY();
    
    int myX=this->getX();
    int myY=this->getY();
    
    if(myY-playerY>=100){
        if(myY<playerY) yVel += speed;
        else if(myY>playerY) yVel -= speed;
    }
    if(myX-playerX>=100){
        if(myX<playerX) xVel += speed;
        else if(myX>playerX){} xVel -= speed;
    }
}

bool Enemy::hit(int x, int y){
    bool hit=false;
    //if statement distance formula x
    //    hit=true;
    //if statement distance formula y
    //    hit=true;
    
    if(hit=true)
        //health-=damage
    return hit;
}

void Enemy::die(){
    
    if(health<=0) delete this;
}

void Enemy::update()
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
	    direction = ENEMY_LEFT;
	else if ( xVel > 0 )
	    direction = ENEMY_RIGHT;
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
	    direction = ENEMY_UP;
	else if ( yVel > 0 )
	    direction = ENEMY_DOWN;
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
	case ENEMY_UP:
	    apply_surface(xOffset - 16, yOffset - 16, player_sprite_up, &spriteClips[frame]);
	    break;
	case ENEMY_RIGHT:
	    apply_surface(xOffset - 16, yOffset - 16, player_sprite_right, &spriteClips[frame]);
	    break;
	case ENEMY_DOWN:
	    apply_surface(xOffset - 16, yOffset - 16, player_sprite_down, &spriteClips[frame]);
	    break;
	case ENEMY_LEFT:
	    apply_surface(xOffset - 16, yOffset - 16, player_sprite_left, &spriteClips[frame]);
	    break;

    }
}

int Enemy::getX()
{
    return xOffset + 16;
}

int Enemy::getY()
{
    return yOffset + 16;
}

void Enemy::set_clips()
{
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
}

int Player::getXVel()
{
    return xVel;
}

int Player::getYVel()
{
    return xVel;
}