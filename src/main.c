
#include <genesis.h>

#include "libs/ECS.h"
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


void entidades ( )
{

    int return1()
    {
        return 1;
    }
    


    // System const sysMovement_tpl = { .updateFn = &system_movement, .max = 160, .name = "sysMovement" };
    // System const sysInput_tpl    = { .updateFn = &system_input,    .max = 8,   .name = "sysInput"    };
    // System const sysSprite_tpl   = { .updateFn = &system_sprite,   .max = 160, .name = "sysSprite"   };

    System *sysMovement = ecsSystem ( &system_movement, 160, "sysMovement" );
    System *sysInput    = ecsSystem ( &system_input,      8, "sysInput"    );
    System *sysSprite   = ecsSystem ( &system_sprite,   160, "sysSprite"   );


    SPR_init ( );

    ///ecsManager()

    // Manager *manEnemies = ecsManager.new();

    Entity *e = ecsEntity ( &entityPlayer1_tpl );
    ecsManagerAdd ( &manPlayers, e );
    // ecs_entity_new ( manEnemies, &entityEnemy1_tpl );



// por alguna razón está haciendo la suma de velocidades de e y e2 en el imput
    Entity *e2 = ecsManagerNewEntity ( &manPlayers, &entityPlayer2_tpl );
    //ecsEntityExec ( disableInput, e2, NULL );



    //e->exec->setPosition ( e, 30, 40 );
    //e->exec->setFallara ( e, 30, 40 );
    
    ecsEntityExec ( setPosition, e, FIX32(130), FIX32(3) );
    ecsEntityExec ( setFallara, e,  130, 3 );
    // ecsEntityExec ( setPositionFIX32, e, 12 );
    
    int g = ecsEntityExec ( getInt, e, NULL );
    drawInt( g, 32,1, 4);
    int f = ecsEntityExec ( getFalla, e, NULL );
    drawInt( f, 32,2, 4);
    

    while ( 1 )
    {
        ecsManagerUpdate ( &manPlayers );
        ecsManagerUpdate ( &manPlayersBullets );
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

// typedef struct {
//     void *stack[12];
//     unsigned current;
// } pile_t;

// func tal = new ( Entity, template );
// tal()->update();
// $(tal)->update();


// #define $(var) \
//     ({ stak[current++] =var( var )})


void screens ()
{
    ecsSystem ( &sysInput, system_input, 8, "sysInput" );
    
    int i;
    
    ({ i = 0; i; });

    ecsManagerNewEntity ( &manScreens, &screen_Entity_tpl );

    while ( 1 )
    {
        ecsManagerUpdate ( &manScreens );

        ecsSystemUpdate ( &sysInput );

        SYS_doVBlankProcess();
        JOY_update();
    }
}


void main ( )
{
    System *sysMovement = ecsSystem ( &system_movement, 160, "sysMovement" );
    System *sysInput    = ecsSystem ( &system_input,      8, "sysInput"    );
    System *sysSprite   = ecsSystem ( &system_sprite,   160, "sysSprite"   );


    // entidades();
    screens();
}