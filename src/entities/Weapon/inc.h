#pragma once

#include "mymodo/mm.h" 
#include "inc/components.h"

#define COMPS(E)                                    \
    Components           *const C        = E->components; \
    ComponentSprite      *const sp       = &C->sprite;    \
    ComponentTimer       *const timer    = &C->timer;     \
    ComponentBoxCollider *const collider = &C->collider;  \
    ComponentMovement2D  *const movement = &C->movement;  \
    ComponentPosition2D  *const pos      = &C->pos;


typedef struct {
    ComponentSprite      sprite;
    ComponentTimer       timer;
    ComponentBoxCollider collider;
    ComponentMovement2D  movement;
    ComponentPosition2D  pos;
}
Components;