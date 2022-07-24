#pragma once

typedef void (*hvlistFn) (void*);


typedef struct histnode
{
	void *data;
	struct histnode *next;
	//int counter;
}
histnode;


typedef struct
{
	histnode *head;
	void (*update)();
}
histlist;



histlist *hist        ( void (*)() );
void      hist_add    ( histlist *const, void *const );
void      hist_update ( histlist *const );

#define hist_foreach( l, n ) \
    for ( histnode *n = l->head; n; n = n->next )
	