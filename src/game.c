
#include <genesis.h>
#include "mm.h" 


#include "libs/draw.h"
#include "inc/entities.h"
#include "inc/systems.h"
#include "inc/managers.h"
#include "interfaces/common.h"





// void showManager ( Manager *manager, int x ) {
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


//     Manager *m1 = manager();
    
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

//     SPR_initEx(800); //SPR_init();

//     manPlayers = $->manager->new ( );
//     manWeapons = $->manager->new ( );

//     sysSprite   = $->system->new ( &system_Sprite_tpl   );
//     sysInput    = $->system->new ( &system_Input_tpl    );
//     sysMovement = $->system->new ( &system_Movement_tpl );
//     sysTimer    = $->system->new ( &system_Timer_tpl    );

//     // $m(manPlayers)->add ( &entity_Player_tpl);
//     //  $(manPlayers)->add ( &entity_Player_tpl);
//     Entity *const e0 = $m->add ( manPlayers, &entity_Player_tpl );
//     Entity *const e1 = $->manager->add ( manPlayers, &entity_Player_tpl );
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

//         $->manager->update ( manPlayers );
//         $->manager->update ( manWeapons );

//         $s->update ( sysMovement );
//         $->system->update ( sysSprite );
//         $->system->update ( sysInput );
//         $->system->update ( sysTimer );

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


void screens(){
    

    manScreens = manager();

    managerAdd ( manScreens, &entity_screen );

    // sysSprite   = system ( &system_sprite   );
    // sysMovement = system ( &system_movement );
    sysInput = system ( &system_Input_tpl );
    sysTimer = system ( &system_Timer_tpl );

    while(1) {
        managerUpdate ( manScreens );
        // managerUpdate ( manWeapons );

        // systemUpdate ( sysMovement );
        // systemUpdate ( sysSprite );
        systemUpdate ( sysInput );
        systemUpdate ( sysTimer );

        Int ( MEM_getFree(), 0, 0, 5 );
        
        SYS_doVBlankProcess();
        JOY_update();
    }
    
    managerEnd ( manScreens );
    systemEnd ( sysInput );
    systemEnd ( sysTimer );
}










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









// y dentro de modo_init...
// una manager exclusivo y privado de modo para pasar entre scenas
// la entidad escena debe ser sigleton.
// 
// los bucles están dentro de la escena
// cada escena tiene su bucle de cotrol



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






//modo->s(aaa)->update();
//$s(aaa)->update();

/* 
// #define modoEntityExec(FUNCTION,ENTITY,...)    ({ ENTITY->exec->FUNCTION ? ENTITY->exec->FUNCTION ( ENTITY, __VA_ARGS__ ) : NULL; })

// #define JOY_DIR_NONE    0
// #define JOY_DIR_UP      1
// #define JOY_DIR_DOWN    2
// #define JOY_DIR_LEFT    3
// #define JOY_DIR_RIGHT   4

// #define joy_get_vertical(J,X)          ( joy_##X##_up   ( J ) ? JOY_DIR_UP   : ( joy_##X##_down  ( J ) ? JOY_DIR_DOWN  : JOY_DIR_NONE ) )
// #define joy_get_horizontal(J,X)        ( joy_##X##_left ( J ) ? JOY_DIR_LEFT : ( joy_##X##_right ( J ) ? JOY_DIR_RIGHT : JOY_DIR_NONE ) )

// // #define joy_exec_vertical(J,X,A,B,C)   ( joy_##X##_up   ( J ) ? A            : ( joy_##X##_down  ( J ) ? B             : C            ) )
// // #define joy_exec_horizontal(J,X,A,B,C) ( joy_##X##_left ( J ) ? A            : ( joy_##X##_right ( J ) ? B             : C            ) )

//  #define joy_exec_vertical(J,X,A,B,C) ({   \
//     int ret = JOY_DIR_NONE;                \
//     if ( joy_##X##_up ( J ) ) {            \
//         ret = JOY_DIR_UP;                  \
//         A                                  \
//     } else if ( joy_##X##_down ( J ) ) {   \
//         ret = JOY_DIR_DOWN;                \
//         B                                  \
//     } else {                               \
//         C                                  \
//     }                                      \
//     ret; })

// #define joy_exec_horizontal(J,X,A,B,C) ({  \
//     int ret = JOY_DIR_NONE;                \
//     if ( joy_##X##_left ( J ) ) {          \
//         ret = JOY_DIR_LEFT;                \
//         A                                  \
//     } else if ( joy_##X##_right ( J ) ) {  \
//         ret = JOY_DIR_RIGHT;               \
//         B                                  \
//     } else {                               \
//         C                                  \
//     }                                      \
//     ret; })

*/













// static System  *s_const;
// static Manager *m_const;
// static Entity  *e_const;
// static void    *x_const;

// #define $SS(x)  ({ s_const = x, $s })
// #define $MM(x)  ({ m_const = x, $m })
// #define $EE(x)  ({ s_const = x, $e })

// // #define $SS(x)  ({ (s_const = x), $s })
// // #define $MM(x)  ({ (m_const = x), $m })
// // #define $EE(x)  ({ (s_const = x), $e })

// // #define $SS(x)  ({ (s_const = x); $s; })
// // #define $MM(x)  ({ (m_const = x); $m; })
// // #define $EE(x)  ({ (s_const = x); $e; })

// #define $(x)  ({ (s_const = x); $s; })
// #define $MMm(x)  ({ (m_const = x); $m; })
// #define $EEe(x)  ({ (s_const = x); $e; })


// struct MYMODO_system  *const $S ( System *const x ) {
//     s_const = x;
//     return $s;
// }

// struct MYMODO_manager *const $M ( Manager *const x ) {
//     m_const = x;
//     return $m;
// }

// struct MYMODO_entity  *const $E ( Entity *const x ) {
//     e_const = x;
//     return $e;
// }

// #define $manTal ( { (m_const = manTal ); $m; } )

// // M(manTal)->add( entity  );
// // $manTal->add( entity  );
// // $manTal->new();

// // $$ ( manaasd )->add ( Entity );

// Entity *const addEntityToManager ( Entity const * tpl ) {
//     return managerAdd ( m_const, tpl );
// }