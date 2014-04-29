#ifndef COMMAND_H
#define	COMMAND_H

#include "SDL2/SDL.h"

class command{
    int sock;

public:
    command();
    ~command();
    void setSocket(int);
    int getSocket();
    void push(SDL_Event, bool);
    void take();
    
    char slfCmd[16];
    char othCmd[16];
};

#endif 

