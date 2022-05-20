#include <genesis.h>

#include "inc/modo.h"
#include "inc/systems.h"
#include "inc/entities.h"
#include "inc/managers.h"
#include "inc/states.h"
#include "../components.h"
#include "../res/logos.h"


static void inputHandler ( Joyreader *j, void *ptr1, void *ptr2 )
{
    Entity* entity = (Entity*) ptr1;
    
    COMPONENTS(entity);

    if ( joy_pressed_start ( j ) )
    {
        modoEntitySetState ( entity, &screenTitle_State );
    }
}





static void enter  ( Entity *entity )
{
    COMPONENTS(entity);
        
    ci->handler = inputHandler;

    SYS_disableInts();
    VDP_drawImage( VDP_BG_A, &res_logo_sega, 0,0);
    SYS_enableInts();



    drawUInt ( timer1->counter,  0, 0, 3 ); drawUInt ( timer1->max, 7, 0, 3 );
    $ComponentTimer.Update ( timer1);
    drawUInt ( timer1->counter,  0, 1, 3 ); drawUInt ( timer1->max, 7, 1, 3 );
};


static void update ( Entity *entity )
{
    COMPONENTS(entity);

    modoSystemAdd ( sysInput, ci     );
    modoSystemAdd ( sysInput, entity );
    modoSystemAdd ( sysTimer, timer1 );

$ComponentTimer.Update ( timer1 );
    
    drawUInt ( timer1->counter, 0, 4, 3 ); drawUInt ( timer1->max, 7, 5, 3 );

    // drawUInt ( timer->max, 20, 0, 4) ;
    // drawUInt ( timer->counter, 20, 1, 4) ;



    // int i = 23;
    // while ( i--)
    // {
    //     $ComponentTimer.Update ( &_timer );
    // drawUInt( _timer.counter, 7,7, 4 );
    // }
    //     // if ( $ComponentTimer.Timeout ( &_timer ))
    //     // {
    //     //     drawText( "acabo", 6,7 );
    //     // }
}


static void exit   ( Entity *entity )
{
    PAL_fadeOut(0,63,10,0);
    VDP_clearPlane(BG_A, 0);
    VDP_clearPlane(BG_B, 0);

}


State const screenLogo_State = { enter, update, exit };