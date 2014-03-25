#include "Projectile.h"
#include "Game.h"
//
Projectile::Projectile( int x, int y, int d, int ID )
{
	//Initialize movement variables
	xOffset = x;
	yOffset = y;
	xPos = xOffset + 4;
	yPos = yOffset + 4;
	speed = 16;
        
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

	//ID: 0=player, 1=enemy
	teamID = ID;

	PROJECTILE_WIDTH = 8;
	PROJECTILE_HEIGHT = 8;
        
        hitsomething=false;

	//Initialize animation variables
	frame = 0;
	direction = DIR_RIGHT;

	set_clips( );

	//Load the sprite sheet
	projectile_sprite_up = image->loadImage( "rsc\\game\\Shot.bmp" ); // move up
	projectile_sprite_right = image->loadImage( "rsc\\game\\Shot.bmp" ); // move right
	projectile_sprite_down = image->loadImage( "rsc\\game\\Shot.bmp" );// move down
	projectile_sprite_left = image->loadImage( "rsc\\game\\Shot.bmp" ); // move left
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
            hitsomething=true;
        
        bool multiplayer=currentLevelGlobal->isMultiplayer();
        if (multiplayer){
            Player* current = currentLevelGlobal->getPlayer(2);
            has_hit=current->hit(myX,myY,damage);
            if(has_hit==true)
                hitsomething=true;
        }
    }
    else if (teamID=0){
        Enemy* current;
        enemies=currentLevelGlobal->getEnemies();
        for(int i=0; i<enemies->size();i++){
            current=enemies->at(i);
            has_hit=current->hit(myX,myY,damage);
            if(has_hit==true)
                hitsomething=true;
        }
    }
}

bool Projectile::checkhit(){return hitsomething;}

void Projectile::update( )
{
        hit();
        //0: Up 1: Right 2: Down 3: Left
	

    cout<<"updating projectile x"<<endl;
    if ( xVel != 0 )
    {
	xOffset += xVel;
	if ( xOffset + 4 <= 0 ||
		xOffset + 4 >= Global::GAME_WIDTH ||
		currentLevelGlobal->getGrid()->getTileAt(( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32) == 8 ){
            cout<<"hit"<<endl;
            hitsomething=true;
        }
	if ( xVel < 0 )
	    direction = DIR_LEFT;
	else if ( xVel > 0 )
	    direction = DIR_RIGHT;
    }
    cout<<"updating projectile y"<<endl;
    if ( yVel != 0 )
    {
	yOffset += yVel;
	if ( yOffset + 4 <= 0 ||
		yOffset + 4 >= Global::GAME_HEIGHT ||
		currentLevelGlobal->getGrid()->getTileAt(( xOffset + 4 ) / 32, ( yOffset + 4 ) / 32) == 8 ){
            cout<<"hit"<<endl;
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

int Projectile::getX( )
{
	return xOffset + 4;
}

int Projectile::getY( )
{
	return yOffset + 4;
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