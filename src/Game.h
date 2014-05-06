#ifndef GAME_H
#define	GAME_H

#include <fstream>
#include <string>
#include <vector>

#include "net.h"
#include "Level.h"
#include "Image.h"
#include "Timer.h"
#include "Global.h"
#include "Command.h"
#include "Audio.h"
#include "Text.h"
#include "chat.h"


class Game
{
public:
    Game(bool,int);
    ~Game();
    int runGame();
    
    int getFrameCounter();
    int getCurrentLevelNumber();
    
    bool multiPlayer;
private:
    Level* currentLevel;
    
    int currentLevelNumber, frameCounter;
    Timer fps;
    command CMD;
    
    int runGameLoop();
    int input();
    int update();
    int draw();
    
    bool pauseGame();
    void displayInfoBar();
    void displayDebug();
    
    SDL_Surface* IMG_MENU2;
    
    SDL_Surface* IMG_HIGHLIGHT;
    SDL_Surface* IMG_INFOBAR;
    
    chat ch_box; 
};

#endif
