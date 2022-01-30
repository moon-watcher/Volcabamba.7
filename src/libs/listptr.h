#pragma once

typedef void (*listptrFn) (void*);


typedef struct listptrNode
{
	void               *data;
	struct listptrNode *next;
	struct listptrNode *prev;
}
listptrNode;


typedef struct
{
    int          length;
	listptrNode *head;
	listptrFn    freeFn;
}
listptr;


#define listptr_foreach( l, n ) \
    for ( listptrNode *n = l->head; n; n = n ->next )


void         listptr_init    ( listptr *list, listptrFn freeFn );
void         listptr_destroy ( listptr *list );
int          listptr_size    ( listptr *list );
listptrNode *listptr_add     ( listptr *list, void *element );
void         listptr_remove  ( listptr *list, listptrNode *node );
void         listptr_iterate ( listptr *list, listptrFn iterator );
