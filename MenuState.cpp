#include "MenuState.h"
#include "PauseState.h"
#include "PlayState.h"

MenuState::MenuState()
{
m_Start=std::unique_ptr<Texture>(new Texture());
m_Credit=std::unique_ptr<Texture>(new Texture());
m_Exit=std::unique_ptr<Texture>(new Texture());

isPaused=false;
m_curbtn=Button::START;
m_bg={0,0,SCREEN_WIDTH,SCREEN_HEIGHT};
}

void MenuState::init()
{
    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,1024);

 m_Start->loadFileFromText("start",COLOR_YELLOW);
 m_Credit->loadFileFromText("credit");
 m_Exit->loadFileFromText("exit");

 m_menusound=Mix_LoadWAV("assets/menu.wav");
}

void MenuState::handleEvent(GameEngineStates* game)
{
     while(SDL_PollEvent(&event))
     {
         switch(event.type)
         {
         case SDL_QUIT:
                game->quit();
            break;
         case SDL_KEYDOWN:
                if(event.key.keysym.sym==SDLK_RETURN && event.key.repeat==0 && m_curbtn==Button::EXIT)
                {

                   game->quit();
                }
                if(event.key.keysym.sym==SDLK_RETURN && event.key.repeat==0 && m_curbtn==Button::CREDIT)
                {
                   game->quit();
                }
                if(event.key.keysym.sym==SDLK_RETURN && event.key.repeat==0 && m_curbtn==Button::START)
                {
                   game->changeState(new PlayState());
                }

                if((event.key.keysym.sym==SDLK_UP || event.key.keysym.sym==SDLK_w) && event.key.repeat==0)
                {
                    nextHoverUp();
                     Mix_PlayChannel(-1,m_menusound,0);
                    if(m_curbtn==Button::START)
                    {
                        m_Start->loadFileFromText("start",COLOR_YELLOW);
                        m_Credit->loadFileFromText("credit",COLOR_WHITE);
                        m_Exit->loadFileFromText("Exit",COLOR_WHITE);


                    }
                    else if(m_curbtn==Button::CREDIT)
                    {
                        m_Start->loadFileFromText("start",COLOR_WHITE);
                        m_Credit->loadFileFromText("credit",COLOR_YELLOW);
                        m_Exit->loadFileFromText("Exit",COLOR_WHITE);

                    }
                    else if(m_curbtn==Button::EXIT)
                    {
                        m_Start->loadFileFromText("start",COLOR_WHITE);
                        m_Credit->loadFileFromText("credit",COLOR_WHITE);
                        m_Exit->loadFileFromText("Exit",COLOR_YELLOW);

                    }
                }
                if((event.key.keysym.sym==SDLK_DOWN || event.key.keysym.sym==SDLK_s) && event.key.repeat==0)
                {
                    nextHoverDown();
                         Mix_PlayChannel(-1,m_menusound,0);
                    if(m_curbtn==Button::START)
                    {

                        m_Start->loadFileFromText("start",COLOR_YELLOW);
                        m_Credit->loadFileFromText("credit",COLOR_WHITE);
                        m_Exit->loadFileFromText("Exit",COLOR_WHITE);

                    }
                    else if(m_curbtn==Button::CREDIT)
                    {

                        m_Start->loadFileFromText("start",COLOR_WHITE);
                        m_Credit->loadFileFromText("credit",COLOR_YELLOW);
                        m_Exit->loadFileFromText("Exit",COLOR_WHITE);

                    }
                    else if(m_curbtn==Button::EXIT)
                    {

                        m_Start->loadFileFromText("start",COLOR_WHITE);
                        m_Credit->loadFileFromText("credit",COLOR_WHITE);
                        m_Exit->loadFileFromText("Exit",COLOR_YELLOW);

                    }
                }

            break;
         }
     }
}
void MenuState::logic(GameEngineStates* game)
{

}

void MenuState::render(GameEngineStates* game)
{
    if(!isPaused)
    {
     SDL_SetRenderDrawColor(game->getRenderer(),COLOR_BLACK.r,COLOR_BLACK.g,COLOR_BLACK.b,COLOR_BLACK.a);
     SDL_RenderFillRect(game->getRenderer(),&m_bg);
     m_Start->render((SCREEN_WIDTH-m_Start->getWidth())/2,(SCREEN_HEIGHT-m_Start->getHeight())/2-40);
     m_Credit->render((SCREEN_WIDTH-m_Credit->getWidth())/2,(SCREEN_HEIGHT-m_Credit->getHeight())/2);
     m_Exit->render((SCREEN_WIDTH-m_Exit->getWidth())/2,(SCREEN_HEIGHT-m_Exit->getHeight())/2+40);
    }

}


void MenuState::clean()
{
std::cout<<"MenuState is finished\n";
m_Start->free();
m_Credit->free();
m_Exit->free();
Mix_HaltChannel(-1);

Mix_FreeChunk(m_menusound);
m_menusound=0;
Mix_CloseAudio();
m_menusound=0;

}

void MenuState::nextHoverDown()
{
  switch(m_curbtn)
  {
      case Button::START:m_curbtn=Button::CREDIT;break;
      case Button::CREDIT:m_curbtn=Button::EXIT;break;
      case Button::EXIT:m_curbtn=Button::START;break;
  }
}
void MenuState::nextHoverUp()
{
  switch(m_curbtn)
  {
      case Button::START:m_curbtn=Button::EXIT;break;
      case Button::CREDIT:m_curbtn=Button::START;break;
      case Button::EXIT:m_curbtn=Button::CREDIT;break;
  }
}
MenuState::~MenuState()
{

}
