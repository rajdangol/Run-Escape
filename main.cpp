
//Includes and header files
#include "SDLGraphics.h"
#include "bckgr.h"
#include "Timer.h"
#include "Character.h"
#include "gameplay.h"
#include "obstacles.h"
#include "menu.h"

//Class pointers

SDLGraphics* g_graphics = NULL;
Timer* g_fps = NULL;
Character* g_char = NULL;
bckgr* g_bck = NULL;
obstacles* g_obst =NULL;
gameplay* g_ply = NULL;
menu* g_menu = NULL;


int main(int argc, char **argv)
{
    //Initialize sdl and other screen components
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    SDL_Surface *screen;
    //Set up the screen
    screen= SDL_SetVideoMode( 880, 500, 32, SDL_SWSURFACE );
    //Set the window caption
    SDL_WM_SetCaption( "Run & Escape", NULL );
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;
    }
    //Dynamic allocation
    g_graphics = new SDLGraphics(screen);
    g_fps = new Timer();
    g_char = new Character( g_graphics,screen);
    g_bck = new bckgr(g_graphics,screen);
    g_obst = new obstacles(g_graphics,screen);
    g_ply = new gameplay(g_graphics,g_char,g_obst,g_fps,g_bck,screen);
    g_menu = new menu(g_graphics,screen,g_bck,g_ply,g_fps);

    g_fps->get_ticks();
    g_menu->start();

    return 0;
    }

