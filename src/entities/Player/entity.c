#include <genesis.h>

#include "libs/ECS.h"
#include "data/systems.h"
#include "components.h"
#include "states.h"
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

    ecsSystemAdd ( sysMovement, cp     );
    ecsSystemAdd ( sysMovement, cv     );
    ecsSystemAdd ( sysSprite,   sp     );
    ecsSystemAdd ( sysSprite,   cp     );
    ecsSystemAdd ( sysInput,    ci     );
    ecsSystemAdd ( sysInput,    entity );
}


static void Delete ( Entity *entity )
{
    // Se destruye todo lo inicializado en el Awake
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Entity const entityPlayer1_tpl = // ( Entity )
{
    .Awake = Awake,
    .Update = Update,
    .Delete = Delete,
    .state = (State*) &idleState,
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
};