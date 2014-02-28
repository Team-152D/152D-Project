#include "Editor.h"

Editor::Editor( )
{
	grid = new Grid( "rsc\\data\\data_c1.txt" );
	fileOpen = true;
	needsUpdate = false;
	needsDraw = true;
	selectedTile = 1;

	oneSpawn.x = 0;
	oneSpawn.y = 0;
	twoSpawn.x = 0;
	twoSpawn.y = 0;
	endzone.x = 0;
	endzone.y = 0;
	endzone.w = 0;
	endzone.h = 0;

	editorBackground = image->loadImage( "resources\\ui_editorBackground.png" );
	horizontalLine = image->loadImage( "resources\\ui_horizontalLine.png" );
	verticalLine = image->loadImage( "resources\\ui_verticalLine.png" );

	IMG_BRICK = image->loadImage( "resources\\tile_brick32.jpg" );
	IMG_DIRT = image->loadImage( "resources\\tile_dirt32.jpg" );
	IMG_DIRTYBRICK = image->loadImage( "resources\\tile_dirtybrick32.jpg" );
	IMG_GRASS = image->loadImage( "resources\\tile_grass32.jpg" );
	IMG_LAVA = image->loadImage( "resources\\tile_lava32.jpg" );
	IMG_REDCARPET = image->loadImage( "resources\\tile_redcarpet32.jpg" );
	IMG_STONE = image->loadImage( "resources\\tile_stone32.jpg" );
	IMG_WATER = image->loadImage( "resources\\tile_water32.jpg" );
	IMG_WOOD = image->loadImage( "resources\\tile_wood32.jpg" );

	IMG_BRICK64 = image->loadImage( "resources\\tile_brick64.jpg" );
	IMG_DIRT64 = image->loadImage( "resources\\tile_dirt64.jpg" );
	IMG_DIRTYBRICK64 = image->loadImage( "resources\\tile_dirtybrick64.jpg" );
	IMG_GRASS64 = image->loadImage( "resources\\tile_grass64.jpg" );
	IMG_LAVA64 = image->loadImage( "resources\\tile_lava64.jpg" );
	IMG_REDCARPET64 = image->loadImage( "resources\\tile_redcarpet64.jpg" );
	IMG_STONE64 = image->loadImage( "resources\\tile_stone64.jpg" );
	IMG_WATER64 = image->loadImage( "resources\\tile_water64.jpg" );
	IMG_WOOD64 = image->loadImage( "resources\\tile_wood64.jpg" );

	IMG_P1 = image->loadImage( "resources\\tile_p1.png" );
	IMG_P2 = image->loadImage( "resources\\tile_p2.png" );
	IMG_END = image->loadImage( "resources\\tile_end.png" );

	IMG_MENU1 = image->loadImage( "resources\\ui_menu1.png" );

	IMG_BUTTON_HIGHLIGHT = image->loadImage( "resources\\ui_menuHighlight.jpg" );
	IMG_SELECT_HIGHLIGHT = image->loadImage( "resources\\ui_editorHighlight.png" );
	IMG_INFOBAR = image->loadImage( "resources\\ui_infoBar.png" );
}

Editor::~Editor( )
{
	SDL_FreeSurface( editorBackground );
	SDL_FreeSurface( horizontalLine );
	SDL_FreeSurface( verticalLine );

	SDL_FreeSurface( IMG_BRICK );
	SDL_FreeSurface( IMG_DIRT );
	SDL_FreeSurface( IMG_DIRTYBRICK );
	SDL_FreeSurface( IMG_GRASS );
	SDL_FreeSurface( IMG_LAVA );
	SDL_FreeSurface( IMG_REDCARPET );
	SDL_FreeSurface( IMG_STONE );
	SDL_FreeSurface( IMG_WATER );
	SDL_FreeSurface( IMG_WOOD );

	SDL_FreeSurface( IMG_MENU1 );

	SDL_FreeSurface( IMG_BUTTON_HIGHLIGHT );
	SDL_FreeSurface( IMG_INFOBAR );
}

int Editor::runEditor( )
{
	bool quit = false;
	while ( !quit )
	{
		switch ( input( ) )
		{
			case -1:
				return Global::AS_MAIN_MENU;
			case 0:
				break;
		}

		switch ( update( ) )
		{
			case -1:
				return Global::AS_MAIN_MENU;
			case 0:
				break;
			case 1:
				return Global::AS_EDITOR;
		}

		switch ( draw( ) )
		{
			case 0:
				break;
		}
	}
}

