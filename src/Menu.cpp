#include "Menu.h"

Menu::Menu( string input )
{
	cout << "DEBUG: initializing menu...\t";
	currentView = 0;
	views = new vector<View*>;

	polledEvent = false;

	loadViews( input );

	background = image->loadImage( "rsc\\ui\\test.bmp" );
	if ( background == NULL )
		cout << "DEBUG: Menu Background is NULL" << endl;
	cout << "DEBUG: Menu initialized" << endl;
}

Menu::~Menu( )
{
	for ( int i = 0; i < views->size( ); i++ )
		delete views->at( i );
	delete views;
}

int Menu::runMenu( )
{
	if ( identifier == "Main Menu" )
		cout << "APPSTATE CHANGE: entering main menu system" << endl;

	bool inMenu = true;
	views->at( currentView )->draw( );

	cout << "Entering menu loop" << endl;
	while ( inMenu )
	{
		//input, update
		int updateRValue = update( input( ) );

		if ( ( updateRValue >= 0 && updateRValue <= 9 ) || ( updateRValue >= 30 && updateRValue <= 39 ) )
		{
			if ( identifier == "Main Menu" && updateRValue <= 9 )
				cout << "APPSTATE CHANGE: leaving main menu system" << endl << endl;
			return updateRValue;
		}

		//draw
		draw( );
	}

	if ( identifier == "Main Menu" )
		cout << "APPSTATE CHANGE: leaving main menu system" << endl << endl;
	return Global::AS_EXIT_FAIL;
}

int Menu::input( )
{
	SDL_Event event;

	if ( SDL_PollEvent( &event ) )
	{
		polledEvent = true;
		if ( event.type == SDL_QUIT )
			return Global::AS_EXIT_SUCC;
		else if ( event.type == SDL_KEYUP )
		{
			if ( event.key.keysym.sym == SDLK_ESCAPE )
				return views->at( currentView )->getParentView( );
		}
		else
		{
			int rValue = views->at( currentView )->input( &event );
			return rValue;
		}
	}
	else
		polledEvent = false;

	return Global::CONTINUE;
}

int Menu::update( int iValue )
{
	if ( iValue >= 0 && iValue <= 9 ) //return exit/game state
		return iValue;
	else if ( iValue >= 10 && iValue <= 29 ) //set current view
	{
		currentView = iValue - 10;
		//cout << "DEBUG: Changed to view " << currentView << endl;
	}
	else if ( iValue >= 30 && iValue <= 39 )
	{
		return iValue;
	}
	else if ( iValue >= 50 && iValue <= 99 ) //handle action
	{

	}

	return Global::CONTINUE;
}

int Menu::draw( )
{
	views->at( currentView )->draw( );

	drawDebug( );

	//flip screen
	SDL_UpdateWindowSurface( window );
	/*
	if (SDL_UpdateWindowSurface(window) != 0)
		cout << "ERROR: ( Menu::draw() ) SDL_UpdateWindowSurface failed" << endl; */
}

void Menu::loadViews( string filepath )
{
	ifstream file;
	file.open( filepath.c_str( ), std::ifstream::in );

	char temp[256];
	file.getline( temp, 256, ';' );
	identifier.assign( temp );

	while ( !file.eof( ) )
	{
		string viewPath, bgPath;
		int viewParent;
		file >> viewPath;
		file >> viewParent;
		file >> bgPath;

		View* nView = new View( viewParent, bgPath );
		nView->loadElements( viewPath );
		views->push_back( nView );
	}
	//cout << "DEBUG: (Menu.cpp) loaded " << views->size() << " views" << endl;
}

void Menu::drawDebug( )
{
	int x, y;
	SDL_GetMouseState( &x, &y );

	ostringstream sstream;
	sstream << "x = " << x;

	text->writeText( 0, 0, sstream.str( ).c_str( ), 36 );
	sstream.str( string( ) );

	sstream << "y= " << y;
	text->writeText( 0, 50, sstream.str( ).c_str( ), 36 );
}