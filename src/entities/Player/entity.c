#include <genesis.h>

#include "inc/modo.h"
#include "inc/systems.h"
#include "inc/systems.h"
#include "inc/states.h"
#include "components.h"
#include "../res/sprites.h"


static void Awake ( Entity *entity )
{
    // Se ejecuta una vez cuando se crea la entidad.
    // Aquí se inicializan cosas como:
    //
    // sprites
    // paleta
    // musica/sfx
    // controles
    // ...
    
    COMPONENTS(entity);

    sp->sd = &res_hero1_sprite;
    sp->index = 0;
    
    system_sprite_init ( sp, cp );
    system_input_init ( ci, ci->joy.port );
}


static void Update ( Entity *entity )
{
    COMPONENTS(entity);

    modoSystemAdd ( sysMovement, cp     );
    modoSystemAdd ( sysMovement, cv     );
    modoSystemAdd ( sysSprite,   sp     );
    modoSystemAdd ( sysSprite,   cp     );
    modoSystemAdd ( sysInput,    ci     );
    modoSystemAdd ( sysInput,    entity );
}


static void Delete ( Entity *entity )
{
    // Se destruye todo lo inicializado en el Awake
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


static void setPosition ( Entity *entity, fix32 x, fix32 y )
{
    COMPONENTS ( entity );

    cp->x = x;
    cp->y = y;
}


// static void setPositionFIX32 ( Entity *entity, fix32 x )
// {
//     //COMPONENTS ( entity );
//     Components         *comps = entity->components;
//     ComponentRigidbody *rb    = &comps->rigidbody;
//     ComponentPosition  *cp    = &rb->position;

//     cp->x = x;
//     cp->y = FIX32 ( 111 );
// }


static int getInt ( )
{
    return 76;
}


static void disableInput ( Entity *entity )
{
    COMPONENTS ( entity );
    // Components     *comps = entity->components;
    // ComponentInput *ci= &comps->input;

    ci->handler = NULL;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Entity const entityPlayer1_tpl = // ( Entity )
{
    .Awake = Awake,
    .Update = Update,
    .Delete = Delete,
    .state = (State*) &Player_idleState,
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
        .input  = { .joy.port = PORT_1 },
    },
    .exec = &(EntityExecInterface) {
        .setPosition  = setPosition,
        .getInt       = getInt,
        .disableInput = disableInput,
    }
};


Entity const entityPlayer2_tpl = // ( Entity )
{
    .Awake = Awake,
    .Update = Update,
    .Delete = Delete,
    .state = (State*) &Player_idleState,
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
        .input  = { .joy.port = PORT_2 },
    },
    .exec = &(EntityExecInterface) {
        .setPosition  = setPosition,
        .getInt       = getInt,
        .disableInput = disableInput,
    }
};