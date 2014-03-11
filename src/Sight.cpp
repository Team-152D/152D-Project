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
        
	SIGHT_WIDTH = 200;
	SIGHT_HEIGHT = 200;
        
        damage=0;
        
        result="";

	//Initialize animation variables
	frame = 0;
	direction = DIR_RIGHT;
}

Sight::~Sight( )
{}

string Sight::hit(){
    int myX=getX();
    int myY=getY();
    bool has_hit;
    
    if(teamID=1){
        Player* current = currentLevelGlobal->getPlayer(1);
        has_hit=current->hit(myX,myY,damage);
        if(has_hit==true)
        return "player1";
        
        bool multiplayer=currentLevelGlobal->isMultiplayer();
        if (multiplayer){
            Player* current = currentLevelGlobal->getPlayer(2);
            has_hit=current->hit(myX,myY,damage);
            if(has_hit==true)
            return "player2";
        }
    } 
    return "nohit";
}

void Sight::end(){delete this;}

string Sight::look( ){
        string conditionwall="nohit";
        string conditionplayer="nohit";
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
		if ( xOffset + 50 <= 0 ||
			 xOffset + 50 >= Global::GAME_WIDTH ||
			 currentLevelGlobal->getGrid( )->getTileAt( ( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32 ) == 8 )
                         conditionwall="hit";
		if ( xVel < 0 )
			direction = DIR_LEFT;
		else if ( xVel > 0 )
			direction = DIR_RIGHT;
	}
	cout << "updating y" << endl;
	if ( yVel != 0 )
	{
		yOffset += yVel;
		if ( yOffset + 50 <= 0 ||
			 yOffset + 50 >= Global::GAME_HEIGHT ||
			 currentLevelGlobal->getGrid( )->getTileAt( ( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32 ) == 8 )
                         conditionwall="hit";
		if ( yVel < 0 )
			direction = DIR_UP;
		else if ( yVel > 0 )
			direction = DIR_DOWN;
	}
        conditionplayer=hit();
	if(conditionwall=="nohit"&&conditionplayer=="nohit"){result=look();}
        else if(conditionplayer!="nohit"){
            result=conditionplayer;
        }
        else if(conditionwall=="hit"){
            result="I hit a wall";
        }
        return result;
}

void Sight::update( ){}
void Sight::draw(){}

int Sight::getX( )
{
	return xOffset + 100;
}

int Sight::getY( )
{
	return yOffset + 100;
}

int Sight::getXVel( )
{
	return xVel;
}

int Sight::getYVel( )
{
	return xVel;
}
