#pragma once

#include "inc/components.h"

typedef struct {
    ComponentTimer timer;
    ComponentInput input;
}
Components;


#define COMPS(E)                                 \
    Components     *const C     = E->components; \
    ComponentTimer *const timer = &C->timer;     \
    ComponentInput *const input = &C->input;     \
    Joyreader      *const joy   = &input->joy;
