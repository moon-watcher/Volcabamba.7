#pragma once


typedef struct ModoNode {
	void *data;
	struct ModoNode *next;
	unsigned char count;
}
ModoNode;


typedef struct {
	ModoNode *head;
	int size;
}
Modo;


void modo               ( );
void modo_addInit       ( void *const );
void modo_addManager    ( void *const );
void modo_addSystem     ( void *const );
void modo_addEnd        ( void *const );
void modo_deleteInit    ( void *const );
void modo_deleteManager ( void *const );
void modo_deleteSystem  ( void *const );
void modo_deleteEnd     ( void *const );


// #pragma once


// typedef struct Modo {
// 	void *data;
// 	struct Modo *next;
// }
// Modo;

// void modo               ( );
// void modo_addInit       ( void *const );
// void modo_addManager    ( void *const );
// void modo_addSystem     ( void *const );
// void modo_addEnd        ( void *const );
// void modo_deleteInit    ( void *const );
// void modo_deleteManager ( void *const );
// void modo_deleteSystem  ( void *const );
// void modo_deleteEnd     ( void *const );
