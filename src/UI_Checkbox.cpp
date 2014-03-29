#include "UI_Checkbox.h"
#include "Audio.h"
#include "Image.h"
#include "Settings.h"
#include "Text.h"

UI_Checkbox::UI_Checkbox( SDL_Rect iBounds, char* iIdentifier, char* iLabel, int linkedValue )
{
	bounds = iBounds;
	identifier = iIdentifier;
	label = iLabel;
	isChecked = settings->getLinkedBool( linkedValue );

	checkboxBackground = image->loadImage( "rsc\\ui\\ui_checkboxBackground.bmp" );
	checkboxCheck = image->loadImage( "rsc\\ui\\ui_checkboxCheck.bmp" );
}

UI_Checkbox::~UI_Checkbox( ) { }

int UI_Checkbox::handleEvents( SDL_Event* event )
{
	int x, y;
	SDL_GetMouseState( &x, &y );
	bool inRect = coordinatesAreInRect( x, y, bounds );
	switch ( event->type )
	{
		case SDL_MOUSEBUTTONDOWN:
			if ( inRect )
				mouseDown = true;
			break;
		case SDL_MOUSEBUTTONUP:
			mouseDown = false;
			if ( inRect )
			{
				audio ->playSound( 4 );
				*isChecked = !( *isChecked );
			}
			break;
	}
}

void UI_Checkbox::draw( )
{
	image->drawSurface( bounds.x, bounds.y, checkboxBackground );
	if ( *isChecked )
		image->drawSurface( bounds.x, bounds.y, checkboxCheck );

	text->writeText( bounds.x + 50, bounds.y, label.c_str( ), 30 );
}