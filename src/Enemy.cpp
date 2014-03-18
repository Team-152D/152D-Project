#include "Enemy.h"
#include "Game.h"
//
Enemy::Enemy(int x, int y)
{
    //Initialize movement variables
    health = 100;
    xOffset = x;
    yOffset = y;
    xPos = xOffset + 16;
    yPos = yOffset + 16;
    xVel = 0;
    yVel = 0;
    speed = 8;

    //Initialize animation variables
    frame = 0;
    direction = DIR_RIGHT;

    seesPlayer=false;
    shootingnow=false;
    knowsPlayerlocation=false;
    
    patroldirection=0; //0=no patrol, 1=up, 2=right, 3=bottom, 4=left
    patroltimer=0;
    
    losessighttimer=0;
    
    target = NULL;
    shoot=NULL;
    projectiles = NULL;
    
    set_clips();

    //Load the sprite sheet
    enemy_sprite_up = image->loadImage("resources\\sprite_RedUp.png"); // move up
    enemy_sprite_right = image->loadImage("resources\\sprite_RedRight.png"); // move right
    enemy_sprite_down = image->loadImage("resources\\sprite_RedDown.png"); // move down
    enemy_sprite_left = image->loadImage("resources\\sprite_RedLeft.png"); // move left
    if ( enemy_sprite_up == NULL || enemy_sprite_right == NULL || enemy_sprite_down == NULL || enemy_sprite_left == NULL )
	cout << "Enemy sprite didn't load" << endl;
}

Enemy::~Enemy()
{
    //Free the surface
    SDL_FreeSurface(enemy_sprite_up);
    SDL_FreeSurface(enemy_sprite_right);
    SDL_FreeSurface(enemy_sprite_down);
    SDL_FreeSurface(enemy_sprite_left);

}

void Enemy::apply_surface(int x, int y, SDL_Surface* source, SDL_Rect* clip)
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = xOffset;
    offset.y = yOffset;

    //Blit
    SDL_BlitSurface(source, clip, screenSurface, &offset);
}


void Enemy::AI(){
    
    if(knowsPlayerlocation==false){
        seesPlayer=sight_check();
        if(seesPlayer==true){
            knowsPlayerlocation=true;
            losessighttimer=0;
            patroltimer=0;
        }
    }
    if(seesPlayer==false&&knowsPlayerlocation==true){
        losessighttimer++;
        if(losessighttimer>=(120)){//loses player after 4 seconds of not being able to see them
            knowsPlayerlocation=false;
            target=NULL;
        }
    }
    if(knowsPlayerlocation==false){
        if(patroltimer<=0)
            patroldirection=0;
        
        if(patroldirection==0){
            patroldirection = rand() % 4 + 1; //0=no patrol, 1=up, 2=right, 3=bottom, 4=left
            patroltimer=90; //patrol in this direction for 3 seconds.
        }
        
        switch (patroldirection){
	case 1:
	    yVel -= (speed/3);
	    break;
	case 2:
	    xVel += (speed/3);
	    break;
	case 3:
	    yVel += (speed/3);
	    break;
	case 4:
	    xVel -= (speed/3);
	    break;
        }
        patroltimer--;
    }
    if(knowsPlayerlocation==true){
        //target=currentLevelGlobal->getPlayer(1);
        int playerX=target->getX();
        int playerY=target->getY();
    
        int myX=this->getX();
        int myY=this->getY();
    
        if(myY-playerY>=100){
            if(myY<playerY) yVel += speed;
            else if(myY>playerY) yVel -= speed;
        }
        if(myX-playerX>=100){
            if(myX<playerX) xVel += speed;
            else if(myX>playerX){} xVel -= speed;
        }
        int distance=sqrt( pow(myX-playerX, 2 ) + pow(myY-playerY, 2 ));
        if(distance<=200){shooting();}
    }
}

