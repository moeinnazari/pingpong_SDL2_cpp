#ifndef __GameEngineStates__
#define __GameEngineStates__
#include "GlobalVar.h"
#include "GameState.h"

class GameState;
class GameEngineStates
{
public:
    GameEngineStates();
    ~GameEngineStates();

    void pushState(GameState* gState);
    void changeState(GameState* gState);
    void popState();

    bool init();
    bool load();
    void handleEvent();
    void logic();
    void render();
    void clean();

    static SDL_Renderer* getRenderer() {return m_Renderer;}
    static SDL_Window* getWindow() {return m_Window;}
    static TTF_Font* getFont() {return m_Font;}

    //if isRunning be false game is over
           bool getIsRunning(){return isRunning;}
    static void quit(){isRunning=false;}


private:

     static  bool isRunning;
     static  SDL_Renderer* m_Renderer;
     static SDL_Window* m_Window;
     static TTF_Font* m_Font;



     std::vector<GameState*> m_GameStates;
};
#endif // __GameEngineStates__
