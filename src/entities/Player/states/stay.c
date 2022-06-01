#include "inc/modo.h"
#include "inc/states.h"
#include "../components.h"


static void inputHandler ( Joyreader *j, void *ptr1, void *ptr2 )
{
    Entity *e = ptr1;

    COMPS(e);

    if ( joy_pressed_horizontal ( j ) ) {
        entityState ( e, &entity_Player_state_walk );
        return;
    }

    if ( joy_pressed_c(j) ) {
        entityState ( e, &entity_Player_state_jump );
        return;
    }
}

static void enter ( Entity *e ) {
    COMPS(e);

    SPR_setAnim ( sp->sprite, 0 );
    ci->handler = inputHandler;
}


State const entity_Player_state_stay = { enter, };