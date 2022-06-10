#include "inc/modo.h"
#include "inc/states.h"
#include "../components.h"


static void enter ( Entity *e ) {
    COMPS(e);
    SPR_setAnim ( sp->sprite, 7 );
}


static void update ( Entity *e ) {
    COMPS(e);

    if ( $ComponentSprite.IsLastFrame ( sp ) )
        entityState ( e, &entity_Player_state_duck );
}


State const entity_Player_state_shotduck = { enter, update, .name="shotduck"  };