#ifndef VIEW_H
#define	VIEW_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "SDL2/SDL.h"

#include "Global.h"
#include "Image.h"
#include "Text.h"
#include "UI_AbstractElement.h"
#include "UI_Button.h"
#include "UI_Checkbox.h"
#include "UI_TextLabel.h"

using namespace std;

class View
{
public:
    View(int,string);
    ~View();
    
    int input(SDL_Event*);
    void draw();
    
    void loadElements(string);
	int getParentView();
private:
    vector<UI_AbstractElement*> *elements;
	int parentView;
	SDL_Surface *backgroundImage;
};

#endif