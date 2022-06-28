#pragma once

#include "inc/modo.h"
#include "inc/components.h"

System *sysMovement;
System *sysInput;
System *sysSprite;
System *sysTimer;


void system_movement   ( System ref );
void system_input      ( System ref );
void system_sprite     ( System ref );
void system_timer      ( System ref );