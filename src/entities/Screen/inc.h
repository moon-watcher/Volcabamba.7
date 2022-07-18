#pragma once

#include "inc/components.h"


#define COMPS(entity)                           \
    Components     *comps = entity->components; \
    ComponentTimer *timer = &comps->timer;      \
    ComponentInput *input = &comps->input;      \
    Joyreader      *joy   = &input->joy;


typedef struct {
    ComponentTimer timer;
    ComponentInput input;
}
Components;