#include "menu.h"


menu::menu(SDLGraphics* graphics,SDL_Surface* s,bckgr* bkg,gameplay* pl,Timer* tm):m_graphics(graphics),screen(s),bck(bkg),ply(pl),t(tm)
{
   men=m_graphics->load_image("menuSprite.png");
   quit =false;
   font = TTF_OpenFont( "MISPROJECT.ttf", 70 );
   music=Mix_LoadMUS("techno.mp3");


}
menu::~menu()
{
     m_graphics->closeFont(font);
     m_graphics->closeImage(men);
     m_graphics->closeImage(screen);
     m_graphics-> closeMusic( music );
}

int menu::start()
{

      while( quit == false )
            {

            bck->scroll_backgr();
            bck->show_backgr();
            t->get_ticks();

             while( SDL_PollEvent( &event ) )
                    {
                        //If the user has Xed out the window
                        if( event.type == SDL_QUIT )
                            {
                                //Quit the program
                                quit = true;
                            }
                        if(event.type==SDL_KEYDOWN)
                        {
                              switch( event.key.keysym.sym )
                                {
                                    case SDLK_ESCAPE: quit=true; break;
                                    default:  break;
                                }
                        }
                    if(event.type == SDL_MOUSEBUTTONDOWN)
                    {
                            int x = event.motion.x;
                            int y = event.motion.y;

                            if((x>375) && (x<558) && (y>210) && (y<249))
                                {
                                    ply->gameStart();
                                    Mix_PlayMusic( music, -1 );

                                    }
                            else if((x>375) && (x<558) && (y>260) && (y<299))
                                {
                                    ply->help_menu();
                                }
                           else if((x>402) && (x<527) && (y>405) && (y<445))
                                {
                                    ply->credits_menu();
                                }
                    }

                    }
                m_graphics->apply_surface( 338, 135, men, screen,0 );

            std::stringstream title;
            //Convert the timer's time to a string
            title<<"Run and Escape ";
            //Render the time surface
            ttl = TTF_RenderText_Solid( font, title.str().c_str(), textColor );
                       //Apply the time surface
            m_graphics->apply_surface( 320,50, ttl, screen ,0);


                    m_graphics->flipScene();
            }
            return 0;

}
