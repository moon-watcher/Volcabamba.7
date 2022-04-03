/*
// #include <genesis.h>

// #include "../libs/ECS.h"
// #include "../res/sprites.h"
// #include "data/components.h"
// #include "data/systems.h"



// enum
// {
//     ST_UNKNOWN = 0b00000000,
//     ST_IDLE    = 0b00000001,
//     ST_MOVE    = 0b00000010,
//     ST_DIE     = 0b00000100,
// };


// typedef struct
// {
//     ComponentRigidbody rigidbody;
//     ComponentSprite    sprite;
//     ComponentTimeout   timeout;
// }
// Components;




// #define COMPONENTS(entity)                          \
//     Components         *comps = entity->components; \
//     ComponentTimeout   *to    = &comps->timeout;    \
//     ComponentRigidbody *rb    = &comps->rigidbody;  \
//     ComponentSprite    *sp    = &comps->sprite;     \
//     ComponentPosition  *cp    = &rb->position;      \
//     ComponentVelocity  *cv    = &rb->velocity;



// ////////////////////////////////////////////////////////////////////////////////////////


// static int puedeMover  ( Entity *entity ) { return 1; }
// static int puedeParar  ( Entity *entity ) { return 1; }
// static int puedeDelete ( Entity *entity )
// { 
//     COMPONENTS(entity);

//     int ret = random() % 2;

//     if ( !ret ) 
//     { 
//         to->count = random() % 100;
//     }
//     return ret;
// }


// static void move ( Entity *entity )
// {
// }

// static void stop ( Entity *entity )
// {
// }

// static void delete ( Entity *entity )
// {
//     entity->delete = 1;
// }





// ////////////////////////////////////////////////////////////////////////////////////////


// static Event const eventStop   = { puedeParar,  { ST_IDLE, stop   } };
// static Event const eventMover  = { puedeMover,  { ST_MOVE, move   } };
// static Event const eventDelete = { puedeDelete, { ST_DIE,  delete } };


// ////////////////////////////////////////////////////////////////////////////////////////


// static void Awake ( Entity *entity )
// {
//     COMPONENTS(entity);

//     system_sprite_init ( sp, cp );

//     to->count = random() % 100;
// }


// static void Update ( Entity *entity )
// {
//     COMPONENTS ( entity );
//     EVENTS ( entity );

//     ecsSystemAdd ( sysMovement, cp );
//     ecsSystemAdd ( sysMovement, cv );
//     ecsSystemAdd ( sysSprite,   sp );
//     ecsSystemAdd ( sysSprite,   cp );


//     if ( !to->count--)
//     {
//         entity->event = eventDelete;
//     }
// }


// static void Delete ( Entity *entity )
// {
//     COMPONENTS ( entity );

//     SPR_releaseSprite ( sp->sprite );
// }



// Entity const entityEnemy1_tpl = ( Entity const )
// {
//     .Awake   = Awake,
//     .Update  = Update,
//     .Delete  = Delete,

//     .compsSize  = sizeof ( Components ),
//     .components = &(Components) {
//         .rigidbody = {
//             .position = { FIX32(2.1), FIX32(100.2) },
//             .velocity = {
//                 .x = { FIX32(4.24), 0, FIX32(1.5), FIX32(1.5), FIX32(0.1), NULL },
//                 .y = { FIX32(4.2), 0, FIX32(1.5), FIX32(1.5), FIX32(0.1), NULL }
//             }
//         },
//         .sprite = { .sd = &res_sp_enemies_2x2, .attr = TILE_ATTR ( PAL3, 1, 0, 0 ) },
//     }
// };
*/