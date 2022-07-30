#pragma once

#include "inc/modo.h"
#include "modo/modo.h"
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


modoList *managers;
modoList *systems;
modoList *init_functions;
modoList *end_functions;
modoList *pre_managers;
modoList *pos_managers;
modoList *pre_systems;
modoList *pos_systems;