#ifndef __Ball__
#define __Ball__
#include "GlobalVar.h"


class Ball
{
  public:
      Ball();
      ~Ball();

      void init();
      void clean();

      void move();
      void changeDir();
      bool IsOut();
      void logic();
      void render();
      bool hitWall();
      SDL_Rect* getRect() {return &m_box;}

      int getPosX() {return m_box.x;}
      int getPosY() {return m_box.y;}

  private:

    int m_velX,m_velY;
    int randDir;
    SDL_Rect m_box;


};
#endif // __Ball__
