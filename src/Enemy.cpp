#include "Enemy.h"
#include "Game.h"
//
Enemy::Enemy(int x, int y, int ID)
{
    //Initialize movement variables
    health = 100;
    xOffset = x;
    yOffset = y;
    xPos = xOffset + 16;
    yPos = yOffset + 16;
    xVel = 0;
    yVel = 0;
    speed = 6;
    cooldown =0;
    dead=false;
    size=32;
    teamID=ID;

    //Initialize animation variables
    frame = 0;
    direction = DIR_RIGHT;

    seesPlayer=false;
    knowsPlayerlocation=false;
    
    losessighttimer=0;
    
    player1 = currentLevelGlobal->getPlayer(1);
    if(currentLevelGlobal->isMultiplayer()) 
        player2 = currentLevelGlobal->getPlayer(2);
    target = player1;
    
    set_clips();

	enemy_sprite_up = image->loadImage( "rsc\\game\\sprite_RedUp.bmp" ); // move up
	enemy_sprite_right = image->loadImage( "rsc\\game\\sprite_RedRight.bmp" ); // move right
	enemy_sprite_down = image->loadImage( "rsc\\game\\sprite_RedDown.bmp" ); // move down
	enemy_sprite_left = image->loadImage( "rsc\\game\\sprite_RedLeft.bmp" ); // move left
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
    //knowsPlayerlocation=true;
    if(knowsPlayerlocation==false){
        seesPlayer=sight_check();
        if(seesPlayer==true){knowsPlayerlocation=true;}
        else if(seesPlayer==false&&knowsPlayerlocation==true){
            losessighttimer++;
            if(losessighttimer>=(4*30)){
                knowsPlayerlocation=false;
                target=NULL;
            }
        }
    }
    else{
        int playerX=target->getX();
        int playerY=target->getY();
        
        int myX=getX();
        int myY=getY();
    
        int distance=sqrt( pow(myX-playerX, 2 ) + pow(myY-playerY, 2 ));
        if(distance>=100){
            if(myY<playerY+20) yVel += speed;
            else if(myY>playerY+20) yVel -= speed;
            
            if(myX<playerX+20) xVel += speed;
            else if(myX>playerX+20) xVel -= speed;
        }
        else{yVel=0;xVel=0;}
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
            for(int i=-25;i<25;i++){
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
            for(int i=-25;i<25;i++){
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
            for(int i=-25;i<25;i++){
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
                    target=player1;
                else
                    target=player2;
            }
        return true;
    }
    else{return false;}
}

void Enemy::shooting(){
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
    
    int myX=getX();
    int myY=getY();
    Projectile* shoot;
    shoot=new Projectile(myX,myY,direction,0);
    vector<Mover*>*  projectiles=currentLevelGlobal->getMovers();
    projectiles->push_back(shoot);
    cooldown=15;
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

void Enemy::update()
{
    AI();
    cout<<"updating enemy x"<<endl;
    if ( xVel != 0 )
    {
	xOffset += xVel;
	if ( xOffset + 16 <= 0 ||
		xOffset + 16 >= Global::GAME_WIDTH ||
		currentLevelGlobal->getGrid()->getTileAt(( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32) == 8 )
	    xOffset -= xVel;
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
		currentLevelGlobal->getGrid()->getTileAt(( xOffset + 16 ) / 32, ( yOffset + 16 ) / 32) == 8 )
	    yOffset -= yVel;
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
