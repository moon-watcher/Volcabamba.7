
#include <genesis.h>

#include "inc/modo.h"
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
    SPR_init ( );


    Entity *e = modoEntity ( &entityPlayer1_tpl );
    modoManagerAdd ( manPlayers, e );



    // por alguna razón está haciendo la suma de velocidades de e y e2 en el imput
    Entity *e2 = modoEntity ( &entityPlayer2_tpl );

    modoManagerAdd ( manPlayers, e2 );


    //modoEntityExec ( disableInput, e2, NULL );


    modoEntityExec ( setPosition, e, FIX32(130), FIX32(3) );
    modoEntityExec ( setFallara, e,  130, 3 );
    
    int g = modoEntityExec ( getInt, e, NULL );
    int f = modoEntityExec ( getFalla, e, NULL );

    drawInt( g, 32,1, 4);
    drawInt( f, 32,2, 4);
    

    while ( 1 )
    {
        modoManagerUpdate ( manPlayers );
        // modoManagerUpdate ( manPlayersBullets );
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
    Entity *screen = modoEntity ( &screen_Entity_tpl );
    manScreens = modoManager ( );

    modoManagerAdd ( manScreens, screen );
    
    while ( 1 )
    {
        modoManagerUpdate ( manScreens );


        modoSystemUpdate ( sysInput );

        SYS_doVBlankProcess();
        JOY_update();
    }
}


void main ( )
{
    sysMovement = modoSystem ( &system_movement, 160, "sysMovement" );
    sysInput    = modoSystem ( &system_input,      8, "sysInput"    );
    sysSprite   = modoSystem ( &system_sprite,   160, "sysSprite"   );

    manPlayersBullets = modoManager ( );
    manPlayers        = modoManager ( );

    // entidades();
    screens();
}