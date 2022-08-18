#include "Ball.h"
#include "GameEngineStates.h"

Ball::Ball()
{
    m_box={(SCREEN_WIDTH-BALL_WIDTH)/2,(SCREEN_HEIGHT-BALL_HEIGHT)/2,BALL_WIDTH,BALL_HEIGHT};



}

void Ball::init()
{

    m_velX=0;
    m_velY=0;
    m_box.x=(int)(SCREEN_WIDTH-BALL_WIDTH)/2;
    m_box.y=(int)(SCREEN_HEIGHT-BALL_HEIGHT)/2;
    randDir=rand()%20;
    if(randDir>=0 && randDir<=4) {m_velX-=BALL_VEL; m_velY-=BALL_VEL;}
    else if(randDir>=5 && randDir<=10) {m_velX+=BALL_VEL; m_velY-=BALL_VEL;}
    else if(randDir>=11 && randDir<=15) {m_velX+=BALL_VEL; m_velY+=BALL_VEL;}
    else if(randDir>=16 && randDir<=19) {m_velX-=BALL_VEL; m_velY+=BALL_VEL;}
    else {m_velX-=BALL_VEL; m_velY-=BALL_VEL;}

}

void Ball::move()
{
   m_box.x+=m_velX;


   m_box.y+=m_velY;
   if(m_box.y < 0  )
   {
       m_velY+=BALL_VEL;


   }

   if(m_box.y+m_box.h > SCREEN_HEIGHT)
   {
       m_velY-=BALL_VEL;

   }

}

bool Ball::hitWall()
{
    if(m_box.y < 0 || m_box.y+m_box.h > SCREEN_HEIGHT )
   {
       return true;
   }
  return false;
}

 void Ball::changeDir()
 {
     if(m_box.x > SCREEN_WIDTH/2)
     {
        m_velX-=BALL_VEL;
     }
     else
     {
         m_velX+=BALL_VEL;
     }
 }

bool Ball::IsOut()
{
    if(m_box.x <=-m_box.w || m_box.x >= SCREEN_WIDTH )
    {
        return true;
    }
    return false;
}
void Ball::logic()
{
  move();
}

void Ball::clean()
{
  std::cout<<"Ball is clean\n";

}



void Ball::render()
{
    SDL_SetRenderDrawColor(GameEngineStates::getRenderer(),COLOR_WHITE.r,COLOR_WHITE.g,COLOR_WHITE.b,COLOR_WHITE.a);
    SDL_RenderFillRect(GameEngineStates::getRenderer(),&m_box);
}



Ball::~Ball()
{

}
