#include "PauseState.h"
#include "MenuState.h"


PauseState::PauseState()
{

m_Resume=std::unique_ptr<Texture>(new Texture());
m_ExitFromGame=std::unique_ptr<Texture>(new Texture());

isPaused=false;
m_curbtn=Button::RESUME;
}

void PauseState::init()
{

    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,1024);
    m_bg={0,0,SCREEN_WIDTH,SCREEN_HEIGHT};
    m_Resume->loadFileFromText("resume",COLOR_YELLOW);
    m_ExitFromGame->loadFileFromText("Exit from game",COLOR_WHITE);
    m_menusound=Mix_LoadWAV("assets/menu.wav");
}

void PauseState::handleEvent(GameEngineStates* game)
{
    while(SDL_PollEvent(&event))
     {
         switch(event.type)
         {
         case SDL_QUIT:
                game->quit();
            break;
         case SDL_KEYDOWN:
                if(event.key.keysym.sym==SDLK_RETURN && event.key.repeat==0 && m_curbtn==Button::EXIT_GAME)
                {
                   game->popState();
                   game->changeState(new MenuState());
                }
                if(event.key.keysym.sym==SDLK_RETURN && event.key.repeat==0 && m_curbtn==Button::RESUME)
                {
                   game->popState();
                }

                if(event.key.keysym.sym==SDLK_UP && event.key.repeat==0 && event.key.repeat==0)
                {
                    nextHoverUp();
                    Mix_PlayChannel(-1,m_menusound,0);
                    if(m_curbtn==Button::RESUME)
                    {
                        m_Resume->loadFileFromText("resume",COLOR_YELLOW);
                        m_ExitFromGame->loadFileFromText("Exit from game",COLOR_WHITE);

                    }
                    else if(m_curbtn==Button::EXIT_GAME)
                    {
                        m_Resume->loadFileFromText("resume",COLOR_WHITE);
                        m_ExitFromGame->loadFileFromText("Exit from game",COLOR_YELLOW);

                    }

                }
                if(event.key.keysym.sym==SDLK_DOWN  && event.key.repeat==0)
                {
                    nextHoverDown();
                    Mix_PlayChannel(-1,m_menusound,0);
                    if(m_curbtn==Button::RESUME)
                    {
                        m_Resume->loadFileFromText("resume",COLOR_YELLOW);
                        m_ExitFromGame->loadFileFromText("Exit from game",COLOR_WHITE);

                    }
                    else if(m_curbtn==Button::EXIT_GAME)
                    {
                        m_Resume->loadFileFromText("resume",COLOR_WHITE);
                        m_ExitFromGame->loadFileFromText("Exit from game",COLOR_YELLOW);

                    }
                }

            break;
         }
     }
}

void PauseState::logic(GameEngineStates* game)
{

}

void PauseState::nextHoverDown()
{
    switch(m_curbtn)
    {
      case Button::RESUME:  m_curbtn=Button::EXIT_GAME;break;
      case Button::EXIT_GAME: m_curbtn=Button::RESUME;break;
    }
}

void PauseState::nextHoverUp()
{
    switch(m_curbtn)
    {
      case Button::RESUME:  m_curbtn=Button::EXIT_GAME;break;
      case Button::EXIT_GAME: m_curbtn=Button::RESUME;break;
    }
}


void PauseState::render(GameEngineStates* game)
{
    if(!isPaused)
    {
        SDL_SetRenderDrawColor(game->getRenderer(),COLOR_GREY.r,COLOR_GREY.g,COLOR_GREY.b,COLOR_GREY.a);
        SDL_RenderFillRect(game->getRenderer(),&m_bg);
        m_Resume->render((SCREEN_WIDTH-m_Resume->getWidth())/2,(SCREEN_HEIGHT-m_Resume->getHeight())/2-20);
        m_ExitFromGame->render((SCREEN_WIDTH-m_ExitFromGame->getWidth())/2,(SCREEN_HEIGHT-m_ExitFromGame->getHeight())/2+20);

    }
}

void PauseState::clean()
{
    std::cout<<"pauseState is finished\n";
    m_Resume->free();
    m_ExitFromGame->free();

    Mix_CloseAudio();
    Mix_FreeChunk(m_menusound);
}

PauseState::~PauseState()
{

}
