
#include <genesis.h>

#include "libs/ECS.h"
#include "libs/draw.h"
#include "data/entities.h"
#include "data/systems.h"

System sysMovement_tpl = { &system_movement_update, sysMovement_list, sysMovement_max, "sysMovement", 0 };
System sysInput_tpl    = { &system_input_update,    sysInput_list,    sysInput_max,    "sysInput",    0 };
System sysSprite_tpl   = { &system_sprite_update,   sysSprite_list,   sysSprite_max,   "sysSprite",   0 };


drawState(char *s)
{
    drawText(s, 0,0);
    // waitMs(5);
    // drawText( "           ", 0, 0 );
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
        ecsSystemInit ( sysMovement );
        ecsSystemInit ( sysInput    );
        ecsSystemInit ( sysSprite   );

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
