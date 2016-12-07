#include "gameplay.h"

gameplay::gameplay(SDLGraphics* graphics,Character* chr,obstacles* obst,Timer* fps,bckgr* bck,SDL_Surface* scr):m_graphics(graphics),m_char(chr),m_obst(obst),m_fps(fps),m_bck(bck),screen(scr)
{
    hlp_menu=true;
    g_gameIsRunning=true;
     crdt_menu=true;
     game_over=true;
    font = TTF_OpenFont( "comicbd.ttf", 18 );
    scorefont=TTF_OpenFont("AROLY.ttf",30);
    tone=Mix_LoadMUS("run.mp3");
    tutr=Mix_LoadMUS("tut.mp3");
    crdt=Mix_LoadMUS("crdt.mp3");
    tut=m_graphics->load_image("tutorial.png");
    cdt=m_graphics->load_image("credis.png");
    over=m_graphics->load_image("gameover.png");
}


void gameplay::move()
{
    int frame;

    if(st==right)
            {m_char->moveRight();Mix_PlayMusic(tone, -1 );}

    else if(st==up)
        {
            frame=m_char->moveUp();

                if(frame>5) st=right;
        }
    else if(st==lup)
        {
            frame=m_char->moveLJ();
                if(frame>8) st=right;
        }

}

void gameplay::gameStart()
{
    g_gameIsRunning=true;
    scr=0;
    start=SDL_GetTicks();

     while (g_gameIsRunning)
    {
       //Set fps
        m_fps->get_ticks();
        //Ste clips
        m_char ->setClips();

      //Scroll units
        m_bck->scroll_backgr();
        m_obst->scroll_obst();
       // m_obst2->scroll_obst();
        //Show scrolled units
        m_bck->show_backgr();
        m_obst->show_obst();
       // m_obst2->show_obst();
 //The timer's time as a string

            std::stringstream time;
            std::stringstream score;
            //Convert the timer's time to a string
            time << "Time: " << (SDL_GetTicks()-start)/1000;

            velocity++;
            if(velocity%4==0)
                scr++;
            scrd=scr;
            score<<"Score: " << scr;
            //Render the time surface
            seconds = TTF_RenderText_Solid( font, time.str().c_str(), textColor );
            scrs= TTF_RenderText_Solid( font, score.str().c_str(), textColor );
            //Apply the time surface
            m_graphics->apply_surface( 745, 10, seconds, screen,0 );
            m_graphics->apply_surface(  745, 40, scrs, screen ,0);



        //If a key was pressed
    while( SDL_PollEvent( &event ) )
    {
    if( event.type == SDL_KEYDOWN )
        {

            switch( event.key.keysym.sym )
                {

                    case SDLK_RIGHT  :  st= right;
                                        break;
                    case SDLK_UP     :  st = up;
                                        break;
                    case SDLK_SPACE  :  st= lup;
                                        break;
                    case SDLK_ESCAPE :  g_gameIsRunning=false;
                                        break;

                    default          :  break;
                }

        }

    }
        move();
        //Show character
        m_char->show();
      //  if(!check_collision())

         if(!check_collision(m_char->getclip(),m_obst->obstClip()) )
           {
               SDL_Delay(2000);
               g_gameIsRunning=false;
                m_graphics->closeMusic(tone);
             gameover();
           }


        //Flip or update screen
        m_graphics->flipScene();

    }
}
gameplay::~gameplay()
{
    m_graphics->closeImage(scrs);
    m_graphics->closeImage(cdt);
    m_graphics->closeImage(tut);
    m_graphics->closeImage(screen);
    m_graphics->closeImage(seconds);
    m_graphics->closeFont(font);
    m_graphics->closeMusic(tone);
    m_graphics->closeMusic(tutr);
    m_graphics->closeMusic(crdt);


}

