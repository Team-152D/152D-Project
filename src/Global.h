#ifndef GLOBAL_H
#define	GLOBAL_H

#include "SDL2/SDL.h"

class Audio;
class Image;
class Text;
class Settings;

extern SDL_Window *window;
extern SDL_Surface *screenSurface;

extern Settings *settings;
extern Audio *audio;
extern Image *image;
extern Text *text;

namespace Global
{
    const int CONTINUE = -1;
    
    const int AS_EXIT_SUCC = 0;
    const int AS_EXIT_FAIL = 1;
    
    const int AS_MAIN_MENU = 2;
    const int AS_GAME_SINGLE = 3;
    const int AS_GAME_MULTI = 4;
    
    const int MMS_0 = 10;
	const int MMS_1 = 11;
	const int MMS_2 = 12;
	const int MMS_3 = 13;
	const int MMS_4 = 14;
	const int MMS_5 = 15;
	const int MMS_6 = 16;
	const int MMS_7 = 17;
	const int MMS_8 = 18;
	const int MMS_9 = 19;
	const int MMS_10 = 20;
	const int MMS_11 = 21;
	const int MMS_12 = 22;
	const int MMS_13 = 23;
	const int MMS_14 = 24;
	const int MMS_15 = 25;
	const int MMS_16 = 26;
	const int MMS_17 = 27;
	const int MMS_18 = 28;
	const int MMS_19 = 29;

	/***** [30 - 39] Subeditors *****/
	const int SE_MENUS = 30;
	const int SE_LEVELS = 31;
	const int SE_UNITS = 32;
	const int SE_ITEMS = 33;

	/***** [100 - 199] Audio *****/
	// Sound Effects
	const int SFX_BUTTONPRESS = 100;
	// Music

	/***** [200 - 299] Settings *****/
	// Audio volume/mute
	const int SET_UISFX_BOOL = 200;
	const int SET_GAMESFX_BOOL = 201;
	const int SET_MUSIC_BOOL = 202;

	const int SET_SET_UISFXVOL = 203;
	const int SET_SET_GAMESFXVOL = 204;
	const int SET_SET_MUSICVOL = 205;

	// Video
	const int SET_TOGGLEFULL = 39;
}

#endif
