#include <genesis.h>

#include "data/components.h"


void system_movement ( void *array[], int length )
{
    for ( int i = 0; i < length; )
    {
        ComponentPosition *cp = array[i++];
        ComponentVelocity *cv = array[i++];

        ComponentVelocity_Inner *x = &cv->x;
        ComponentVelocity_Inner *y = &cv->y;
        
        fix32 x_vel          = x->vel;
        char  x_dir          = x->dir;
        fix32 x_acceleration = x->acceleration;
        fix32 x_deceleration = x->deceleration;
        fix32 x_maximum      = x->maximum;

        fix32 y_vel          = y->vel;
        char  y_dir          = y->dir;
        fix32 y_acceleration = y->acceleration;
        fix32 y_deceleration = y->deceleration;
        fix32 y_maximum      = y->maximum;

        if ( x_dir > 0 )
        {
            x_vel = fix32Add ( x_vel, x_acceleration );

            if ( x_vel > x_maximum )
            {
                x_vel = x_maximum;
            }
        }
        else if ( x_dir < 0 )
        {
            x_vel = fix32Add ( x_vel, fix32Neg(x_acceleration) );

            if ( x_vel < fix32Neg(x_maximum) )
            {
                x_vel = fix32Neg(x_maximum);
            }
        }
        else if ( x_vel > 0 )
        {
            x_vel = fix32Sub ( x_vel, x_deceleration );

            if ( x_vel < 0 )
            {
                x_vel = 0;
            }
        }
        else if ( x_vel < 0 )
        {
            x_vel = fix32Sub ( x_vel, fix32Neg(x_deceleration) );

            if ( x_vel < fix32Neg(x_maximum) )
            {
                x_vel = fix32Neg(x_maximum);
            }
        }


        if ( y_dir > 0 )
        {
            y_vel = fix32Add ( y_vel, y_acceleration );

            if ( y_vel > y_maximum )
            {
                y_vel = y_maximum;
            }
        }
        else if ( y_dir < 0 )
        {
            y_vel = fix32Add ( y_vel, fix32Neg(y_acceleration) );

            if ( y_vel < fix32Neg(y_maximum) )
            {
                y_vel = fix32Neg(y_maximum);
            }
        }
        else if ( y_vel > 0 )
        {
            y_vel = fix32Sub ( y_vel, y_deceleration );

            if ( y_vel < 0 )
            {
                y_vel = 0;
            }
        }
        else if ( y_vel < 0 )
        {
            y_vel = fix32Sub ( y_vel, fix32Neg(y_deceleration) );

            if ( y_vel < fix32Neg(y_maximum) )
            {
                y_vel = fix32Neg(y_maximum);
            }
        }


        x->vel = x_vel;
        y->vel = y_vel;
        
        cp->x = fix32Add ( cp->x, x_vel );
        cp->y = fix32Add ( cp->y, y_vel );
    }
}