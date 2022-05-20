#pragma once

#include "inc/modo.h"
#include "inc/components.h"

System *sysMovement;
System *sysInput;
System *sysSprite;
System *sysTimer;


void system_input       ( void*, int );
void system_movement    ( void*, int );
void system_sprite      ( void*, int );
void system_timer       ( void*, int );


void system_input_init  ( ComponentInput *, int );
void system_sprite_init ( ComponentSprite *, ComponentPosition * );