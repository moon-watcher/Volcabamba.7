#pragma once

#include "inc/components.h"


#define COMPONENTS(entity)                          \
    Components         *comps = entity->components; \
    ComponentRigidbody *rb    = &comps->rigidbody;  \
    ComponentSprite    *sp    = &comps->sprite;     \
    ComponentPosition  *cp    = &rb->position;      \
    ComponentVelocity  *cv    = &rb->velocity;


typedef struct
{
    ComponentRigidbody rigidbody;
    ComponentSprite    sprite;
    ComponentAttribute attrs;
}
Components;