#include <genesis.h>

#include "inc/modo.h"
#include "inc/systems.h"
#include "inc/states.h"
#include "../inc.h"
#include "../res/logos.h"


static void inputHandler ( Joyreader *const j, Entity *const e ) {
    COMPS(e);

    if ( joy_pressed_start ( j ) )
        entityState ( e, &entity_screen_state_gameloop );
}


stateDefine ( entity_screen_state_title,
{ // enter
    COMPS(e);
        
    input->handler = inputHandler;

    SYS_disableInts();
    VDP_drawImage ( VDP_BG_A, &res_logo_sega, 10,20);
    SYS_enableInts();
    
    VDP_setScreenWidth256();
},

{ // update
    COMPS(e);

    systemAdd2 ( sysInput, input, e );
},

{ // exit
    PAL_fadeOut(0,63,10,0);
    VDP_clearPlane(BG_A, 0);
    VDP_clearPlane(BG_B, 0);
});