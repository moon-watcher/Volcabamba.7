#include <genesis.h>

#include "mymodo.h" 
#include "inc/systems.h"
#include "inc/states.h"
#include "../inc.h"
#include "../res/logos.h"


static System *sssss;

stateDefine ( entity_screen_state_logo,

{ // enter
    SYS_disableInts();
    VDP_drawImage ( VDP_BG_A, &res_logo_sega, 0, 0 );
    SYS_enableInts();
    
    ComponentTimer_Init ( timer, 100 );
    VDP_setScreenWidth320();

    sssss = system ( &system_Timer_tpl );
},

{ // update
    int exit = 0;

    while ( !exit ) {
        exit = ComponentTimer_Timeout ( timer  );
    
        systemAdd1 ( sssss, timer );
        systemUpdate ( sssss );

        Int ( MEM_getFree(), 0, 0, 5 );
        
        JOY_update();
        SYS_doVBlankProcess();
    }

    entityState ( e, &entity_screen_state_title );
},

{ // exit
    PAL_fadeOut ( 0, 63, 10, 0 );
    VDP_clearPlane ( BG_A, 0 );
    VDP_clearPlane ( BG_B, 0 );
    
    systemEnd ( sssss );
});
















// #include <genesis.h>

// #include "mymodo.h" 
// #include "inc/systems.h"
// #include "inc/states.h"
// #include "../inc.h"
// #include "../res/logos.h"


// System *sssss;

// stateDefine ( entity_screen_state_logo,
// { // enter
//     COMPS(e);
        
//     SYS_disableInts();
//     VDP_drawImage ( VDP_BG_A, &res_logo_sega, 0, 0 );
//     SYS_enableInts();
    
//     ComponentTimer_Init ( timer, 100 );
//     VDP_setScreenWidth320();
    
//     // sysSprite   = system ( &system_sprite   );
//     // sysMovement = system ( &system_movement );
//     // sysInput = system ( &system_Input_tpl );
//     sssss = system ( &system_Timer_tpl );
// },

// { // update
//     COMPS(e);
    
//     while(1) {
//         if ( ComponentTimer_Timeout ( timer  ) )
//             break;
    
//         systemAdd1 ( sssss, timer );

//         // systemUpdate ( sysInput );
//         systemUpdate ( sssss );

//         Int ( MEM_getFree(), 0, 0, 5 );
        
//         JOY_update();
//         SYS_doVBlankProcess();
//     }

//     entityState ( e, &entity_screen_state_title );
// },

// { // exit
//     PAL_fadeOut ( 0, 63, 10, 0 );
//     VDP_clearPlane ( BG_A, 0 );
//     VDP_clearPlane ( BG_B, 0 );

//     // systemEnd ( sysInput );
//     systemEnd ( sssss );
// });