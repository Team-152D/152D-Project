#ifndef ENUMERATIONS_H
#define	ENUMERATIONS_H

namespace Enums
{
	/***** Config values *****/
	const int SCREEN_WIDTH = 1280; // Total screen width
	const int SCREEN_HEIGHT = 768; // Total screen height
	const int LEVEL_WIDTH = 1280; // Width of the on-screen area occupied by the level
	const int LEVEL_HEIGHT = 640; // Height of the on-screen area occupied by the level
	const int GRID_WIDTH = 40; // Number of tiles in the width of the grid
	const int GRID_HEIGHT = 20; // Number of tiles in the height of the grid
	const int FRAMES_PER_SECOND = 30; // Number of times the game loop executes/draws per second

	const int CONTINUE = -1; // Notifies update loops to continue execution; no action necessary

	/***** [0 - 9] Game states *****/
	const int AS_EXIT_SUCC = 0; // Notifies the app state loop to exit and return 0 in main
	const int AS_EXIT_FAIL = 1; // Notifies the app state loop to exit and return 1 in main. Mainly used if program initialization fails
	const int AS_MAIN_MENU = 2; // Game state - Main Menu
	const int AS_GAME_NEW = 3; // Game state - New Game
	const int AS_GAME_CONT = 4; // Game state - Continue Game
	const int AS_GAME_JOIN = 5; // Game state - Join a multiplayer game at the IP address specified in settings
	const int AS_GAME_HOST = 6; // Game state - Host a multiplayer game
	const int AS_EDITOR = 7; // Game state - Level Editor

	/***** [10 - 39] GUI element action values *****/
	const int MS_0 = 10; // [10 - 29] Prefix "MS_"
	const int MS_1 = 11; // Used in menus, these values are used to specify which menu screen to change to
	const int MS_2 = 12;
	const int MS_3 = 13;
	const int MS_4 = 14;
	const int MS_5 = 15;
	const int MS_6 = 16;
	const int MS_7 = 17;
	const int MS_8 = 18;
	const int MS_9 = 19;
	const int MS_10 = 20;
	const int MS_11 = 21;
	const int MS_12 = 22;
	const int MS_13 = 23;
	const int MS_14 = 24;
	const int MS_15 = 25;
	const int MS_16 = 26;
	const int MS_17 = 27;
	const int MS_18 = 28;
	const int MS_19 = 29;

	const int SET_IP = 30; // enum::SET_IP tells a view to take the string contained by a UI_IPfield and write it to a file
	const int SET_UISFX_BOOL = 31;
	const int SET_GAMESFX_BOOL = 32;
	const int SET_MUSIC_BOOL = 33;
	const int SUBMENU_EXIT = 34;
	
	const int GAME_VICTORY = 40;
	const int GAME_DEFEAT = 41;
	
	/***** [100 - 199] Audio *****/
    // Sound Effects
    // NOTE: These values won't be needed after play audio functions are modified to accept pointers to the audio files as arguments
    const int SFX_BUTTONPRESS = 100;
    const int SFX_BEGIN = 101;
    const int SFX_END = 102;
    const int SFX_MUS1 = 103;
};

#endif