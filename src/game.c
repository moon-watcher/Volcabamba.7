
#include <genesis.h>
#include "mm.h" 





// #include "mm.h" 
// #include "libs/draw.h"
// #include "interfaces/common.h"
// #include "modo/modo.h"


// void showManager ( Manager *manager, int x ) { // Wyrmwood - 
//     managerUpdate(manager);
    
    
//     int y = 0;

//     //Entity *entity = manager->entities;

//     managerForeach ( manager, entity ) {

//         drawInt ( getIntFromEntity(entity), x, y++, 4 );
//     }

//     //drawInt ( manager->length, x, y++, 2 );
// }


// void mainManager()
// {
//     drawUInt( MEM_getFree(), 0,21, 8);


//     Manager *m1 = manager ( NULL );
    
//     Entity *e1, *e2, *e3, *e4; 
//     int y = 0;

//     e1 = managerAdd ( m1, &enemy5_Entity_tpl );
//     e2 = managerAdd ( m1, &enemy5_Entity_tpl );
//     e3 = managerAdd ( m1, &enemy5_Entity_tpl );
//     e4 = managerAdd ( m1, &enemy5_Entity_tpl );

// // listptr_destroy(m1);

//     setIntFromEntity ( e1, 1 );
//     setIntFromEntity ( e2, 22 );
//     setIntFromEntity ( e3, 333 );
//     setIntFromEntity ( e4, 4444 );
//     showManager ( m1, 0 );

//     entityDelete(e2); showManager(m1,  5 );
//     entityDelete(e4); showManager(m1, 10 );
//     entityDelete(e3); showManager(m1, 15 );
//     entityDelete(e1); showManager(m1, 20 );



//     // int v1 = getIntFromEntity ( e1 );

//     // drawInt ( v1, 29, 0, 4 );


//     // entityDelete(e2);

//     managerEnd( m1 );
//     drawUInt( MEM_getFree(), 0,22, 8);

//     while (1)
//     {
//      //   managerUpdate ( &m1 );
//     }
// }






// void ramiro(){

//     SPR_initEx(1200); //SPR_init();

//     manPlayers = manager ( "Players" );
//     manWeapons = manager ( "Weapons" );

//     sysSprite   = system ( &system_sprite,   2 );
//     sysInput    = system ( &system_input,    2 );
//     sysMovement = system ( &system_movement, 2 );
//     sysTimer    = system ( &system_timer,    1 );

//     Entity *const e0 = managerAdd ( manPlayers, &entity_Player_tpl);
//     Entity *const e1 = managerAdd ( manPlayers, &entity_Player_tpl);
//     // Entity *const e2 = managerAdd ( manPlayers, &entity_Player_tpl);
//     // Entity *const e3 = managerAdd ( manPlayers, &entity_Player_tpl);

            
//     entityExec ( InterfaceCommon, enableInput, e0, 0 );
//     entityExec ( InterfaceCommon, setX, e0, 30 );
//     entityExec ( InterfaceCommon, setY, e0, 30 );
//     entityExec ( InterfaceCommon, setX, e1, 70 );
//     entityExec ( InterfaceCommon, setY, e1, 70 );
//     // entityExec ( InterfaceCommon, setX, e2, 130 );
//     // entityExec ( InterfaceCommon, setY, e2, 130 );
//     // entityExec ( InterfaceCommon, setX, e3, 160 );
//     // entityExec ( InterfaceCommon, setY, e3, 160 );

//     while(1){

//         managerUpdate ( manPlayers );
//         managerUpdate ( manWeapons );

//         systemUpdate ( sysMovement );
//         systemUpdate ( sysSprite );
//         systemUpdate ( sysInput );
//         systemUpdate ( sysTimer );

//         Int( MEM_getFree(), 0,0,5);

//         SPR_update();
//         SYS_doVBlankProcess();
//         JOY_update();
//     }
// }



// void listtest(){
//     #include "libs/listptr.h"

//     listptr l;
//     listptr_init ( &l, NULL );

//     int *a = &(int) {1};
//     int *b = &(int) {2};
//     int *c = &(int) {3};

//     listptrNode* n1 = listptr_add( &l, a );
//     listptrNode* n2 = listptr_add( &l, b );
//     listptrNode* n3 = listptr_add( &l, c );


//     listptr_remove ( &l, n3 );
//     listptr_destroy( &l );
    
//     int y = 0;
//     for ( listptrNode const* node = l.head; node; node = node->next )
//     {
//         int *show = node->data;
//         drawInt ( *show, 0, y++, 3 );
//     }
//     y++;

//     listptr_remove ( &l, n1 );
//     for ( listptrNode const* node = l.head; node; node = node->next )
//     {
//         int *show = node->data;
//         drawInt ( *show, 0, y++, 3 );
//     }
//     y++;

//     listptr_remove ( &l, n3 );
//     for ( listptrNode const* node = l.head; node; node = node->next )
//     {
//         int *show = node->data;
//         drawInt ( *show, 0, y++, 3 );
//     }
//     y++;
// }




                            // void main() {
                            //     modo_lists_init     = modo ( NULL );
                            //     modo_lists_managers = modo ( &managerUpdate );
                            //     modo_lists_middle   = modo ( NULL );
                            //     modo_lists_systems  = modo ( &systemUpdate );
                            //     modo_lists_end      = modo ( NULL );

                            //     gameInit(); // the game init function

                            //     while ( 1 ) {
                            //         modoUpdate ( modo_lists_init     );
                            //         modoUpdate ( modo_lists_managers );
                            //         modoUpdate ( modo_lists_middle   );
                            //         modoUpdate ( modo_lists_systems  );
                            //         modoUpdate ( modo_lists_end      );
                            //     }
                            // }


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