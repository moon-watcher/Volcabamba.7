#pragma once

#include "data/components.h"


void system_movement_update ( void *array, int length );

void system_input_update    ( void *array, int length );
void system_input_init      ( ComponentInput *input, int port );

void system_sprite_update   ( void *array, int length );
void system_sprite_init     ( ComponentSprite *sp, ComponentPosition *cp );


#define sysMovement_max 160
#define sysInput_max    8
#define sysSprite_max   160

void *sysMovement_list [ sysMovement_max ];
void *sysInput_list    [ sysInput_max    ];
void *sysSprite_list   [ sysSprite_max   ];

System *sysMovement;
System *sysInput;
System *sysSprite;