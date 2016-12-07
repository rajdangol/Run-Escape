#include "bckgr.h"

bckgr::bckgr(SDLGraphics* graphics,SDL_Surface *s):m_graphics(graphics),screen(s)
    {
    //The offsets of the background

    bgX = 0, bgY = 0;
    bckgrw= m_graphics -> load_image("Background.bmp");
    }

bckgr::~bckgr()
    {
        m_graphics->closeImage(screen);
        m_graphics->closeImage(bckgrw);

    }
void bckgr::scroll_backgr()
    {
        //Scroll background
        bgX -= 2;
        //If the background has gone too far
        if( bgX <= -bckgrw->w )
        {
            //Reset the offset
            bgX = 0;
        }
    }

void bckgr::show_backgr()
    {
       //Show the background
        m_graphics->apply_surface( bgX, bgY, bckgrw, screen,NULL );
        m_graphics-> apply_surface( bgX + bckgrw->w, bgY,bckgrw, screen,NULL);

    }

