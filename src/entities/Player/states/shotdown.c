#include "mm.h" 
#include "inc/states.h"
#include "../inc.h"



static void enter ( Entity *const e ) {
    COMPS(e);

    SPR_setAnim ( sp->sprite, 5 );
}


static void update ( Entity *const e ) {
    COMPS(e);

    if ( ComponentSprite_IsLastFrame ( sp ) )
        entityState ( e, e->prevState );
}



State const entity_Player_state_shotdown = { enter, update };