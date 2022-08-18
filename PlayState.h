#ifndef __PlayState__
#define __PlayState__
#include "GlobalVar.h"
#include "GameState.h"
#include "GameEngineStates.h"
#include "Texture.h"
#include "Player.h"
#include "Ball.h"

class Ball;
class Player;
class Texture;
class GameEngineStates;

class PlayState : public GameState
{
public:
    PlayState();
    ~PlayState();

    void init();
    void handleEvent(GameEngineStates* game);
    void logic(GameEngineStates* game);
    void render(GameEngineStates* game);
    void clean();

    void pause() {isPaused=true;}
    void resume() {isPaused=false;}

private:
    bool isPaused;

    std::unique_ptr<Texture> m_scorePlayer;
    std::unique_ptr<Texture> m_scorePC;
    std::unique_ptr<Player> m_player;
    std::unique_ptr<Player> m_PC;
    std::unique_ptr<Ball> m_ball;


    SDL_Event event;
    SDL_Rect m_boarder;
    SDL_Rect m_bg;

    Mix_Chunk* m_success;
    Mix_Chunk* m_lose;
    Mix_Chunk* m_ballHitRocket;
    Mix_Chunk* m_ballHitWall;

    int scorePC;
    int scorePlayer;
};
#endif // __PlayState__
