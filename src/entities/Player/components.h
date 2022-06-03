#pragma once

#include "inc/components.h"
#include "libs/joyreader.h"

#define COMPS(E)                                 \
    Components         *C     = E->components;   \
    ComponentAttribute *attrs = &C->attributes;  \
    ComponentSprite    *sp    = &C->sprite;      \
    ComponentPosition  *cp    = &C->position;    \
    ComponentInput     *ci    = &C->input;       \
    Joyreader          *joy   = &ci->joy;


typedef struct
{
    ComponentAttribute attributes;
    ComponentSprite    sprite;
    ComponentPosition  position;
    ComponentInput     input;
}
Components;