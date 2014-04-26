#include "UI_IPfield.h"

UI_IPfield::UI_IPfield(SDL_Rect fieldSize, int textSize, bool center){
    addr= ""; mousedown= focus= false; centered= center;
    fontSize= textSize; bounds= fieldSize; blink.start();
	ipSav.open("rsc\\data\\data_ip.txt",std::fstream::in);
    //the below variables are static and have room for generalization/abstraction
    bg= image->loadImage("rsc\\ui\\ui_IPfield.bmp");
    
    getline(ipSav, addr);
	ipSav.close();
}

int UI_IPfield::handleEvents(SDL_Event* ev){
    if(ev->type== SDL_KEYDOWN && focus){
        char k= ev->key.keysym.sym;
        if(isdigit(k) || k== '.')
            addr.push_back(k);
        else if(k== '\b') addr.pop_back();       
    } else{
        int x, y;
        SDL_GetMouseState(&x, &y);
        if(coordinatesAreInRect(x, y, bounds)){
                if(ev->type== SDL_MOUSEBUTTONDOWN) mousedown= true;
                else if(ev->type== SDL_MOUSEBUTTONUP && mousedown){
                    mousedown= false; focus= true;
                }
        } 
        else if(ev->type== SDL_MOUSEBUTTONDOWN) focus= false;
        else if(ev->type== SDL_MOUSEBUTTONUP) mousedown= false;        
    }
}

void UI_IPfield::draw(){
    //note the src background must operate with increments of 10pixels (x-axis))
    for ( int i = bounds.x; i < ( bounds.x + bounds.w ); i += 10 )
        image->drawSurface(i, bounds.y, bg);
    cursorBlink();
    if( centered )
	text->writeTextCentered(bounds,addr.c_str(),fontSize);
    else
	text->writeText(bounds.x,bounds.y,addr.c_str(),fontSize);
}

void UI_IPfield::cursorBlink(){
    if(!focus)
        if(addr.back()=='|'){
            addr.pop_back();
            return;
        } else return;
    int t= blink.get_ticks()/1000;
    if(t%2 && addr.back()!='|')
        addr.push_back('|');
    else if(!(t%2) && addr.back()=='|')
        addr.pop_back();
}

void UI_IPfield::setIP(){
	ipSav.open("rsc\\data\\data_ip.txt",std::fstream::out | std::fstream::trunc);
	ipSav << addr;
	ipSav.close();
}