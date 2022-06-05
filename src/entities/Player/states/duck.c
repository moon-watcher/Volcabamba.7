#include "inc/modo.h"
#include "inc/states.h"
#include "../components.h"


static void inputHandler ( Joyreader *j, void *ptr1, void *ptr2 )
{
    Entity *e = ptr1;

    COMPS(e);

    if ( joy_released_down ( j ) ) {
        entityState ( e, &entity_Player_state_stay );
        return;
    }

    if ( joy_pressed_horizontal ( j ) ) {
        entityState ( e, &entity_Player_state_walk );
        return;
    }

    if ( joy_pressed_c ( j ) ) {
        entityState ( e, &entity_Player_state_jump );
        return;
    }

    if ( joy_pressed_b ( j ) ) {
        entityState ( e, &entity_Player_state_shotduck );
        return;
    }
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



State const entity_Player_state_duck = { enter, .name="duck" };