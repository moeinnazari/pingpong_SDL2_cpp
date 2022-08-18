#include <iostream>
#include "GlobalVar.h"
#include "GameEngineStates.h"
#include "Timer.h"
#include "MenuState.h"
#include "PauseState.h"
#include "PlayState.h"


int main(int argc,char* argv[])
{
    srand(time(0));
    GameEngineStates* game=new GameEngineStates();
    if(!game->init())
    {
        std::cout<<"init gameEngineStates failed\n";
        delete game;
        return -1;
    }
    else
    {
        if(!game->load())
        {
        std::cout<<"load gameEngineState failed\n";
        delete game;
        return -1;
        }
        else
        {   Timer fps;

            game->changeState(new MenuState());
            while(game->getIsRunning())
            {
                fps.start();

                  game->handleEvent();


                game->logic();
                game->render();

                if(fps.getTick() < SECOND_PER_FRAME)
                {
                    SDL_Delay(SECOND_PER_FRAME-fps.getTick());
                }
            }
            game->clean();
        }
    }
    delete game;
    return 0;
}
