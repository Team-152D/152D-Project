#include "Audio.h"

Audio::Audio( )
{
	UI_Button_click = loadSound( "rsc\\audio\\sfx_buttonPress.wav" );
	UI_Checkbox_click = loadSound( "rsc\\audio\\sfx_checkboxPress.wav" );
	Game_readyGo = loadSound( "rsc\\audio\\sfx_readyGo.wav" );
	Game_victory = loadSound( "rsc\\audio\\sfx_victory.wav" );
	Music1 = Mix_LoadMUS( "rsc\\audio\\sfx_music1.wav" );

	cout << "\tAudio class..." << endl;
}

Audio::~Audio( )
{
	Mix_FreeChunk( UI_Button_click );
	Mix_FreeChunk( UI_Checkbox_click );
	Mix_FreeChunk( Game_readyGo );
	Mix_FreeChunk( Game_victory );
	Mix_FreeMusic( Music1 );
}

Mix_Chunk* Audio::loadSound( string identifier )
{
	Mix_Chunk *temp = Mix_LoadWAV( identifier.c_str( ) );
	return temp;
}

void Audio::playSound( int identifier )
{
	switch ( identifier )
	{
		case 1:
			if ( Mix_PlayChannel( 1, UI_Button_click, 0 ) == -1 )
				cout << "ERROR: Failed to play sound UI_Button_click" << endl;
			break;
		case 2:
			if ( Mix_PlayChannel( 1, Game_readyGo, 0 ) == -1 )
				cout << "ERROR: Failed to play sound Game_readyGo" << endl;
			break;
		case 3:
			if ( Mix_PlayChannel( 1, Game_victory, 0 ) == -1 )
				cout << "ERROR: Failed to play sound Game_victory" << endl;
			break;
		case 4:
			if ( Mix_PlayChannel( 1, UI_Checkbox_click, 0 ) == -1 )
				cout << "ERROR: Failed to play sound Game_victory" << endl;
			break;
		default:
			break;
	}
}

void Audio::playMusic( int identifier )
{
	switch( identifier )
	{
		case 1:
			if( Mix_PlayMusic( Music1, 0 ) == -1 )
				cout << "ERROR: Failed to play Music1" << endl;
			break;
		default:
			break;
	}
}