#include <genesis.h>

#include "libs/ECS.h"
#include "data/systems.h"
#include "data/managers.h"
#include "data/entities.h"
#include "inc/systems.h"
#include "components.h"
#include "states.h"
#include "../res/sprites.h"


void entity_PlayerBullet_create ( int x, int y )
{
    Entity *bullet = ecsEntity ( &entityPlayerBullet1_tpl );
        
    ecsManagerAdd ( &manPlayersBullets, bullet );
    
    ecsEntityExec ( setPosition, bullet, 0, 0 );
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


static void Awake ( Entity *entity )
{
    COMPONENTS(entity);

    sp->sd = &player_bullets;
    sp->index = 0;
    
    system_sprite_init ( sp, cp );
}


static void Update ( Entity *entity )
{
    COMPONENTS(entity);

    ecsSystemAdd ( sysMovement, cp     );
    ecsSystemAdd ( sysMovement, cv     );
    ecsSystemAdd ( sysSprite,   sp     );
    ecsSystemAdd ( sysSprite,   cp     );
}


static void Delete ( Entity *entity )
{
    // Se destruye todo lo inicializado en el Awake
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


static void setPosition ( Entity *entity, int x, int y )
{
    COMPONENTS ( entity );

    cp->x = FIX32 ( x );
    cp->y = FIX32 ( y );
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Entity const entityPlayerBullet1_tpl = // ( Entity )
{
    .Awake = Awake,
    .Update = Update,
    .Delete = Delete,
    .state = (State*) &PlayerBullet_moveState,
    .compsSize = sizeof(Components),
    .components = &(Components) {
        .rigidbody = { 
            .position = { 0, 0 },
            .velocity = {
                .x = { 0, 0, 0, 0, 0, NULL },
                .y = { 0, 0, 0, 0, 0, NULL }
            }
        },
        .sprite = { .attr = TILE_ATTR ( PAL3, 1, 0, 0 ) },
        .attrs  = { 0b00000000000000000000000000000000 },
    },
    .exec = &(EntityExecInterface) {
        .setPosition = setPosition,
    }
};