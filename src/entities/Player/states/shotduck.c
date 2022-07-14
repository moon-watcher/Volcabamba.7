#include "inc/modo.h"
#include "inc/states.h"
#include "../inc.h"



static void enter ( Entity *const e ) {
    COMPS(e);

    ComponentSprite_SetAnim ( sp, 7 );
    ComponentBoxCollider_Init ( collider, &collider_duck );
}


static void update ( Entity *const e ) {
    COMPS(e);

    if ( ComponentSprite_IsLastFrame ( sp ) )
        entityState ( e, &entity_Player_state_duck );
}



State const entity_Player_state_shotduck = { enter, update };