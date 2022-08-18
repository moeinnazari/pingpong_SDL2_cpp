#ifndef __Texture__
#define __Texture__
#include "GlobalVar.h"
#include "GameEngineStates.h"


class Texture{
public:
    Texture();
    ~Texture();

    bool loadFileFromText(std::string text,SDL_Color color=COLOR_WHITE,int font=FONT_SIZE_MEDIUM);
    void render(int x,int y,SDL_Rect* clip=NULL,double angel=0,SDL_Point* center=0,SDL_RendererFlip flip=SDL_FLIP_NONE);
    void free();

    int getWidth() const {return m_Width;}
    int getHeight() const {return m_Height;}
private:
    int m_Width;
    int m_Height;

    SDL_Texture* m_Texture;

};
#endif // __Texture__
