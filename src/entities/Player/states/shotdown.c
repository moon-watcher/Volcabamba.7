#include "inc/modo.h"
#include "inc/states.h"
#include "../components.h"


static void enter ( Entity *e ) {
    COMPS(e);
    SPR_setAnim ( sp->sprite, 5 );
}


static void update ( Entity *e ) {
    COMPS(e);

    if ( ComponentSprite_IsLastFrame ( sp ) )
        entityState ( e, e->prevState  );
}



State const entity_Player_state_shotdown = { enter, update, .name="shotdown" };