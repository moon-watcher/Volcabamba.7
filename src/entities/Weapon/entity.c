#include <genesis.h>
#include "inc/modo.h"
#include "components.h"
#include "inc/systems.h"
#include "inc/states.h"
#include "../res/spr_weapon.h"
#include "inc/entities.h"
#include "inc/managers.h"



static void awake ( Entity *e ) {
    COMPS(e);

    ComponentSprite_Init ( sp, pos->x.rounded, pos->y.rounded );
}


static void update ( Entity *e ) {
    COMPS(e);
    
    systemAdd2 ( sysSprite, sp, pos );
    systemAdd2 ( sysMovement, pos, movement );
    systemAdd1 ( sysTimer, timer );
}


static void delete ( Entity *e ) {
    COMPS(e);

    ComponentSprite_Release(sp);
}



Entity const entity_Weapon_tpl = {
    .Awake  = awake,
    .Update = update,
    .Delete = delete,
    .state  = (State*) &entity_Weapon_state_move,
    .compsSize  = sizeof(Components),
    .components = &(Components) {
        .sprite = { &res_sprite_weapon, TILE_ATTR(PAL3,1,0,0) },
        .movement.x  = { FIX32(2), FIX32(2) }
    },
};



//////////////////////////////////////////////////////////////////////////////


void entity_Weapon_setXY ( Entity *e, int x, int y ) {
    Components          *C  = e->components;
    ComponentPosition2D *cp = &C->pos;

    ComponentPosition2D$SetX ( cp, x );
    ComponentPosition2D$SetY ( cp, y );
}

void entity_Weapon_setDirH ( Entity *e, int dir  ) {
    if ( !dir ) return;

    Components *C = e->components;
    ComponentMovement2D ref cm = &C->movement;
    
    cm->x.dir = dir;

    if ( dir < 0 )
        cm->x.vel = -cm->x.vel;
}




// void entity_PlayerBullet_create ( int x, int y )
// {
//     Entity *bullet = modoEntity ( &entityWeapon1_tpl );
//     modoManagerAdd ( &manWeapons, bullet );
//     modoEntityExec ( setPosition, bullet, 0, 0 );
// }


// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// static void setPosition ( Entity *entity, fix32 x, fix32 y )
// {
//     COMPONENTS ( entity );
//
//     cp->x = x;
//     cp->y = y;
// }


// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Entity const entityPlayerBullet1_tpl = // ( Entity )
// {
//     .Awake = Awake,
//     .Update = Update,
//     .Delete = Delete,
//     .state = (State*) &PlayerBullet_moveState,
//     .compsSize = sizeof(Components),
//     .components = &(Components) {
//         .rigidbody = { 
//             .position = { 0, 0 },
//             .velocity = {
//                 .x = { 0, 0, 0, 0, 0, NULL },
//                 .y = { 0, 0, 0, 0, 0, NULL }
//             }
//         },
//         .sprite = { .attr = TILE_ATTR ( PAL3, 1, 0, 0 ) },
//         .attrs  = { 0b00000000000000000000000000000000 },
//     },
//     .exec = &(EntityExecInterface) {
//         .setPosition = setPosition,
//     }
// };