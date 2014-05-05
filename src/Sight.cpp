#include "Sight.h"
#include "Game.h"
//
Sight::Sight( int x, int y, int d, int ID )
{
	//Initialize movement variables
	xOffset = x;
	yOffset = y;
	speed =  20;
        radius = 10;
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
        
        max_length = x +300;
        min_length = x -300;
        max_height = y +300;
        min_height = y -300;       
        
	//ID: 0=player, 1=enemy
	teamID = ID;
        
        damage=0;
        
        result="";
}

Sight::~Sight( ){}

string Sight::hit(){
    bool has_hit;
    string result;
    vector<Unit*>* characters = currentLevelGlobal->getCharacters();
    Unit* Upointer;
    
    for(int i=0;i<characters->size();i++){
        Upointer=characters->at(i);
        if(teamID!=Upointer->myside()){
            has_hit=Upointer->hit(xOffset,yOffset,radius,damage);
            if(has_hit==true&&Upointer->mynum()>0){
                //result = "Player "+Upointer->mynum();
                result = "Player 1";
                return result;
            }
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
		if ( xOffset + 8 <= 0 ||
		xOffset + 8 >= Global::GAME_WIDTH || xOffset<=min_length || xOffset >=max_length)
                         conditionwall="hit";
	}
	if ( yVel != 0 )
	{
		yOffset += yVel;
		if ( yOffset + 8 <= 0 ||
		yOffset + 8 >= Global::GAME_HEIGHT || yOffset<=min_height || yOffset >=max_height)
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