void gameplay::help_menu()
{

     hlp_menu=true;
        Mix_PlayMusic(tutr, -1 );
    while(hlp_menu)
    {
        m_fps->get_ticks();
         //Scroll units
        m_bck->scroll_backgr();
        //Show scrolled units
        m_bck->show_backgr();


               //If a key was pressed
        while( SDL_PollEvent( &event ) )
        {
        if( event.type == SDL_KEYDOWN )
            {

                switch( event.key.keysym.sym )
                    {
                    case SDLK_ESCAPE :  hlp_menu=false;
                                        break;

                    default          :  break;
                    }
            }

        }
        m_graphics->apply_surface(120, 0, tut,screen,0);

        m_graphics->flipScene();
    }
}
void gameplay::credits_menu()
{

     crdt_menu=true;
     Mix_PlayMusic( crdt, -1 );

    while(crdt_menu)
    {
        m_fps->get_ticks();
         //Scroll units
        m_bck->scroll_backgr();
        //Show scrolled units
        m_bck->show_backgr();


               //If a key was pressed
        while( SDL_PollEvent( &event ) )
        {
        if( event.type == SDL_KEYDOWN )
            {

                switch( event.key.keysym.sym )
                    {
                    case SDLK_ESCAPE :  crdt_menu=false;
                                        break;

                    default          :  break;
                    }
            }

        }
           m_graphics->apply_surface(120, 0, cdt,screen,0);
        m_graphics->flipScene();
    }
}

int gameplay::gameover()
{

     game_over=true;


     Mix_PlayMusic( crdt, -1 );

    while(game_over)
    {
        m_fps->get_ticks();
         //Scroll units
        m_bck->scroll_backgr();
        //Show scrolled units
        m_bck->show_backgr();


               //If a key was pressed
        while( SDL_PollEvent( &event ) )
        {
        if( event.type == SDL_KEYDOWN )
            {

                switch( event.key.keysym.sym )
                    {
                    case SDLK_ESCAPE :  SDL_Delay(3000);
                                        SDL_Quit();
                                        break;

                    default          :  break;
                    }
            }

        }
            std::ifstream hgh;
            hgh.open("highscore.txt");
            int bestscore;
            hgh>>bestscore;
            if(bestscore<=scrd)
               {
                   std::ofstream hgh;
                   hgh.open("highscore.txt");
                   bestscore=scrd;

                hgh<<bestscore;}

            std::stringstream dfg;
            std::stringstream sc;
            sc<<scrd;
            dfg<<bestscore;

            m_graphics->apply_surface(120, 0, over,screen,0);
            scoreshow= TTF_RenderText_Solid( scorefont, sc.str().c_str(), textColor );
            highscor=TTF_RenderText_Solid( scorefont, dfg.str().c_str(), textColor );
            m_graphics->apply_surface(490, 256, scoreshow,screen,0);
            m_graphics->apply_surface(490,195,highscor,screen,0);

        m_graphics->flipScene();
    }
}

bool gameplay::check_collision(SDL_Rect B, SDL_Rect A)
{
     //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
/*    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;

    //Calculate the sides of rect B
    leftB = B->x;
    rightB = B->x + B->w;
    topB = B->y;
    bottomB = B->y + B->h;

    //If any of the sides from A are outside of B
   if( bottomA >= topB )
    {
        if(rightA>=leftB)
            return false;
        else if(leftA<=rightB)
            return false;
    }
    else if (bottomB<=topA)
    {
        if(rightA>=leftB)
            return false;
        else if(leftA<=rightB)
            return false;
    }
    //If none of the sides from A are outside B
    return true;*/
    //Calculate the sides of rect A
    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;

    //Calculate the sides of rect B
    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return true;
    }

    if( topA >= bottomB )
    {
        return true;
    }

    if( rightA <= leftB )
    {
        return true;
    }

    if( leftA >= rightB )
    {
        return true;
    }

    //If none of the sides from A are outside B
    return false;
}


