#include "inc/modo.h"
#include "inc/states.h"
#include "../components.h"


static void enter ( Entity *e ) {
    COMPS(e);

    ComponentSprite_SetAnim ( sp, 7 );
    ComponentBoxCollider_Init ( collider, &collider_duck );
}


static void update ( Entity *e ) {
    COMPS(e);

    if ( ComponentSprite_IsLastFrame ( sp ) )
        entityState ( e, &entity_Player_state_duck );
}


State const entity_Player_state_shotduck = { enter, update, .name="shotduck" };