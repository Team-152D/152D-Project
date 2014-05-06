#ifndef GLOBAL_H
#define	GLOBAL_H

#include "SDL2/SDL.h"

class Audio;
class Image;
class Text;
class Settings;
class Game;
class Level;

extern SDL_Window *window;				// Pointer to the program's SDL_Window
extern SDL_Surface *screenSurface;		// Pointer to the SDL_Surface that is drawn to the screen

extern Audio *audio;					// Pointer to the audio object
extern Image *image;					// Pointer to the image object
extern Text *text;						// Pointer to the text object

extern Settings *settings;				// Pointer to the settings object

// These two should be eliminated after game engine classes are rearranged
extern Game *currentGameGlobal;			// Pointer to the game object
extern Level *currentLevelGlobal;		// Pointer to the level object

#endif
