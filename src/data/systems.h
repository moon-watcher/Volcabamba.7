#pragma once

#include "data/components.h"


void system_movement_update ( void *array, int length );

void system_input_update    ( void *array, int length );
void system_input_init      ( ComponentInput *input );

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


#define SYSTEM(s,v)              s->list [ s->length++ ] = v;
#define SYSTEM_2(s,v1,v2)        SYSTEM(s,v1); SYSTEM(s,v2);
#define SYSTEM_3(s,v1,v2,v3)     SYSTEM(s,v1); SYSTEM(s,v2); SYSTEM(s,v3);
#define SYSTEM_4(s,v1,v2,v3,v4)  SYSTEM(s,v1); SYSTEM(s,v2); SYSTEM(s,v3); SYSTEM(s,v4);