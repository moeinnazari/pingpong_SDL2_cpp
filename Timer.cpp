#include "Timer.h"

Timer::Timer()
{
    startTick=0;
    pauseTick=0;
    started=false;
    paused=false;
}

Timer::~Timer()
{
    startTick=0;
    pauseTick=0;
    started=false;
    paused=false;
}

void Timer::start()
{

        started=true;

        startTick=SDL_GetTicks();
        pauseTick=0;

}

void Timer::pause()
{
    if(started && !paused)
    {
        paused=true;

        pauseTick=SDL_GetTicks()-startTick;
    }
}

void Timer::unpause()
{
    if(started && paused)
    {
        paused=false;

        startTick=SDL_GetTicks()-pauseTick;
        pauseTick=0;
    }
}

void Timer::stop()
{
    started=false;
    paused=false;

    startTick=0;
    pauseTick=0;
}

int Timer::getTick()
{
    if(started)
    {
        if(paused)
        {
            return pauseTick;
        }
        else
        {
            return SDL_GetTicks()-startTick;
        }

    }
    return 0;
}
