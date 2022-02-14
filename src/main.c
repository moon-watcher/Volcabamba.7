
#include <genesis.h>

#include "libs/ECS.h"
#include "libs/draw.h"
#include "data/entities.h"
#include "data/systems.h"

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


    Manager *manPlayers = ecsManager ( );
    // Manager *manEnemies = ecsManager.new();

    ecsEntity ( manPlayers, &entityPlayer1_tpl );
//     // ecs_entity_new ( manEnemies, &entityEnemy1_tpl );

    while ( 1 )
    {
        ecsManagerUpdate ( manPlayers );
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
