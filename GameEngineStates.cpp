#include "GameEngineStates.h"

SDL_Renderer* GameEngineStates::m_Renderer=0;
SDL_Window* GameEngineStates::m_Window=0;
TTF_Font* GameEngineStates::m_Font=0;




bool GameEngineStates::isRunning=true;

GameEngineStates::GameEngineStates()
{

}

bool GameEngineStates::init()
{
    bool success=true;
    if(SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO)<0)
    {
        std::cout<<"sdl init failed\n"<<SDL_GetError()<<"\n";
        success=false;
    }
    else
    {
        m_Window=SDL_CreateWindow("myGame",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
        if(m_Window==NULL)
        {
            std::cout<<"creation window failed\n"<<SDL_GetError()<<"\n";
            success=false;
        }
        else
        {
            m_Renderer=SDL_CreateRenderer(m_Window,-1,SDL_RENDERER_ACCELERATED |SDL_RENDERER_PRESENTVSYNC);
            if(m_Renderer==NULL)
            {
                std::cout<<"creation renderer faield\n"<<SDL_GetError()<<"\n";
                success=false;
            }
            else
            {
                //init SDL_TTF
                if(TTF_Init()==-1)
                {
                    std::cout<<"ini ttf failed\n";
                    success=false;
                }
                else
                {

                      SDL_SetRenderDrawColor(m_Renderer,COLOR_BLACK.r,COLOR_BLACK.g,COLOR_BLACK.b,COLOR_BLACK.a);
                }
            }
        }
    }

    return success;
}

bool GameEngineStates::load()
{
    bool success=true;
    m_Font=TTF_OpenFont("assets/Bebas-Regular.ttf",FONT_SIZE_MEDIUM);
    if(m_Font==NULL)
    {
        success=false;
    }

    return success;
}

void GameEngineStates::handleEvent()
{
    if(!m_GameStates.empty())
    {
       m_GameStates.back()->handleEvent(this);
    }
}


void GameEngineStates::logic()
{
    if(!m_GameStates.empty())
     {
       m_GameStates.back()->logic(this);
     }
}


void GameEngineStates::render()
{
   SDL_SetRenderDrawColor(m_Renderer,255,0,0,255);
   SDL_RenderClear(m_Renderer);

   if(!m_GameStates.empty())
   {
       m_GameStates.back()->render(this);
   }

   SDL_RenderPresent(m_Renderer);

}




void GameEngineStates::pushState(GameState* gState)
{
    if(!m_GameStates.empty())
    {
        m_GameStates.back()->pause();

    }

    m_GameStates.push_back(gState);
    m_GameStates.back()->init();

}

void GameEngineStates::changeState(GameState* gState)
{
    if(!m_GameStates.empty())
    {
        m_GameStates.back()->clean();
        m_GameStates.pop_back();
    }

    m_GameStates.push_back(gState);
    m_GameStates.back()->init();

}

void GameEngineStates::popState()
{
    if(!m_GameStates.empty())
      {
          m_GameStates.back()->clean();
          m_GameStates.pop_back();
      }

      if(!m_GameStates.empty())
      {
          m_GameStates.back()->resume();
      }

}


void GameEngineStates::clean()
{
    while(!m_GameStates.empty())
    {
        m_GameStates.back()->clean();
        m_GameStates.pop_back();
    }

    SDL_DestroyRenderer(m_Renderer);
    m_Renderer=0;
    SDL_DestroyWindow(m_Window);
    m_Window=0;



    TTF_CloseFont(m_Font);
    TTF_Quit();
    SDL_Quit();
}



GameEngineStates::~GameEngineStates()
{

}
