#include "Game.h"
#include "Command.h"

Game::Game( bool newGame, int socket )
{
	if ( socket > 0 )
	{
		cout << "DEBUG: Starting multiPlayer game" << endl;
		multiPlayer = true;
		CMD.setSocket( socket );
		currentLevelNumber = 1;
	}
	else if ( newGame )
	{
		cout << "DEBUG: Starting new singleplayer game" << endl;
		currentLevelNumber = 1;
		multiPlayer = false;
	}
	else
	{
		multiPlayer = false;
		cout << "DEBUG: Continuing singleplayer game" << endl;
		ifstream infile;
		infile.open( "resources\\data_saveGameData.txt" );
		infile >> currentLevelNumber;
		infile.close( );
	}

	frameCounter = 0;
	currentGameGlobal = this;
	currentLevel = new Level( currentLevelNumber );




	IMG_MENU2 = image->loadImage( "resources\\ui_menu2.png" );

	IMG_HIGHLIGHT = image->loadImage( "resources\\ui_menuHighlight.jpg" );
	IMG_INFOBAR = image->loadImage( "resources\\ui_infoBar.png" );
}

Game::~Game( )
{
	delete currentLevel;
	currentGameGlobal = NULL;

	SDL_FreeSurface( IMG_MENU2 );

	SDL_FreeSurface( IMG_HIGHLIGHT );
	SDL_FreeSurface( IMG_INFOBAR );
}

int Game::runGame( )
{
	cout << "DEBUG: runGame()" << endl;
	bool quit = false;
	while ( !quit )
	{
		SDL_Event event;

		CMD.push( event, multiPlayer );
		CMD.take( );

		audio->playMusic( "rsc\\audio\\sfx_music1.wav" );
		if ( runGameLoop( ) == Global::AS_MAIN_MENU )
		{
			Mix_HaltMusic( );
			cout << "DEBUG: (Game.cpp) game is quitting." << endl;
			if ( multiPlayer )
				endNet( CMD.getSocket( ) );
			return Global::AS_MAIN_MENU;
		}
		cout << "DEBUG: (Game.cpp) Level complete, loading victory screen" << endl;
		currentLevelNumber++;


		SDL_Surface* victoryMenu = image->loadImage( "Resources\\ui_menu2.png" );
		bool atVictoryScreen = true;

		while ( atVictoryScreen )
		{
			if ( SDL_PollEvent( &event ) )
			{
				switch ( event.type )
				{
					/**/case SDL_MOUSEBUTTONUP:
						if ( event.button.button == SDL_BUTTON_LEFT )
						{
							int x = event.button.x, y = event.button.y;
							if ( x > 390 && x < 890 )
							{
								if ( y > 134 && y < 234 ) //Continue
								{
									audio->playSound( "rsc\\audio\\sfx_buttonPress.wav" );
									delete currentLevel;
									currentLevel = new Level( currentLevelNumber );
									atVictoryScreen = false;
									if ( currentLevelNumber > 5 )
										quit = true;
									break;
								}
								else if ( y > 234 && y < 334 ) //save & quit
								{
									audio->playSound( "rsc\\audio\\sfx_buttonPress.wav" );
									ofstream outfile;
									outfile.open( "resources\\data_saveGameData.txt" );
									outfile << currentLevelNumber;
									outfile.close( );


									Mix_HaltMusic( );
									endNet( CMD.getSocket( ) );
									return Global::AS_MAIN_MENU;
								}
							}
						}
						break;
					/**/default:
						break;
				}
			}
			image->drawSurface( 0, 0, victoryMenu );
			text->writeText( 490, 58, "Level Complete!", 46 );
			text->writeText( 523, 158, "Next Level", 46 );
			text->writeText( 495, 258, "Save and Quit", 46 );
			SDL_UpdateWindowSurface( window );

		}
	}
	Mix_HaltMusic( );
	//display game complete screen
	if ( multiPlayer )
		endNet( CMD.getSocket( ) );
	return Global::AS_MAIN_MENU;
}

int Game::runGameLoop( )
{
	cout << "Beginning game loop" << endl;
	audio->playSound( "rsc\\audio\\sfx_readyGo.wav" );

	bool victory = false;

	gameTimer.start( );
	while ( !victory )
	{
		fps.start( );

		switch ( input( ) )
		{
			case 0: break;
			case 2: return Global::AS_MAIN_MENU;
			default: break;
		}
		switch ( update( ) )
		{
			case 0: break;
			case 1: victory = true;
				break;
			default: break;
		}
		switch ( draw( ) )
		{
			case 0: break;
			case 2: return Global::AS_MAIN_MENU;
			default: break;
		}
		frameCounter++;
		if ( frameCounter > 30 )
			frameCounter = 0;
		if ( fps.get_ticks( ) < 1000 / Global::FRAMES_PER_SECOND )
			SDL_Delay( ( 1000 / Global::FRAMES_PER_SECOND ) - fps.get_ticks( ) );
	}
	audio->playSound( "rsc\\audio\\sfx_victory.wav" );
	return 1;
}

