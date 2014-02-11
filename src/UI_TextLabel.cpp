#include "UI_TextLabel.h"

UI_TextLabel::UI_TextLabel(SDL_Rect iBounds,string iString,int iSize,bool iCentered)
{
    bounds = iBounds;
    displayString = iString;
    displaySize = iSize;
    displayCentered = iCentered;
}

UI_TextLabel::~UI_TextLabel()
{

}

int UI_TextLabel::handleEvents(SDL_Event*) {}

void UI_TextLabel::draw()
{
    if( displayCentered )
	text->writeTextCentered(bounds,displayString.c_str(),displaySize);
    else
	text->writeText(bounds.x,bounds.y,displayString.c_str(),displaySize);
}