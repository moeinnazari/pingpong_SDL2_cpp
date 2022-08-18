#include "Player.h"

Player::Player()
{
 m_player={(SCREEN_WIDTH-15),(SCREEN_HEIGHT-Player_HEIGHT)/2,Player_WIDTH,Player_HEIGHT};
}

void Player::init(int x,int y)
{

  m_player.x = x==0 ? m_player.x : x;

  m_player.y = y==0 ? m_player.y : y;
}


void Player::doDown()
{
    m_velY+=PLAYER_VEL;
}

void Player::stopDown()
{
    m_velY-=PLAYER_VEL;
}

void Player::stopUp()
{
 m_velY+=PLAYER_VEL;
}

void Player::doUp()
{
    m_velY-=PLAYER_VEL;
}


void Player::logic()
{
   move();
}

void Player::move()
{

    m_player.y+=m_velY;

    if(m_player.y<=-1|| m_player.y+Player_HEIGHT> SCREEN_HEIGHT+5)
    {
     m_player.y-=m_velY;
    }


}




void Player::render()
{
    SDL_SetRenderDrawColor(GameEngineStates::getRenderer(),COLOR_WHITE.r,COLOR_WHITE.g,COLOR_WHITE.b,COLOR_WHITE.a);
    SDL_RenderFillRect(GameEngineStates::getRenderer(),&m_player);
}

void Player::clean()
{

}

Player::~Player()
{

}
