#pragma once

#include "inc/modo.h"
#include "modo/hist.h"
#include "inc/components.h"

System *sysMovement;
//System *sysInput;
System *sysInput;
System *sysSprite;
System *sysTimer;


void system_movement   ( System *const );
//void system_input      ( System *const );
void system_input  ( System *const );
void system_sprite     ( System *const );
void system_timer      ( System *const );


histlist *managers;
histlist *systems;
histlist *init_functions;
histlist *end_functions;
histlist *pre_managers;
histlist *pos_managers;
histlist *pre_systems;
histlist *pos_systems;