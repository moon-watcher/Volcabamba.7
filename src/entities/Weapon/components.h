#pragma once

#include "inc/components.h"

#define COMPS(E)                                    \
    Components           *C        = E->components; \
    ComponentSprite      *sp       = &C->sprite;    \
    ComponentTimer       *timer    = &C->timer;     \
    ComponentBoxCollider *collider = &C->collider;  \
    ComponentMovement2D  *movement = &C->movement;  \
    ComponentPosition2D  *pos      = &C->pos;


typedef struct {
    ComponentSprite      sprite;
    ComponentTimer       timer;
    ComponentBoxCollider collider;
    ComponentMovement2D  movement;
    ComponentPosition2D  pos;
}
Components;