#include "inc/modo.h"
#include "inc/states.h"
#include "../components.h"


static void inputHandler ( Joyreader *j, void *ptr1, void *ptr2 )
{
    Entity *e = ptr1;
    COMPS(e);

    JOY ( joy_released_down,      entity_Player_state_stay     );
    JOY ( joy_pressed_horizontal, entity_Player_state_walk     );
    JOY ( joy_pressed_c,          entity_Player_state_jump     );
    JOY ( joy_pressed_b,          entity_Player_state_shotduck );
}



static void enter ( Entity *e ) {
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