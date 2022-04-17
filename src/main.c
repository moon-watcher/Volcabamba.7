
#include <genesis.h>

#include "modo/modo.h"
#include "libs/draw.h"
#include "inc/entities.h"
#include "inc/systems.h"
#include "inc/managers.h"


void drawState(char *s)
{
    drawText(s, 0,0);
    waitMs(50);
    drawText( "           ", 0, 0 );
}


// void entidades ( )
// {

//     int return1()
//     {
//         return 1;
//     }
    


//     // System const sysMovement_tpl = { .updateFn = &system_movement, .max = 160, .name = "sysMovement" };
//     // System const sysInput_tpl    = { .updateFn = &system_input,    .max = 8,   .name = "sysInput"    };
//     // System const sysSprite_tpl   = { .updateFn = &system_sprite,   .max = 160, .name = "sysSprite"   };

//     System *sysMovement = modoSystem ( &system_movement, 160, "sysMovement" );
//     System *sysInput    = modoSystem ( &system_input,      8, "sysInput"    );
//     System *sysSprite   = modoSystem ( &system_sprite,   160, "sysSprite"   );


//     SPR_init ( );

//     ///modoManager()

//     // Manager *manEnemies = modoManager.new();

//     Entity *e = modoEntity ( &entityPlayer1_tpl );
    
//     manPlayers        = modoManager ();
//     manPlayersBullets = modoManager ();

//     modoManagerAdd ( manPlayers, e );
//     // MODO_entity_new ( manEnemies, &entityEnemy1_tpl );



// // por alguna razón está haciendo la suma de velocidades de e y e2 en el imput
//     Entity *e2 = modoManagerNewEntity ( manPlayers, &entityPlayer2_tpl );
//     //modoEntityExec ( e2, disableInput, NULL );



//     //e->exec->setPosition ( e, 30, 40 );
//     //e->exec->setFallara ( e, 30, 40 );
    
//     modoEntityExec ( e, setPosition, FIX32(130), FIX32(3) );
//     modoEntityExec ( e, setFallara,  130, 3 );
//     // modoEntityExec ( e, setPositionFIX32, 12 );
    
//     int g = modoEntityExec ( e, getInt, NULL );
//     drawInt( g, 32,1, 4);
//     int f = modoEntityExec ( e, getFalla, NULL );
//     drawInt( f, 32,2, 4);
    

//     while ( 1 )
//     {
//         modoManagerUpdate ( manPlayers );
//         modoManagerUpdate ( manPlayersBullets );
//         // modoManager_update ( manEnemies );

//         modoSystemUpdate ( sysMovement );
//         modoSystemUpdate ( sysInput    );
//         modoSystemUpdate ( sysSprite   );

//         SPR_update ( );
//         SYS_doVBlankProcess();
//         JOY_update();
//     }

//     SPR_end ( ); 
// }

// typedef struct {
//     void *stack[12];
//     unsigned current;
// } pile_t;

// func tal = new ( Entity, template );
// tal()->update();
// $(tal)->update();




void screens ()
{
    //modoSystemInit ( sysMovement, &system_movement, 160, "sysMovement" );
    //modoSystemInit ( sysSprite,   &system_sprite,   160, "sysSprite"   );
    modoSystemInit ( sysInput, &system_input, 8, "sysInput" );
    //drawText ( sysInput->name, 0,0 ); waitMs(1000);

    Entity *screen = modo ( Entity );
    modoEntityInit ( screen, &screen_Entity_tpl );

    modoManagerInit ( manScreens );
    drawUInt ( manScreens->entities.length, 10, 0, 4 ); waitMs ( 1000 );
    modoManagerAdd ( manScreens, screen );
        drawUInt ( manScreens->entities.length, 10, 1, 4 ); waitMs ( 1000 );

    

    int p = 0;
    
    while ( 1 )
    {
        modoManagerUpdate ( manScreens );

        //modoSystemUpdate ( sysMovement );
        //modoSystemUpdate ( sysInput );
        //modoSystemUpdate ( sysSprite );

        //SYS_doVBlankProcess();
        //JOY_update();

        //drawText("asd",1,++p); waitMs(111);
    }


    modoSystemDelete ( sysMovement );
    modoSystemDelete ( sysInput );
    modoSystemDelete ( sysSprite );

    modoManagerDelete ( manScreens );
}





void main ( )
{
    sysMovement = modo ( System );
    sysInput    = modo ( System );
    sysSprite   = modo ( System );
    
    while(1)
    {
        screens();
    }
}    




// void main11 ( )
// {
//     sysMovement = modo ( System );
//     sysInput    = modo ( System );
//     sysSprite   = modo ( System );


//     modoSystemInit ( sysMovement, &system_movement, 160, "sysMovement" );
//     modoSystemInit ( sysInput,    &system_input,      8, "sysInput"    );
//     modoSystemInit ( sysSprite,   &system_sprite,   160, "sysSprite"   );
    
//     manScreens  = modo ( Manager );


//     int *a = 1;
//     int *b = 2;
//     int *p1 = &a;
//     int *p2 = &b;

//     modoSystemAdd ( sysMovement, *p1 );
//     modoSystemAdd ( sysMovement, *p2 );

//     while(1)
//     {
//         screens();
//         modoSystemUpdate ( sysMovement );
//         modoSystemUpdate ( sysInput );
//         modoSystemUpdate ( sysSprite );
//         modoSystemUpdate ( manScreens );
//     }
    


    
// //     $(sysMovement)->init ( &system_movement, 144, "sysMovement" );
// //     $(sysMovement)->setUpdateFn ( system_movement );
// //     $(sysMovement)
// //         ->setMax ( 143 )
// //         ->setName ( "vvv" );
    
// //     algo(algo, 2);
// //     $(algo)->tal(2);
// //     modo( )

// // hay una variable que es de tipo system con sus valores y funciones


// //     // entidades();
// }