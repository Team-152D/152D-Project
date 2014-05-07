#include "DetTile.h"

DetTile::DetTile(int x, int y, int cnt){
    otype= "DetTile";
    if(cnt > 9 || cnt < 1) cnt= 3;
    cntMax= cntCur= cnt;
    bounds.x= x; bounds.y= y;
    bounds.w= 32; bounds.h= 32; 
    bg= image->loadImage("rsc\\game\\tile_det.bmp");
    blast_1= image->loadImage("rsc\\game\\object_Detonate1.bmp");
    blast_2= image->loadImage("rsc\\game\\object_Detonate2.bmp");
}

void DetTile::draw(){
    image->drawSurface(bounds.x, bounds.y, bg);
    
    char *t= ""; t+= cntCur+30;
    number.changeColor(244,20,20);
    number.writeTextCentered(bounds, t, 11);
    
    /*insert animation logic here*/
}

void DetTile::update(){
    vector<Unit*>::iterator it= above.begin();
    while(it!=above.end())
        if(!(*it)->hit(bounds.x+16, bounds.y+16, 16, 0))
            it= above.erase(it);
        else it++;                       
}

void DetTile::collide(Unit* impact){
    for(int i= above.size(); i>=0; i--)
        if(impact==above[i]) return;
    if(!impact->hit(bounds.x+16, bounds.y+16, 16, 0))
        return;
    above.push_back(impact); cntCur--;
    if(cntCur==0){
        cntCur= cntMax;
        //set blast animation variables here
        for(int i= above.size(); i>=0; i--)
            above[i]->hit(bounds.x+16, bounds.y+16, 16, 100);
    }      
}