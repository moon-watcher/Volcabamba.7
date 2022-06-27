#pragma once

#include "inc/components.h"
#include "libs/joyreader.h"


#define COMPS(E)                                     \
    Components           *C        = E->components;  \
    ComponentAttribute   *attrs    = &C->attributes; \
    ComponentSprite      *sp       = &C->sprite;     \
    ComponentPosition2D  *cp       = &C->position;   \
    ComponentBoxCollider *collider = &C->collider;   \
    ComponentRigidbody   *rb       = &C->rigidbody;  \
    ComponentInput       *ci       = &C->input;      \
    Joyreader            *joy      = &ci->joy;


typedef struct {
    ComponentAttribute   attributes;
    ComponentSprite      sprite;
    ComponentPosition2D  position;
    ComponentBoxCollider collider;
    ComponentRigidbody   rigidbody;
    ComponentInput       input;
    int                  dirH:2;
}
Components;




#define JOY( A, B ) \ 
    if ( A ( j ) ) { \
        entityState ( e, &B ); \
        return; \
    }



static ComponentBoxCollider const collider_stand = { {20,20}, { 8,28} };
static ComponentBoxCollider const collider_duck  = { {16,32}, {16,16} };