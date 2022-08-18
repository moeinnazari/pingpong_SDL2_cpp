#ifndef __GameState__
#define __GameState__
#include "GlobalVar.h"
#include "GameEngineStates.h"


class GameEngineStates;
class GameState
{
public:


    virtual ~GameState(){}
    virtual void init()=0;
    virtual void handleEvent(GameEngineStates* game)=0;
    virtual void logic(GameEngineStates* game)=0;
    virtual void render(GameEngineStates* game)=0;
    virtual void clean()=0;

    virtual void pause()=0;
    virtual void resume()=0;
};
#endif // __
