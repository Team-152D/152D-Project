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

        max_height=yPos+100;
        min_height=yPos-100;
        max_length=xPos+100;
        min_length=xPos-100;
        
        hit_something=false;
        hit_player=false;
        
	SIGHT_WIDTH = 32;
	SIGHT_HEIGHT = 32;
        
        damage=0;
        
        result="";

	//Initialize animation variables
	frame = 0;
	direction = DIR_RIGHT;
}

Sight::~Sight( ){}

string Sight::hit(){
    int myX=getX();
    int myY=getY();
    bool has_hit;
    
    if(teamID==1){
        Player* current = currentLevelGlobal->getPlayer(1);
        has_hit=current->hit(myX,myY,damage);
        if(has_hit==true)
        return "Player 1";
        
        bool multiplayer=currentLevelGlobal->isMultiplayer();
        if (multiplayer){
            Player* current = currentLevelGlobal->getPlayer(2);
            has_hit=current->hit(myX,myY,damage);
            if(has_hit==true)
            return "Player 2";
        }
    } 
    return "nohit";
}

string Sight::look(){
        string conditionwall="nohit";
        string conditionplayer="nohit";

	if ( xVel != 0 )
	{
		xOffset += xVel;
		if ( xOffset + 16 <= min_length ||
			 xOffset + 16 >= max_length ||
			 currentLevelGlobal->getGrid( )->getTileAt( ( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32 ) == 8 )
                         conditionwall="hit";
		if ( xVel < 0 )
			direction = DIR_LEFT;
		else if ( xVel > 0 )
			direction = DIR_RIGHT;
	}
	if ( yVel != 0 )
	{
		yOffset += yVel;
		if ( yOffset + 16 <= min_height ||
			 yOffset + 16 >= max_height ||
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

void Sight::update(){}
void Sight::draw(){}

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
