#ifndef TEXT_H
#define	TEXT_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

#include "Image.h"

class Text
{
public:
    Text();
    ~Text();
    
    void writeText(int,int,const char*,int);
    void writeTextCentered(SDL_Rect,const char*,int);
    void changeColor(int,int,int);
private:
    int fontSize;
    TTF_Font *font;
    SDL_Color color;
};

#endif