#include "inc/modo.h"
#include "inc/states.h"
#include "../components.h"


static void inputHandler ( Joyreader *j, void *ptr1, void *ptr2 )
{
    Entity *e = ptr1;

    COMPS(e);

    if ( joy_active_horizontal ( j ) ) {
        entityState ( e, &entity_Player_state_walk );
        return;
    }

    if ( joy_active_down ( j ) ) {
        entityState(e, &entity_Player_state_duck);
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

    ComponentSprite_SetAnim ( sp, 0 );
    ComponentInput_Handler ( ci, inputHandler );
    ComponentBoxCollider2D_Init ( collider, &collider_stand );
}


State const entity_Player_state_stay = { enter,  .name="stayc" };