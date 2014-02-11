#ifndef TIMER_H
#define	TIMER_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <vector>

//The timer
class Timer
{
    public:
    //Initializes variables
    Timer();
    ~Timer();

    //The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();

    //Gets the timer's time
    int get_ticks();

    //Checks the status of the timer
    bool is_started();
    bool is_paused();
    
    private:
    //The clock time when the timer started
    int startTicks;

    //The ticks stored when the timer was paused
    int pausedTicks;

    //The timer status
    bool paused;
    bool started;

};

#endif	/* TIMER_H */

