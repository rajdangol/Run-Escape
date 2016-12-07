#ifndef GAMEPLAY_H
#define GAMEPLAY_H
enum state {right, up, lup};
#include<ios>
#include "SDLGraphics.h"
#include "bckgr.h"
#include "Timer.h"
#include "Character.h"
#include "obstacles.h"
#include<fstream>


class gameplay
{
    public:
        gameplay(SDLGraphics*,Character*,obstacles*,Timer*,bckgr*,SDL_Surface*);
        void gameStart();
        void move();
        void help_menu();
        void credits_menu();
        bool check_collision(SDL_Rect , SDL_Rect);
        int gameover();
        ~gameplay();

    private:

        int velocity=0;
        Uint32  start=32;
        int scr,scrd;
        bool g_gameIsRunning, hlp_menu,crdt_menu,game_over;

        SDL_Event event;

        SDLGraphics* m_graphics;
        Character* m_char;
        obstacles* m_obst;
        obstacles* m_obst2;
        TTF_Font *font = NULL;
        TTF_Font *scorefont = NULL;
        Timer* m_fps;
        bckgr* m_bck;

        state st=right;

        SDL_Color textColor = { 0, 0, 0 };

        SDL_Surface* seconds ;
        SDL_Surface* scrs ;
        SDL_Surface* tut;
        SDL_Surface* cdt;
        SDL_Surface* over;
        SDL_Surface* scoreshow;
        SDL_Surface* highscor;
            SDL_Surface* screen;
        Mix_Music* tone;
        Mix_Music* tutr;
        Mix_Music*  crdt;

};

#endif // GAMEPLAY_H
