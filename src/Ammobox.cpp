#include "Ammobox.h"
#include "Game.h"
//
Ammobox::Ammobox(int x, int y, int rounds)
{
    xOffset=x;
    yOffset=y;
    xPos = xOffset+8;
    yPos = yOffset+8;
    obtained=false;
    poweruptype="ammo";
    contents=rounds;
    
    set_clips();

	ammobox_sprite = image->loadImage( "rsc\\game\\object_Ammobox.bmp" ); 
	if ( ammobox_sprite == NULL)
		cout << "Box sprite didn't load" << endl;
}

Ammobox::~Ammobox()
{
    //Free the surface
    SDL_FreeSurface(ammobox_sprite);

}

void Ammobox::apply_surface(int x, int y, SDL_Surface* source, SDL_Rect* clip)
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = xOffset;
    offset.y = yOffset;

    //Blit
    SDL_BlitSurface(source, clip, screenSurface, &offset);
}

void Ammobox::update(){
    Unit* target;
    int get=0;
    int x;
    int y;
    int radius;
    vector<Unit*>* characters;
    
    bool in=false;
    int distance;
    
    characters=currentLevelGlobal->getCharacters();
    
    target=characters->at(get);
    
    while(target->myside()==0){
        radius = target->myradius();
        x = target->getXoffset();
        y = target->getYoffset();
        
        if(x>=(xOffset-radius) && x<=(xPos+radius) && y>=(yOffset-radius) && y<=(yPos+radius))
        {
            obtained=true;
            target->addammo(contents); 
            return;
        }
        if(obtained==false){
            get++;
            target=characters->at(get);
        }    
    }
}

void Ammobox::draw()
{/*
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

    }*/
}

void Ammobox::set_clips()
{/*
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
*/}

