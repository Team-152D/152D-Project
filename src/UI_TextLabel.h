#ifndef TEXTLABEL_H
#define	TEXTLABEL_H

#include <iostream>
#include <string>

#include "Text.h"
#include "UI_AbstractElement.h"

class UI_TextLabel : public UI_AbstractElement
{
public:
    UI_TextLabel(SDL_Rect,string,int,bool);
    ~UI_TextLabel();
    int handleEvents(SDL_Event*);
    void draw();
private:
    string displayString;
    int displaySize;
    bool displayCentered;
};

#endif