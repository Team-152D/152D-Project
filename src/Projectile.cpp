#include "Projectile.h"
#include "Game.h"
//
Projectile::Projectile( int x, int y, int d, int ID )
{
	//Initialize movement variables
	xOffset = x;
	yOffset = y;
	speed = 8;
        radius = 8;
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
        
        hitsomething=false;

	//Load the sprite sheet
	projectile_sprite = image->loadImage( "rsc\\game\\object_Shot.bmp" ); // move up
	if ( projectile_sprite == NULL)
		cout << "Projectile sprite didn't load" << endl;
}

Projectile::~Projectile( )
{
	//Free the surface
	SDL_FreeSurface( projectile_sprite);
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
    }
    if ( yVel != 0 )
    {
	yOffset += yVel;
	if ( yOffset + 8 <= 0 ||
		yOffset + 8 >= Global::GAME_HEIGHT){
            hitsomething=true;
        }
    }
}

void Projectile::draw( )
{
    image->drawSurface(xOffset,yOffset,projectile_sprite);
}