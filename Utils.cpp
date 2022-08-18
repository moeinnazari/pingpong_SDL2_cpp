#include "Utils.h"

 bool Utils::checkCollision(SDL_Rect* A,SDL_Rect* B)
 {
     int topA,bottomA,leftA,rightA;
    int topB,bottomB,leftB,rightB;

    topA=A->y;
    bottomA=A->y+A->h;
    leftA=A->x;
    rightA=A->x+A->w;

    topB=B->y;
    bottomB=B->y+B->h;
    leftB=B->x;
    rightB=B->x+B->w;

    if( leftA > rightB ){return false;}
    if( rightA < leftB ) {return false;}
    if( topA > bottomB ) {return false;}
    if( bottomA < topB ) {return false;}

    return true;
 }
