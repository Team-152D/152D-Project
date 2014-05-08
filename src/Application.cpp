#include "Application.h"
#include "Enumerations.h"
#include "Settings.h"
#include "Game.h"
#include <fstream>

Application::Application( )
{
	//editor = NULL;
	menu = NULL;

	if ( initializeApplication( ) == false )
		appState = Enums::AS_EXIT_FAIL;
	else
		appState = Enums::AS_MAIN_MENU;
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
			case Enums::AS_MAIN_MENU:
				cout << "APPSTATE CHANGE: Main Menu" << endl;
				menu = new Menu( "rsc\\data\\data_menu_MM.txt" );
				appState = menu -> runMenu( );
				delete menu;
				menu = NULL;
				break;
			case Enums::AS_GAME_NEW:
				cout << "APPSTATE CHANGE: New Game" << endl;
				game = new Game( true, 0 );
				appState = game ->runGame( );
				delete game;
				game = NULL;
				break;
			case Enums::AS_GAME_CONT:
				cout << "APPSTATE CHANGE: Continue Game" << endl;
				game = new Game( false, 0 );
				appState = game->runGame( );
				delete game;
				game = NULL;
				break;
			case Enums::AS_GAME_JOIN:
			{
				cout << "APPSTATE CHANGE: Join Game" << endl;
				ifstream infile;
				infile.open( "rsc\\data\\data_ip.txt" );
				char IP[16];
				infile >> IP;
				cout << "IP is: " << IP << endl;
				int socket = client( IP );
				game = new Game( false, socket );
				appState = game -> runGame( );
				delete game;
				break;
			}
			case Enums::AS_GAME_HOST:
			{
				cout << "APPSTATE CHANGE: Host Game" << endl;
				SDL_Surface *blk = image->loadImage( "rsc\\ui\\ui_blackScreen.bmp" );
				image->drawSurface( 0, 0, blk );
				text->writeText( 0, 0, "waiting for other player", 44 );
				int sock = server( );
				game = new Game( false, sock );
				appState = game -> runGame( );
				delete game;
				break;
			}
			case Enums::AS_EDITOR:
				cout << "APPSTATE CHANGE: Editor" << endl;
				editor = new Editor( );
				appState = editor -> runEditor( );
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
		cout << endl << "ERROR: SDL failed to initialize!" << endl << SDL_GetError() << endl << "Exiting...";
		return false;
	}

	if ( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 1024 ) != 0 )
	{
		cout << endl << "ERROR: SDL_Mixer failed to initialize!" << endl << SDL_GetError() << endl << "Exiting...";
		return false;
	}

	if ( TTF_Init( ) != 0 )
	{
		cout << endl << "ERROR: SDL_TTF failed to initialize!" << endl << SDL_GetError() << endl << "Exiting...";
		return false;
	}

	//Initialize sdl_image

	window = SDL_CreateWindow( "152 Project", 0, 0, 1280, 768, SDL_WINDOW_FULLSCREEN );
	if ( window == NULL )
	{
		cout << endl << "ERROR: Window is null!" << endl << SDL_GetError() << endl << "Exiting...";
		return false;
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