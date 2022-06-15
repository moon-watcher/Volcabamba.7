#pragma once

#include "inc/components.h"
#include "libs/joyreader.h"

#define COMPS(E) \
    Components             *C        = E->components;  \
    ComponentAttribute     *attrs    = &C->attributes; \
    ComponentSprite        *sp       = &C->sprite;     \
    ComponentPosition2D      *cp       = &C->position;   \
    ComponentInput         *ci       = &C->input;      \
    ComponentBoxCollider2D *collider = &C->collider;   \
    Joyreader              *joy      = &ci->joy;


typedef struct {
    ComponentAttribute     attributes;
    ComponentSprite        sprite;
    ComponentPosition2D      position;
    ComponentBoxCollider2D collider;
    ComponentInput         input;
}
Components;


static ComponentBoxCollider2D const collider_stand = { {20,20}, { 8,28} }; 
static ComponentBoxCollider2D const collider_duck  = { {16,32}, {16,16} };