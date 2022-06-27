#include <genesis.h>
#include "inc/modo.h"
#include "inc/states.h"
#include "../components.h"
#include "inc/entities.h"
#include "inc/managers.h"


static void enter ( Entity *e ) {
    COMPS(e);

    ComponentSprite_SetAnim ( sp, 4 );
    ComponentBoxCollider_Init ( collider, &collider_stand );
}

static void update ( Entity *e ) {
    COMPS(e);

    if ( ComponentSprite_IsLastFrame ( sp ) )
        entityState ( e, e->prevState );
}

static void exit ( Entity *e ) {
    COMPS(e);

    int x = C->dirH > 0 ? 25: -2;

    Entity reff weapon = managerAdd ( manWeapons, &entity_Weapon_tpl );
    entity_Weapon_setXY ( weapon, cp->x.rounded + x, cp->y.rounded + 20 );
    entity_Weapon_setDirH ( weapon, C->dirH );
}


State const entity_Player_state_shot = { enter, update, exit };