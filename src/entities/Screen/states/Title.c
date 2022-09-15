#include <genesis.h>

#include "mymodo.h" 
#include "inc/systems.h"
#include "inc/states.h"
#include "../inc.h"
#include "../res/logos.h"


static System *ssss;

static void inputHandler ( Joyreader *const j, Entity *const e ) {
    COMPS(e);

    if ( joy_pressed_start ( j ) )
        $e->state ( e, &entity_screen_state_gameloop );
}


stateDefine ( entity_screen_state_title,

{ // enter
    input->handler = inputHandler;

    SYS_disableInts();
    VDP_drawImage ( VDP_BG_A, &res_logo_sega, 10,20);
    SYS_enableInts();
    
    VDP_setScreenWidth256();

    ssss = $s->new ( &system_Input_tpl );
},

{ // update
    systemAdd2 ( ssss, input, e );
    // systemAdd ( ssss, (void *const[]) { input, e, 0 } );
    $s->update ( ssss );

    JOY_update();
    SYS_doVBlankProcess();
},

{ // exit
    PAL_fadeOut(0,63,10,0);
    VDP_clearPlane(BG_A, 0);
    VDP_clearPlane(BG_B, 0);

    $s->end ( ssss );
});