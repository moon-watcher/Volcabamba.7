#pragma once

#include "inc/components.h"


#define COMPONENTS(entity)                    \
    Components   *comps = entity->components; \
    ComponentBox *cb    = &comps->box;


typedef struct
{
    ComponentBox box;
}
Components;