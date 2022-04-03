#include <genesis.h>

#include "libs/ECS.h"
#include "data/systems.h"
#include "data/states.h"
#include "../components.h"


static void enter ( Entity *entity )
{
    COMPONENTS ( entity );
    
    cv->x.vel = FIX32(2.0);
    cv->x.dir = 1;
    cv->x.maximum = FIX32(2.0);
    cv->x.acceleration = FIX32(2.0);
    cv->x.deceleration = FIX32(0.0);

    cv->y.vel = 10;
    cv->y.dir = 0;
    cv->y.maximum = FIX32(2.0);
    cv->y.acceleration = FIX32(2.0);
    cv->y.deceleration = FIX32(0.0);

    // drawText("dispara", 3,3);
    // waitMs(100);
    // drawText("       ", 3,3);
}


static void update ( Entity *entity )
{
    //     COMPONENTS ( entity );
    
    // cv->x.vel = FIX32(2.0);
    // cv->x.dir = 1;
    // cv->x.maximum = FIX32(2.0);

    // drawText("update", 3,3);
    // waitMs(100);
    // drawText("       ", 3,3);
}


static void exit ( Entity *entity )
{
    //
}


State const PlayerBullet_moveState = { enter, update, exit };