#ifndef BCKGR_H
#define BCKGR_H

#include "SDL/SDL.h"
#include "SDLGraphics.h"
class bckgr
{

private:
    SDLGraphics* m_graphics;
    SDL_Surface* screen;
    SDL_Surface* bckgrw;
    int bgX;
    int bgY;

public:
    bckgr(SDLGraphics* , SDL_Surface*);
    void scroll_backgr();
    void show_backgr();
   // void show_backg();
    ~bckgr();
};


#endif // BCKGR_H
