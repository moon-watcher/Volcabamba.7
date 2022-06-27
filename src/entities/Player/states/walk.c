#include "inc/modo.h"
#include "inc/states.h"
#include "../components.h"


static void inputHandler ( Joyreader *j, void *ptr1, void *ptr2 )
{
    Entity *e = ptr1;
    COMPS(e);

    if ( joy_active_left(joy)  ) SPR_setHFlip(sp->sprite,1);
    if ( joy_active_right(joy) ) SPR_setHFlip(sp->sprite,0);
    
    JOY ( joy_released_horizontal, entity_Player_state_stay );
    JOY ( joy_pressed_down,        entity_Player_state_duck );
    JOY ( joy_pressed_c,           entity_Player_state_jump );
    JOY ( joy_pressed_b,           entity_Player_state_shot );
    JOY ( joy_pressed_a,           entity_Player_state_fall );
}



static void enter ( Entity *e ) {
    COMPS(e);

    ComponentSprite_SetAnim ( sp, 1 );
    ComponentInput_Handler ( ci, inputHandler );
    ComponentBoxCollider_Init ( collider, &collider_stand );
}



State const entity_Player_state_walk = { enter };