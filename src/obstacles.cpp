#include "obstacles.h"

obstacles::obstacles(SDLGraphics* graphics,SDL_Surface *s):m_graphics(graphics),screen(s)
    {
        //The offsets of the background
        srand(time(NULL));
      obst= m_graphics -> load_image("obst.png");
       // obst1= m_graphics -> load_image("obst1.png");
       box.x=  rand() % 100+550;
        box.y= 170+ rand()%100;
//        box1.x=  rand() % 100+650;
      //  box1.y= 170+ rand()%100;

        box.w=35;
        box.h=35;
      //  box1.w=35;
       // box1.h=35;

    }
SDL_Rect obstacles::obstClip()
{
    return box;
}
/*SDL_Rect obstacles::obst1Clip()
{
        return box1;
}*/

obstacles::~obstacles()
    {
        m_graphics->closeImage(screen);
        m_graphics->closeImage(obst1);
        m_graphics->closeImage(obst);
    }
void obstacles::scroll_obst()
    {
           //Scroll obstacle

        box.x-= 10;
//         box1.x-=10;

            //If the obstacle has gone too far
        if(  box.x <= -obst->w )
            {            //Reset the offset
                srand(time(NULL));

   box.x= rand() % 200+740;
                box.y = 210+ rand()%90;
            }
        /*if(  box1.x <= -obst1->w)
            {
                srand(time(NULL));

               box1.x = rand() % 200+840;
                 box1.y= 210+ rand()%90;
            }*/
    }

void obstacles::show_obst()
    {
        //Show the background
       m_graphics-> apply_surface(  box.x + obst->w,  box.y,obst, screen,NULL);
      //  m_graphics-> apply_surface(bgX,bgY,background,screen);
//       m_graphics-> apply_surface(  box1.x+ obst1->w, box1.y,obst, screen,NULL);
    }
