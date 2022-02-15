
#include <genesis.h>

#include "libs/ECS.h"
#include "libs/draw.h"
#include "data/entities.h"
#include "data/systems.h"
#include "inc/systems.h"
#include "libs/draw.h"



System const sysMovement_tpl = { .updateFn = &system_movement, .max = 160, .name = "sysMovement" };
System const sysInput_tpl    = { .updateFn = &system_input,    .max = 8,   .name = "sysInput"    };
System const sysSprite_tpl   = { .updateFn = &system_sprite,   .max = 160, .name = "sysSprite"   };

void drawState(char *s)
{
    drawText(s, 0,0);
    waitMs(50);
    drawText( "           ", 0, 0 );
}


void main ( )
{
    sysMovement = ecsSystem ( &sysMovement_tpl );
    sysInput    = ecsSystem ( &sysInput_tpl    );
    sysSprite   = ecsSystem ( &sysSprite_tpl   );


    SPR_init ( );


    Manager manPlayers;
    // Manager *manEnemies = ecsManager.new();

    Entity *e = ecsEntity ( &manPlayers, &entityPlayer1_tpl );
    // ecs_entity_new ( manEnemies, &entityEnemy1_tpl );

    //e->exec->setPositionInt ( e, 30, 40 );
    //e->exec->setFallara ( e, 30, 40 );
    
    ecsEntityExec ( e, setPositionInt, 130, 3 );
    ecsEntityExec ( e, setFallara, 130, 3 );
    ecsEntityExec ( e, setPositionFIX32, 12 );
    int g = ecsEntityExec ( e, getInt, NULL );
    drawInt( g, 32,1, 4);
    int f = ecsEntityExec ( e, getFalla, NULL );
    drawInt( f, 32,2, 4);
    

    while ( 1 )
    {
        ecsManagerUpdate ( &manPlayers );
        // ecsManager_update ( manEnemies );

        ecsSystemUpdate ( sysMovement );
        ecsSystemUpdate ( sysInput    );
        ecsSystemUpdate ( sysSprite   );

        SPR_update ( );
        SYS_doVBlankProcess();
        JOY_update();
    }

    SPR_end ( ); 
}
