#include <genesis.h>
#include "mm.h" 
#include "inc/states.h"
#include "../inc.h"
#include "inc/entities.h"
#include "inc/managers.h"


static void enter ( Entity *const e ) {
    COMPS(e);

    ComponentSprite_SetAnim ( sp, 4 );
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

    if ( ComponentSprite_IsLastFrame ( sp ) )
        entityState ( e, e->prevState );
}

static void exit ( Entity *const e ) {
    COMPS(e);

    int x = C->dirH > 0 ? 25: -2;

    Entity *const weapon = managerAdd ( manWeapons, &entity_Weapon_tpl );
    entity_Weapon_setXY ( weapon, cp->x.rounded + x, cp->y.rounded + 20 );
    entity_Weapon_setDirH ( weapon, C->dirH );
}


State const entity_Player_state_shot = { enter, update, exit };