bool Enemy::sight_check(){

    string canisee="";
    string currsight;
    int myX=getX();
    int myY=getY();
    
    int shoot_direction;
    switch ( direction ){
	case DIR_UP:
	    shoot_direction=0;
            for(int i=-25;i<25;i++){
                Sight* look=new Sight(myX+i,myY,direction,0);
                currsight=look->look();
                look->end();
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
            for(int i=-25;i<25;i++){
                Sight* look=new Sight(myX,myY+i,direction,0);
                currsight=look->look();
                look->end();
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
            for(int i=-25;i<25;i++){
                Sight* look=new Sight(myX+i,myY,direction,0);
                currsight=look->look();
                look->end();
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
            for(int i=-25;i<25;i++){
                Sight* look=new Sight(myX,myY+i,direction,0);
                currsight=look->look();
                look->end();
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
    
    if(canisee=="Player 1"){target=currentLevelGlobal->getPlayer(1); return true;}
    else if(canisee=="Player 2"){target=currentLevelGlobal->getPlayer(2); return true;}
    else if(canisee=="Both Players"){
        string difficulty=currentLevelGlobal->getDifficulty();
            if(difficulty=="Easy"){
                target=currentLevelGlobal->getPlayer(1);
            }
            else if(difficulty=="Medium"||difficulty=="Hard"){
                Player* one=currentLevelGlobal->getPlayer(1);
                Player* two=currentLevelGlobal->getPlayer(2);
                int hp1 = one->getHP();
                int hp2 = two->getHP();
                if(hp1>=hp2)
                    target=one;
                else
                    target=two;
            }
        return true;
    }
    else{return false;}
}

void Enemy::shooting(){
    int shoot_direction;
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
    
    int myX=getX();
    int myY=getY();
    shoot=new Projectile(myX,myY,direction,0);
    projectiles=currentLevelGlobal->getProjectiles();
    projectiles->push_back(shoot);
}

bool Enemy::hit(int x, int y, int damage){
    bool hit=false;
    int distance;
    distance= sqrt( pow( x - xOffset , 2 ) + pow( y - yOffset , 2 ));
    if (distance<=16)
        hit=true;
    
    if(hit==true)
        health-=damage;
    return hit;
}

void Enemy::die(){
    
    if(health<=0) delete this;
}

void Enemy::update()
{
    cout<<"updating x"<<endl;
    AI();
    if ( xVel != 0 )
    {
	xOffset += xVel;
	if ( xOffset + 16 <= 0 ||
		xOffset + 16 >= Global::GAME_WIDTH ||
		currentLevelGlobal->getGrid()->getTileAt(( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32) == 8 ||
                currentLevelGlobal->getGrid()->getTileAt(( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32) == 5){
	        xOffset -= xVel; 
                patroltimer=0;
            }
	if ( xVel < 0 )
	    direction = DIR_LEFT;
	else if ( xVel > 0 )
	    direction = DIR_RIGHT;
    }
    cout<<"updating y"<<endl;
    if ( yVel != 0 )
    {
	yOffset += yVel;
	if ( yOffset + 16 <= 0 ||
		yOffset + 16 >= Global::GAME_HEIGHT ||
		currentLevelGlobal->getGrid()->getTileAt(( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32) == 8 ||
                currentLevelGlobal->getGrid()->getTileAt(( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32 )== 5 ){
	        yOffset -= yVel; 
                patroltimer=0;
            }
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

void Enemy::draw()
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
	    apply_surface(xOffset - 16, yOffset - 16, enemy_sprite_up, &spriteClips[frame]);
	    break;
	case DIR_RIGHT:
	    apply_surface(xOffset - 16, yOffset - 16, enemy_sprite_right, &spriteClips[frame]);
	    break;
	case DIR_DOWN:
	    apply_surface(xOffset - 16, yOffset - 16, enemy_sprite_down, &spriteClips[frame]);
	    break;
	case DIR_LEFT:
	    apply_surface(xOffset - 16, yOffset - 16, enemy_sprite_left, &spriteClips[frame]);
	    break;

    }
}

int Enemy::getX()
{
    return xOffset + 16;
}

int Enemy::getY()
{
    return yOffset + 16;
}

void Enemy::set_clips()
{
    //Clip the sprites Right move
    spriteClips[ 0 ].x = ENEMY_WIDTH;
    spriteClips[ 0 ].y = 0;
    spriteClips[ 0 ].w = ENEMY_WIDTH;
    spriteClips[ 0 ].h = ENEMY_HEIGHT;

    spriteClips[ 1 ].x = 0;
    spriteClips[ 1 ].y = 0;
    spriteClips[ 1 ].w = ENEMY_WIDTH;
    spriteClips[ 1 ].h = ENEMY_HEIGHT;

    spriteClips[ 2 ].x = ENEMY_WIDTH;
    spriteClips[ 2 ].y = 0;
    spriteClips[ 2 ].w = ENEMY_WIDTH;
    spriteClips[ 2 ].h = ENEMY_HEIGHT;

    spriteClips[ 3 ].x = ENEMY_WIDTH * 2;
    spriteClips[ 3 ].y = 0;
    spriteClips[ 3 ].w = ENEMY_WIDTH;
    spriteClips[ 3 ].h = ENEMY_HEIGHT;
}

int Enemy::getXVel()
{
    return xVel;
}

int Enemy::getYVel()
{
    return xVel;
}