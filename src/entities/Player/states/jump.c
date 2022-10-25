#include "mm.h" 
#include "inc/states.h"
#include "../inc.h"


int counter1;


static void inputHandler ( Joyreader *const j, Entity *const e )
{
    COMPS(e);

    if ( joy_active_left(j) ) SPR_setHFlip ( sp->sprite, 1 );
    if ( joy_active_right(j)) SPR_setHFlip ( sp->sprite, 0 );

    if ( joy_pressed_b(j) ) {
        if ( joy_active_down(j) )
            entityState ( e, &entity_Player_state_shotdown );
        else
            entityState ( e, &entity_Player_state_shot );
        return;
    }
}



static void enter ( Entity *const e ) {
    COMPS(e);

    counter1 = 70;
    SPR_setAnim ( sp->sprite, 3 );
    ci->handler = inputHandler;
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

    --counter1;

    sp->sprite->timer= 200;
    SPR_setFrame(sp->sprite, 0);
    
    if ( counter1 < 65)
        SPR_setFrame(sp->sprite, 1);

    Int(counter1, 0,0,4);

    if ( !counter1  ) 
        entityState ( e, &entity_Player_state_stay );
}



State const entity_Player_state_jump = { enter, update };