#include <genesis.h>

#include "libs/ECS.h"
#include "data/systems.h"
#include "../components.h"
#include "../states.h"


static void inputHandler ( Joyreader *joy, void *ptr1, void *ptr2 )
{
    Entity* entity = (Entity*) ptr1;

    if ( joy_pressed_dir ( joy ) )
    {
        ecsEntityState ( entity, &moveState );
        drawText("pressed ", 10, 23 );
    }
}


////////////////////////////////////////////////////////////////////////


static void enter ( Entity *entity )
{
    COMPONENTS(entity);

    ci->handler = inputHandler;
    //cv = NULL;
}


static void update ( Entity *entity )
{
    drawText("idle_update",2,1);
}


static void exit ( Entity *entity )
{
    //
}


////////////////////////////////////////////////////////////////////////


State const idleState = { enter, update, exit };


// al cambiar una entidad de *monoestado debe haber una transción 

// debe hacer un estado CREATE que inicializa los sprites y todo, y una vez ejecutado,
// pasa al estado indicado.
// Al cambiar de monoestado no será necesario reinicializar el sprite, pero habrá que 
// hacer una transicón entre estados para solo volcar los datos necesarios y no 
// volver a crear el sprite
//
// además 


// Entity const entityPlayerIdle_tpl = //( Entity )
// {
//     .Awake  = Awake,
//     .Update = Update,
//     .Delete = Delete,

//     .compsSize  = sizeof ( Components ),
//     .components = &(Components) {
//         .rigidbody = {
//             .position = { FIX32(2.1), FIX32(100.2) },
//             .velocity = {
//                 .x = { FIX32(6), 0, FIX32(1.5), FIX32(1.5), FIX32(0.1), NULL },
//                 .y = { FIX32(3), 0, FIX32(1.5), FIX32(1.5), FIX32(0.1), NULL }
//             }
//         },
//         .sprite = { .sd = &res_hero1_sprite, .attr = TILE_ATTR ( PAL3, 1, 0, 0 ) },
//         .input  = { .handlerFn = inputHandler },
//         .attrs  = { 0b00000000000000000000000000000000 },
//     }
// };


