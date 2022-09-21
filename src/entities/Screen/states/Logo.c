#include <genesis.h>

#include "mymodo/mm.h" 
#include "inc/systems.h"
#include "inc/states.h"
#include "../inc.h"
#include "../res/logos.h"


static System *sssss;

defineState ( entity_screen_state_logo,

{ // enter
    SYS_disableInts();
    VDP_drawImage ( VDP_BG_A, &res_logo_sega, 0, 0 );
    SYS_enableInts();
    
    ComponentTimer_Init ( timer, 100 );
    VDP_setScreenWidth320();

    sssss = $s->new ( &system_Timer_tpl );
},

{ // update
    if ( ComponentTimer_Timeout ( timer ) )
        $e->state ( e, &entity_screen_state_title );


    systemAdd ( sssss, timer );
    $s->update ( sssss );

    Int ( MEM_getFree(), 0, 0, 5 );
    
    JOY_update();
    SYS_doVBlankProcess();
},

{ // exit
    PAL_fadeOut ( 0, 63, 10, 0 );
    VDP_clearPlane ( BG_A, 0 );
    VDP_clearPlane ( BG_B, 0 );
    
    $s->end ( sssss );
});