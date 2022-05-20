#pragma once

#include "inc/components.h"


#define COMPONENTS(entity)                      \
    Components     *comps = entity->components; \
    ComponentInput *ci    = &comps->input;      \
    Joyreader      *joy   = &ci->joy;           \
    ComponentTimer *timer1 = &comps->timer1;


typedef struct
{
    ComponentInput input;
    ComponentTimer timer1;
}
Components;