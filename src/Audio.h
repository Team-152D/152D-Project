#ifndef AUDIO_H
#define	AUDIO_H

#include <iostream>
#include <string>

#include "SDL2/SDL_mixer.h"

#include "Global.h"

using namespace std;

class Audio
{
public:
    Audio();
    ~Audio();
    
    void playSound(string);
    void playMusic(string);
private:
    Mix_Chunk* loadSound(string);
};

#endif