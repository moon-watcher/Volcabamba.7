#include "mm.h" 
#include "inc/states.h"
#include "../inc.h"



static void enter ( Entity *const e ) {
    COMPS(e);

    SPR_setAnim ( sp->sprite, 5 );
}


static void update ( Entity *const e ) {
    COMPS(e);

    // para meter en los updates
    if ( joy_active_left(joy)  ) C->dirH = -1;
    if ( joy_active_right(joy) ) C->dirH = +1;

    systemAdd ( sysInput,  ci );
    systemAdd ( sysInput,   e );
    systemAdd ( sysSprite, sp );
    systemAdd ( sysSprite, cp );

    if ( ComponentSprite_IsLastFrame ( sp ) )
        entityState ( e, e->prevState );
}



State const entity_Player_state_shotdown = { enter, update };