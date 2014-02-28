#include "Audio.h"

Audio::Audio( )
{
	cout << "\tAudio class..." << endl;
}

Audio::~Audio( )
{
	
}

Mix_Chunk* Audio::loadSound(string identifier)
{
	Mix_Chunk *temp = Mix_LoadWAV(identifier.c_str());
	return temp;
}

void Audio::playSound( string identifier )
{
	Mix_Chunk *sound = loadSound( identifier );
	if ( Mix_PlayChannel( 1, sound, 0 ) == -1 )
		cout << "ERROR: Failed to play sound" << endl;
	Mix_FreeChunk( sound );
}

void Audio::playMusic( string identifier )
{
	Mix_Music *music = Mix_LoadMUS(identifier.c_str());
	if( Mix_PlayMusic(music,1) == -1 )
		cout << "ERROR: Failed to play music" << endl;
	Mix_FreeMusic(music);
}