int Editor::input( )
{
	cout << "DEBUG:: editor input" << endl;
	SDL_Event event;
	if ( SDL_PollEvent( &event ) )
	{
		if ( event.type == SDL_MOUSEBUTTONUP )
			if ( event.button.button == SDL_BUTTON_LEFT )
			{
				needsUpdate = true;
				mouseUp.x = event.button.x;
				mouseUp.y = event.button.y;
				if ( mouseUp.y < 640 )
					needsDraw = true;
			}
	}
	return 0;
}

int Editor::update( )
{
	if ( needsUpdate )
	{

		if ( mouseUp.y <= 640 )
		{
			cout << "grid update" << endl;
			mouseUp.x /= 32;
			mouseUp.y /= 32;
			grid->setTileAt( mouseUp.x, mouseUp.y, selectedTile );
		}
		else
		{
			if ( mouseUp.y >= 704 && mouseUp.y <= 736 )
				for ( int i = 0; i < 9; i++ )
				{
					if ( mouseUp.x >= ( 12 + ( i * 48 ) ) && mouseUp.x <= ( ( 12 + ( i * 48 ) ) + 32 ) )
						selectedTile = i + 1;

				}
			if ( mouseUp.x > 1024 && mouseUp.x < 1280 )
			{
				int y = mouseUp.y;
				if ( y >= 641 && y <= 683 )
				{
					return 1;
				}
				else if ( y >= 683 && y <= 725 )
				{
					save( );
					needsDraw = true;
				}
				else if ( y >= 725 && y <= 767 )
				{
					return -1;
				}
			}
		}
		needsUpdate = false;
	}
	return 0;
}

int Editor::draw( )
{
	cout << "DEBUG:: editor input" << endl;
	if ( !fileOpen )
	{
		image->drawSurface( 0, 0, editorBackground );
		for ( int i = 0; i <= Global::GRID_WIDTH; i++ )
			image->drawSurface( i * 32, 0, verticalLine );
		image->drawSurface( 1279, 0, verticalLine );
		for ( int j = 0; j <= Global::GRID_HEIGHT; j++ )
			image->drawSurface( 0, j * 32, horizontalLine );
	}

	if ( needsDraw )
		grid->drawGrid( );

	//Draw bar
	image->drawSurface( 0, 640, IMG_INFOBAR );
	image->drawSurface( 0, 640, horizontalLine );
	image->drawSurface( 0, 767, horizontalLine );

	//Draw tile selection
	image->drawSurface( 12 + ( 48 * ( selectedTile - 1 ) ), 700, IMG_SELECT_HIGHLIGHT );
	image->drawSurface( 16, 704, IMG_BRICK );
	image->drawSurface( 64, 704, IMG_DIRT );
	image->drawSurface( 112, 704, IMG_DIRTYBRICK );
	image->drawSurface( 160, 704, IMG_GRASS );
	image->drawSurface( 208, 704, IMG_LAVA );
	image->drawSurface( 256, 704, IMG_REDCARPET );
	image->drawSurface( 304, 704, IMG_STONE );
	image->drawSurface( 352, 704, IMG_WATER );
	image->drawSurface( 400, 704, IMG_WOOD );
	SDL_Rect offset;
	offset.x = 0;
	offset.y = 640;
	offset.w = 432;
	offset.h = 64;

	//Draw selection display
	switch ( selectedTile )
	{
		case 1:
			image->drawSurface( 496, 700, IMG_BRICK64 );
			text->writeText( 0, 640, "Brick", 24 );
			text->writeText( 0, 672, "Background", 24 );
			break;
		case 2:
			image->drawSurface( 496, 700, IMG_DIRT64 );
			text->writeText( 0, 640, "Dirt", 24 );
			text->writeText( 0, 672, "Background", 24 );
			break;
		case 3:
			image->drawSurface( 496, 700, IMG_DIRTYBRICK64 );
			text->writeText( 0, 640, "Dirty Brick", 24 );
			text->writeText( 0, 672, "Background", 24 );
			break;
		case 4:
			image->drawSurface( 496, 700, IMG_GRASS64 );
			text->writeText( 0, 640, "Grass", 24 );
			text->writeText( 0, 672, "Background", 24 );
			break;
		case 5:
			image->drawSurface( 496, 700, IMG_LAVA64 );
			text->writeText( 0, 640, "Lava", 24 );
			text->writeText( 0, 672, "Unpassable", 24 );
			break;
		case 6:
			image->drawSurface( 496, 700, IMG_REDCARPET64 );
			text->writeText( 0, 640, "Red Carpet", 24 );
			text->writeText( 0, 672, "Background", 24 );
			break;
		case 7:
			image->drawSurface( 496, 700, IMG_STONE64 );
			text->writeText( 0, 640, "Stone", 24 );
			text->writeText( 0, 672, "Background", 24 );
			break;
		case 8:
			image->drawSurface( 496, 700, IMG_WATER64 );
			text->writeText( 0, 640, "Water", 24 );
			text->writeText( 0, 672, "Unpassable", 24 );
			break;
		case 9:
			image->drawSurface( 496, 700, IMG_WOOD64 );
			text->writeText( 0, 640, "Wood", 24 );
			text->writeText( 0, 672, "Background", 24 );
			break;
		default:
			break;
	}

	//Spawns/Endzones

	//Buttons
	SDL_Rect size;
	size.x = 390;
	size.y = 134;
	size.w = 256;
	size.h = 42;

	offset.x = 1024;
	offset.y = 641;
	offset.w = 256;
	offset.h = 42;
	SDL_BlitSurface( IMG_MENU1, &size, screenSurface, &offset );
	text->writeTextCentered( offset, "New", 36 );
	offset.y = 683;
	SDL_BlitSurface( IMG_MENU1, &size, screenSurface, &offset );
	text->writeTextCentered( offset, "Save", 36 );
	offset.y = 725;
	SDL_BlitSurface( IMG_MENU1, &size, screenSurface, &offset );
	text->writeTextCentered( offset, "Exit", 36 );

	needsDraw = false;
	SDL_UpdateWindowSurface( window );

	return 0;
}

