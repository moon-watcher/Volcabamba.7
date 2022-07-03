#pragma once

#include "inc/modo.h"
#include "inc/components.h"

System *sysMovement;
System *sysInput;
System *sysSprite;
System *sysTimer;


void system_movement   ( System *const );
void system_input      ( System *const );
void system_sprite     ( System *const );
void system_timer      ( System *const );