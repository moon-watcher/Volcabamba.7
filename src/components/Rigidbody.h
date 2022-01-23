#pragma once

#include <genesis.h>
#include "BoxCollider.h"
#include "Velocity.h"
#include "Position.h"

// https://docs.unity3d.com/Manual/class-Rigidbody.html
// https://docs.unity3d.com/ScriptReference/Rigidbody2D.html

typedef struct
{
    fix32      mass; // peso
    fix32      drag; // resistencia al aire
    bool       gravity;

    //ComponentBoxCollider collider;

    ComponentVelocity velocity;
    ComponentPosition position;


//    void  (*Sleep) (void*);
//    void  (*WakeUp)(void*);
}
ComponentRigidbody;
