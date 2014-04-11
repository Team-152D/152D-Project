#include "Monster.h"
#include "Game.h"
//
Monster::Monster(int x, int y, int ID)
{
    //Initialize movement variables
    health = 125;
    xOffset = x;
    yOffset = y;
    xPos = xOffset + 16;
    yPos = yOffset + 16;
    xVel = 0;
    yVel = 0;
    speed = 10;
    cooldown =0;
    dead=false;
    size=32;
    teamID=ID;
    damage=15;

    //Initialize animation variables
    frame = 0;
    direction = DIR_RIGHT;

    seesPlayer=false;
    knowsPlayerlocation=false;
    patroldirection=0;
    patrolsteps=0;
    
    losessighttimer=0;
    
    player1 = currentLevelGlobal->getPlayer(1);
    if(currentLevelGlobal->isMultiplayer()) 
        player2 = currentLevelGlobal->getPlayer(2);
    target = player1;
    
    set_clips();

	monster_sprite_up = image->loadImage( "rsc\\game\\sprite_RedUp.bmp" ); // move up
	monster_sprite_right = image->loadImage( "rsc\\game\\sprite_RedRight.bmp" ); // move right
	monster_sprite_down = image->loadImage( "rsc\\game\\sprite_RedDown.bmp" ); // move down
	monster_sprite_left = image->loadImage( "rsc\\game\\sprite_RedLeft.bmp" ); // move left
	if ( monster_sprite_up == NULL || monster_sprite_right == NULL || monster_sprite_down == NULL || monster_sprite_left == NULL )
		cout << "Monster sprite didn't load" << endl;
}

Monster::~Monster()
{
    //Free the surface
    SDL_FreeSurface(monster_sprite_up);
    SDL_FreeSurface(monster_sprite_right);
    SDL_FreeSurface(monster_sprite_down);
    SDL_FreeSurface(monster_sprite_left);

}

void Monster::apply_surface(int x, int y, SDL_Surface* source, SDL_Rect* clip)
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = xOffset;
    offset.y = yOffset;

    //Blit
    SDL_BlitSurface(source, clip, screenSurface, &offset);
}


void Monster::AI(){
    if(knowsPlayerlocation==false){
        seesPlayer=sight_check();
        if(seesPlayer==true){knowsPlayerlocation=true;}
        else if(seesPlayer==false&&knowsPlayerlocation==true){
            losessighttimer++;
            if(losessighttimer>=(1*30)){
                knowsPlayerlocation=false;
                target=NULL;
            }
        }
        else{
            if(patrolsteps<=0){
                patroldirection= rand() % 4 + 1;
                patrolsteps=10;
            }
            
            switch (patroldirection)
	    {
	        case 1:
		    yVel += speed;
	        break;
	        case 2:
		    xVel += speed;
		break;
	        case 3:
		    yVel += speed;
		break;
	        case 4:
		    xVel += speed;
		break;
	    }
            
            patrolsteps--;
        }
    }
    else{
        int playerX=target->getX();
        int playerY=target->getY();
        
        int myX=getX();
        int myY=getY();
    
        if(myY<playerY+20) yVel += speed;
        else if(myY>playerY+20) yVel -= speed;
            
        if(myX<playerX+20) xVel += speed;
        else if(myX>playerX+20) xVel -= speed;
    }
}

bool Monster::sight_check(){

    string canisee="";
    string currsight;
    int myX=getX();
    int myY=getY();
    
    int shoot_direction;
    switch ( direction ){
	case DIR_UP:
	    shoot_direction=0;
            for(int i=-10;i<10;i++){
                Sight* look=new Sight(myX+i,myY,shoot_direction,1);
                currsight=look->look();
                delete look;
                if(currsight=="Player 1"&&canisee=="")
                    canisee="Player 1";
                else if(currsight=="Player 1"&&canisee=="Player 2")
                    canisee="Both Players";
                else if(currsight=="Player 2"&&canisee=="")
                    canisee="Player 2";
                else if(currsight=="Player 2"&&canisee=="Player 1")
                    canisee="Both Players";
                }
	    break;
	case DIR_RIGHT:
	    shoot_direction=1;
            for(int i=-10;i<10;i++){
                Sight* look=new Sight(myX,myY+i,shoot_direction,1);
                currsight=look->look();
                delete look;
                if(currsight=="Player 1"&&canisee=="")
                    canisee="Player 1";
                else if(currsight=="Player 1"&&canisee=="Player 2")
                    canisee="Both Players";
                else if(currsight=="Player 2"&&canisee=="")
                    canisee="Player 2";
                else if(currsight=="Player 2"&&canisee=="Player 1")
                    canisee="Both Players";
                }
	    break;
	case DIR_DOWN:
	    shoot_direction=2;
            for(int i=-10;i<10;i++){
                Sight* look=new Sight(myX+i,myY,shoot_direction,1);
                currsight=look->look();
                delete look;
                if(currsight=="Player 1"&&canisee=="")
                    canisee="Player 1";
                else if(currsight=="Player 1"&&canisee=="Player 2")
                    canisee="Both Players";
                else if(currsight=="Player 2"&&canisee=="")
                    canisee="Player 2";
                else if(currsight=="Player 2"&&canisee=="Player 1")
                    canisee="Both Players";
                }
	    break;
	case DIR_LEFT:
	    shoot_direction=3;
            for(int i=-10;i<10;i++){
                Sight* look=new Sight(myX,myY+i,shoot_direction,1);
                currsight=look->look();
                delete look;
                if(currsight=="Player 1"&&canisee=="")
                    canisee="Player 1";
                else if(currsight=="Player 1"&&canisee=="Player 2")
                    canisee="Both Players";
                else if(currsight=="Player 2"&&canisee=="")
                    canisee="Player 2";
                else if(currsight=="Player 2"&&canisee=="Player 1")
                    canisee="Both Players";
                }
	    break;
    }
    if(canisee!="")
        patrolsteps=0;
    
    if(canisee=="Player 1"){target=player1; return true;}
    else if(canisee=="Player 2"){target=player2; return true;}
    else if(canisee=="Both Players"){
        if((rand() % 2 + 1) == 1) target=player1;
        else target=player2;
        return true;
    }
    else{return false;}
}

