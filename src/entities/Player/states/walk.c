#include "mm.h" 
#include "inc/states.h"
#include "../inc.h"


static void inputHandler ( Joyreader *const j, void *const ptr1, void *const ptr2 )
{
    Entity *const e = ptr1;
    COMPS(e);

    if ( joy_active_left(joy)  ) SPR_setHFlip(sp->sprite,1);
    if ( joy_active_right(joy) ) SPR_setHFlip(sp->sprite,0);
    
    JOY ( joy_released_horizontal, entity_Player_state_stay );
    JOY ( joy_pressed_down,        entity_Player_state_duck );
    JOY ( joy_pressed_c,           entity_Player_state_jump );
    JOY ( joy_pressed_b,           entity_Player_state_shot );
    JOY ( joy_pressed_a,           entity_Player_state_fall );
}


static void enter ( Entity *const e ) {
    COMPS(e);

    ComponentSprite_SetAnim ( sp, 1 );
    ComponentInput_Handler ( ci, inputHandler );
    ComponentBoxCollider_Init ( collider, &collider_stand );
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
}


State const entity_Player_state_walk = { enter, update };