int Game::input( )
{
	cout << "DEBUG: input()" << endl;
	SDL_Event event;

	SDL_PollEvent( &event );

	CMD.push( event, multiPlayer );
	CMD.take( );
	if ( multiPlayer )
		currentLevel->input( CMD.slfCmd, CMD.othCmd );
	else
		currentLevel->input( CMD.slfCmd, NULL );


	if ( !multiPlayer )
		if ( event.type == SDL_KEYUP )
			if ( event.key.keysym.sym == SDLK_ESCAPE )
			{
				bool x = pauseGame( );
				switch ( x )
				{
					case false:
						break;
					case true:
						return 2;
						break;
				}
			}

	return 0;
}

int Game::update( )
{
	cout << "DEBUG: update()" << endl;
	currentLevel -> update( );
	cout << "checking victory" << endl;
	if ( currentLevel -> victoryCondition( ) )
		return 1;
	else return 0;
}

int Game::draw( )
{
	cout << "DEBUG: draw()" << endl;
	currentLevel -> draw( );
	displayInfoBar( );

	//displayDebug();

	if ( SDL_UpdateWindowSurface( window ) < 0 )
		return 2;
	else
		return 0;
}

bool Game::pauseGame( )
{
	gameTimer.pause( );
	bool isPaused = true;
	SDL_Event event;
	SDL_Surface* pauseMenu = image->loadImage( "Resources\\ui_menu2.png" );
	if ( pauseMenu == NULL )
		cout << "Pause menu image didn't load" << endl;

	while ( isPaused )
	{
		if ( SDL_PollEvent( &event ) )
		{
			switch ( event.type )
			{
				/**/case SDL_MOUSEBUTTONDOWN:
					break;
				/**/case SDL_MOUSEBUTTONUP:
					if ( event.button.button == SDL_BUTTON_LEFT )
					{
						int x = event.button.x;
						int y = event.button.y;

						if ( x > 390 && x < 890 )
						{
							if ( y > 134 && y < 234 )
							{
								audio->playSound( "rsc\\audio\\sfx_buttonPress.wav" );
								return false;
							}
							else if ( y > 234 && y < 334 )
							{
								audio->playSound( "rsc\\audio\\sfx_buttonPress.wav" );
								ofstream outfile;
								outfile.open( "resources\\data_saveGameData.txt" );
								outfile << currentLevelNumber;
								outfile.close( );
								return true;
							}
						}
					}
					break;
				/**/case SDL_KEYUP:
					if ( event.key.keysym.sym == SDLK_ESCAPE )
						return false;
					break;
				default: break;
			}
		}
		image->drawSurface( 0, 0, pauseMenu );
		text->writeText( 523, 158, "Unpause", 46 );
		text->writeText( 495, 258, "Save and Quit", 46 );
		if ( SDL_UpdateWindowSurface( window ) < 0 )
			cout << "SDL_Flip failed" << endl;
	}
	SDL_FreeSurface( pauseMenu );
	gameTimer.unpause( );
	return false;
}

void Game::displayDebug( ) {
 }

void Game::displayInfoBar( )
{
	image->drawSurface( 0, 640, IMG_INFOBAR );
	vector<string>* vec = currentLevel->getInfoBarData( );
	/*
	string str = "Hello, world!";
    
	copy(str.begin(), str.end(), displayText);
	displayText[str.size()] = '\0'; */

	for ( int i = 0; i < 2; i++ )
	{
		string inputStr = vec->at( i );
		char * displayText = new char[inputStr.size( ) + 1];
		copy( inputStr.begin( ), inputStr.end( ), displayText );
		displayText[inputStr.size( )] = '\0';
		text->writeText( 0, 672 + ( 32 * i ), displayText, 30 );
		delete[] displayText;
	}
	for ( int j = 2; j < 6; j++ )
	{
		string inputStr = vec->at( j );
		char * displayText = new char[inputStr.size( ) + 1];
		copy( inputStr.begin( ), inputStr.end( ), displayText );
		displayText[inputStr.size( )] = '\0';
		text->writeText( 256, 640 + ( 32 * j ), displayText, 30 );
		delete[] displayText;
	}
}

int Game::getCurrentLevelNumber( )
{
	return currentLevelNumber;
}

int Game::getFrameCounter( )
{
	return frameCounter;
}