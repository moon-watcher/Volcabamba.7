#pragma once


typedef struct ModoNode {
	void *data;
	struct ModoNode *next;
	unsigned char count;
}
ModoNode;


typedef struct {
	ModoNode *head;
	int size:8;
}
Modo;


void modo             ( );
void modoAdd          ( Modolist_t, void *const );
void modoUpdate       ( Modo *const );
void modoDelete       ( Modolist_t, void *const );
void modoDeleteForce  ( Modo *const, void *const );
void modoInfoManagers ( Modo *const );
void modoInfoSystems  ( Modo *const );


typedef enum {
	MODOLIST_INIT,
	MODOLIST_SYSTEM,
	MODOLIST_MIDDLE,
	MODOLIST_MANAGER,
	MODOLIST_END,
	MODOLIST_MAX,
}
Modolist_t;

Modo modo_lists [ MODOLIST_MAX ];


// #define modo_addToInit( D )     modoAdd ( &modo_lists_init,     D )
// #define modo_addToManager( D )  modoAdd ( &modo_lists_managers, D )
// #define modo_addToMiddle( D )   modoAdd ( &modo_lists_middle,   D )
// #define modo_addToSystem( D )   modoAdd ( &modo_lists_systems,  D )
// #define modo_addToEnd( D )      modoAdd ( &modo_lists_end,      D )

// #define modo_deleteFromInit( D )     modoDelete ( &modo_lists_init,     D )
// #define modo_deleteFromManager( D )  modoDelete ( &modo_lists_managers, D )
// #define modo_deleteFromMiddle( D )   modoDelete ( &modo_lists_middle,   D )
// #define modo_deleteFromSystem( D )   modoDelete ( &modo_lists_systems,  D )
// #define modo_deleteFromEnd( D )      modoDelete ( &modo_lists_end,      D )
