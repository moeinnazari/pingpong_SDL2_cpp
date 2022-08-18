#include "PlayState.h"
#include "PauseState.h"
#include "Utils.h"

PlayState::PlayState()
{
    m_scorePlayer=std::unique_ptr<Texture>(new Texture());
    m_scorePC=std::unique_ptr<Texture>(new Texture());
    m_player=std::unique_ptr<Player>(new Player());
    m_PC=std::unique_ptr<Player>(new Player());
    m_ball=std::unique_ptr<Ball>(new Ball());

    isPaused=false;
    scorePC=0;
    scorePlayer=0;
}

void PlayState::init()
{
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,1024);


    m_bg={0,0,SCREEN_WIDTH,SCREEN_HEIGHT};
    m_boarder={(SCREEN_WIDTH-10)/2,0,4,SCREEN_HEIGHT};

    m_scorePlayer->loadFileFromText(std::to_string(scorePlayer),COLOR_WHITE,FONT_SIZE_LARGE);
    m_scorePC->loadFileFromText(std::to_string(scorePC),COLOR_WHITE,FONT_SIZE_LARGE);
   m_PC->init(5,(SCREEN_HEIGHT-Player_HEIGHT)/2);
    m_ball->init();

    m_success=Mix_LoadWAV("assets/success.wav");
    m_lose=Mix_LoadWAV("assets/lose.wav");
    m_ballHitRocket=Mix_LoadWAV("assets/rocket.wav");
    m_ballHitWall=Mix_LoadWAV("assets/wall.wav");

}

void PlayState::handleEvent(GameEngineStates* game)
{
   while(SDL_PollEvent(&event))
   {


       switch(event.type)
       {
       case SDL_QUIT:
           game->quit();
        break;
       case SDL_KEYDOWN:

                if(event.key.keysym.sym==SDLK_ESCAPE && event.key.repeat==0)
                {
                    game->pushState(new PauseState());
                }

                 if(event.key.keysym.sym==SDLK_DOWN && event.key.repeat==0)
                {
                     m_player->doDown();
                }
                 if(event.key.keysym.sym==SDLK_UP && event.key.repeat==0)
                {

                    m_player->doUp();
                }
                  if(event.key.keysym.sym==SDLK_s && event.key.repeat==0)
                {

                     m_PC->doDown();
                }
                  if(event.key.keysym.sym==SDLK_w&& event.key.repeat==0)
                {
                    m_PC->doUp();
                }
        break;
       case SDL_KEYUP:
                if(event.key.keysym.sym==SDLK_DOWN && event.key.repeat==0)
                {
                    m_player->stopDown();
                }
                if(event.key.keysym.sym==SDLK_UP && event.key.repeat==0)
                {

                    m_player->stopUp();
                }
                if(event.key.keysym.sym==SDLK_s && event.key.repeat==0)
                {
                    m_PC->stopDown();
                }
                if(event.key.keysym.sym==SDLK_w && event.key.repeat==0)
                {
                    m_PC->stopUp();
                }
        break;
       }
   }


}

void PlayState::logic(GameEngineStates* game)
{
 m_player->logic();
 m_ball->logic();
 m_PC->logic();
 if( Utils::checkCollision(m_ball->getRect(),m_player->getRect()) || Utils::checkCollision(m_ball->getRect(),m_PC->getRect()))
 {
     Mix_PlayChannel(-1,m_ballHitRocket,0);
     m_ball->changeDir();


 }
 if(m_ball->IsOut())
 {

     SDL_Delay(800);
     if(m_ball->getPosX()>= SCREEN_WIDTH)
     {
        Mix_PlayChannel(-1,m_lose,0);
         m_scorePC->loadFileFromText(std::to_string(++scorePC),COLOR_WHITE,FONT_SIZE_LARGE);

     }
     else if(m_ball->getPosX() <= 0)
     {
         Mix_PlayChannel(-1,m_success,0);
          m_scorePlayer->loadFileFromText(std::to_string(++scorePlayer),COLOR_WHITE,FONT_SIZE_LARGE);
     }
     m_ball->init();
 }

 if(m_ball->hitWall())
 {
     Mix_PlayChannel(-1,m_ballHitWall,0);
 }
}

void PlayState::render(GameEngineStates* game)
{
    if(!isPaused)
    {
        SDL_SetRenderDrawColor(game->getRenderer(),COLOR_BLACK.r,COLOR_BLACK.g,COLOR_BLACK.b,COLOR_BLACK.a);
        SDL_RenderFillRect(game->getRenderer(),&m_bg);

        SDL_SetRenderDrawColor(game->getRenderer(),COLOR_WHITE.r,COLOR_WHITE.g,COLOR_WHITE.b,COLOR_WHITE.a);
        SDL_RenderFillRect(game->getRenderer(),&m_boarder);

        m_scorePC->render((((SCREEN_WIDTH-30)/2)-m_scorePC->getWidth())/2,30);
        m_scorePlayer->render((SCREEN_WIDTH-30)/2+(((SCREEN_WIDTH-30)/2)+m_scorePC->getWidth())/2,30);

        m_player->render();
        m_PC->render();
        m_ball->render();
    }
}

void PlayState::clean()
{
  std::cout<<"playState finish\n";
   m_scorePC->free();
   m_scorePlayer->free();
   m_player->clean();
   m_PC->clean();
   m_ball->clean();

   Mix_FreeChunk(m_ballHitWall);
   Mix_FreeChunk(m_ballHitRocket);
   Mix_FreeChunk(m_success);
   Mix_FreeChunk(m_lose);
   Mix_CloseAudio();

}
PlayState::~PlayState()
{

}
