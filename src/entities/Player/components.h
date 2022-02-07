#pragma once

#include "data/components.h"

#define COMPONENTS(entity)                          \
    Components         *comps = entity->components; \
    ComponentRigidbody *rb    = &comps->rigidbody;  \
    ComponentSprite    *sp    = &comps->sprite;     \
    ComponentPosition  *cp    = &rb->position;      \
    ComponentVelocity  *cv    = &rb->velocity;      \
    ComponentInput     *ci    = &comps->input;      \
    Joyreader          *joy   = &ci->joy;


typedef struct
{
    ComponentRigidbody rigidbody;
    ComponentSprite    sprite;
    ComponentInput     input;
    ComponentAttribute attrs;
}
Components;
