#ifndef __Timer__
#define __Timer__
#include "GlobalVar.h"

class Timer{
public:
    Timer();
    ~Timer();
    void start();
    void stop();
    void pause();
    void unpause();

    int getTick();

    bool isStarted(){return started;}
    bool isPaused(){return paused;}
private:
    int startTick;
    int pauseTick;

    bool started;
    bool paused;

};
#endif // __Timer__
