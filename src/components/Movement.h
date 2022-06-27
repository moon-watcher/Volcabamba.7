#pragma once

#include <genesis.h>


typedef struct {
    fix32 vel;
    fix32 maximum;
    fix32 acceleration;
    fix32 deceleration;
    int   dir:2;
} 
ComponentMovement;


typedef struct {
    ComponentMovement x;
    ComponentMovement y;
}
ComponentMovement2D;