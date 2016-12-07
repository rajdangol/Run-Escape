#ifndef MENU_H
#define MENU_H

#include "SDL/SDL.h"
#include "SDLGraphics.h"
#include "bckgr.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "gameplay.h"
#include "Timer.h"
#include <iostream>
#include <cstring>
#include <sstream>

class menu
{
    public:
        menu(SDLGraphics*  ,SDL_Surface * ,bckgr* ,gameplay*,Timer* );
        int start();
        ~menu();
    private:
        SDLGraphics* m_graphics;
        SDL_Surface* screen;
        SDL_Surface* m_bitmap ;
        SDL_Surface* ttl;
        SDL_Surface* men;
        bckgr* bck;
        gameplay* ply;
        Timer* t;
        bool quit;
        SDL_Event event;
        TTF_Font *font = NULL;
        TTF_Font *large = NULL;
        TTF_Font *small = NULL;
        Mix_Music *music = NULL;

//The color of the font
    SDL_Color textColor = { 0, 0, 0 };
};

#endif // MENU_H
