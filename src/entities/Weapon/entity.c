#include <genesis.h>
#include "inc/modo.h"
#include "inc.h"
#include "inc/systems.h"
#include "inc/states.h"
#include "../res/spr_weapon.h"
#include "inc/entities.h"
#include "inc/managers.h"


static void awake ( Entity *const e ) {
    COMPS(e);

    ComponentSprite_Init ( sp, pos->x.rounded, pos->y.rounded );

    struct sysvars *a = malloc ( sizeof(struct sysvars) );

    a->sprite[0]   = systemAdd ( sysSprite,   sp       );
    a->sprite[1]   = systemAdd ( sysSprite,   pos      );
    a->movement[0] = systemAdd ( sysMovement, pos      );
    a->movement[1] = systemAdd ( sysMovement, movement );
    a->timer       = systemAdd ( sysTimer,    timer    );

    e->sysvars = a;
}


static void update ( Entity *const e ) {
    COMPS(e);
}


static void delete ( Entity *const e ) {
    COMPS(e);

    ComponentSprite_Release ( sp );


    struct sysvars *const a = e->sysvars;

    systemDelete ( sysSprite,   ((struct sysvars *const) e->sysvars)->sprite[0] );
    systemDelete ( sysSprite,   a->sprite[1] );
    systemDelete ( sysMovement, a->movement[0] );
    systemDelete ( sysMovement, a->movement[1] );
    systemDelete ( sysTimer,    a->timer );
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


void entity_Weapon_setXY ( Entity *const e, int x, int y ) {
    Components          *C  = e->components;
    ComponentPosition2D *cp = &C->pos;

    ComponentPosition2D_SetX ( cp, x );
    ComponentPosition2D_SetY ( cp, y );
}

void entity_Weapon_setDirH ( Entity *const e, int dir  ) {
    if ( !dir ) return;

    Components *C = e->components;
    ComponentMovement2D *const cm = &C->movement;
    
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