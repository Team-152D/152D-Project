#include "UI_Button.h"
#include "Settings.h"

UI_Button::UI_Button(SDL_Rect rect, char* label, int actionValue)
{
    mouseover = false;
    mousedown = false;

    bounds = rect;
    textLabel = label;
    action = actionValue;

    /*cout
	<< bounds.w << " x " << bounds.h << " button created at ("
	<< bounds.x << "," << bounds.y << ")" << endl
	<< "Label is: " << textLabel
	<< " and action value is: " << action << endl;
    */

    button = image->loadImage("rsc\\ui\\ui_tempButton.bmp");
    mousedownHighlight = image->loadImage("rsc\\ui\\ui_tempHighlightButtonDown.bmp");
    mouseoverHighlight = image->loadImage("rsc\\ui\\ui_tempHighlightMouseOver.bmp");
}

UI_Button::~UI_Button()
{
    delete button;
    delete mouseoverHighlight;
    delete mousedownHighlight;
}

int UI_Button::handleEvents(SDL_Event* event)
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    bool inRect = coordinatesAreInRect(x, y, bounds);
    switch ( event->type )
    {
	case SDL_MOUSEMOTION:
	    if ( inRect )
		mouseover = true;
	    else
		mouseover = false;
	    break;
	case SDL_MOUSEBUTTONDOWN:
	    if ( inRect )
		mousedown = true;
	    break;
	case SDL_MOUSEBUTTONUP:
	    if ( mousedown )
		mousedown = false;
	    if ( inRect )
	    {
		//cout << "DEBUG: ( Button::handleEvents() ) Button with action value " << action
		//<< " received click at (" << x << "," << y << ")" << endl;
		//if ( settings->getUiSfxEnabled() )
		if( settings->getUiSfxEnabled() )
		    audio->playSound("rsc\\audio\\sfx_buttonPress.wav");
		return action;
	    }
	    break;
	default:
	    break;
    }
    return Global::CONTINUE;
}

void UI_Button::draw()
{
    //draw button rectangle
    for ( int i = bounds.x; i < ( bounds.x + bounds.w ); i += 10 )
	image->drawSurface(i, bounds.y, button);

    //draw mouseover if applicable
    if ( mouseover )
	for ( int j = bounds.x; j < ( bounds.x + bounds.w ); j += 10 )
	    image->drawSurface(j, bounds.y, mouseoverHighlight);

    //draw mousedown if applicable
    if ( mousedown )
	for ( int k = bounds.x; k < ( bounds.x + bounds.w ); k += 10 )
	    image->drawSurface(k, bounds.y, mousedownHighlight);

    //write text
    text->writeTextCentered(bounds, textLabel.c_str(), 36);
}