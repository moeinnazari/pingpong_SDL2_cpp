#ifndef __GlobalVar__
#define __GlobalVar__

#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <memory>
#include "SDL2/include/SDL2/SDL.h"
#include "SDL2/include/SDL2/SDL_ttf.h"
#include "SDL2/include/SDL2/SDL_mixer.h"

const int SCREEN_WIDTH=640;
const int SCREEN_HEIGHT=480;

const int FPS=60;
const int SECOND_PER_FRAME=1000/FPS;

const int FONT_SIZE_SMALL=20;
const int FONT_SIZE_MEDIUM=30;
const int FONT_SIZE_LARGE=40;



const SDL_Color COLOR_BLACK={100,100,100,255};
const SDL_Color COLOR_WHITE={243,243,243,255};
const SDL_Color COLOR_GREY={170,170,170,255};
const SDL_Color COLOR_YELLOW={255,255,36,255};

const int PLAYER_VEL=10;
const int Player_WIDTH=10;
const int Player_HEIGHT=70;

const int BALL_VEL=4;
const int BALL_WIDTH=10;
const int BALL_HEIGHT=10;

#endif // __GlobalVar__

