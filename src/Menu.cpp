#include "Menu.h"
#include "Enumerations.h"

Menu::Menu( string input )
{
	//cout << "DEBUG: initializing menu..." << endl;
	currentView = 0;
	views = new vector<View*>;

	polledEvent = false;
	loadViews( input );
	text->changeColor( 0, 0, 0 );
	background = image->loadImage( "rsc\\ui\\test.bmp" );
	//cout << "DEBUG: Menu initialized" << endl;
}

Menu::~Menu( )
{
	for ( int i = 0; i < views->size( ); i++ )
		delete views->at( i );
	delete views;
}

int Menu::runMenu( )
{
	cout << "Running Menu: " << identifier << endl;

	bool inMenu = true;
	views->at( currentView )->draw( );

	//cout << "DEBUG: Entering menu loop" << endl;
	while ( inMenu )
	{
		int updateRValue = update( input( ) );

		if ( updateRValue > -1 && updateRValue <= 9 )
			return updateRValue;
		else
			switch ( updateRValue )
			{
				case 30:
					cout << "Received action value 30" << endl;
					views -> at( currentView ) -> getIPfield( ) -> setIP( );
					cout << "set position" << endl;
					break;
				case 34:
					return Enums::CONTINUE;
				default:
					break;
			}

		draw( );
	}
	return Enums::AS_EXIT_FAIL;
}

int Menu::input( )
{
	// cout << "DEBUG: Menu::input()" << endl;
	SDL_Event event;

	if ( SDL_PollEvent( &event ) )
	{
		polledEvent = true;
		if ( event.type == SDL_QUIT )
			return Enums::AS_EXIT_SUCC;
		else if ( event.type == SDL_KEYUP )
		{
			if ( event.key.keysym.sym == SDLK_ESCAPE )
			{
				int temp = views->at( currentView )->getParentView( );
				cout << "Menu::input() escape pressed: returning " << temp << endl;
				return temp;
			}
		}
		else
			return views->at( currentView )->input( &event );
	}
	else
		polledEvent = false;

	return Enums::CONTINUE;
}

int Menu::update( int iValue )
{
	// cout << "DEBUG: Menu::update()" << endl;
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

	return Enums::CONTINUE;
}

int Menu::draw( )
{
	// cout << "DEBUG: Menu::draw()" << endl;
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
	cout << "DEBUG: loaded " << views->size( ) << " views for " << identifier << endl;
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