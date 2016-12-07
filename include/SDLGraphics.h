// SDLGraphics.h

#ifndef SDLGRAPHICS_H
#define SDLGRAPHICS_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include<string>


class SDLGraphics
{
// Methods
public:
    // This creates a window and initializes the graphics object.
    SDLGraphics(SDL_Surface*);
    ~SDLGraphics();
    // Each call to loadBitmap() must have a corresponding call to closeBitmap().
    SDL_Surface* load_image( std::string filename);
    void closeImage(SDL_Surface* );
    void closeFont(TTF_Font *);
    // These calls must surround all drawing routines.
    void flipScene();

    void closeMusic(Mix_Music*);
    void closeTone (Mix_Chunk*);
    void closeMixer();
    void apply_surface( int x, int y, SDL_Surface* , SDL_Surface*  , SDL_Rect* );

 // Data
private:
    SDL_Surface* screen;

};

#endif
