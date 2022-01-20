
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
    typedef struct
    {
        int  a;
        char b;
        int  c;
    }
    Interface_t;

    typedef struct
    {
        int  primero;
        char segundo;
    }
    Implement1_Interface_t;

    typedef struct
    {
        int  primero;
        char segundo;
        int  tercero; 

        // otros
        char cuarto;
    }
    Implement2_Interface_t;

    Interface_t var1 = { 1, 2, 3 };
    Interface_t var2 = { 7, 8, 9 };
    Implement1_Interface_t *i1 = (Interface_t*) &var1;
    Implement2_Interface_t *i2 = (Interface_t*) &var2;

    i2->primero = 11;
    i2->cuarto  = 4;

    drawInt ( i1->primero, 1, 1, 2 ); // 11
    drawInt ( i1->segundo, 1, 2, 2 ); // 2

    drawInt ( i2->primero, 1, 4, 2 ); // 11
    drawInt ( i2->segundo, 1, 5, 2 ); // 8
    drawInt ( i2->tercero, 1, 6, 2 ); // 9
    drawInt ( i2->cuarto,  1, 7, 2 ); // 4

    














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
