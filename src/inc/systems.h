#pragma once

#include "mm.h" 


System *sysMovement;
System *sysInput;
System *sysSprite;
System *sysTimer;


void system_movement ( System *const );
void system_input    ( System *const );
void system_sprite   ( System *const );
void system_timer    ( System *const );


System const system_Movement_tpl;
System const system_Input_tpl;
System const system_Sprite_tpl;
System const system_Timer_tpl;