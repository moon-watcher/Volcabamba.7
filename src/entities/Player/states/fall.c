#include "mymodo.h" 
#include "inc/states.h"
#include "../inc.h"


int counter1;


static void inputHandler ( Joyreader *const j, Entity *const e )
{
    COMPS(e);

    if ( joy_active_down(j) && joy_pressed_b(j)) {
        entityState(e, &entity_Player_state_shotdown);
    }
}




static void enter ( Entity *const e ) {
    COMPS(e);

    counter1 = 80;
    SPR_setAnim ( sp->sprite, 2 );
    ci->handler = inputHandler;
}


static void update ( Entity *const e ) {
    COMPS(e);
    --counter1;

    sp->sprite->timer= 200;
    SPR_setFrame(sp->sprite, 0);
    
    if ( counter1 < 75)
        SPR_setFrame(sp->sprite, 1);

    Int(counter1, 0,0,4);

    if ( !counter1  ) 
        entityState ( e, &entity_Player_state_stay );
}



State const entity_Player_state_fall = { enter, update };