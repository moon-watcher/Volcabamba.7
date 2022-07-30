#pragma once

//typedef void (*hvlistFn) (void*);


typedef struct modoNode {
	void *data;
	struct modoNode *next;
	unsigned char count;
}
modoNode;


typedef struct {
	modoNode *head;
	void (*update)();
	unsigned char size;
}
modoList;



modoList *modo             ( void (*)() );
void      modoAdd          ( modoList *const, void *const );
void      modoUpdate       ( modoList *const );
void      modoDelete       ( modoList *const, void *const );
void      modoDeleteForce  ( modoList *const, void *const );
void      modoInfoManagers ( modoList *const );
void      modoInfoSystems  ( modoList *const );

#define modoForeach( l, n ) \
    for ( modoNode *n = l->head; n; n = n->next )
	