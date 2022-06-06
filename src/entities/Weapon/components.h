#pragma once

#include "inc/components.h"

#define COMPS(E)                                 \
    Components         *C     = E->components;   \
    ComponentAttribute *attrs = &C->attributes;  \
    ComponentSprite    *sp    = &C->sprite;      \
    ComponentPosition  *cp    = &C->position;    \
    ComponentTimer     *timer = &C->timer;



typedef struct
{
    ComponentAttribute  attributes;
    ComponentSprite     sprite;
    ComponentPosition   position;
    ComponentTimer      timer;
}
Components;