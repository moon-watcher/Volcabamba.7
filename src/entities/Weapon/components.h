#pragma once

#include "inc/components.h"

#define COMPS(E)                                 \
    Components         *C     = E->components;   \
    ComponentAttribute *attrs = &C->attributes;  \
    ComponentSprite    *sp    = &C->sprite;      \
    ComponentPosition2D  *cp    = &C->position;    \
    ComponentVelocity  *cv    = &C->velocity;    \
    ComponentTimer     *timer = &C->timer;



typedef struct
{
    ComponentAttribute  attributes;
    ComponentSprite     sprite;
    ComponentPosition2D   position;
    ComponentTimer      timer;
    ComponentVelocity   velocity;
}
Components;