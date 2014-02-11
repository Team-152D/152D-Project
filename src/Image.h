#ifndef IMAGE_H
#define	IMAGE_H

#include <iostream>
#include <string>
#include <vector>

#include "SDL2/SDL.h"

#include "Global.h"

using namespace std;

class Image
{
public:
    Image();
    ~Image();
    
    SDL_Surface* loadImage(string);
    int drawSurface(int,int,SDL_Surface*);
private:
};

#endif

