#include <genesis.h>

#include "libs/ECS.h"
#include "data/systems.h"
#include "../components.h"
#include "../states.h"


static void inputHandler ( Joyreader *j, void *p1, void *p2 )
{
    Entity *entity = (Entity*) p1;

    COMPONENTS ( entity );

    if ( !joy_active_dir ( j ) )
    {
        ecsEntityState ( entity, &idleState );

        return;
    }


    if ( joy_active_left ( j ) )
    {
        cv->x.dir = -1;
    }
    else if ( joy_active_right ( j ) )
    {
        cv->x.dir = +1;
    }
    else
    {
        cv->x.dir = 0;
    }
    
    if ( joy_active_up ( j ) )
    {
        cv->y.dir = -1;
    }
    else if ( joy_active_down ( j ) )
    {
        cv->y.dir = +1;
    }
    else
    {
        cv->y.dir = 0;
    }
}


////////////////////////////////////////////////////////////////////////


static void enter ( Entity *entity )
{
    COMPONENTS ( entity );
    
    ci->handler = inputHandler;

    cv->x.vel = 0;
    cv->x.dir = 0;
    cv->x.maximum = FIX32(2.0);
    cv->x.acceleration = FIX32(2.0);
    cv->x.deceleration = FIX32(0.2);
    cv->x.accel_fn =  NULL;

    cv->y.vel = 0;
    cv->y.dir = 0;
    cv->y.maximum = FIX32(2.0);
    cv->y.acceleration = FIX32(2.0);
    cv->y.deceleration = FIX32(0.2);
    cv->y.accel_fn =  NULL;
}


static void update ( Entity *entity )
{
    //     COMPONENTS(entity);

    // ecsSystemAdd ( sysMovement, cp     );
    // ecsSystemAdd ( sysMovement, cv     );
}


static void exit ( Entity *entity )
{
    //
}


////////////////////////////////////////////////////////////////////////


State const moveState = { enter, update, exit };
// State const moveState = { enter, NULL, NULL };
