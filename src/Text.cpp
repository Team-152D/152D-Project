#include "Text.h"

Text::Text()
{
    fontSize = 44;

    font = TTF_OpenFont("rsc\\ui\\font_Xolonium-Regular.ttf", fontSize);
    if ( font == NULL )
	cout << "ERROR: font failed to load!" << endl;

    color = { 0, 0, 0 };
    cout << "\tText class..." << endl;
}

Text::~Text()
{
    TTF_CloseFont(font);
}

void Text::writeText(int x, int y, const char* text, int size)
{
    if ( fontSize != size )
    {
	fontSize = size;
	TTF_CloseFont(font);
	font = TTF_OpenFont("rsc\\ui\\font_Xolonium-Regular.ttf", fontSize);
    }

    SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
    if ( surface == NULL )
	cout << "ERROR: ( Text::writeText() ) text surface is NULL" << endl;
    else if ( image->drawSurface(x, y, surface) != 0 )
	cout << "ERROR: ( Text::writeText() ) couldn't blit the text surface" << endl;
}

void Text::writeTextCentered(SDL_Rect offsets, const char* text, int size)
{
    if ( fontSize != size )
    {
	fontSize = size;
	TTF_CloseFont(font);
	font = TTF_OpenFont("rsc\\font_Xolonium-Regular.ttf", fontSize);
    }
    int x, y, w, h;
    TTF_SizeText(font, text, &w, &h);
    x = offsets.x + ( ( offsets.w - w ) / 2 ) - 10;
    y = offsets.y + ( ( offsets.h - h ) / 2 );

    SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
    if( surface == NULL )
	cout << "ERROR: ( Text::writeTextCentered() ) text surface is NULL" << endl;
    image->drawSurface(x, y, surface);
}