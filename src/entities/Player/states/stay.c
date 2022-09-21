#include "mm.h" 
#include "inc/states.h"
#include "../inc.h"


static void inputHandler ( Joyreader *const j, void *const ptr1, void *const ptr2 )
{
    Entity *const e = ptr1;
    COMPS(e);

    JOY ( joy_active_horizontal, entity_Player_state_walk );
    JOY ( joy_active_down,       entity_Player_state_duck );
    JOY ( joy_pressed_c,         entity_Player_state_jump );
    JOY ( joy_pressed_b,         entity_Player_state_shot );
    JOY ( joy_pressed_a,         entity_Player_state_fall );
}



static void enter ( Entity *const e ) {
    COMPS(e);

    ComponentSprite_SetAnim ( sp, 0 );
    ComponentInput_Handler ( ci, inputHandler );
    ComponentBoxCollider_Init ( collider, &collider_stand );
    e->action = 0;
}


State const entity_Player_state_stay = { enter };