#include "Guard.h"
#include "Game.h"
//
Guard::Guard(int x, int y)
{
    //Initialize movement variables
    health = 80;
    xOffset = x;
    yOffset = y;
    xVel = 0;
    yVel = 0;
    speed = 6;
    cooldown = 0;
    alive=true;
    radius=16;
    teamID=1;
    ammo=0;
    sightcooldown=0;

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

	guard_sprite_up = image->loadImage( "rsc\\game\\sprite_RedUp.bmp" ); // move up
	guard_sprite_right = image->loadImage( "rsc\\game\\sprite_RedRight.bmp" ); // move right
	guard_sprite_down = image->loadImage( "rsc\\game\\sprite_RedDown.bmp" ); // move down
	guard_sprite_left = image->loadImage( "rsc\\game\\sprite_RedLeft.bmp" ); // move left
	if ( guard_sprite_up == NULL || guard_sprite_right == NULL || guard_sprite_down == NULL || guard_sprite_left == NULL )
		cout << "Guard sprite didn't load" << endl;
}

Guard::~Guard()
{
    //Free the surface
    SDL_FreeSurface(guard_sprite_up);
    SDL_FreeSurface(guard_sprite_right);
    SDL_FreeSurface(guard_sprite_down);
    SDL_FreeSurface(guard_sprite_left);

}

void Guard::apply_surface(int x, int y, SDL_Surface* source, SDL_Rect* clip)
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = xOffset;
    offset.y = yOffset;

    //Blit
    SDL_BlitSurface(source, clip, screenSurface, &offset);
}


void Guard::AI(){
    if(knowsPlayerlocation==false){
        if(sightcooldown>0){sightcooldown--;return;}
        seesPlayer=sight_check();
        if(seesPlayer==true){knowsPlayerlocation=true;}
        else if(seesPlayer==false&&knowsPlayerlocation==true){
            losessighttimer++;
            if(losessighttimer>=(4*30)){
                knowsPlayerlocation=false;
                target=NULL;
            }
        }
        else{
            if(patrolsteps<=0){
                patroldirection= rand() % 4 + 1;
                patrolsteps=20;
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
        int playerX=target->getXoffset();
        int playerY=target->getYoffset();
        
        int myX=getXoffset();
        int myY=getYoffset();
    
        int distance=sqrt( pow(myX-playerX, 2 ) + pow(myY-playerY, 2 ));
        if(distance>=100){
            if(myY<playerY+20) yVel += speed;
            else if(myY>playerY+20) yVel -= speed;
            
            if(myX<playerX+20) xVel += speed;
            else if(myX>playerX+20) xVel -= speed;
        }
        /*else{
            
        }*/
        else{yVel=0;xVel=0;}
        if(distance<=200){shooting();}
    }
}

bool Guard::sight_check(){
    
    string canisee="";
    string currsight;
    int myX=getXoffset();
    int myY=getYoffset();
    
    int shoot_direction;
    switch ( direction ){
	case DIR_UP:
	    shoot_direction=0;
            for(int i=-25;i<=25;i+=16){
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
            for(int i=-25;i<=25;i+=16){
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
            for(int i=-25;i<=25;i+=16){
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
            for(int i=-25;i<=25;i+=16){
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
        string difficulty=currentLevelGlobal->getDifficulty();
            if(difficulty=="Easy"){
                target=player1;
            }
            else if(difficulty=="Medium"||difficulty=="Hard"){
                int hp1 = player1->getHealth();
                int hp2 = player2->getHealth();
                if(hp1>=hp2)
                    target=player2;
                else
                    target=player1;
            }
        return true;
    }
    else{return false;}
}

void Guard::shooting(){
    if(cooldown>0){cooldown--; return;}
    
    int shoot_direction=0;
    switch ( direction ){
	case DIR_UP:
	    shoot_direction=0;
	    break;
	case DIR_RIGHT:
	    shoot_direction=1;
	    break;
	case DIR_DOWN:
	    shoot_direction=2;
	    break;
	case DIR_LEFT:
	    shoot_direction=3;
	    break;
    }
    Projectile* shoot;
    shoot=new Projectile(xOffset,yOffset,shoot_direction,1);
    vector<Mover*>*  projectiles=currentLevelGlobal->getMovers();
    projectiles->push_back(shoot);
    cooldown=15;
}

bool Guard::checkGates(){
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

void Guard::checkSwitches(){
    vector<Switch*>* switches=currentLevelGlobal->getSwitches();
    Switch* spointer;
    for(int i=0;i<switches->size();i++){
        spointer=switches->at(i);
        if(spointer->collision(xOffset, yOffset, radius)==true)
            spointer->down();
    }
}

void Guard::update()
{
    AI();
    checkSwitches();
    
    cout<<"updating enemy x"<<endl;
    if ( xVel != 0 )
    {
        if(knowsPlayerlocation==false){
            xVel=xVel/2;
        }
	xOffset += xVel;
	if ( xOffset + 16 <= 0+32 ||
		xOffset + 16 >= Global::GAME_WIDTH-32 ||
		currentLevelGlobal->getGrid()->getTileAt(( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32) == 8 ||
                currentLevelGlobal->getGrid()->getTileAt(( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32) == 5 ||
                checkGates()){
	    xOffset -= xVel; patrolsteps=0;}
	if ( xVel < 0 )
	    direction = DIR_LEFT;
	else if ( xVel > 0 )
	    direction = DIR_RIGHT;
    }
    cout<<"updating enemy y"<<endl;
    if ( yVel != 0 )
    {
        if(knowsPlayerlocation==false){
            yVel=yVel/2;
        }
	yOffset += yVel;
	if ( yOffset + 16 <= 0+32 ||
		yOffset + 16 >= Global::GAME_HEIGHT-32 ||
		currentLevelGlobal->getGrid()->getTileAt(( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32) == 8 ||
                currentLevelGlobal->getGrid()->getTileAt(( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32) == 5 ||
                checkGates()){
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

void Guard::draw()
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
	    apply_surface(xOffset - 16, yOffset - 16, guard_sprite_up, &spriteClips[frame]);
	    break;
	case DIR_RIGHT:
	    apply_surface(xOffset - 16, yOffset - 16, guard_sprite_right, &spriteClips[frame]);
	    break;
	case DIR_DOWN:
	    apply_surface(xOffset - 16, yOffset - 16, guard_sprite_down, &spriteClips[frame]);
	    break;
	case DIR_LEFT:
	    apply_surface(xOffset - 16, yOffset - 16, guard_sprite_left, &spriteClips[frame]);
	    break;

    }
}

void Guard::set_clips()
{
    //Clip the sprites Right move
    spriteClips[ 0 ].x = GUARD_WIDTH;
    spriteClips[ 0 ].y = 0;
    spriteClips[ 0 ].w = GUARD_WIDTH;
    spriteClips[ 0 ].h = GUARD_HEIGHT;

    spriteClips[ 1 ].x = 0;
    spriteClips[ 1 ].y = 0;
    spriteClips[ 1 ].w = GUARD_WIDTH;
    spriteClips[ 1 ].h = GUARD_HEIGHT;

    spriteClips[ 2 ].x = GUARD_WIDTH;
    spriteClips[ 2 ].y = 0;
    spriteClips[ 2 ].w = GUARD_WIDTH;
    spriteClips[ 2 ].h = GUARD_HEIGHT;

    spriteClips[ 3 ].x = GUARD_WIDTH * 2;
    spriteClips[ 3 ].y = 0;
    spriteClips[ 3 ].w = GUARD_WIDTH;
    spriteClips[ 3 ].h = GUARD_HEIGHT;
}
