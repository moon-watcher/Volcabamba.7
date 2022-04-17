#pragma once

#include "modo/system.h"
#include "inc/components.h"


System *sysMovement;
System *sysInput;
System *sysSprite;


void system_movement    ( void *array[], unsigned length );
void system_sprite      ( void *array[], unsigned length );
void system_input       ( void *array[], unsigned length );

void system_input_init  ( ComponentInput *input, int port );
void system_sprite_init ( ComponentSprite *sp, ComponentPosition *cp );