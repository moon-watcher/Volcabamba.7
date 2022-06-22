#pragma once

#include <genesis.h>


#define ComponentVelocity_Update( A, B ) \
         if ( B     ) A.vel = clamp ( A.vel + A.acceleration, 0, A.maximum ); \
    else if ( A.vel ) A.vel = clamp ( A.vel - A.deceleration, 0, A.maximum )


#define ComponentVelocity_Stop( A ) \
    A.vel = 0



typedef struct {
    struct {
        fix32 vel;
        fix32 maximum;
        fix32 acceleration;
        fix32 deceleration;
    } 
    x, y;
}
ComponentVelocity;