#include "MobileBoxes.h"
#include "Level.h"
#include "Enumerations.h"

PushBox::PushBox(int x, int y){
    otype= "PushBox";
    bounds.x= x; bounds.y= y;
    bounds.w= bounds.h= 32;
    xVel= yVel= 0;
    //need to correct bellow image
    bg= image->loadImage("rsc\\game\\tile_det.bmp");     
}

void PushBox::draw(){image->drawSurface(bounds.x, bounds.y, bg);}

void PushBox::collide(Unit* impact){
    if(impact->myside()) {impact->stop(); return;}//non-player collision
    //player collision, disallowing diagonal pushes
    int tx, ty, tw, th; tx= impact->getXVel(), ty=impact->getYVel();
    if((tx && !ty) || (!tx && ty)){ xVel= tx; yVel= ty;}  
    //check if push would send box out of map bounds
    if(bounds.x+xVel < 0 || bounds.x+bounds.w+xVel > Enums::GRID_WIDTH)
        xVel= 0;
    if(bounds.y+yVel < 0 || bounds.y+bounds.h+yVel > Enums::GRID_HEIGHT)
        yVel= 0;
    //check if box movement would cause a collision with another object
    vector<Object*>* check= currentLevelGlobal->getObjects();
    vector<Object*>::iterator it = check->begin();
    while (it != check->end() && (xVel || yVel)){
        if((*it)->getType()=="PushBox"){
            tx= (*it)->getCord().x, ty= (*it)->getCord().y,
            tw= (*it)->getCord().w, th= (*it)->getCord().h;
            //invalid horizontal movement
            if(bounds.y+bounds.h >= ty && bounds.y <= ty+th &&
              (xVel+bounds.x+bounds.w >= tx || xVel+bounds.x <= tx+tw)
            ) {xVel= 0; break;}
            //invalid vertical movement
            else if(bounds.x <= tx+tw && bounds.x+bounds.w >= tx &&
              (yVel+bounds.y <= ty+th || yVel+bounds.y+bounds.h >= ty)    
            ) {yVel= 0; break;}
        }
    }
    //end collision checking with other objects
    //begin checking collision with units
    vector<Unit*>* checku= currentLevelGlobal->getCharacters();
    vector<Unit*>::iterator itu = checku->begin();
    while(itu!= checku->end() && (xVel || yVel)){
            tx= (*itu)->getXoffset()-(*itu)->myradius(), 
            ty= (*itu)->getYoffset()-(*itu)->myradius(),
            tw= (*itu)->getXoffset()+(*itu)->myradius(),
            th= (*itu)->getYoffset()+(*itu)->myradius();
            //invalid horizontal movement
            if(bounds.y+bounds.h >= ty && bounds.y <= ty+th &&
              (xVel+bounds.x+bounds.w >= tx || xVel+bounds.x <= tx+tw)
            ) {xVel= 0; break;}
            //invalid vertical movement
            else if(bounds.x <= tx+tw && bounds.x+bounds.w >= tx &&
              (yVel+bounds.y <= ty+th || yVel+bounds.y+bounds.h >= ty)    
            ) {yVel= 0; break;}
    } //end checking collision with units
    if(!xVel && !yVel) {impact->stop(); return;}
    bounds.x+= xVel; bounds.y+=yVel; xVel= 0; yVel= 0;
}
