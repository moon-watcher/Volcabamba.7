#include "mm.h" 
#include "inc/states.h"
#include "../inc.h"



defineState ( entity_Player_state_shotduck,
{ // enter
    ComponentSprite_SetAnim ( sp, 7 );
    ComponentBoxCollider_Init ( collider, &collider_duck );
},
{ // update
    if ( joy_active_left(joy)  ) C->dirH = -1;
    if ( joy_active_right(joy) ) C->dirH = +1;

    systemAdd ( sysInput,  ci );
    systemAdd ( sysInput,   e );
    systemAdd ( sysSprite, sp );
    systemAdd ( sysSprite, cp );

    if ( ComponentSprite_IsLastFrame ( sp ) )
        entityState ( e, &entity_Player_state_duck );
},
{});