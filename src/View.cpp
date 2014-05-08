#include "View.h"
#include "Enumerations.h"

View::View( int iParentView, string backgroundPath )
{
	elements = new vector<UI_AbstractElement*>;
	parentView = iParentView;
	//cout << "view bg image" << endl;
	backgroundImage = image->loadImage( "rsc\\ui\\test.bmp" );
	ipfield = NULL;
}

View::~View( )
{
	for ( int i = 0; i < elements->size( ); i++ )
		delete elements->at( i );
	delete elements;
}

int View::input( SDL_Event* event )
{
	for ( int i = 0; i < elements->size( ); i++ )
	{
		int rValue = elements->at( i )->handleEvents( event );
		if ( rValue == Enums::CONTINUE )
			continue;
		else if ( rValue >= 0 && rValue <= 39 )
			return rValue;
	}
	return Enums::CONTINUE;
}

void View::draw( )
{
	image->drawSurface( 0, 0, backgroundImage );

	//draw ui elements
	for ( int i = 0; i < elements->size( ); i++ )
		elements->at( i )->draw( );

	//draw text

}

void View::loadElements( string filepath )
{
	ifstream file;
	file.open( filepath.c_str( ), std::fstream::in );
	string type;
	while ( file >> type )
	{
		if ( type == "Button" )
		{
			SDL_Rect bounds;
			char label[256];
			int actionValue;

			file >> bounds.x;
			file >> bounds.y;
			file >> bounds.w;
			file >> bounds.h;
			file.getline( label, 256, ';' );
			file >> actionValue;

			UI_Button* nButton = new UI_Button( bounds, label, actionValue );
			elements->push_back( nButton );
		}
		else if( type == "IPfield" )
		{
			SDL_Rect bounds;
			
			file >> bounds.x;
			file >> bounds.y;
			file >> bounds.w;
			file >> bounds.h;
			
			UI_IPfield *nField = new UI_IPfield( bounds, 36, true );
			elements->push_back( nField );
			ipfield = nField;
		}
		else if ( type == "Text" )
		{
			int iSize;
			bool centered;
			char input[256];
			string align;
			SDL_Rect offsets;
			SDL_Surface *surface;

			file >> align;
			if ( align == "centered" )
				centered = true;
			else
				centered = false;
			file >> offsets.x;
			file >> offsets.y;
			file >> offsets.w;
			file >> offsets.h;
			file.getline( input, 256, ';' );
			string textString( input );
			file >> iSize;

			UI_TextLabel* label = new UI_TextLabel( offsets, textString, iSize, centered );
			elements->push_back( label );
		}
		else if ( type == "Input Field" )
		{

		}
		else if ( type == "Slider" )
		{

		}
		else if ( type == "Checkbox" )
		{
			SDL_Rect bounds;
			char identifier[256], label[256];
			int linkedValue;

			file.getline( identifier, 256, ';' );
			file >> bounds.x;
			file >> bounds.y;
			file >> bounds.w;
			file >> bounds.h;
			file.getline( label, 256, ';' );
			file >> linkedValue;

			UI_Checkbox* nCheckbox = new UI_Checkbox( bounds, identifier, label, linkedValue );
			elements->push_back( nCheckbox );
		}
		else
			cout << "WARNING: View didn't detect a valid element identifier" << endl;

		type.clear( );
	}
	//cout << "DEBUG: View at " << filepath << " loaded " << elements->size( ) << " elements" << endl;
}

int View::getParentView( )
{
	return parentView;
}

UI_IPfield* View::getIPfield()
{
	return ipfield;
}