#include <genesis.h>

#include "libs/ECS.h"

#include "libs/joyreader.h"
#include "data/systems.h"
#include "../res/sprites.h"

#include "components.h"
#include "states/Idle.h"
#include "states/Move.h"



static void Awake ( Entity *entity )
{
    COMPONENTS(entity);

    system_sprite_init ( sp, cp );
    system_input_init ( ci );
}

static void Update ( Entity *entity )
{
    entity->state->update ( entity );
}

static void Delete ( Entity *entity )
{
    //
}


////////////////////////////////////////////////////////////////////////////////////////


void inputHandler ( void *param1, void *param2 )
{
    Entity    *entity = (Entity*)    param1;
    Joyreader *joy    = (Joyreader*) param2;
    
    if ( joy_released_dir ( joy  ) )
    {
        ecsEntityState ( entity, &idleState );
    }

    if ( joy_active_dir ( joy ) )
    {
        ecsEntityState ( entity, &moveState );
    }

    if ( joy_pressed_b ( joy ) )
    {
        // create_entity_bullet ( entity, &entityBullet1_tpl );
    }
}



Entity entityHero1_tpl = //( Entity )
{
    .Awake  = Awake,
    .Update = Update,
    .Delete = Delete,
    .state  = &idleState, // &idleState, // &(states.idle),

    .compsSize  = sizeof ( Components ),
    .components = &(Components) {
        .rigidbody = {
            .position = { FIX32(2.1), FIX32(100.2) },
            .velocity = {
                .x = { FIX32(6), 0, FIX32(1.5), FIX32(1.5), FIX32(0.1), NULL },
                .y = { FIX32(3), 0, FIX32(1.5), FIX32(1.5), FIX32(0.1), NULL }
            }
        },
        .sprite = { .sd = &res_hero1_sprite, .attr = TILE_ATTR ( PAL3, 1, 0, 0 ) },
        .input  = { .handlerFn = inputHandler },
        .attrs  = { 0b00000000000000000000000000000000 },
    }
};