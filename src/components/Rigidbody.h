#pragma once

#include <genesis.h>
// #include "BoxCollider2D.h"
// #include "Velocity.h"
// #include "Position2D.h"

// https://docs.unity3d.com/Manual/class-Rigidbody.html
// https://docs.unity3d.com/Manual/class-Rigidbody2D.html
// https://docs.unity3d.com/ScriptReference/Rigidbody2D.html

typedef struct {
    fix32 mass;    // peso
    fix32 drag;    // resistencia al aire
    bool  gravity; // si/no

    // ComponentVelocity      velocity;
    // ComponentPosition2D    position;
    // ComponentBoxCollider2D collider;

    // void  (*Sleep) (void*);
    // void  (*WakeUp)(void*);
}
ComponentRigidbody;
