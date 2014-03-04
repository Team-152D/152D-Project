#include "Application.h"
#include "Settings.h"
#include "Game.h"

Application::Application( )
{
	//editor = NULL;
	menu = NULL;

	if ( initializeApplication( ) == false )
		appState = Global::AS_EXIT_FAIL;
	else
		appState = Global::AS_MAIN_MENU;
}

Application::~Application( )
{
	delete editor;
	delete menu;
}

int Application::runApplication( )
{
	cout << "Entering main loop, appState = " << appState << endl;
	while ( appState > 1 )
	{
		switch ( appState )
		{
			case Global::AS_MAIN_MENU:
				menu = new Menu( "rsc\\data\\data_menu_MM.txt" );
				appState = menu -> runMenu( );
				delete menu;
				menu = NULL;
				break;
			case Global::AS_GAME_NEW:
				game = new Game( true, 0 );
				appState = game ->runGame( );
				delete game;
				game = NULL;
				break;
			case Global::AS_GAME_CONT:
				game = new Game( false,0 );
				appState = game->runGame();
				delete game;
				game = NULL;
				break;
			case Global::AS_GAME_JOIN:
				appState = Global::AS_MAIN_MENU;
				break;
			case Global::AS_EDITOR:
				editor = new Editor();
				appState = editor -> runEditor();
				delete editor;
				editor = NULL;
				break;
			default:
				break;
		}
	}

	cout << "Exiting main loop, appState = " << appState << endl;
	return appState;
}

bool Application::initializeApplication( )
{
	if ( SDL_Init( SDL_INIT_EVERYTHING ) != 0 )
	{
		//fail
	}

	if ( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 1024 ) != 0 )
	{
		//fail
	}

	if ( TTF_Init( ) != 0 )
	{
		//fail
	}

	//Initialize sdl_image

	window = SDL_CreateWindow( "152 Project", 0, 0, 1280, 800, SDL_WINDOW_FULLSCREEN );
	if ( window == NULL )
	{
		//fail
	}

	screenSurface = SDL_GetWindowSurface( window );
	if ( screenSurface == NULL )
	{
		//fail
	}

	audio = new Audio( );
	image = new Image( );
	text = new Text( );
	settings = new Settings( );

	return true;
}