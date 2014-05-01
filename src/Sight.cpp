#include "Sight.h"
#include "Game.h"
//
Sight::Sight( int x, int y, int d, int ID )
{
	//Initialize movement variables
	xOffset = x;
	yOffset = y;
	speed =  14;
        radius = 8;
        damage = 0;

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
        
        damage=0;
        
        result="";
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
                //else if(Upointer->myside()==0) return "Player 2";
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
		if ( xOffset + 8 <= 0 ||
		xOffset + 8 >= Global::GAME_WIDTH)
                         conditionwall="hit";
	}
	if ( yVel != 0 )
	{
		yOffset += yVel;
		if ( yOffset + 8 <= 0 ||
		yOffset + 8 >= Global::GAME_HEIGHT)
                         conditionwall="hit";
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

