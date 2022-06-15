#pragma once

#include "inc/modo.h"
#include "inc/components.h"

System *sysMovement;
System *sysInput;
System *sysSprite;


void system_movement ( void*, int );
void system_input    ( void*, int );
void system_sprite   ( void*, int );

//void system_input_init  ( ComponentInput *input, int port );
//void system_sprite_init ( ComponentSprite *sp, ComponentPosition2D *cp );