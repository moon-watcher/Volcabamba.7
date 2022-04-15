
#include <genesis.h>

#include "modo/modo.h"
#include "modo/current.h"
#include "libs/draw.h"
#include "data/entities.h"
#include "data/systems.h"
#include "data/managers.h"


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
//     //modoEntityExec ( disableInput, e2, NULL );



//     //e->exec->setPosition ( e, 30, 40 );
//     //e->exec->setFallara ( e, 30, 40 );
    
//     modoEntityExec ( setPosition, e, FIX32(130), FIX32(3) );
//     modoEntityExec ( setFallara, e,  130, 3 );
//     // modoEntityExec ( setPositionFIX32, e, 12 );
    
//     int g = modoEntityExec ( getInt, e, NULL );
//     drawInt( g, 32,1, 4);
//     int f = modoEntityExec ( getFalla, e, NULL );
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




// void screens ()
// {
//     sysInput = modoSystem ( system_input, 8, "sysInput" );
    
//     int i;
    
//     ({ i = 0; i; });

//     modoManagerNewEntity ( manScreens, &screen_Entity_tpl );

//     while ( 1 )
//     {
//         modoManagerUpdate ( manScreens );

//         modoSystemUpdate ( sysInput );

//         SYS_doVBlankProcess();
//         JOY_update();
//     }

//     modoSystemDelete ( sysInput );
// }


void main ( )
{
    sysMovement = modo ( System );
    sysInput    = modo ( System );
    sysSprite   = modo ( System );

    $(sysMovement)->init ( &system_movement, 160, "sysMovement" );
    $(sysInput)->init    ( &system_input,      8, "sysInput"    );
    $(sysSprite)->init   ( &system_sprite,   160, "sysSprite"   );
    

    int *a = NULL;
    $(sysMovement)->add(a);
    //modo->system(asd)->update();

    while(1)
    {
        $(sysMovement)->update();
        $(sysInput)->update();
        $(sysSprite)->update();
    }
    
//     modoSystemInit ( sysMovement, &system_movement, 160, "sysMovement" );

//     manScreens  = modo ( Manager );
//     $S(manScreens)->update();
    
//     $(sysMovement)->init ( &system_movement, 144, "sysMovement" );
//     $(sysMovement)->setUpdateFn ( system_movement );
//     $(sysMovement)
//         ->setMax ( 143 )
//         ->setName ( "vvv" );
    
//     algo(algo, 2);
//     $(algo)->tal(2);
//     modo( )

// hay una variable que es de tipo system con sus valores y funciones


//     // entidades();
//     screens();
}