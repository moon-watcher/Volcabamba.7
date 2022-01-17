
#include <genesis.h>

#include "../libs/ECS.h"
#include "../libs/draw.h"
#include "data/entities.h"
#include "data/systems.h"

System const sysMovement_tpl = { &system_movement_update, sysMovement_list, sysMovement_max, "sysMovement", 0 };
System const sysInput_tpl    = { &system_input_update,    sysInput_list,    sysInput_max,    "sysInput",    0 };
System const sysSprite_tpl   = { &system_sprite_update,   sysSprite_list,   sysSprite_max,   "sysSprite",   0 };



void main ( )
{
    sysMovement = ecs.system.new ( &sysMovement_tpl );
    sysInput    = ecs.system.new ( &sysInput_tpl    );
    sysSprite   = ecs.system.new ( &sysSprite_tpl   );

    SPR_init ( );


    ECS *e = &ecs;

    Manager *manPlayers = ecs.manager.new();
    Manager *manEnemies = ecs.manager.new();

    e->entity.new ( manPlayers, &entityHero1_tpl );
    ecs.entity.new ( manEnemies, &entityEnemy1_tpl );

    

    while ( 1 )
    {
        ecs.system.init ( sysMovement );
        ecs.system.init ( sysInput    );
        ecs.system.init ( sysSprite   );

        ecs.manager.update ( manEnemies );
        ecs.manager.update ( manPlayers );

        ecs.system.update ( sysMovement );
        ecs.system.update ( sysInput    );
        ecs.system.update ( sysSprite   );

        
        SPR_update ( );
        SYS_doVBlankProcess();
        JOY_update();
    }

    SPR_end ( );
}
