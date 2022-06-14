#include "inc/modo.h"
#include "inc/states.h"
#include "../components.h"


static void enter ( Entity *e ) {
    COMPS(e);

    $ComponentSprite.SetAnim ( sp, 7 );
    $ComponentBoxCollider2D.Init ( collider, &collider_duck );
}


static void update ( Entity *e ) {
    COMPS(e);

    if ( $ComponentSprite.IsLastFrame ( sp ) )
        entityState ( e, &entity_Player_state_duck );
}


State const entity_Player_state_shotduck = { enter, update, .name="shotduck" };