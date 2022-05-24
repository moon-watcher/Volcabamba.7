#pragma once

// https://docs.unity3d.com/Manual/class-BoxCollider.html
// https://docs.unity3d.com/ScriptReference/BoxCollider2D.html

typedef struct
{
    int is_trigger; // If enabled, this Collider is used for triggering events, and is ignored by the physics engine

    struct
    {
        unsigned x;
        unsigned y;
    }
    center;

    struct
    {
        unsigned w;
        unsigned h;
    }
    size;
}
ComponentBoxCollider;
