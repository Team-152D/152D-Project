#include "Projectile.h"
#include "Game.h"

Projectile::Projectile(int x, int y, int d, int ID)
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
    teamID=ID;
    //direction: 0: Up 1: Right 2: Down 3: Left
    shooting_direction=d;
    
    PROJECTILE_WIDTH=32;
    PROJECTILE_HEIGHT=32;
    
    //Initialize animation variables
    frame = 0;
    direction = PROJECTILE_RIGHT;

    set_clips();

    //Load the sprite sheet
    projectile_sprite_up = Utility::loadImage("resources\\sprite_RedUp.png"); // move up
    projectile_sprite_right = Utility::loadImage("resources\\sprite_RedRight.png"); // move right
    projectile_sprite_down = Utility::loadImage("resources\\sprite_RedDown.png"); // move down
    projectile_sprite_left = Utility::loadImage("resources\\sprite_RedLeft.png"); // move left
    if ( projectile_sprite_up == NULL || projectile_sprite_right == NULL || projectile_sprite_down == NULL || projectile_sprite_left == NULL )
	cout << "Projectile sprite didn't load" << endl;
}

Projectile::~Projectile()
{
    //Free the surface
    SDL_FreeSurface(projectile_sprite_up);
    SDL_FreeSurface(projectile_sprite_right);
    SDL_FreeSurface(projectile_sprite_down);
    SDL_FreeSurface(projectile_sprite_left);

}

void Projectile::apply_surface(int x, int y, SDL_Surface* source, SDL_Rect* clip)
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = xOffset;
    offset.y = yOffset;

    //Blit
    SDL_BlitSurface(source, clip, mainScreenSurface, &offset);
}

void Projectile::hit(){
    if(teamID=1){
        void has_hit;
        Player* current = Level->getPlayer(1);
        has_hit=current->hit();
        if(hit)
            delete this;
        //if multiplayer, do the same for player 2
    }
    //else if ID=0, do the same for all enemies in the enemy vector
}

void Projectile::update()
{

    //0: Up 1: Right 2: Down 3: Left
    switch(direction){
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
    
    cout<<"updating x"<<endl;
    if ( xVel != 0 )
    {
	xOffset += xVel;
	if ( xOffset + 16 <= 0 ||
		xOffset + 16 >= GAME_WIDTH ||
		currentLevelGlobal->getGrid()->getTileAt(( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32) == 8 )
	    delete this;
	if ( xVel < 0 )
	    direction = PROJECTILE_LEFT;
	else if ( xVel > 0 )
	    direction = PROJECTILE_RIGHT;
    }
    cout<<"updating y"<<endl;
    if ( yVel != 0 )
    {
	yOffset += yVel;
	if ( yOffset + 16 <= 0 ||
		yOffset + 16 >= GAME_HEIGHT ||
		currentLevelGlobal->getGrid()->getTileAt(( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32) == 8 )
	    delete this;
	if ( yVel < 0 )
	    direction = PROJECTILE_UP;
	else if ( yVel > 0 )
	    direction = PROJECTiLE_DOWN;
    }
    cout<<"checking tiles"<<endl;
    
//    switch(currentLevelGlobal->getGrid()->getTileAt( (xOffset+16)/32,(yOffset+16)/32 ))
//    {
//	case 5: //lava
//	    health--;
//	    break;
//	    //Other dmg tiles
//    }
}

void Projectile::draw()
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
	case PROJETILE_UP:
	    apply_surface(xOffset - 16, yOffset - 16, enemy_sprite_up, &spriteClips[frame]);
	    break;
	case PROJECTILE_RIGHT:
	    apply_surface(xOffset - 16, yOffset - 16, enemy_sprite_right, &spriteClips[frame]);
	    break;
	case PROJECTILE_DOWN:
	    apply_surface(xOffset - 16, yOffset - 16, enemy_sprite_down, &spriteClips[frame]);
	    break;
	case PROJECTILE_LEFT:
	    apply_surface(xOffset - 16, yOffset - 16, enemy_sprite_left, &spriteClips[frame]);
	    break;

    }
}

int Projectile::getX()
{
    return xOffset + 16;
}

int Projectile::getY()
{
    return yOffset + 16;
}

void Projectile::set_clips()
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

int Projectile::getXVel()
{
    return xVel;
}

int Projectile::getYVel()
{
    return xVel;
}