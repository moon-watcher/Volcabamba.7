#include <genesis.h>

#include "inc/modo.h"
#include "inc/systems.h"
#include "inc/states.h"
#include "inc/managers.h"
#include "inc/entities.h"
#include "../inc.h"
#include "interfaces/common.h"



stateDefine ( entity_screen_state_gameloop,
{ // enter
    COMPS(e);
        
    PAL_setPalette(PAL0,palette_blue );
    PAL_setPalette(PAL1,palette_grey );
    PAL_setPalette(PAL2,palette_red );
    PAL_setPalette(PAL0,palette_green );

    SPR_initEx(600);
    VDP_setScreenWidth256();

    manPlayers = manager ( "Players" );
    manWeapons = manager ( "Weapons" );

    sysSprite   = system ( &system_sprite   );
    sysMovement = system ( &system_movement );

    Entity *const e0 = managerAdd ( manPlayers, &entity_Player_tpl );
    Entity *const e1 = managerAdd ( manPlayers, &entity_Player_tpl );
            
    entityExec ( InterfaceCommon, enableInput, e0, 0 );
    entityExec ( InterfaceCommon, setX, e0, 30 );
    entityExec ( InterfaceCommon, setY, e0, 30 );
    entityExec ( InterfaceCommon, setX, e1, 0 );
    entityExec ( InterfaceCommon, setY, e1, 70 );


    modoAdd ( managers, manPlayers );
    modoAdd ( managers, manWeapons );
    
    modoAdd ( systems, sysMovement );
    modoAdd ( systems, sysSprite );

    SPR_init();

    //listpstr_insertBefore ( end_functions, &SPR_update, &SYS_doVBlankProcess );
    // listpstr_moveBefore ( functions, &SPR_update, &SYS_doVBlankProcess );
    modoAdd ( end_functions, &SPR_update );
},

{ // update
    COMPS(e);

  
        Int ( MEM_getFree(), 2, 2, 5 );


        // SPR_update();
        // SYS_doVBlankProcess();
        // JOY_update();
    //}
},

{ // exit
    // listprt_remove ( functions, &SPR_update );
    // listprt_remove ( functions, &SYS_doVBlankProcess );

    // modoRemove ( systems, sysMovement );
    // modoRemove ( systems, sysSprite );

    // modoRemove ( managers, manWeapons );
    // modoRemove ( managers, manPlayers );


    managerEnd ( manPlayers );
    managerEnd ( manWeapons );
    
    SPR_end();

    systemEnd ( sysSprite );
    systemEnd ( sysMovement );
    systemEnd ( sysInput );


    PAL_fadeOut(0,63,10,0);
    VDP_clearPlane(BG_A, 0);
    VDP_clearPlane(BG_B, 0);
});





// // #include <genesis.h>

// // #include "inc/modo.h"
// // #include "libs/draw.h"
// // #include "inc/entities.h"
// // #include "inc/managers.h"
// // #include "inc/states.h"
// // #include "inc/systems.h"
// // #include "../components.h"


// // static void _enter ( Entity *entity )
// // {
// //     PAL_setPalette(PAL0,palette_blue );
// //     PAL_setPalette(PAL1,palette_grey );
// //     PAL_setPalette(PAL2,palette_red );
// //     PAL_setPalette(PAL0,palette_green );

// //     modoSystem ( &sysMovement, &system_movement, 160, "sysMovement" );
// //     modoSystem ( &sysInput,    &system_input,      8, "sysInput"    );
// //     modoSystem ( &sysSprite,   &system_sprite,   160, "sysSprite"   );

// //     drawText("enter",3,2 ); waitMs(1000); 


// //     SPR_init ( );

// //     ///modoManager()

// //     // Manager *manEnemies = modoManager.new();

// //     Entity *e = modoEntity ( &entityPlayer1_tpl );
// //     modoManagerAdd ( &manPlayers, e );
// //     //modo_entity_new ( manEnemies, &entityEnemy1_tpl );



// // // // por alguna razón está haciendo la suma de velocidades de e y e2 en el imput
// // //     Entity *e2 = modoManagerNewEntity ( &manPlayers, &entityPlayer2_tpl );
// // //     //modoEntityExec ( disableInput, e2, NULL );



// // //     //e->exec->setPosition ( e, 30, 40 );
// // //     //e->exec->setFallara ( e, 30, 40 );
    
// //     modoEntityExec ( setPosition, e, FIX32(130), FIX32(3) );
// // //     modoEntityExec ( setFallara, e,  130, 3 );
// // //     // modoEntityExec ( setPositionFIX32, e, 12 );
    
// // //     int g = modoEntityExec ( getInt, e, NULL );
// // //     drawInt( g, 32,1, 4);
// // //     int f = modoEntityExec ( getFalla, e, NULL );
// // //     drawInt( f, 32,2, 4);
// // }


// // static void _update ( Entity *entity )
// // {
// //     COMPONENTS(entity);




// //     drawText("update",3,3 ); 
        

// //     modoManagerUpdate ( &manPlayers );
// //     modoManagerUpdate ( &manWeapons );
// //     // modoManager_update ( manEnemies );

// //     modoSystemUpdate ( &sysMovement );
// //     modoSystemUpdate ( &sysInput    );
// //     modoSystemUpdate ( &sysSprite   );

// //     SPR_update ( );
// //     SYS_doVBlankProcess();
// //     JOY_update();
// // }


// // static void _exit ( Entity *entity )
// // {
// //     SPR_end ( ); 
// // }


// // State const screenGameloop_State = { _enter, _update, _exit };