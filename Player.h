#ifndef __Player__
#define __Player__
#include "Texture.h"
#include "GlobalVar.h"


class Player
{
public:
    Player();
    ~Player();

    void init(int x=0,int y=0);
    void doDown();
    void stopDown();
    void stopUp();
    void doUp();
    void logic();
    void render();
    void move();
    void clean();



    SDL_Rect* getRect() {return &m_player;}
private:

    int m_posY;
    int m_velY;

    SDL_Rect m_player;

};
#endif // __Player__
