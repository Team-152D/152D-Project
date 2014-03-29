#include "Game.h"
#include "Command.h"

Game::Game( bool nGame, int socket )
{
	newGame = nGame;
	if ( socket > 0 )
	{
		multiPlayer = true;
		CMD.setSocket( socket );
		currentLevelNumber = 1;
	}
	else if ( newGame )
	{
		currentLevelNumber = 1;
		multiPlayer = false;
	}
	else
	{
		multiPlayer = false;
		ifstream infile;
		infile.open( "rsc\\data\\data_saveGameData.txt" );
		infile >> currentLevelNumber;
		infile.close( );
	}

	frameCounter = 0;
	currentGameGlobal = this;
	currentLevel = new Level( currentLevelNumber );

	IMG_MENU2 = image->loadImage( "rsc\\ui\\ui_menu2.bmp" );
	IMG_INFOBAR = image->loadImage( "rsc\\ui\\ui_infoBar.bmp" );
	victoryMenu = image->loadImage( "Resources\\ui_menu2.bmp" );
}

Game::~Game( )
{
	delete currentLevel;
	currentGameGlobal = NULL;

	SDL_FreeSurface( IMG_MENU2 );
	SDL_FreeSurface( IMG_INFOBAR );
}

int Game::runGame( )
{
	// Debug output
	cout << "\tAppstate change: ";
	if ( multiPlayer )
		cout << "MULTIPLAYER GAME" << endl;
	else if ( newGame )
		cout << "NEW SINGLE PLAYER GAME" << endl;
	else
		cout << "CONTINUE SINGLE PLAYER GAME" << endl;

	// LEVEL LOOP: play level, check return value ( victory = next level, death = restart, quit = quit )
	bool quit = false;
	while ( !quit )
	{
		// Event structure for level loop
		SDL_Event event;

		// Start multiplayer (if necessary))
		CMD.push( event, multiPlayer );
		CMD.take( );

		// Start game loop
		switch ( runGameLoop( ) )
		{
				// Quit
			case Global::AS_MAIN_MENU:
				Mix_HaltMusic( );
				cout << "DEBUG: (Game.cpp) game is quitting." << endl;
				if ( multiPlayer )
					endNet( CMD.getSocket( ) );
				text->changeColor( 0, 0, 0 );
				return Global::AS_MAIN_MENU;

				// Restart level
			case Global::AS_GAME_CONT:
				Mix_HaltMusic( );
				cout << "DEBUG: (Game.cpp) game is quitting." << endl;
				if ( multiPlayer )
					endNet( CMD.getSocket( ) );
				return Global::AS_GAME_NEW;

				// Next level
			default:
				break;
		}

		cout << "DEBUG: (Game.cpp) Level complete, loading victory screen" << endl;
		currentLevelNumber++;

		// VICTORY MENU LOOP: 
		/* Note: The victory menu code (and death menu, for that matter) should be recoded so that they are menu type objects
		 * Upon victory/death, the program should switch to the appropriate menu state: death - restart/quit, victory - next/quit
		 */
		bool atVictoryScreen = true;
		while ( atVictoryScreen )
		{
			if ( SDL_PollEvent( &event ) )
			{
				// Check input
				switch ( event.type )
				{
						// SDL_MOUSEBUTTONUP : Somebody released a click, check buttons
					case SDL_MOUSEBUTTONUP:
					{
						if ( event.button.button == SDL_BUTTON_LEFT )
						{
							int x = event.button.x, y = event.button.y;
							// Check if click x is within button range
							if ( x > 390 && x < 890 )
							{
								// Button 1: Continue
								if ( y > 134 && y < 234 )
								{
									audio->playSound( 1 );

									delete currentLevel;
									currentLevel = new Level( currentLevelNumber );
									atVictoryScreen = false;
									if ( currentLevelNumber > 5 )
										quit = true;
									break;
								}
									// Button 2: Save & quit
								else if ( y > 234 && y < 334 )
								{
									audio->playSound( 1 );

									ofstream outfile;
									outfile.open( "rsc\\data\\data_saveGameData.txt" );
									outfile << currentLevelNumber;
									outfile.close( );

									Mix_HaltMusic( );
									endNet( CMD.getSocket( ) );
									return Global::AS_MAIN_MENU;
								}
							}
						}
						break;
					}
					default:
						break;
				}

				// Draw victory menu
				image->drawSurface( 0, 0, victoryMenu );			// Button image
				text->writeText( 490, 58, "Level Complete!", 46 );	// Message
				text->writeText( 523, 158, "Next Level", 46 );		// Button label
				text->writeText( 495, 258, "Save and Quit", 46 );	// Button label
				SDL_UpdateWindowSurface( window );					// Update the frame
			}
		}
		// End of level loop
	}
	
	// Exiting the game
	Mix_HaltMusic( );
	if ( multiPlayer )
		endNet( CMD.getSocket( ) );
	text->changeColor( 0, 0, 0 );
	
	return Global::AS_MAIN_MENU;
}

int Game::runGameLoop( )
{
	//cout << "Beginning game loop" << endl;
	audio->playMusic( "rsc\\audio\\sfx_music1.wav" );
	audio->playSound( 2 );

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
			case 0:
				break;
			case 1:
				victory = true;
				break;
			case 2:
				return Global::AS_GAME_NEW;
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
	audio->playSound( 3 );
	return 1;
}

int Game::input( )
{
	//cout << "DEBUG: input()" << endl;
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
	//cout << "DEBUG: update()" << endl;
	currentLevel -> update( );
	if ( currentLevel -> victoryCondition( ) )
		return 1;
	else if ( currentLevel ->deathCondition( ) )
		return 2;
	else return 0;
}

int Game::draw( )
{
	//cout << "DEBUG: draw()" << endl;
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
	SDL_Surface* pauseMenu = image->loadImage( "rsc\\ui\\ui_menu2.bmp" );

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
	gameTimer.unpause( );
	return false;
}

void Game::displayDebug( ) { }

void Game::displayInfoBar( )
{
	text->changeColor( 255, 255, 255 );
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