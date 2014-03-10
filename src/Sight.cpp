#include "Sight.h"
#include "Game.h"
//
Sight::Sight( int x, int y, int d, int ID )
{
	//Initialize movement variables
	xOffset = x;
	yOffset = y;
	xPos = xOffset + 16;
	yPos = yOffset + 16;
	xVel = 0;
	yVel = 0;
	speed = 1;

	//ID: 0=player, 1=enemy
	teamID = ID;
	//direction: 0: Up 1: Right 2: Down 3: Left
	shooting_direction = d;

        hit_something=false;
        hit_player=false;
        
	SIGHT_WIDTH = 32;
	SIGHT_HEIGHT = 32;
        
        result="";

	//Initialize animation variables
	frame = 0;
	direction = DIR_RIGHT;
}

Sight::~Sight( )
{}

/*(void Projectile::hit(){
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
        Enemy* current;
        enemies=currentLevelGlobal->getEnemies();
        for(int i=0; i<enemies->size();i++){
            current=enemies->at(i);
            has_hit=current->hit(myX,myY,damage);
            if(has_hit==true)
                delete this;
        }
    }
}*/

void Sight::end(){delete this;}

string Sight::update( ){
        hit_player=hit();
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
                          hit_something=true;
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
			 hit_something=true;
		if ( yVel < 0 )
			direction = DIR_UP;
		else if ( yVel > 0 )
			direction = DIR_DOWN;
	}
	if(hit_something==false&&hit_player==false){result=update();}
        else if(hit_something==true){
            result="I hit a wall";
        }
        else if(hit_player==true){
            result="I hit the player";
        }
        return result;
}

int Sight::getX( )
{
	return xOffset + 16;
}

int Sight::getY( )
{
	return yOffset + 16;
}

int Sight::getXVel( )
{
	return xVel;
}

int Sight::getYVel( )
{
	return xVel;
}
