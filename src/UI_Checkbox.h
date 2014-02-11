#ifndef CHECKBOX_H
#define	CHECKBOX_H

#include <string>

#include "SDL2/SDL.h"

#include "Settings.h"
#include "UI_AbstractElement.h"

using namespace std;

class UI_Checkbox : public UI_AbstractElement
{
public:
	UI_Checkbox(SDL_Rect,char*,char*,int);
	~UI_Checkbox();
	
	int handleEvents(SDL_Event*);
	void draw();
private:
	bool *isChecked;
	bool mouseDown;
	
	int actionValue;
	
	SDL_Surface *checkboxBackground;
	SDL_Surface *checkboxCheck;
};

#endif