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

	ammobox_sprite = image->loadImage( "rsc\\game\\object_Ammobox.bmp" ); 
	if ( ammobox_sprite == NULL)
		cout << "Box sprite didn't load" << endl;
}

Ammobox::~Ammobox()
{
    //Free the surface
    SDL_FreeSurface(ammobox_sprite);

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
        get++;
        target=characters->at(get);
    }
}

void Ammobox::draw(){
    image->drawSurface(xOffset+4,yOffset+4,ammobox_sprite);
}