bool Monster::hit(int x, int y, int damage){
    bool hit=false;
    int distance;
    distance= sqrt( pow( x - xOffset , 2 ) + pow( y - yOffset , 2 ));
    if (distance<=16)
        hit=true;
    
    if(hit==true)
        health-=damage;
    return hit;
}

void Monster::attack(){
    if(cooldown>0)
        cooldown--;
    else{
        bool n;
        vector<Unit*>* characters = currentLevelGlobal->getCharacters();
        Unit* upointer;
        for(int i=0; i<characters->size();i++){
            upointer=characters->at(i);
            if(upointer->myside()!=teamID)
                n=upointer->hit(xOffset+16, yOffset+16, damage);
        }
        if(n==true)
            cooldown=2*30;
    }
}

bool Monster::checkGates(int x, int y){
    bool stop=false;
    vector<Gate*>* gates=currentLevelGlobal->getGates();
    Gate* gpointer;
    for(int i=0;i<gates->size();i++){
        gpointer=gates->at(i);
        if(gpointer->collision(x,y)==true)
            stop=true;
    }
    return stop;
}

void Monster::update()
{
    AI();
    attack();
    
    cout<<"updating enemy x"<<endl;
    if ( xVel != 0 )
    {
	xOffset += xVel;
	if ( xOffset + 16 <= 0 ||
		xOffset + 16 >= Global::GAME_WIDTH ||
		currentLevelGlobal->getGrid()->getTileAt(( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32) == 8 ||
                checkGates(xOffset+16, yOffset+16)){
	    xOffset -= xVel; patrolsteps=0;}
	if ( xVel < 0 )
	    direction = DIR_LEFT;
	else if ( xVel > 0 )
	    direction = DIR_RIGHT;
    }
    cout<<"updating enemy y"<<endl;
    if ( yVel != 0 )
    {
	yOffset += yVel;
	if ( yOffset + 16 <= 0 ||
		yOffset + 16 >= Global::GAME_HEIGHT ||
		currentLevelGlobal->getGrid()->getTileAt(( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32) == 8 ||
                checkGates(xOffset+16, yOffset+16)){
	    yOffset -= yVel; patrolsteps=0;}
	if ( yVel < 0 )
	    direction = DIR_UP;
	else if ( yVel > 0 )
	    direction = DIR_DOWN;
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

void Monster::draw()
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
	case DIR_UP:
	    apply_surface(xOffset - 16, yOffset - 16, monster_sprite_up, &spriteClips[frame]);
	    break;
	case DIR_RIGHT:
	    apply_surface(xOffset - 16, yOffset - 16, monster_sprite_right, &spriteClips[frame]);
	    break;
	case DIR_DOWN:
	    apply_surface(xOffset - 16, yOffset - 16, monster_sprite_down, &spriteClips[frame]);
	    break;
	case DIR_LEFT:
	    apply_surface(xOffset - 16, yOffset - 16, monster_sprite_left, &spriteClips[frame]);
	    break;

    }
}

void Monster::set_clips()
{
    //Clip the sprites Right move
    spriteClips[ 0 ].x = MONSTER_WIDTH;
    spriteClips[ 0 ].y = 0;
    spriteClips[ 0 ].w = MONSTER_WIDTH;
    spriteClips[ 0 ].h = MONSTER_HEIGHT;

    spriteClips[ 1 ].x = 0;
    spriteClips[ 1 ].y = 0;
    spriteClips[ 1 ].w = MONSTER_WIDTH;
    spriteClips[ 1 ].h = MONSTER_HEIGHT;

    spriteClips[ 2 ].x = MONSTER_WIDTH;
    spriteClips[ 2 ].y = 0;
    spriteClips[ 2 ].w = MONSTER_WIDTH;
    spriteClips[ 2 ].h = MONSTER_HEIGHT;

    spriteClips[ 3 ].x = MONSTER_WIDTH * 2;
    spriteClips[ 3 ].y = 0;
    spriteClips[ 3 ].w = MONSTER_WIDTH;
    spriteClips[ 3 ].h = MONSTER_HEIGHT;
}
