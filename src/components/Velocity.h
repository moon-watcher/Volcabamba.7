#pragma once

#include <genesis.h>

typedef struct
{
    fix32  vel;
    char   dir:2;
    fix32  maximum;
    fix32  acceleration;
    fix32  deceleration;
    void  (*accel_fn)(void*,void*);
}
ComponentVelocity_Inner;


typedef struct
{
    ComponentVelocity_Inner x;
    ComponentVelocity_Inner y;
    //ComponentVelocity_Inner z;
}
ComponentVelocity;
