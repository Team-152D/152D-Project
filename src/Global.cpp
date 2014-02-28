#include "Global.h"

SDL_Window *window = NULL;
SDL_Surface *screenSurface = NULL;

Game *currentGameGlobal = NULL;
Level *currentLevelGlobal = NULL ;

Settings *settings = NULL;
Audio *audio = NULL;
Image *image = NULL;
Text *text = NULL;