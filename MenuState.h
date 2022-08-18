#ifndef __MenuState__
#define __MenuState__

#include "GlobalVar.h"
#include "GameState.h"
#include "Texture.h"

class Texture;
class GameEngineStates;
class MenuState : public GameState
{
public:
    MenuState();
    ~MenuState();

    void init();
    void handleEvent(GameEngineStates* game);
    void logic(GameEngineStates* game);
    void render(GameEngineStates* game);
    void clean();

    void pause(){isPaused=true;}
    void resume(){isPaused=false;}
    void nextHoverDown();
    void nextHoverUp();
private:
    bool isPaused;
    std::unique_ptr<Texture> m_Start;
    std::unique_ptr<Texture> m_Credit;
    std::unique_ptr<Texture> m_Exit;

     enum class Button : int{START=0,CREDIT=1,EXIT=2};


    Button m_curbtn;
    SDL_Event event;
    SDL_Rect m_bg;
    Mix_Chunk* m_menusound;

};

#endif // __MenuState__
