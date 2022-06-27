
#include <genesis.h>

#include "inc/modo.h"
#include "libs/draw.h"
#include "inc/entities.h"
#include "inc/systems.h"
#include "inc/managers.h"



void showManager ( Manager *manager, int x ) {
    managerUpdate(manager);
    
    
    int y = 0;

    //Entity *entity = manager->entities;

    managerForeach ( manager, entity ) {

        drawInt ( getIntFromEntity(entity), x, y++, 4 );
    }

    //drawInt ( manager->length, x, y++, 2 );
}


void mainManager()
{
    drawUInt( MEM_getFree(), 0,21, 8);


    Manager *m1 = manager();
    
    Entity *e1, *e2, *e3, *e4; 
    int y = 0;

    e1 = managerAdd ( m1, &enemy5_Entity_tpl );
    e2 = managerAdd ( m1, &enemy5_Entity_tpl );
    e3 = managerAdd ( m1, &enemy5_Entity_tpl );
    e4 = managerAdd ( m1, &enemy5_Entity_tpl );

// listptr_destroy(m1);

    setIntFromEntity ( e1, 1 );
    setIntFromEntity ( e2, 22 );
    setIntFromEntity ( e3, 333 );
    setIntFromEntity ( e4, 4444 );
    showManager ( m1, 0 );

    entityDelete(e2); showManager(m1,  5 );
    entityDelete(e4); showManager(m1, 10 );
    entityDelete(e3); showManager(m1, 15 );
    entityDelete(e1); showManager(m1, 20 );



    // int v1 = getIntFromEntity ( e1 );

    // drawInt ( v1, 29, 0, 4 );


    // entityDelete(e2);

    managerEnd( m1 );
    drawUInt( MEM_getFree(), 0,22, 8);

    while (1)
    {
     //   managerUpdate ( &m1 );
    }
}






void ramiro(){

    SPR_init();

    manPlayers = manager();
    manWeapons = manager();

    sysSprite   = system ( &system_sprite,   160, "system sprite"   );
    sysInput    = system ( &system_input,      5, "system input"    );
    sysMovement = system ( &system_movement, 200, "system movement" );
    sysTimer    = system ( &system_timer,    100, "system Timer"    );

    managerAdd ( manPlayers, &entity_Player_tpl);


    while(1){

        managerUpdate ( manPlayers );
        managerUpdate ( manWeapons );

        systemUpdate ( sysMovement );
        systemUpdate ( sysSprite );
        systemUpdate ( sysInput );
        systemUpdate ( sysTimer );

        SPR_update();
        SYS_doVBlankProcess();
        JOY_update();
    }
}


void main()
{
    VDP_setScreenWidth256();

    // mainManager();
    ramiro();

//     listptr l;
//     listptr_init ( &l, NULL );

//     int *a = &(int) {1};
//     int *b = &(int) {2};
//     int *c = &(int) {3};

//     listptrNode* n1 = listptr_add( &l, a );
//     listptrNode* n2 = listptr_add( &l, b );
//     listptrNode* n3 = listptr_add( &l, c );


//     int y = 0;

//     listptr_remove ( &l, n3 );
//     for ( listptrNode *node = l.head; node; node = node->next )
//     {
//         int *show = node->data;
//         drawInt ( *show, 0, y++, 3 );
//     }
//     y++;


    // listptr_remove ( &l, n1 );
    // for ( listptrNode *node = l.head; node; node = node->next )
    // {
    //     int *show = node->data;
    //     drawInt ( *show, 0, y++, 3 );
    // }
    // y++;


    // listptr_remove ( &l, n3 );
    // for ( listptrNode *node = l.head; node; node = node->next )
    // {
    //     int *show = node->data;
    //     drawInt ( *show, 0, y++, 3 );
    // }
    // y++;
}


// void drawState(char *s)
// {
//     drawText(s, 0,0);
//     waitMs(50);
//     drawText( "           ", 0, 0 );
// }


// void entidades ( )
// {
//     SPR_init ( );


//     Entity *e = modoEntity ( &entityPlayer1_tpl );
//     modoManagerAdd ( manPlayers, e );



//     // por alguna razón está haciendo la suma de velocidades de e y e2 en el imput
//     Entity *e2 = modoEntity ( &entityPlayer2_tpl );

//     modoManagerAdd ( manPlayers, e2 );


//     //modoEntityExec ( disableInput, e2, NULL );


//     modoEntityExec ( setPosition, e, FIX32(130), FIX32(3) );
//     modoEntityExec ( setFallara, e,  130, 3 );
    
//     int g = modoEntityExec ( getInt, e, NULL );
//     int f = modoEntityExec ( getFalla, e, NULL );

//     drawInt( g, 32,1, 4);
//     drawInt( f, 32,2, 4);
    

//     while ( 1 )
//     {
//         modoManagerUpdate ( manPlayers );
//         // modoManagerUpdate ( manWeapons );
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


// void screens ()
// {
//     modoManagerEntityAdd( manScreens, &screen_Entity_tpl )


//     Entity *screen = modoEntity ( &screen_Entity_tpl );
//     manScreens = modoManager ( );

//     modoManagerAdd ( manScreens, screen );
    
//     while ( 1 )
//     {
//         modoManagerUpdate ( manScreens );


//         modoSystemUpdate ( sysInput );

//         SYS_doVBlankProcess();
//         JOY_update();
//     }
// }


// void main ( )
// {
//     sysMovement = modoSystem ( &system_movement, 160, "sysMovement" );
//     sysInput    = modoSystem ( &system_input,      8, "sysInput"    );
//     sysSprite   = modoSystem ( &system_sprite,   160, "sysSprite"   );

//     manWeapons = modoManager ( );
//     manPlayers        = modoManager ( );

//     // entidades();
//     screens();

//     Manager man;

    
//     Entity *e = managerAdd ( &man, &screen_Entity_tpl );

//     manager_entity_delete( man, e );


//     Manager *man = manager();
//     Entity *ent = manager_add ( man, &entity_tpl );


//     system()
//     systemUpdate()
//     manager_update()




// }