#include <genesis.h>
#include "mymodo/mm.h" 
#include "inc.h"
#include "inc/systems.h"
#include "inc/states.h"
#include "../res/spr_weapon.h"
#include "inc/entities.h"
#include "inc/managers.h"

#define AAA ComponentSprite *const sp2 = &(e->COMPS[0]);

static void awake ( Entity *const e ) {
    COMPS(e);

    ComponentSprite_Init ( sp, pos->x.rounded, pos->y.rounded );
    //ComponentSprite_InitEx ( sp, pos->x.rounded, pos->y.rounded );
}


static void update ( Entity *const e ) {
    COMPS(e);

    systemAdd ( sysSprite,   sp );
    systemAdd ( sysSprite,   pos );
    systemAdd ( sysMovement, pos );
    systemAdd ( sysMovement, movement );
    systemAdd ( sysTimer,    timer );
}


static void delete ( Entity *const e ) {
    COMPS(e);

    ComponentSprite_Release ( sp );
}



Entity const entity_Weapon_tpl = {
    .Awake  = awake,
    .Update = update,
    .Delete = delete,
    .state  = (State*) &entity_Weapon_state_move,
    .compsSize  = sizeof(Components),
    .components = &(Components) {
        .sprite = { &res_sprite_weapon, TILE_ATTR(PAL3,1,0,0) },
        //.sprite = { &res_sprite_weapon, TILE_ATTR_FULL(PAL3,1,0,0,200), SPR_FLAG_AUTO_SPRITE_ALLOC|SPR_FLAG_AUTO_TILE_UPLOAD },
        .movement.x  = { FIX32(2), FIX32(2) }
    },
//     .COMPS = {
//         &(ComponentSprite      ) { &res_sprite_weapon, TILE_ATTR(PAL3,1,0,0) },
//         &(ComponentMovement2D  ) { { FIX32(2), FIX32(2) } },
//         &(ComponentTimer       ) { },
//         &(ComponentBoxCollider ) { },
//         &(ComponentPosition2D  ) { },
//    }
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