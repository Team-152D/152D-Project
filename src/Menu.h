#ifndef MENU_H
#define	MENU_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "SDL2/SDL.h"

#include "Global.h"
#include "View.h"

#include "chat.h"

using namespace std;

class Menu
{
public:
    Menu(string);
    ~Menu();

    int runMenu();
private:
	string identifier;
    int currentView;
    vector<View*>* views;
    bool polledEvent;

    int input();
    int update(int);
    int draw();
	void drawDebug();
    void loadViews(string);
    
    SDL_Surface *background;
    string str;
    
    chat ch;
};

#endif