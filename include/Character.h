// Character.h

#ifndef CHARACTER_H
#define CHARACTER_H


#include "SDL/SDL.h"
#include "SDLGraphics.h"
#include "SDL/SDL_ttf.h"
#include <iostream>
#include <cstring>
#include <sstream>
class Character
{
// Methods
public:

   // This class holds a pointer to the graphics object but will not destroy it.
    Character(SDLGraphics* ,SDL_Surface* );
    ~Character();
    void setClips();
    void moveRight();
    int moveUp();
    int moveLJ();
SDL_Rect getclip();
    void show();
    void anim();
// Data
private:

    int frame;
    int status;
    int velocity;
    const int STATUS_RIGHT =1;
    const int STATUS_UP =0;
    const int STATUS_LJ=2;

    SDLGraphics* m_graphics;
    SDL_Surface* m_bitmap ;

    SDL_Surface* screen;
    SDL_Rect clipsUp[7];
    SDL_Rect clipsRight[7];
    SDL_Rect clipsLJ[10];
    int STICK_WIDTH_JUMP = 77;
    int STICK_HEIGHT_JUMP = 303;
    int STICK_WIDTH_RUN = 134;
    int STICK_HEIGHT_RUN = 99;

    int vel=0;
//The color of the font
    SDL_Color textColor = { 0, 0, 0 };

};

#endif
