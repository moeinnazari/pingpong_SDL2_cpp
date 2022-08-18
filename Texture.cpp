#include "Texture.h"

Texture::Texture()
{
    m_Width=0;
    m_Height=0;

    m_Texture=NULL;




}



Texture::~Texture()
{
    free();
}




bool Texture::loadFileFromText(std::string text,SDL_Color color,int font)
{
    free();
    bool success=true;
    TTF_SetFontSize(GameEngineStates::getFont(),font);
    SDL_Surface* p_TempSurface=TTF_RenderText_Solid(GameEngineStates::getFont(),text.c_str(),color);
    if(p_TempSurface==NULL)
    {
        std::cout<<"load text failed\n";
        success=false;
    }
    else
    {
        m_Texture=SDL_CreateTextureFromSurface(GameEngineStates::getRenderer(),p_TempSurface);
        if(m_Texture==NULL)
        {
            std::cout<<"creation texture failed\n";
            success=false;
        }
        else
        {
            m_Width=p_TempSurface->w;
            m_Height=p_TempSurface->h;
        }
    }
    SDL_FreeSurface(p_TempSurface);
    return success;
}


void Texture::render(int x,int y,SDL_Rect* clip,double angel,SDL_Point* center,SDL_RendererFlip flip)
{
    SDL_Rect destRect={x,y,m_Width,m_Height};
    if(clip!=NULL)
    {
        destRect.w=clip->w;
        destRect.h=clip->h;
    }
    SDL_RenderCopyEx(GameEngineStates::getRenderer(),m_Texture,clip,&destRect,angel,center,flip);
}

void Texture::free()
{
    if(m_Texture!=NULL)
    {
        SDL_DestroyTexture(m_Texture);
        m_Width=0;
        m_Height=0;
    }
}
