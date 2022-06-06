#include <genesis.h>
#include "inc/modo.h"
#include "components.h"
#include "inc/systems.h"
#include "inc/states.h"
#include "../res/spr_weapon.h"


static void awake ( Entity *e ) { COMPS(e);

    $ComponentSprite.Init( sp, fix32ToRoundedInt(cp->x), fix32ToRoundedInt(cp->y) );
}


static void update ( Entity *e ) { COMPS(e);

    systemAdd ( sysSprite,   sp ); systemAdd ( sysSprite,   cp );
    systemAdd ( sysMovement, sp ); systemAdd ( sysMovement, cp );
}


static void delete ( Entity *e ) { COMPS(e);

    $ComponentSprite.Release(sp);
}



Entity const entity_Weapon_tpl = {
    .Awake  = awake,
    .Update = update,
    .Delete = delete,
    .state  = (State*) &entity_Weapon_state_move,
    .compsSize  = sizeof(Components),
    .components = &(Components) {
        .sprite   = { &res_sprite_weapon, TILE_ATTR(PAL3,1,0,0) },
        .position = { FIX32(123), FIX32(11) },
    },
};




// void entity_PlayerBullet_create ( int x, int y )
// {
//     Entity *bullet = modoEntity ( &entityWeapon1_tpl );
        
//     modoManagerAdd ( &manWeapons, bullet );
    
//     modoEntityExec ( setPosition, bullet, 0, 0 );
// }


// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// static void Awake ( Entity *entity )
// {
//     COMPONENTS(entity);

//     sp->sd = &player_bullets;
//     sp->index = 0;
    
//     system_sprite_init ( sp, cp );
// }


// static void Update ( Entity *entity )
// {
//     COMPONENTS(entity);

//     modoSystemAdd ( sysMovement, cp     );
//     modoSystemAdd ( sysMovement, cv     );
//     modoSystemAdd ( sysSprite,   sp     );
//     modoSystemAdd ( sysSprite,   cp     );
// }


// static void Delete ( Entity *entity )
// {
//     // Se destruye todo lo inicializado en el Awake
// }


// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// static void setPosition ( Entity *entity, fix32 x, fix32 y )
// {
//     COMPONENTS ( entity );

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