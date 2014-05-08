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

	text->changeColor( 255, 255, 255 );

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
	cout << "DEBUG: Running Game" << endl;

	SDL_Event event;
	CMD.push( event, multiPlayer );
	CMD.take( );

	int loopReturn = runGameLoop( );
	cout << "DEBUG: Game loop returned: " << loopReturn << endl;

	Mix_HaltMusic( );
	if ( multiPlayer )
		endNet( CMD.getSocket( ) );
	
	switch( loopReturn )
	{
		case Enums::AS_MAIN_MENU:
			return loopReturn;
		case Enums::GAME_VICTORY:
		{
			currentLevelNumber++;
			ofstream outfile;
			outfile.open( "rsc\\data\\data_saveGameData.txt" );
			outfile << currentLevelNumber;
			outfile.close();
			
			Menu *vMenu = new Menu( "rsc\\data\\data_menu_VM.txt" );
			int ret = vMenu -> runMenu();
			delete vMenu;
			return ret;
		}
		case Enums::GAME_DEFEAT:
		{
			Menu *dMenu = new Menu( "rsc\\data\\data_menu_DM.txt" );
			int ret = dMenu -> runMenu();
			delete dMenu;
			return ret;
		}
	}
}

int Game::runGameLoop( )
{
	//cout << "DEBUG: Beginning game loop" << endl;
	if ( settings->getMusicEnabled( ) )
		audio->playMusic( 1 );
	if ( settings->getGameSfxEnabled( ) )
		audio->playSound( 2 );

	bool victory = false;

	while ( !victory )
	{
		fps.start( );
		int iTime, uTime, dTime;

		if ( input( ) )
			return Enums::AS_MAIN_MENU;
		iTime = fps.get_ticks( );

		switch ( update( ) )
		{
			case Enums::CONTINUE:
				break;
			case Enums::GAME_VICTORY:
				return Enums::GAME_VICTORY;
			case Enums::GAME_DEFEAT:
				return Enums::GAME_DEFEAT;
			default:
				break;
		}
		uTime = fps.get_ticks( );

		draw( );
		dTime = fps.get_ticks( );

		frameCounter++;
		if ( frameCounter > 30 )
			frameCounter = 0;

		if ( fps.get_ticks( ) < 1000 / Enums::FRAMES_PER_SECOND )
			SDL_Delay( ( 1000 / Enums::FRAMES_PER_SECOND ) - fps.get_ticks( ) );
		/*else if ( fps.get_ticks( ) > 1000 / Enumerations::FRAMES_PER_SECOND )
			cout << "WARNING: Frame took too long to draw. "
			<< endl << "\tinput: " << iTime << "\tupdate: " << uTime << "\tdraw: " << dTime << endl;*/
	}

	if ( settings->getGameSfxEnabled( ) )
		audio->playSound( 3 );
	return 1;
}

bool Game::input( )
{
	// cout << "DEBUG: input()" << endl;
	SDL_Event event;

	while ( SDL_PollEvent( &event ) != 0 )
	{
		//chatbox input stuff
		ch_box.old_chatting( event );
		if ( ch_box.can_type( ) == false )
			CMD.push( event, multiPlayer );
		else strcpy( CMD.slfCmd, "nil" );

		if ( multiPlayer )
		{
			CMD.take( );
			currentLevel->input( CMD.slfCmd, CMD.othCmd );
		}
		else
		{
			currentLevel->input( CMD.slfCmd, NULL );

			if ( event.type == SDL_KEYUP )
				if ( event.key.keysym.sym == SDLK_ESCAPE )
				{
					Menu *pMenu = new Menu( "rsc\\data\\data_menu_PM.txt" );
					int retVal = pMenu ->runMenu( );
					switch ( retVal )
					{
						case Enums::CONTINUE:
							break;
						case Enums::AS_MAIN_MENU:
							return true;
						default:
							break;
					}

					// return true if the users quits
				}
		}
	}
	return false;
}

int Game::update( )
{
	// cout << "DEBUG: update()" << endl;
	currentLevel -> update( );

	if ( currentLevel -> victoryCondition( ) )
		return Enums::GAME_VICTORY;
		// if (death condition), return GAME_DEFEAT

	else return Enums::CONTINUE;
}

void Game::draw( )
{
	// cout << "DEBUG: draw()" << endl;
	currentLevel -> draw( );
	displayInfoBar( );

	if ( ch_box.can_type( ) == true )
	{
		ch_box.show_input( );
	}
	if ( ch_box.toggle( ) == 1 )
	{
		ch_box.show_output( );
	}

	//displayDebug();

	if ( SDL_UpdateWindowSurface( window ) < 0 )
		cout << "ERROR: Game::draw() SDL_UpdateWindowSurface failed" << endl;
}

bool Game::pauseGame( )
{
	bool isPaused = true;
	SDL_Event event;
	SDL_Surface* pauseMenu = image->loadImage( "rsc\\ui\\ui_menu2.bmp" );
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
