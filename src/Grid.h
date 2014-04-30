#ifndef __GameProject__Grid__
#define __GameProject__Grid__

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "Global.h"
#include "Image.h"

using namespace std;

class Grid
{
public:
    Grid(string);
    Grid(vector<vector<int>*>*);
    ~Grid();
    
    void loadGrid(string);
    void editorSave(string,SDL_Rect,SDL_Rect, SDL_Rect);
    void drawGrid();
    int getTileAt(int,int);
    void setTileAt(int,int,int);
private:
    void printGrid();
    
    vector< vector<int>*>* grid;
    int width;
    int height;
    
    SDL_Surface* IMG_BRICK;
    SDL_Surface* IMG_DIRT;
    SDL_Surface* IMG_DIRTYBRICK;
    SDL_Surface* IMG_GRASS;
    SDL_Surface* IMG_LAVA;
    SDL_Surface* IMG_REDCARPET;
    SDL_Surface* IMG_STONE;
    SDL_Surface* IMG_WATER;
    SDL_Surface* IMG_WOOD;
    SDL_Surface* IMG_TEMP;
};

#endif