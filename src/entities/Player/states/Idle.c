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
    }
}


////////////////////////////////////////////////////////////////////////


static void enter ( Entity *entity )
{
    COMPONENTS(entity);

    ci->handler = inputHandler;
    cv->x.dir = 0;
    cv->y.dir = 0;
}


static void update ( Entity *entity )
{
    //
}


static void exit ( Entity *entity )
{
    //
}


////////////////////////////////////////////////////////////////////////


State const idleState = { enter, update, exit };