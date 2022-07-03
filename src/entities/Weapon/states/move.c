#include <genesis.h>

#include "inc/modo.h"
#include "inc/systems.h"
#include "inc/states.h"
#include "../components.h"



static void enter ( Entity *const e ) {
    Components          *C  = e->components;
    ComponentMovement2D *cm = &C->movement;
    //ComponentTimer      *ct = &C->timer;

    // ComponentTimer_Init ( ct, 30 );
}


static void update ( Entity *const e ) {
    COMPS ( e );

    // if ( ComponentTimer_Timeout ( timer ) )
    //     entityDelete ( e );
}


State const entity_Weapon_state_move = { enter, update, };
// State const entity_Weapon_state_move = { 0 };




   
    //dx->dir = -1;
    //ComponentMovement_DirectionX ( cv, -1 );

    // cv->x.vel = FIX32(7.0);
    // cv->x.maximum = FIX32(7.0);
    // cv->x.acceleration = FIX32(0.2);
    // cv->x.deceleration = FIX32(0.0);

    // cv->y.vel = FIX32(2.0);
    // cv->y.dir = 0;
    // cv->y.maximum = FIX32(2.0);
    // cv->y.acceleration = FIX32(2.0);
    // cv->y.deceleration = FIX32(0.0);

    


    //ComponentMovement_DirectionX ( cv, 0 );
    //ComponentTimer_Update ( timer );


        //entityDelete ( e );
       // C->vel.x.dir = 0;
        
       // if ( ! C->vel.x.vel )


       //ComponentMovement_DirectionX ( vx, 0 ); // entityDelete ( e );

    // cv->x.vel = FIX32(2.0);
    // cv->x.dir = 1;
    // cv->x.maximum = FIX32(2.0);

    // drawText("update", 3,3);
    // waitMs(100);
    // drawText("       ", 3,3);