#include <genesis.h>

#include "inc/modo.h"
#include "inc/systems.h"
#include "inc/states.h"
#include "../inc.h"
#include "../res/logos.h"


stateDefine ( entity_screen_state_logo,
{ // enter
    COMPS(e);
        
    SYS_disableInts();
    VDP_drawImage ( VDP_BG_A, &res_logo_sega, 0, 0 );
    SYS_enableInts();
    
    ComponentTimer_Init ( timer, 100 );
    VDP_setScreenWidth320();

    systemUse ( sysTimer );
},

{ // update
    COMPS(e);
    systemAdd ( sysTimer, timer );
    
    if ( ComponentTimer_Timeout ( timer  ) )
        entityState ( e, &entity_screen_state_title );
},

{ // exit
    PAL_fadeOut ( 0, 63, 10, 0 );
    VDP_clearPlane ( BG_A, 0 );
    VDP_clearPlane ( BG_B, 0 );
});