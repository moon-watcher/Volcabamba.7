#include <genesis.h>

#include "libs/ECS.h"
#include "libs/draw.h"
#include "data/entities.h"
#include "data/managers.h"
#include "data/states.h"
#include "data/systems.h"
#include "../components.h"


static void _enter ( Entity *entity )
{
    PAL_setPalette(PAL0,palette_blue );
    PAL_setPalette(PAL1,palette_grey );
    PAL_setPalette(PAL2,palette_red );
    PAL_setPalette(PAL0,palette_green );


    drawText("enter",3,2 ); waitMs(1000);

    SPR_init ( );

    ///ecsManager()

    // Manager *manEnemies = ecsManager.new();

    Entity *e = ecsEntity ( &entityPlayer1_tpl );
    ecsManagerAdd ( &manPlayers, e );
    //ecs_entity_new ( manEnemies, &entityEnemy1_tpl );



// // por alguna razón está haciendo la suma de velocidades de e y e2 en el imput
//     Entity *e2 = ecsManagerNewEntity ( &manPlayers, &entityPlayer2_tpl );
//     //ecsEntityExec ( disableInput, e2, NULL );



//     //e->exec->setPosition ( e, 30, 40 );
//     //e->exec->setFallara ( e, 30, 40 );
    
    ecsEntityExec ( setPosition, e, FIX32(130), FIX32(3) );
//     ecsEntityExec ( setFallara, e,  130, 3 );
//     // ecsEntityExec ( setPositionFIX32, e, 12 );
    
//     int g = ecsEntityExec ( getInt, e, NULL );
//     drawInt( g, 32,1, 4);
//     int f = ecsEntityExec ( getFalla, e, NULL );
//     drawInt( f, 32,2, 4);
}


static void _update ( Entity *entity )
{
    COMPONENTS(entity);




    // drawText("update",3,3 ); 
        

    // ecsManagerUpdate ( &manPlayers );
    // ecsManagerUpdate ( &manPlayersBullets );
    // // ecsManager_update ( manEnemies );

    // ecsSystemUpdate ( &sysMovement );
    // ecsSystemUpdate ( &sysInput    );
    // ecsSystemUpdate ( &sysSprite   );

    // SPR_update ( );
    // SYS_doVBlankProcess();
    // JOY_update();
}


static void _exit ( Entity *entity )
{
    SPR_end ( ); 
}


State const screenGameloop_State = { _enter, _update, _exit };







// #include <genesis.h>

// #include "libs/ECS.h"
// #include "libs/draw.h"
// #include "data/entities.h"
// #include "data/managers.h"
// #include "data/states.h"
// #include "data/systems.h"
// #include "../components.h"


// static void _enter ( Entity *entity )
// {
//     PAL_setPalette(PAL0,palette_blue );
//     PAL_setPalette(PAL1,palette_grey );
//     PAL_setPalette(PAL2,palette_red );
//     PAL_setPalette(PAL0,palette_green );

//     ecsSystem ( &sysMovement, &system_movement, 160, "sysMovement" );
//     ecsSystem ( &sysInput,    &system_input,      8, "sysInput"    );
//     ecsSystem ( &sysSprite,   &system_sprite,   160, "sysSprite"   );

//     drawText("enter",3,2 ); waitMs(1000); 


//     SPR_init ( );

//     ///ecsManager()

//     // Manager *manEnemies = ecsManager.new();

//     Entity *e = ecsEntity ( &entityPlayer1_tpl );
//     ecsManagerAdd ( &manPlayers, e );
//     //ecs_entity_new ( manEnemies, &entityEnemy1_tpl );



// // // por alguna razón está haciendo la suma de velocidades de e y e2 en el imput
// //     Entity *e2 = ecsManagerNewEntity ( &manPlayers, &entityPlayer2_tpl );
// //     //ecsEntityExec ( disableInput, e2, NULL );



// //     //e->exec->setPosition ( e, 30, 40 );
// //     //e->exec->setFallara ( e, 30, 40 );
    
//     ecsEntityExec ( setPosition, e, FIX32(130), FIX32(3) );
// //     ecsEntityExec ( setFallara, e,  130, 3 );
// //     // ecsEntityExec ( setPositionFIX32, e, 12 );
    
// //     int g = ecsEntityExec ( getInt, e, NULL );
// //     drawInt( g, 32,1, 4);
// //     int f = ecsEntityExec ( getFalla, e, NULL );
// //     drawInt( f, 32,2, 4);
// }


// static void _update ( Entity *entity )
// {
//     COMPONENTS(entity);




//     drawText("update",3,3 ); 
        

//     ecsManagerUpdate ( &manPlayers );
//     ecsManagerUpdate ( &manPlayersBullets );
//     // ecsManager_update ( manEnemies );

//     ecsSystemUpdate ( &sysMovement );
//     ecsSystemUpdate ( &sysInput    );
//     ecsSystemUpdate ( &sysSprite   );

//     SPR_update ( );
//     SYS_doVBlankProcess();
//     JOY_update();
// }


// static void _exit ( Entity *entity )
// {
//     SPR_end ( ); 
// }


// State const screenGameloop_State = { _enter, _update, _exit };