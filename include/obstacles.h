#ifndef OBSTACLES_H
#define OBSTACLES_H

#include "SDL/SDL.h"
#include "SDLGraphics.h"
#include "time.h"
class obstacles
{
private:
    SDLGraphics* m_graphics;
    SDL_Surface* screen;
   SDL_Surface* obst;
  SDL_Surface* obst1;
   SDL_Rect box;
   //SDL_Rect box1;

public:
    obstacles(SDLGraphics* , SDL_Surface*);
    void scroll_obst();
    void show_obst();
    ~obstacles();
    SDL_Rect obstClip();
  //  SDL_Rect obst1Clip();
};
#endif // OBSTACLES_H
