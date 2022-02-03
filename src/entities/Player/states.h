#pragma once 

#include "libs/ECS.h"

#include "states/Idle.h"
#include "states/Move.h"


struct 
{
    union 
    { 
        struct moveState *move;
        struct idleState *idle;
    }
    values;

    State *state;
}
state;