#include "Monster.h"
#include "Game.h"
#include "Enumerations.h"

Monster::Monster(int x, int y)
{
    //Initialize movement variables
    health = 50;
    xOffset = x;
    yOffset = y;
    xVel = 0;
    yVel = 0;
    speed = 16;
    cooldown =0;
    alive=true;
    radius=16;
    teamID=1;
    damage=15;
    ammo=0;
    num=0;

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
    if(sightcooldown<=0){
        seesPlayer=sight_check();
        sightcooldown=30;}
    if(seesPlayer==true){knowsPlayerlocation=true; losessighttimer=0;}
    if(knowsPlayerlocation==true){
        int playerX=target->getXoffset();
        int playerY=target->getYoffset();
            
        if(yOffset<playerY){
	    if ( yVel < speed )
		yVel += speed;
        }
        else if(yOffset>playerY){
            if ( yVel > ( 0 - speed ) )
		yVel -= speed;
        }            
        if(xOffset<playerX){
	    if ( xVel < speed )
	        xVel += speed;
	}
        else if(xOffset>playerX){
            if ( xVel > ( 0 - speed ) )
		xVel -= speed;
	    }
        int up= sqrt( pow(xOffset-playerX, 2 ) + pow((yOffset-radius)-playerY, 2 ));
        int right= sqrt( pow((xOffset+radius)-playerX, 2 ) + pow(yOffset-playerY, 2 ));
        int down= sqrt( pow(xOffset-playerX, 2 ) + pow((yOffset+radius)-playerY, 2 ));
        int left= sqrt( pow((xOffset-radius)-playerX, 2 ) + pow(yOffset-playerY, 2 ));
            
        if(up>=right && up>=left && up>=down){direction = DIR_DOWN;}
        else if(right>=up && right>=left && right>=down){direction = DIR_LEFT;}
        else if(down>=up && down>=right && down>=left){direction = DIR_UP;}
        else{direction = DIR_RIGHT;}
    }
    if(seesPlayer==false&&knowsPlayerlocation==true){
        losessighttimer++;
        if(losessighttimer>=(10*30)){
            knowsPlayerlocation=false;
            target=NULL;
        }
    }
    if(knowsPlayerlocation==false){
        if(patrolsteps<=0){
            patroldirection= rand() % 100 + 1;
            patrolsteps=10;
        }
            
        switch (patroldirection%4)
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

bool Monster::sight_check(){
    
    string canisee="";
    string currsight;
    int myX=getXoffset();
    int myY=getYoffset();
    
    int shoot_direction;
    switch ( direction ){
	case DIR_UP:
	    shoot_direction=0;
            for(int i=-70;i<=70;i+=20){
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
            for(int i=-70;i<=70;i+=20){
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
            for(int i=-70;i<=70;i+=20){
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
            for(int i=-70;i<=70;i+=20){
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
        int decide = rand() +1;
        switch (decide){
            case 1:
                target = player1;
            break;
            case 2:
                target = player2;
            break;            
        }
        return true;
    }
    else{return false;}
}

bool Monster::checkGates(){
    bool stop=false;
    vector<Gate*>* gates=currentLevelGlobal->getGates();
    Gate* gpointer;
    for(int i=0;i<gates->size();i++){
        gpointer=gates->at(i);
        if(gpointer->collision(xOffset, yOffset, radius)==true)
            stop=true;
    }
    return stop;
}

bool Monster::checkCharacters(){
    bool stop=false;
    int hurt=0;
    vector<Unit*>* characters=currentLevelGlobal->getCharacters();
    Unit* upointer;
    for(int i=0;i<characters->size();i++){
        upointer=characters->at(i);
        if(upointer->myside()!=teamID&&cooldown<=0){
            hurt=damage;
            cooldown=30;
        }
        if(upointer->hit(xOffset,yOffset,radius,hurt)==true && upointer!=this)
            stop=true;
        hurt=0;
    }
    return stop;
}

void Monster::update()
{
    AI();
    
    //begin object collision detection
    vector<Object*> impact= objsAhead(*currentLevelGlobal->getObjects());
    vector<Object*>::iterator it= impact.begin();
    while(it!=impact.end()) (*it)->collide(this);
    //end object collision detection
    
    if(cooldown>0)
        cooldown--;
    if(sightcooldown>0)
        sightcooldown--;
    
    //cout<<"updating enemy x"<<endl;
    if ( xVel != 0 )
    {
        if(knowsPlayerlocation==true)
            xVel/=2;
        else
            xVel/=2;
	xOffset += xVel;
	if ( xOffset + 16 <= 0+32 ||
		xOffset + 16 >= Enumerations::LEVEL_WIDTH-32 ||
		currentLevelGlobal->getGrid()->getTileAt(( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32) == 8 ||
                checkGates()||checkCharacters()){
	    xOffset -= xVel;}
	if ( xVel < 0 )
	    direction = DIR_LEFT;
	else if ( xVel > 0 )
	    direction = DIR_RIGHT;
    }
    //cout<<"updating enemy y"<<endl;
    if ( yVel != 0 )
    {
        if(knowsPlayerlocation==true)
            yVel/=2;
        else
            yVel/=2;
	yOffset += yVel;
	if ( yOffset + 16 <= 0+32 ||
		yOffset + 16 >= Enumerations::LEVEL_HEIGHT-32 ||
		currentLevelGlobal->getGrid()->getTileAt(( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32) == 8 ||
                checkGates()||checkCharacters()){
	    yOffset -= yVel;}
	if ( yVel < 0 )
	    direction = DIR_UP;
	else if ( yVel > 0 )
	    direction = DIR_DOWN;
    }
    //cout<<"checking tiles"<<endl;
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
