#pragma once

#include "libs/ECS.h"

System *sysMovement;
System *sysInput;
System *sysSprite;



#include "inc/systems.h"

System const sysMovement_tpl = { .updateFn = &system_movement, .max = 160, .name = "sysMovement" };
System const sysInput_tpl    = { .updateFn = &system_input,    .max = 8,   .name = "sysInput"    };
System const sysSprite_tpl   = { .updateFn = &system_sprite,   .max = 160, .name = "sysSprite"   };
