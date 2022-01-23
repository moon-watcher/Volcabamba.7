#include <genesis.h>

#include "../libs/ECS.h"
#include "../libs/joyreader.h"
#include "../res/sprites.h"
#include "data/components.h"
#include "data/systems.h"


typedef struct
{
    ComponentRigidbody rigidbody;
    ComponentSprite    sprite;
    ComponentInput     input;
    ComponentAttribute attrs;
}
Components;


#define COMPONENTS(entity)                          \
    Components         *comps = entity->components; \
    ComponentRigidbody *rb    = &comps->rigidbody;  \
    ComponentSprite    *sp    = &comps->sprite;     \
    ComponentPosition  *cp    = &rb->position;      \
    ComponentVelocity  *cv    = &rb->velocity;      \
    ComponentInput     *ci    = &comps->input;      \
    Joyreader          *joy   = &ci->joy;



static void _idle_enter  ( Entity *entity );
static void _idle_update ( Entity *entity );
static void _move_enter  ( Entity *entity );
static void _move_update ( Entity *entity );

static State stateIdle = { "Idle", _idle_enter, _idle_update, NULL };
static State stateMove = { "Move", _move_enter, _move_update, NULL };




////////////////////////////////////////////////////////////////////////////////////////

static void _idle_enter ( Entity *entity )
{
    drawText("entra en idle", 10,1);
}

static void _idle_update ( Entity *entity )
{
    COMPONENTS ( entity );
    //EVENTS ( entity );

    SYSTEM_2 ( sysSprite, sp, cp     );
    SYSTEM_2 ( sysInput,  ci, entity );

    // meter un contador que cuando acaba lanza _move
    //    entity->state = &stateMove;
}

static void _move_enter ( Entity *entity )
{
    drawText("entra en move", 10,1);
}

static void _move_update ( Entity *entity )
{
    COMPONENTS ( entity );
    //EVENTS ( entity );

    SYSTEM_2 ( sysMovement, cp, cv     );
    SYSTEM_2 ( sysSprite,   sp, cp     );
    SYSTEM_2 ( sysInput,    ci, entity );
}


//////////////////////////////////////////////////////////////////////////////////////

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
        ecsEntityState ( entity, &stateIdle );
    }

    if ( joy_active_dir ( joy ) )
    {
        ecsEntityState ( entity, &stateMove );
    }

    if ( joy_pressed_b ( joy ) )
    {
        // create_entity_bullet ( entity, &entityBullet1_tpl );
    }
}



Entity const entityHero1_tpl = ( Entity const )
{
    .Awake  = Awake,
    .Update = Update,
    .Delete = Delete,
    .state  = &stateIdle,

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


// Entity const entityHero2_tpl = ( Entity const )
// {
//     .Awake  = Awake,
//     .Update = Update,
//     .Delete = Delete,

//     .compsSize  = sizeof ( Components ),
//     .components = &(Components) {
//         .rigidbody = {
//             .position = { FIX32(40.1), FIX32(10.2) },
//             .velocity = {
//                 .x = { FIX32(0), 0, FIX32(2.0), FIX32(2.0), FIX32(0.1), NULL },
//                 .y = { FIX32(0), 0, FIX32(2.0), FIX32(2.0), FIX32(0.1), NULL }
//             }
//         },
//         .sprite = { .sd = &res_hero2_sprite, .attr = TILE_ATTR ( PAL2, 1, 0, 0 ) },
//         .input  = { .joy = joyreader2, .handlerFn = &inputHandler },
//         .attrs  = { 0b00000000000000000000000000000000 },
//     }
// };


//https://stackoverflow.com/questions/1647631/c-state-machine-design
//https://ajmmertens.medium.com/why-storing-state-machines-in-ecs-is-a-bad-idea-742de7a18e59
//https://www.codeproject.com/Articles/1275479/State-Machine-Design-in-C
//https://stackoverflow.com/questions/1647631/c-state-machine-design/1647679#1647679
//https://stackoverflow.com/questions/1371460/state-machines-tutorials
//https://www.it-swarm-es.com/es/c%2B%2B/diseno-de-maquina-de-estado-c/968853663/
//https://www.it-swarm.com.ru/ru/c%2B%2B/c-state-design/968853663/amp/
//https://opensource.lely.com/canopen/docs/fsm/
//https://stackoverflow.com/questions/133214/is-there-a-typical-state-machine-implementation-pattern
//https://aticleworld.com/state-machine-using-c/
//https://gist.github.com/ankurs/355708


/*
typedef struct
{
    size_t size;
    void*  p;
}
pointer;

void * my_malloc(size_t s)
{
  size_t * ret = malloc(sizeof(size_t) + s);
  *ret = s;
  return &ret[1];
}

void my_free(void * ptr)
{
  free( (size_t*)ptr - 1);
}

size_t allocated_size(void * ptr)
{
  return ((size_t*)ptr)[-1];
}

int main(int argc, const char ** argv) {
  int * array = my_malloc(sizeof(int) * 3);
  printf("%u\n", allocated_size(array));
  my_free(array);
  return 0;
}
*/



/*
typedef int(*COMPARE)(void*, void*);
Node *getNode(ptrl *list, COMPARE compare , void* data) {
    Node *node = list->head;
    while (node != NULL) {
            if (compare(node->data, data) == 0) {
                return node;
            }
            node = node->next;
        }
    return NULL;
}
*/



/*
static void Update ( Entity *entity )
{
    EntityState *state = &entity->state;
    EntityEvent *event = &entity->event;

    int (*condition)(void*) = event->condition;
    if ( condition  &&  condition ( entity ) )
    {
        state = &event->state;
        state->exec ( entity );
    }
    condition = NULL;


    COMPONENTS(entity);
    Joyreader *joy = ci->joy;
    system_movement_entity ( cp, cv );
    system_sprite_position ( sp, cp );
    system_input_update ( ci );

    if ( joy_released_dir ( joy ) )
    {
        entity->event = eventSto;
    }

    if ( joy_active_dir ( joy ) )
    {
        entity->event = _event_mover;
    }

    if ( joy_pressed_b(joy) )
    {
         create_entity_bullet ( entity, &entityBullet1_tpl );
    }
}
*/