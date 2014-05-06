#include "Game.h"
#include "Settings.h"
#include "Enumerations.h"

Game::Game( bool newGame, int socket )
{
	if ( socket > 0 )
	{
		//cout << "DEBUG: Starting multiPlayer game" << endl;
		multiPlayer = true;
		CMD.setSocket( socket );
		currentLevelNumber = 1;
	}
	else if ( newGame )
	{
		//cout << "DEBUG: Starting new singleplayer game" << endl;
		currentLevelNumber = 1;
		multiPlayer = false;
	}
	else
	{
		multiPlayer = false;
		//cout << "DEBUG: Continuing singleplayer game" << endl;
		ifstream infile;
		infile.open( "rsc\\data\\data_saveGameData.txt" );
		infile >> currentLevelNumber;
		infile.close( );
	}

	frameCounter = 0;
	currentGameGlobal = this;
	currentLevel = new Level( currentLevelNumber );
	currentLevel->loadLevel( );

	IMG_MENU2 = image->loadImage( "rsc\\ui\\ui_menu2.bmp" );

	IMG_HIGHLIGHT = image->loadImage( "rsc\\ui\\ui_menuHighlight.bmp" );
	IMG_INFOBAR = image->loadImage( "rsc\\ui\\ui_infoBar.bmp" );
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

		if ( settings->getMusicEnabled( ) )
			audio->playMusic( 1 );
		text->changeColor( 255, 255, 255 );
		if ( runGameLoop( ) == Enumerations::AS_MAIN_MENU )
		{
			Mix_HaltMusic( );
			cout << "DEBUG: (Game.cpp) game is quitting." << endl;
			if ( multiPlayer )
				endNet( CMD.getSocket( ) );
			text->changeColor( 0, 0, 0 );
			return Enumerations::AS_MAIN_MENU;
		}
		cout << "DEBUG: (Game.cpp) Level complete, loading victory screen" << endl;
		currentLevelNumber++;

		/* Victory Screen
		 This section of the code should be replaced by a menu system
		 - Whatever is currently on the screen should be saved to an SDL_Surface to be used as the background for the menu
		 - A new menu object should be created and run
		 - The menu should offer two options:
			- Continue: increment the current level number and return Enumerations::AS_GAME_CONT
			- Exit: return Enumerations::AS_MAIN_MENU
		 - Finally, Game::runGame() should return the value the menu object returned
		 */
		SDL_Surface* victoryMenu = image->loadImage( "Resources\\ui_menu2.bmp" );
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
									audio->playSound( 1 );
									delete currentLevel;
									currentLevel = new Level( currentLevelNumber );
									atVictoryScreen = false;
									if ( currentLevelNumber > 5 )
										quit = true;
									break;
								}
								else if ( y > 234 && y < 334 ) //save & quit
								{
									audio->playSound( 1 );
									ofstream outfile;
									outfile.open( "rsc\\data\\data_saveGameData.txt" );
									outfile << currentLevelNumber;
									outfile.close( );


									Mix_HaltMusic( );
									endNet( CMD.getSocket( ) );
									return Enumerations::AS_MAIN_MENU;
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
	return Enumerations::AS_MAIN_MENU;
}

int Game::runGameLoop( )
{
	cout << "Beginning game loop" << endl;
	if ( settings->getGameSfxEnabled( ) )
		audio->playSound( 2 );

	bool victory = false;

	while ( !victory )
	{
		fps.start( );
		int iTime, uTime, dTime;

		switch ( input( ) )
		{
			case 0: break;
			case 2: return Enumerations::AS_MAIN_MENU;
			default: break;
		}
		iTime = fps.get_ticks( );

		switch ( update( ) )
		{
			case 0: break;
			case 1: victory = true;
				break;
			default: break;
		}
		uTime = fps.get_ticks( );

		switch ( draw( ) )
		{
			case 0: break;
			case 2: return Enumerations::AS_MAIN_MENU;
			default: break;
		}
		dTime = fps.get_ticks( );

		frameCounter++;
		if ( frameCounter > 30 )
			frameCounter = 0;

		if ( fps.get_ticks( ) < 1000 / Enumerations::FRAMES_PER_SECOND )
			SDL_Delay( ( 1000 / Enumerations::FRAMES_PER_SECOND ) - fps.get_ticks( ) );
		else if ( fps.get_ticks( ) > 1000 / Enumerations::FRAMES_PER_SECOND )
			cout << "WARNING: Frame took too long to draw. "
			<< endl << "\tinput: " << iTime << "\tupdate: " << uTime << "\tdraw: " << dTime << endl;
	}
	if ( settings->getGameSfxEnabled( ) )
		audio->playSound( 3 );
	return 1;
}

int Game::input( )
{
	// cout << "DEBUG: input()" << endl;
	SDL_Event event;

	while ( SDL_PollEvent( &event ) != 0 )
	{
		CMD.push( event, multiPlayer );
		CMD.take( );

		if ( multiPlayer )
			currentLevel->input( CMD.slfCmd, CMD.othCmd );
		else
		{
			currentLevel->input( CMD.slfCmd, NULL );
			
			// Check for escape key, if received run pause menu
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
		}
	}
	return 0;
}

int Game::update( )
{
	// cout << "DEBUG: update()" << endl;
	currentLevel -> update( );

	if ( currentLevel -> victoryCondition( ) )
		return 1;
	else return 0;
}

int Game::draw( )
{
	// cout << "DEBUG: draw()" << endl;
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
	bool isPaused = true;
	SDL_Event event;
	SDL_Surface* pauseMenu = image->loadImage( "Resources\\ui_menu2.bmp" );
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
								audio->playSound( 1 );
								return false;
							}
							else if ( y > 234 && y < 334 )
							{
								audio->playSound( 1 );
								ofstream outfile;
								outfile.open( "rsc\\data\\data_saveGameData.txt" );
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
	return false;
}

void Game::displayDebug( )
{
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