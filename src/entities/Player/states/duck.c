#include "inc/modo.h"
#include "inc/states.h"
#include "../inc.h"


static void inputHandler ( Joyreader *const j, void *const ptr1, void *const ptr2 )
{
    Entity *const e = ptr1;
    COMPS(e);

    JOY ( joy_released_down,      entity_Player_state_stay     );
    JOY ( joy_pressed_horizontal, entity_Player_state_walk     );
    JOY ( joy_pressed_c,          entity_Player_state_jump     );
    JOY ( joy_pressed_b,          entity_Player_state_shotduck );
}



static void enter ( Entity *const e ) {
    COMPS(e);

    SPR_setAnim ( sp->sprite, 6 );
    ci->handler = inputHandler;
}


// static void update ( Entity *e ) {
//     COMPS(e);

//     // if ( joy_active_left(joy) )
//     //     SPR_setHFlip(sp->sprite,1);
//     // else if ( joy_active_right(joy) )
//     //     SPR_setHFlip(sp->sprite,0);

// }



State const entity_Player_state_duck = { enter };