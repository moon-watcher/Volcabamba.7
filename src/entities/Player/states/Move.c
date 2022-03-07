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
        ecsEntityState ( entity, &Player_idleState );

        return;
    }

    int h = joy_get_horizontal ( j, active );
    int v = joy_exec_vertical  ( j, active,
        {
            SPR_setAnim ( sp->sprite, 1 );
        },
        {
            SPR_setAnim ( sp->sprite, 2 );
        },
        {
            SPR_setAnim ( sp->sprite, 0 );
        }
    );

    cv->x.dir = h ? ( h == JOY_DIR_LEFT ? -1 : +1 ) : 0;
    cv->y.dir = v ? ( v == JOY_DIR_UP   ? -1 : +1 ) : 0;
}


////////////////////////////////////////////////////////////////////////


static void enter ( Entity *entity )
{
    COMPONENTS ( entity );
    
    ci->handler = inputHandler;

    cv->x.vel = 0;
    cv->x.dir = 0;
    cv->x.maximum = FIX32(2.0);
    cv->x.acceleration = FIX32(1.0);
    cv->x.deceleration = FIX32(0.19);
    cv->x.accel_fn =  NULL;

    cv->y.vel = 0;
    cv->y.dir = 0;
    cv->y.maximum = FIX32(2.0);
    cv->y.acceleration = FIX32(1.0);
    cv->y.deceleration = FIX32(0.19);
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

State const Player_moveState = { enter, update, exit };