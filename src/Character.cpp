// Character.cpp

#include "Character.h"

Character::Character(SDLGraphics* graphics,SDL_Surface* s):m_graphics(graphics),screen(s)
{
    status=STATUS_RIGHT;
    frame =0;
    m_bitmap= m_graphics -> load_image("Sprites.png");
    velocity=0;

}

Character::~Character()
{
    m_graphics->closeImage(m_bitmap);

    m_graphics->closeImage(screen);


}


void Character::setClips()
{
//Clip the sprites
//run sprite
    clipsRight[ 0 ].x = 0;
    clipsRight[ 0 ].y = STICK_HEIGHT_JUMP;
    clipsRight[ 0 ].w = STICK_WIDTH_RUN;
    clipsRight[ 0 ].h = STICK_HEIGHT_RUN;

    clipsRight[ 1 ].x = STICK_WIDTH_RUN;
    clipsRight[ 1 ].y = STICK_HEIGHT_JUMP;
    clipsRight[ 1 ].w = STICK_WIDTH_RUN;
    clipsRight[ 1 ].h = STICK_HEIGHT_RUN;

    clipsRight[ 2 ].x = STICK_WIDTH_RUN * 2;
    clipsRight[ 2 ].y = STICK_HEIGHT_JUMP;
    clipsRight[ 2 ].w = STICK_WIDTH_RUN;
    clipsRight[ 2 ].h = STICK_HEIGHT_RUN;

    clipsRight[ 3 ].x = STICK_WIDTH_RUN * 3;
    clipsRight[ 3 ].y = STICK_HEIGHT_JUMP;
    clipsRight[ 3 ].w = STICK_WIDTH_RUN;
    clipsRight[ 3 ].h = STICK_HEIGHT_RUN;

    clipsRight[ 4 ].x = 0;
    clipsRight[ 4 ].y = STICK_HEIGHT_JUMP;
    clipsRight[ 4 ].w = STICK_WIDTH_RUN;
    clipsRight[ 4 ].h = STICK_HEIGHT_RUN;

    clipsRight[ 5 ].x = STICK_WIDTH_RUN;
    clipsRight[ 5 ].y = STICK_HEIGHT_JUMP;
    clipsRight[ 5 ].w = STICK_WIDTH_RUN;
    clipsRight[ 5 ].h = STICK_HEIGHT_RUN;

    clipsRight[ 6 ].x = STICK_WIDTH_RUN * 2;
    clipsRight[ 6 ].y = STICK_HEIGHT_JUMP;
    clipsRight[ 6 ].w = STICK_WIDTH_RUN;
    clipsRight[ 6 ].h = STICK_HEIGHT_RUN;
    //jump sprite
    clipsUp[ 0 ].x = 0;
    clipsUp[ 0 ].y = 0;
    clipsUp[ 0 ].w = STICK_WIDTH_JUMP;
    clipsUp[ 0 ].h = STICK_HEIGHT_JUMP;

    clipsUp[ 1 ].x = STICK_WIDTH_JUMP;
    clipsUp[ 1 ].y = 0;
    clipsUp[ 1 ].w = STICK_WIDTH_JUMP;
    clipsUp[ 1 ].h = STICK_HEIGHT_JUMP;

    clipsUp[ 2 ].x = STICK_WIDTH_JUMP*2;
    clipsUp[ 2 ].y = 0;
    clipsUp[ 2 ].w = STICK_WIDTH_JUMP;
    clipsUp[ 2 ].h = STICK_HEIGHT_JUMP;

    clipsUp[ 3 ].x = STICK_WIDTH_JUMP*3;
    clipsUp[ 3 ].y = 0;
    clipsUp[ 3 ].w = STICK_WIDTH_JUMP;
    clipsUp[ 3 ].h = STICK_HEIGHT_JUMP;

    clipsUp[ 4 ].x = STICK_WIDTH_JUMP*4;
    clipsUp[ 4 ].y = 0;
    clipsUp[ 4 ].w = STICK_WIDTH_JUMP;
    clipsUp[ 4 ].h = STICK_HEIGHT_JUMP;

    clipsUp[ 5 ].x = STICK_WIDTH_JUMP*5;
    clipsUp[ 5 ].y = 0;
    clipsUp[ 5 ].w = STICK_WIDTH_JUMP;
    clipsUp[ 5 ].h = STICK_HEIGHT_JUMP;

    clipsUp[ 6 ].x = STICK_WIDTH_JUMP*6;
    clipsUp[ 6 ].y = 0;
    clipsUp[ 6 ].w = STICK_WIDTH_JUMP;
    clipsUp[ 6 ].h = STICK_HEIGHT_JUMP;

    //long jump sprite
    clipsLJ[ 0 ].x = 0;
    clipsLJ[ 0 ].y = 0;
    clipsLJ[ 0 ].w = STICK_WIDTH_JUMP;
    clipsLJ[ 0 ].h = STICK_HEIGHT_JUMP;

    clipsLJ[ 1 ].x = STICK_WIDTH_JUMP;
    clipsLJ[ 1 ].y = 0;
    clipsLJ[ 1 ].w = STICK_WIDTH_JUMP;
    clipsLJ[ 1 ].h = STICK_HEIGHT_JUMP;

    clipsLJ[ 2 ].x = STICK_WIDTH_JUMP*2;
    clipsLJ[ 2 ].y = 0;
    clipsLJ[ 2 ].w = STICK_WIDTH_JUMP;
    clipsLJ[ 2 ].h = STICK_HEIGHT_JUMP;

    clipsLJ[ 3 ].x = STICK_WIDTH_JUMP*3;
    clipsLJ[ 3 ].y = 0;
    clipsLJ[ 3 ].w = STICK_WIDTH_JUMP;
    clipsLJ[ 3 ].h = STICK_HEIGHT_JUMP;

    clipsLJ[ 4 ].x = STICK_WIDTH_JUMP*3;
    clipsLJ[ 4 ].y = 0;
    clipsLJ[ 4 ].w = STICK_WIDTH_JUMP;
    clipsLJ[ 4 ].h = STICK_HEIGHT_JUMP;

    clipsLJ[ 5 ].x = STICK_WIDTH_JUMP*3;
    clipsLJ[ 5 ].y = 0;
    clipsLJ[ 5 ].w = STICK_WIDTH_JUMP;
    clipsLJ[ 5 ].h = STICK_HEIGHT_JUMP;

    clipsLJ[ 6 ].x = STICK_WIDTH_JUMP*3;
    clipsLJ[ 6 ].y = 0;
    clipsLJ[ 6 ].w = STICK_WIDTH_JUMP;
    clipsLJ[ 6 ].h = STICK_HEIGHT_JUMP;

    clipsLJ[ 7 ].x = STICK_WIDTH_JUMP*4;
    clipsLJ[ 7 ].y = 0;
    clipsLJ[ 7 ].w = STICK_WIDTH_JUMP;
    clipsLJ[ 7 ].h = STICK_HEIGHT_JUMP;

    clipsLJ[ 8 ].x = STICK_WIDTH_JUMP*5;
    clipsLJ[ 8 ].y = 0;
    clipsLJ[ 8 ].w = STICK_WIDTH_JUMP;
    clipsLJ[ 8 ].h = STICK_HEIGHT_JUMP;

    clipsLJ[ 9 ].x = STICK_WIDTH_JUMP*6;
    clipsLJ[ 9 ].y = 0;
    clipsLJ[ 9 ].w = STICK_WIDTH_JUMP;
    clipsLJ[ 9 ].h = STICK_HEIGHT_JUMP;

}

