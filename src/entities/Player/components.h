#pragma once

#include "inc/components.h"
#include "libs/joyreader.h"


#define COMPS(E)                                     \
    Components           *const C        = E->components;  \
    ComponentAttribute   *const attrs    = &C->attributes; \
    ComponentSprite      *const sp       = &C->sprite;     \
    ComponentPosition2D  *const cp       = &C->position;   \
    ComponentBoxCollider *const collider = &C->collider;   \
    ComponentRigidbody   *const rb       = &C->rigidbody;  \
    ComponentInput       *const ci       = &C->input;      \
    Joyreader            *const joy      = &ci->joy;


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




#define JOY( A, B )            \
    if ( A ( j ) ) {           \
        entityState ( e, &B ); \
        return; \
    }



static ComponentBoxCollider const collider_stand = { {20,20}, { 8,28} };
static ComponentBoxCollider const collider_duck  = { {16,32}, {16,16} };