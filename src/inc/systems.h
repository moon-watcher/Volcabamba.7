#pragma once

#include "inc/modo.h"
#include "inc/components.h"

System *sysMovement;
System *sysInput;
System *sysSprite;
System *sysTimer;


void system_movement   ( System reff );
void system_input      ( System reff );
void system_sprite     ( System reff );
void system_timer      ( System reff );