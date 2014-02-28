#ifndef APPLICATION_H
#define	APPLICATION_H

#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"

#include "Editor.h"
#include "Global.h"
#include "Menu.h"

class Audio;
class Image;
class Text;

using namespace std;

class Application
{
public:
    Application();
    ~Application();
    int runApplication();
private:
    bool initializeApplication();
    int appState;
    Game *game;
    Editor *editor;
    Menu *menu;
};

#endif