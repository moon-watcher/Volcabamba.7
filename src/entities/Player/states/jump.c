#include "inc/modo.h"
#include "inc/states.h"
#include "../components.h"


int counter1;


static void inputHandler ( Joyreader *j, void *ptr1, void *ptr2 )
{
    Entity *e = ptr1;

    COMPS(e);

    if ( joy_active_left(j)) {
        SPR_setHFlip( sp->sprite, 1);
    }

    if ( joy_active_right(j)) {
        SPR_setHFlip( sp->sprite, 0);
    }

    if ( joy_active_down(j) && joy_pressed_b(j) ) {
        entityState ( e, &entity_Player_state_shotdown );
        return;
    }

    if ( joy_pressed_b(j) ) {
        entityState ( e, &entity_Player_state_shot );
        return;
    }
}


static void enter ( Entity *e ) {
    COMPS(e);

    counter1 = 70;
    SPR_setAnim ( sp->sprite, 3 );
    ci->handler = inputHandler;
}


static void update ( Entity *e ) {
    COMPS(e);
    --counter1;

    sp->sprite->timer= 200;
    SPR_setFrame(sp->sprite, 0);
    
    if ( counter1 < 65)
        SPR_setFrame(sp->sprite, 1);

    Int(counter1, 0,0,4);

    if ( !counter1  ) 
        entityState ( e, &entity_Player_state_stay );
}



State const entity_Player_state_jump = { enter, update, .name="jump"  };