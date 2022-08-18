#ifndef __PauseState__
#define __PauseState__
#include "GlobalVar.h"
#include "GameState.h"
#include "GameEngineStates.h"
#include "Texture.h"

class Texture;
class GameEngineStates;
class PauseState: public GameState
{
   public:
       PauseState();
       ~PauseState();

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
    SDL_Event event;

    std::unique_ptr<Texture> m_Resume;
    std::unique_ptr<Texture> m_ExitFromGame;
    SDL_Rect m_bg;
    Mix_Chunk* m_menusound;

    enum class Button : int {RESUME=0,EXIT_GAME=1};
    Button m_curbtn;
};
#endif // __PauseState__
