#ifndef BUTTON_H
#define	BUTTON_H

#include <iostream>
#include <string>

#include "Audio.h"
#include "Global.h"
#include "Image.h"
#include "Text.h"
#include "UI_AbstractElement.h"

using namespace std;

class UI_Button : public UI_AbstractElement
{
public:
    UI_Button(SDL_Rect,char*,int);
    ~UI_Button();
    
    int handleEvents(SDL_Event*);
    void draw();
private:
    string textLabel;
    int action;
    
    bool mouseover;
    bool mousedown;
    
    SDL_Surface* button;
    SDL_Surface* mouseoverHighlight;
    SDL_Surface* mousedownHighlight;
};

#endif