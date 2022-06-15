#include <genesis.h>

#include "inc/components.h"


void system_movement ( void *array[], int length ) {
    for ( int i = 0; i < length; ) {
        ComponentPosition2D * const cp = array [ i++ ];
        ComponentVelocity * const cv = array [ i++ ];

        ComponentVelocity_Update ( cv );
        
        cp->x = fix32Add ( cp->x, cv->x.vel );
        cp->y = fix32Add ( cp->y, cv->y.vel );
    }
}



// for ( int i = 0; i < length; )
// {
//     ComponentPosition2D *cp = array [ i++ ];
//     ComponentVelocity *cv = array [ i++ ];

//     ComponentVelocity_Inner *velArray [ 2 ] = { &cv->x, &cv->y };
//     ComponentPosition2D       *posArray [ 2 ] = { &cp->x, &cp->y };
    
//     fix32 fv;

//     for ( int j = 0; j < 2; j++ )
//     {
//         ComponentVelocity_Inner *velocity = velArray [ j ];
//         ComponentPosition2D       *position = posArray [ j ];

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