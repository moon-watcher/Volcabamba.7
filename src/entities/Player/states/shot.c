#include <genesis.h>
#include "inc/modo.h"
#include "inc/states.h"
#include "../components.h"
#include "inc/entities.h"
#include "inc/managers.h"


static void enter ( Entity *e ) {
    COMPS(e);
    SPR_setAnim ( sp->sprite, 4 );


    Entity *weapon = managerAdd ( manWeapons, &entity_Weapon_tpl );

    entity_Weapon_setXY ( weapon, 100, 100 );
}


static void update ( Entity *e ) {
    COMPS(e);

    if ( $ComponentSprite.IsLastFrame ( sp ) )
        entityState ( e, e->prevState );
}


State const entity_Player_state_shot = { enter, update, .name="shot" };