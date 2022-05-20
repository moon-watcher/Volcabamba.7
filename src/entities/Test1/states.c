#include <genesis.h>

#include "inc/modo.h"
#include "inc/systems.h"
#include "inc/entities.h"
#include "inc/managers.h"
#include "inc/states.h"
#include "components.h"





static void inputHandler ( Joyreader *j, void *ptr1, void *ptr2 )
{
    Entity* entity = (Entity*) ptr1;
    COMPONENTS(entity);


    // if ( joy_pressed_dir ( j ) )
    // {
    //     modoEntitySetState ( entity, &Player_moveState );
    // }

    // if ( joy_pressed_a ( j ) )
    // {
    //     drawText ( "dispara", 4, 3 );        
    //     entity_PlayerBullet_create ( FIX32(cp->x), FIX32(cp->y) );
    // }

    // if ( joy_pressed_c ( j ) )
    // {
    //     drawText ( "muere", 4, 4 );
    //     modoEntitySetState ( entity, &Player_dieState );
    // }
}









static void inputHandlerDos ( Joyreader *j, void *p1, void *p2 )
{
    Entity *entity = (Entity*) p1;

    COMPONENTS ( entity );

    // if ( !joy_active_dir ( j ) )
    // {
    //     modoEntitySetState ( entity, &Player_idleState );

    //     return;
    // }

    // int h = joy_get_horizontal ( j, active );
    // int v = joy_exec_vertical  ( j, active,
    //     {
    //         SPR_setAnim ( sp->sprite, 1 );
    //     },
    //     {
    //         SPR_setAnim ( sp->sprite, 2 );
    //     },
    //     {
    //         SPR_setAnim ( sp->sprite, 0 );
    //     }
    // );

    // cv->x.dir = h ? ( h == joydir.left ? -1 : +1 ) : 0;
    // cv->y.dir = v ? ( v == joydir.up   ? -1 : +1 ) : 0;
}


////////////////////////////////////////////////////////////////////////



static void enter_uno ( Entity *entity )
{
    COMPONENTS(entity);

    // ci->handler = NULL;
    // SPR_setAnim ( sp->sprite, 3 );
}


static void update_uno ( Entity *entity )
{
    //
}


static void exit_uno ( Entity *entity )
{
    //
}






static void enter_dos ( Entity *entity )
{
    COMPONENTS ( entity );
    
    // ci->handler = inputHandlerDos;

    // cv->x.vel = 0;
    // cv->x.dir = 0;
    // cv->x.maximum = FIX32(2.0);
    // cv->x.acceleration = FIX32(1.0);
    // cv->x.deceleration = FIX32(0.19);
    // cv->x.accel_fn =  NULL;

    // cv->y.vel = 0;
    // cv->y.dir = 0;
    // cv->y.maximum = FIX32(2.0);
    // cv->y.acceleration = FIX32(1.0);
    // cv->y.deceleration = FIX32(0.19);
    // cv->y.accel_fn =  NULL;
}


static void update_dos ( Entity *entity )
{
    //     COMPONENTS(entity);

    // modoSystemAdd ( sysMovement, cp     );
    // modoSystemAdd ( sysMovement, cv     );
}


static void exit_dos ( Entity *entity )
{
    //
}






static void enter_tres ( Entity *entity )
{
    COMPONENTS(entity);

    // ci->handler = inputHandler;
    // cv->x.dir = 0;
    // cv->y.dir = 0;
    // SPR_setAnim ( sp->sprite, 0 );
}


static void update_tres ( Entity *entity )
{
    //
}


static void exit_tres ( Entity *entity )
{
    //
}


State const Test1_unoState  = { enter_uno,  update_uno,  exit_uno  };
State const Test1_dosState  = { enter_dos,  update_dos,  exit_dos  };
State const Test1_tresState = { enter_tres, update_tres, exit_tres };