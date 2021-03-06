#ifndef UI_IPFIELD_H
#define	UI_IPFIELD_H

#include <fstream>
#include "UI_AbstractElement.h"
#include "Text.h"
#include "Timer.h"

class UI_IPfield: public UI_AbstractElement{
    public:
        UI_IPfield(SDL_Rect, int, bool);
        ~UI_IPfield();
        virtual void draw();
        virtual int handleEvents(SDL_Event*);
        void setIP();
    private:
        string addr;//ip address stored by user
        SDL_Surface* bg;//background
        bool focus, mousedown, centered;         
        int fontSize;
        fstream ipSav;
        
        //currently uses internal timer
        //consider switch to passed down timer (gametimer)
        bool cursorBlink();
        Timer blink;
};

#endif	/* UI_TEXTFIELD_H */

