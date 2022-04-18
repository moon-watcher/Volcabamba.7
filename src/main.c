
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


void entidades ( )
{

    int return1()
    {
        return 1;
    }

    sysMovement = modoSystem ( &system_movement, 160, "sysMovement" );
    sysInput    = modoSystem ( &system_input,      8, "sysInput"    );
    sysSprite   = modoSystem ( &system_sprite,   160, "sysSprite"   );


    SPR_init ( );


    Entity *e = modoEntity ( &entityPlayer1_tpl );
    modoManagerAdd ( manPlayers, e );
    // modo_entity_new ( manEnemies, &entityEnemy1_tpl );



// por alguna razón está haciendo la suma de velocidades de e y e2 en el imput
    Entity *e2 = modoEntity ( &entityPlayer2_tpl );

    modoManagerAdd ( manPlayers, e2 );


    //modoEntityExec ( disableInput, e2, NULL );



    //e->exec->setPosition ( e, 30, 40 );
    //e->exec->setFallara ( e, 30, 40 );
    
    modoEntityExec ( setPosition, e, FIX32(130), FIX32(3) );
    modoEntityExec ( setFallara, e,  130, 3 );
    // modoEntityExec ( setPositionFIX32, e, 12 );
    
    int g = modoEntityExec ( getInt, e, NULL );
    drawInt( g, 32,1, 4);
    int f = modoEntityExec ( getFalla, e, NULL );
    drawInt( f, 32,2, 4);
    

    while ( 1 )
    {
        modoManagerUpdate ( manPlayers );
        modoManagerUpdate ( manPlayersBullets );
        // modoManager_update ( manEnemies );

        modoSystemUpdate ( sysMovement );
        modoSystemUpdate ( sysInput    );
        modoSystemUpdate ( sysSprite   );

        SPR_update ( );
        SYS_doVBlankProcess();
        JOY_update();
    }

    SPR_end ( ); 
}


void screens ()
{
    // modoManagerNewEntity ( manScreens, &screen_Entity_tpl );

    // while ( 1 )
    // {
    //     modoManagerUpdate ( manScreens );

    //     modoSystemUpdate ( sysInput );

    //     SYS_doVBlankProcess();
    //     JOY_update();
    //}
}


void main ( )
{
    sysMovement = modoSystem ( &system_movement, 160, "sysMovement" );
    sysInput    = modoSystem ( &system_input,      8, "sysInput"    );
    sysSprite   = modoSystem ( &system_sprite,   160, "sysSprite"   );

    manScreens        = modoManager();
    manPlayersBullets = modoManager();
    manPlayers        = modoManager();

    entidades();
    //screens();
}