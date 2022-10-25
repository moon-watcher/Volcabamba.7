// #include <genesis.h>

// #include "mm.h" 
// #include "inc/systems.h"
// #include "inc/states.h"
// #include "../inc.h"

#include "mm.h" 
#include "inc.h"
#include "inc/systems.h"
// #include "../inc/states.h"
// #include "../inc/entities.h"
// #include "../inc/managers.h"
// #include "inc/systems.h"
// #include "inc/entities.h"
// #include "inc/managers.h"

defineState ( entity_Weapon_state_move,
{ // enter
    Components          *const C   = e->components;
    ComponentMovement2D *const cm  = &C->movement;
    ComponentSprite     *const sp  = &C->sprite;
    ComponentPosition2D *const pos = &C->pos;
    //ComponentTimer      *ct = &C->timer;

    // ComponentTimer_Init ( ct, 30 );
    ComponentSprite_Init ( sp, pos->x.rounded, pos->y.rounded );
    //ComponentSprite_InitEx ( sp, pos->x.rounded, pos->y.rounded );
},

{ }, // update


{ // exit
    systemAdd ( sysSprite,   sp );
    systemAdd ( sysSprite,   pos );
    systemAdd ( sysMovement, pos );
    systemAdd ( sysMovement, movement );
    systemAdd ( sysTimer,    timer );

    if ( pos->x.rounded > screenWidth  ||  pos->x.rounded < - 16 )
        entityDelete ( e );


    // if ( ComponentTimer_Timeout ( timer ) )
    //     entityDelete ( e );
});





   
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