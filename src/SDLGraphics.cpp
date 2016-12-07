// SDLGraphics.cpp

#include "SDLGraphics.h"


SDLGraphics::SDLGraphics(SDL_Surface *s):screen(s){}

SDLGraphics::~SDLGraphics()
{
    TTF_Quit();
    SDL_Quit();
}

SDL_Surface* SDLGraphics::load_image(std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );

        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }

    //Return the optimized surface
    return optimizedImage;
}

void SDLGraphics::closeImage(SDL_Surface* image)
{
   SDL_FreeSurface(image);

}
void SDLGraphics::closeFont(TTF_Font * font)
{
   TTF_CloseFont(font);

}


void SDLGraphics::flipScene()
{
   SDL_Flip(screen);
}


void SDLGraphics::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );

}

void SDLGraphics::closeMusic(Mix_Music * mus)
{
    Mix_FreeMusic(mus);
}

void SDLGraphics::closeTone(Mix_Chunk* mus)
{
    Mix_FreeChunk(mus);
}
void SDLGraphics::closeMixer()
{
    Mix_CloseAudio();
}
