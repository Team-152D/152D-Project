#ifndef UI_ELEMENT_H
#define	UI_ELEMENT_H

#include <string>

#include "SDL2/SDL.h"

using namespace std;

class UI_AbstractElement {
public:

    UI_AbstractElement() {
    }

    ~UI_AbstractElement() {
    }
    virtual int handleEvents(SDL_Event*) = 0;
    virtual void draw() = 0;
protected:
    SDL_Rect bounds;
    string identifier, label;

    bool coordinatesAreInRect(int x, int y, SDL_Rect rect) {
        if ((x > rect.x) && (x < rect.x + rect.w) && (y > rect.y) && (y < rect.y + rect.h))
            return true;
        else
            return false;
    }
};

#endif