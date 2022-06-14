#include "inc/modo.h"
#include "inc/states.h"
#include "../components.h"


static void inputHandler ( Joyreader *j, void *ptr1, void *ptr2 )
{
    Entity *e = ptr1;
    COMPS(e);

    if ( joy_active_left(joy) ) {
        SPR_setHFlip(sp->sprite,1);
    }

    if ( joy_active_right(joy) ) {
        SPR_setHFlip(sp->sprite,0);
    }

    if ( joy_released_horizontal ( j ) ) {
        entityState ( e, &entity_Player_state_stay );
        return;
    }

    if ( joy_pressed_down ( j ) ) {
        entityState ( e, &entity_Player_state_duck );
        return;
    }
    
    if ( joy_pressed_c ( j ) ) {
        entityState ( e, &entity_Player_state_jump );
        return;
    }
    
    if ( joy_pressed_b ( j ) ) {
        entityState ( e, &entity_Player_state_shot );
        return;
    }
    
    if ( joy_pressed_a ( j ) ) {
        entityState ( e, &entity_Player_state_fall );
        return;
    }
}



static void enter ( Entity *e ) {
    COMPS(e);

    $ComponentSprite.SetAnim ( sp, 1 );
    $ComponentInput.Handler ( ci, inputHandler );
    $ComponentBoxCollider2D.Init ( collider, &collider_stand );
}


static void update ( Entity *e ) {
    COMPS(e);

    // if ( joy_active_left(joy) )
    //     SPR_setHFlip(sp->sprite,1);
    // else if ( joy_active_right(joy) )
    //     SPR_setHFlip(sp->sprite,0);

}



State const entity_Player_state_walk = { enter, .name="walk" };