#include <genesis.h>

#include "inc/modo.h"
#include "inc/systems.h"
#include "inc/states.h"
#include "../components.h"


static void enter ( Entity *e )
{
    COMPS ( e );
    
    cv->x.vel = FIX32(7.0);
    cv->x.dir = -1;
    cv->x.maximum = FIX32(7.0);
    cv->x.acceleration = FIX32(0.2);
    cv->x.deceleration = FIX32(0.0);

    // cv->y.vel = FIX32(2.0);
    // cv->y.dir = 0;
    // cv->y.maximum = FIX32(2.0);
    // cv->y.acceleration = FIX32(2.0);
    // cv->y.deceleration = FIX32(0.0);

    $ComponentTimer.Init ( timer, 50 );
}


static void update ( Entity *e )
{
    COMPS ( e );
    
    $ComponentTimer.Update ( timer );

    if ( $ComponentTimer.Timeout ( timer ) )
        entityDelete ( e );

    // cv->x.vel = FIX32(2.0);
    // cv->x.dir = 1;
    // cv->x.maximum = FIX32(2.0);

    // drawText("update", 3,3);
    // waitMs(100);
    // drawText("       ", 3,3);
}



State const entity_Weapon_state_move = { enter, update, };