void Editor::save( )
{
	SDL_Surface* menu = image->loadImage( "resources\\ui_menu5.png" );
	image->drawSurface( 0, 0, menu );
	SDL_Rect box;
	box.x = 390;
	box.y = 134;
	box.w = 500;
	box.h = 100;

	string titles[5] = { "Save to level 1", "Save to level 2", "Save to level 3", "Save to level 4", "Save to level 5" };
	for ( int i = 0; i < 5; i++ )
	{
		string inputStr = titles[i];
		char * displayText = new char[inputStr.size( ) + 1];
		copy( inputStr.begin( ), inputStr.end( ), displayText );
		displayText[inputStr.size( )] = '\0';

		text->writeTextCentered( box, displayText, 46 );
		box.y += 100;
	}

	SDL_UpdateWindowSurface( window );

	bool havePath = false;
	while ( !havePath )
	{
		int x, y;
		string savePath;
		SDL_Event event;

		if ( SDL_PollEvent( &event ) )
		{
			if ( event.type == SDL_MOUSEBUTTONUP )
				if ( event.button.button == SDL_BUTTON_LEFT )
				{
					x = event.button.x;
					y = event.button.y;
				}

			if ( x > 390 && x < 890 )
			{
				if ( y > 134 && y < 234 )
				{
					audio->playSound( "rsc\\audio\\sfx_buttonPress.wav" );
					savePath = "resources\\data_s1.txt";
					havePath = true;
				}
				else if ( y > 234 && y < 334 )
				{
					audio->playSound( "rsc\\audio\\sfx_buttonPress.wav" );
					savePath = "resources\\data_s2.txt";
					havePath = true;
				}
				else if ( y > 334 && y < 434 )
				{
					audio->playSound( "rsc\\audio\\sfx_buttonPress.wav" );
					savePath = "resources\\data_s3.txt";
					havePath = true;
				}
				else if ( y > 434 && y < 534 )
				{
					audio->playSound( "rsc\\audio\\sfx_buttonPress.wav" );
					savePath = "resources\\data_s4.txt";
					havePath = true;
				}
				else if ( y > 534 && y < 634 )
				{
					audio->playSound( "rsc\\audio\\sfx_buttonPress.wav" );
					savePath = "resources\\data_s5.txt";
					havePath = true;
				}
			}
		}

		grid->editorSave( savePath, oneSpawn, twoSpawn, endzone );
	}
}