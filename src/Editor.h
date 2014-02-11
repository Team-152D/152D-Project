#ifndef EDITOR_H
#define	EDITOR_H

#include <fstream>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "Global.h"
#include "Image.h"
#include "Text.h"
#include "Grid.h"

class Editor
{
public:
    Editor();
    ~Editor();
    int runEditor();
private:
    int input();
    int update();
    int draw();
    
    //void newMap();
    //void close();
    void save();

    Grid* grid;
    bool fileOpen, needsUpdate, needsDraw;
    int selectedTile;
    SDL_Rect mouseDown, mouseUp, oneSpawn, twoSpawn, endzone;

    SDL_Surface* editorBackground;
    SDL_Surface* horizontalLine;
    SDL_Surface* verticalLine;

    SDL_Surface* IMG_BRICK;
    SDL_Surface* IMG_DIRT;
    SDL_Surface* IMG_DIRTYBRICK;
    SDL_Surface* IMG_GRASS;
    SDL_Surface* IMG_LAVA;
    SDL_Surface* IMG_REDCARPET;
    SDL_Surface* IMG_STONE;
    SDL_Surface* IMG_WATER;
    SDL_Surface* IMG_WOOD;
    
    SDL_Surface* IMG_BRICK64;
    SDL_Surface* IMG_DIRT64;
    SDL_Surface* IMG_DIRTYBRICK64;
    SDL_Surface* IMG_GRASS64;
    SDL_Surface* IMG_LAVA64;
    SDL_Surface* IMG_REDCARPET64;
    SDL_Surface* IMG_STONE64;
    SDL_Surface* IMG_WATER64;
    SDL_Surface* IMG_WOOD64;
    SDL_Surface* IMG_P1;
    SDL_Surface* IMG_P2;
    SDL_Surface* IMG_END;
    
    SDL_Surface* IMG_MENU1;
    
    SDL_Surface* IMG_BUTTON_HIGHLIGHT;
    SDL_Surface* IMG_SELECT_HIGHLIGHT;    
    SDL_Surface* IMG_INFOBAR;
};

#endif