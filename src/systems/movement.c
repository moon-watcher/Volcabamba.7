#include <genesis.h>

#include "modo/system.h"
#include "inc/components.h"



void system_movement ( void *array[], unsigned length )
{
    for ( unsigned i = 0; i < length; )
    {
        ComponentPosition *cp = array [ i++ ];
        ComponentVelocity *cv = array [ i++ ];

        ComponentVelocity_Inner *x = &cv->x;
        ComponentVelocity_Inner *y = &cv->y;
        
        fix32 vel;
        char  dir;
        fix32 acceleration;
        fix32 deceleration;
        fix32 maximum;

        vel          = x->vel;
        dir          = x->dir;
        acceleration = x->acceleration;
        deceleration = x->deceleration;
        maximum      = x->maximum;


        if ( dir > 0 )
        {
            vel = fix32Add ( vel, acceleration );
            if ( vel > maximum ) vel = maximum;
        }
        else if ( dir < 0 )
        {
            vel = fix32Add ( vel, fix32Neg(acceleration) );
            if ( vel < fix32Neg(maximum) ) vel = fix32Neg(maximum);
        }
        else if ( vel > 0 )
        {
            vel = fix32Sub ( vel, deceleration );
            if ( vel < 0 ) vel = 0;
        }
        else if ( vel < 0 )
        {
            vel = fix32Sub ( vel, fix32Neg(deceleration) );
            if ( vel < fix32Neg(maximum) ) vel = fix32Neg(maximum);
        }

        x->vel = vel;
        cp->x = fix32Add ( cp->x, vel );

        

        vel          = y->vel;
        dir          = y->dir;
        acceleration = y->acceleration;
        deceleration = y->deceleration;
        maximum      = y->maximum;

        if ( dir > 0 )
        {
            vel = fix32Add ( vel, acceleration );
            if ( vel > maximum ) vel = maximum;
        }
        else if ( dir < 0 )
        {
            vel = fix32Add ( vel, fix32Neg(acceleration) );
            if ( vel < fix32Neg(maximum) ) vel = fix32Neg(maximum);
        }
        else if ( vel > 0 )
        {
            vel = fix32Sub ( vel, deceleration );
            if ( vel < 0 ) vel = 0;
        }
        else if ( vel < 0 )
        {
            vel = fix32Sub ( vel, fix32Neg(deceleration) );
            if ( vel < fix32Neg(maximum) ) vel = fix32Neg(maximum);
        }

        y->vel = vel;        
        cp->y = fix32Add ( cp->y, vel );
    }
}


// void system_movement ( void *array[], unsigned length )
// {
//     for ( unsigned i = 0; i < length; )
//     {
//         ComponentPosition *cp = array[i++];
//         ComponentVelocity *cv = array[i++];

//         ComponentVelocity_Inner *x = &cv->x;
//         ComponentVelocity_Inner *y = &cv->y;
        
//         fix32 x_vel          = x->vel;
//         char  x_dir          = x->dir;
//         fix32 x_acceleration = x->acceleration;
//         fix32 x_deceleration = x->deceleration;
//         fix32 x_maximum      = x->maximum;

//         fix32 y_vel          = y->vel;
//         char  y_dir          = y->dir;
//         fix32 y_acceleration = y->acceleration;
//         fix32 y_deceleration = y->deceleration;
//         fix32 y_maximum      = y->maximum;

//         if ( x_dir > 0 )
//         {
//             x_vel = fix32Add ( x_vel, x_acceleration );

//             if ( x_vel > x_maximum )
//             {
//                 x_vel = x_maximum;
//             }
//         }
//         else if ( x_dir < 0 )
//         {
//             x_vel = fix32Add ( x_vel, fix32Neg(x_acceleration) );

//             if ( x_vel < fix32Neg(x_maximum) )
//             {
//                 x_vel = fix32Neg(x_maximum);
//             }
//         }
//         else if ( x_vel > 0 )
//         {
//             x_vel = fix32Sub ( x_vel, x_deceleration );

//             if ( x_vel < 0 )
//             {
//                 x_vel = 0;
//             }
//         }
//         else if ( x_vel < 0 )
//         {
//             x_vel = fix32Sub ( x_vel, fix32Neg(x_deceleration) );

//             if ( x_vel < fix32Neg(x_maximum) )
//             {
//                 x_vel = fix32Neg(x_maximum);
//             }
//         }


//         if ( y_dir > 0 )
//         {
//             y_vel = fix32Add ( y_vel, y_acceleration );

//             if ( y_vel > y_maximum )
//             {
//                 y_vel = y_maximum;
//             }
//         }
//         else if ( y_dir < 0 )
//         {
//             y_vel = fix32Add ( y_vel, fix32Neg(y_acceleration) );

//             if ( y_vel < fix32Neg(y_maximum) )
//             {
//                 y_vel = fix32Neg(y_maximum);
//             }
//         }
//         else if ( y_vel > 0 )
//         {
//             y_vel = fix32Sub ( y_vel, y_deceleration );

//             if ( y_vel < 0 )
//             {
//                 y_vel = 0;
//             }
//         }
//         else if ( y_vel < 0 )
//         {
//             y_vel = fix32Sub ( y_vel, fix32Neg(y_deceleration) );

//             if ( y_vel < fix32Neg(y_maximum) )
//             {
//                 y_vel = fix32Neg(y_maximum);
//             }
//         }


//         x->vel = x_vel;
//         y->vel = y_vel;
        
//         cp->x = fix32Add ( cp->x, x_vel );
//         cp->y = fix32Add ( cp->y, y_vel );
//     }
// }






    // for ( int i = 0; i < length; )
    // {
    //     ComponentPosition *cp = array [ i++ ];
    //     ComponentVelocity *cv = array [ i++ ];

    //     ComponentVelocity_Inner *velArray [ 2 ] = { &cv->x, &cv->y };
    //     ComponentPosition       *posArray [ 2 ] = { &cp->x, &cp->y };
        
    //     fix32 fv;

    //     for ( int j = 0; j < 2; j++ )
    //     {
    //         ComponentVelocity_Inner *velocity = velArray [ j ];
    //         ComponentPosition       *position = posArray [ j ];

    //         fix32 vel          = velocity->vel;
    //         char  dir          = velocity->dir;
    //         fix32 acceleration = velocity->acceleration;
    //         fix32 deceleration = velocity->deceleration;
    //         fix32 maximum      = velocity->maximum;

    //         if ( dir > 0 )
    //         {
    //             vel = fix32Add ( vel, acceleration );
    //             vel = ( vel > maximum ) ? maximum : vel;
    //         }
    //         else if ( dir < 0 )
    //         {
    //             vel = fix32Add ( vel, fix32Neg(acceleration) );
    //             vel = ( vel < (fv = fix32Neg(maximum))) ? fv : vel;
    //         }
    //         else if ( vel > 0 )
    //         {
    //             vel = fix32Sub ( vel, deceleration );
    //             vel = ( vel < 0 ) ? 0 : vel;
    //         }
    //         else if ( vel < 0 )
    //         {
    //             vel = fix32Sub ( vel, fix32Neg(deceleration) );
    //             vel = ( vel < (fv = fix32Neg(maximum))) ? fv : vel;
    //         }

    //         velocity->vel = vel;
            
    //         cp->x = fix32Add ( cp->x, vel );
    //     }
    // }