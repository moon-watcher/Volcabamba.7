#pragma once

#include "../inc/components.h"
#include "../../libs/joyreader.h"


#define COMPS(E)                            \
    Components        *C   = E->components; \
    ComponentSprite   *sp  = &C->sprite;    \
    ComponentPosition *cp  = &C->position;  \
    ComponentInput    *ci  = &C->input;     \
    Joyreader         *joy = &ci->joy;


typedef struct
{
    ComponentInput    input;
    ComponentSprite   sprite;
    ComponentPosition position;
}
Components;
