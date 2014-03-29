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
    
    void playSound(int);
    void playMusic(string);
private:
    Mix_Chunk* loadSound(string);
    
    Mix_Chunk *UI_Button_click;
    Mix_Chunk *UI_Checkbox_click;
    Mix_Chunk *Game_readyGo;
    Mix_Chunk *Game_victory;
};

#endif