SDL_Rect Character::getclip()
{
    SDL_Rect r;
    if(status==STATUS_RIGHT)
    {
    r.x=6;
    r.w=55;
    r.h=99;
    r.y= 330 - STICK_HEIGHT_RUN;
    return r;
    }
     if(status==STATUS_UP)
    {
       if(frame<4)
      {r.x = 6;
    r.y = 232- frame*75;
    r.w = 70;
    r.h = 306-213;
    return r;
      }
      if(frame>=4)
      {
          r.x = 6;
    r.y = (frame+2-5)*60;
    r.w = 70;
    r.h = 306-213;
    return r;
      }
    }
     if(status==STATUS_LJ)
    {
       if(frame<3)
      {r.x = 6;
    r.y = 232- frame*75;
    r.w = 70;
    r.h = 306-213;
    return r;
      }
      if(frame>6)
      {
          r.x = 6;
    r.y = (frame-6)*60;
    r.w = 70;
    r.h = 306-213;
    return r;
      }
      if(frame==3||frame==4||frame==5||frame==6)
      {
        r.x = 6;
    r.y = 232- 3*75;
    r.w = 80;
    r.h = 306-213;
    return r;
      }
    }
    return r;
    //if(status==STATUS_RIGHT)
      //  return clipsRight[frame];
    // if(status==STATUS_LJ)
   //     return clipsLJ[frame];
  //  else if(status==STATUS_UP)
      //  return clipsUp[frame];
    //    else
      //      return clipsRight[frame];
}

void Character::moveRight()
{
 //If char is moving right
vel++;
 if(vel%4==0)
{

    if( frame<7)
    {
        status = STATUS_RIGHT;
        //Move to the next frame in the animation
       frame++;

    }

   else
   {
   //     //Restart the animation
       frame = 0;
    }
    //Loop the animation
   if( frame >= 7 )
    {
      frame = 0;
    }
}
}

int Character::moveUp()
{
 //If char is jumping
 vel++;
 if(vel%4==0)
{

       if( frame<7)
    {

        status= STATUS_UP;
        //Move to the next frame in the animation
        frame++;
    }


    else
    {
        //Restart the animation
        frame = 0;


    }
    //Loop the animation
    if( frame >= 7 )
    {
        frame=0;

    }
}
return frame;
}

int Character::moveLJ()
{
    vel++;
 if(vel%4==0)
 {//If char is long jumping

   if( frame<10)
    {

        status= STATUS_LJ;
        //Move to the next frame in the animation
        frame++;
    }


    else
    {
        //Restart the animation
        frame = 0;


    }
    //Loop the animation
    if( frame >9 )
    {

        frame = 0;

    }
}
return frame;
}

void Character::show()
{

      //Show the stickman

    if( status == STATUS_RIGHT )
        {
            m_graphics->apply_surface(  0, 330 - STICK_HEIGHT_RUN, m_bitmap, screen, &clipsRight[ frame ] );

        }
    else if( status == STATUS_UP )
        {
            m_graphics->apply_surface(  0, 115 - STICK_HEIGHT_RUN, m_bitmap, screen , &clipsUp[ frame ] );

        }
     else if( status == STATUS_LJ )
        {
            m_graphics->apply_surface(  0, 115 - STICK_HEIGHT_RUN, m_bitmap, screen , &clipsLJ[ frame ] );

        }


}


