#pragma once

#include "inc/components.h"

#define COMPS(E)                               \
    Components         *C     = E->components; \
    ComponentSprite    *sp    = &C->sprite;    \
    ComponentTimer     *timer = &C->timer;     \
    ComponentVelocity  *vel   = &C->vel;       \
    ComponentDirection *dir   = &C->dir;       \
    ComponentPosition  *pos   = &C->pos;
    // ComponentAttribute  *attrs = &C->attributes;


typedef struct {
    ComponentSprite    sprite;
    ComponentTimer     timer;
    ComponentVelocity  vel;
    ComponentDirection dir;
    ComponentPosition  pos;
    // ComponentAttribute   attributes;
}
Components;