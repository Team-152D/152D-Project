#include "Sight.h"
#include "Game.h"
//
Sight::Sight( int x, int y, int d, int ID )
{
	//Initialize movement variables
	xOffset = x;
	yOffset = y;
	speed =  4;
        radius = 8;

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

        max_height=yOffset+1100;
        min_height=yOffset+1100;
        max_length=xOffset+1100;
        min_length=xOffset+1100;
        
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
    bool has_hit;
    vector<Unit*>* characters = currentLevelGlobal->getCharacters();
    Unit* Upointer;
    
    for(int i=0;i<characters->size();i++){
        Upointer=characters->at(i);
        if(teamID!=Upointer->myside()){
            has_hit=Upointer->hit(xOffset,yOffset,damage,radius);
            if(has_hit==true){
                if(i==0) return "Player 1";
                else if(Upointer->myside()==0) return "Player 2";
            }
        }
    }
    return "no hit";
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

void Sight::update(){return;}
void Sight::draw(){return;}

