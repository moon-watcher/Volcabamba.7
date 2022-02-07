#include <genesis.h>

#include "libs/ECS.h"
#include "data/systems.h"
#include "../components.h"
#include "../states.h"


static void inputHandler ( Joyreader *joy, void *ptr1, void *ptr2 )
{
    Entity *entity = (Entity*) ptr1;
    
    if ( joy_active_dir ( joy ) )
    {
        drawText("active  ", 10, 23 );
    }

    if ( joy_released_dir ( joy ) )
    {
        ecsEntityState ( entity, &idleState );
        drawText("released", 10, 23 );
    }
}


////////////////////////////////////////////////////////////////////////


static void enter ( Entity *entity )
{
    drawText("move_enter",2,0);
    COMPONENTS ( entity );
    
    ci->handler = inputHandler;

    cv->x.vel = FIX32(3);
    cv->x.dir = 0;
    cv->x.maximum = FIX32(1.5);
    cv->x.acceleration = FIX32(1.5);
    cv->x.deceleration = FIX32(0.1);
    cv->x.accel_fn =  NULL;

    cv->y.vel = FIX32(3);
    cv->y.dir = 0;
    cv->y.maximum = FIX32(1.5);
    cv->y.acceleration = FIX32(1.5);
    cv->y.deceleration = FIX32(0.1);
    cv->y.accel_fn =  NULL;
}


static void update ( Entity *entity )
{
    drawText("move_update",2,1);
}


static void exit ( Entity *entity )
{
    //
}


////////////////////////////////////////////////////////////////////////


State const moveState = { enter, update, exit };
