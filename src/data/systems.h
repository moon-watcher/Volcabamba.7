#pragma once

#include "data/components.h"


void system_movement_update ( void *array, int length );

void system_input_update    ( void *array, int length );
void system_input_init      ( ComponentInput *input, int port );

void system_sprite_update   ( void *array, int length );
void system_sprite_init     ( ComponentSprite *sp, ComponentPosition *cp );


System *sysMovement;
System *sysInput;
System *sysSprite;