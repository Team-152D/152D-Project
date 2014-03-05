#include "Image.h"

Image::Image( )
{
	cout << "\tImage class..." << endl;
}

Image::~Image( )
{

}

SDL_Surface* Image::loadImage( std::string path )
{
	SDL_Surface* optimizedSurface = NULL;

	SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str( ) );
	if ( loadedSurface == NULL )
		//return NULL;
		cout << "ERROR: ( Image::loadImage() ) failed to load BMP at path " << path << endl;
	else
	{
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0 ) );
		optimizedSurface = SDL_ConvertSurface( loadedSurface, SDL_GetWindowSurface( window ) -> format, NULL );
		if ( optimizedSurface == NULL )
			cout
			<< "ERROR: ( Image::loadImage() ) Unable to optimize surface from image at path "
			<< path << endl;
	}

	SDL_FreeSurface( loadedSurface );
	return optimizedSurface;
}

int Image::drawSurface( int x, int y, SDL_Surface* src )
{
	SDL_Rect offsets;
	offsets.x = x;
	offsets.y = y;
	if ( SDL_BlitSurface( src, NULL, screenSurface, &offsets ) != 0 )
	{
		//cout << "ERROR: ( Image::drawToScreen() ) SDL_BlitSurface failed" << endl;
		return 1;
	}
	else
		return 0;
}