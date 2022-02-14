#pragma once

#include "libs/ECS.h"
#include "inc/components.h"


void system_movement    ( void *array, int length );

void system_input       ( void *array, int length );
void system_input_init  ( ComponentInput *input, int port );

void system_sprite      ( void *array, int length );
void system_sprite_init ( ComponentSprite *sp, ComponentPosition *cp );