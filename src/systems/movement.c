#include <genesis.h>

#include "inc/modo.h"
#include "inc/components.h"


void system_movement ( System * const system ) {
    void ** const array = system->list;
    int length = system->length; 

    for ( int i = 0; i < length; ) {
        ComponentPosition  * const pos = array [ i++ ];
        ComponentVelocity  * const vel = array [ i++ ];
        ComponentDirection * const dir = array [ i++ ];

        ComponentVelocity_Update ( vel->x, dir->x );
        ComponentVelocity_Update ( vel->y, dir->y );
        
        pos->x += vel->x.vel;
        pos->y += vel->y.vel;
    }
}



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