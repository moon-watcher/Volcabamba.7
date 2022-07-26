#pragma once

//typedef void (*hvlistFn) (void*);


typedef struct histnode {
	void *data;
	struct histnode *next;
	unsigned char count;
}
histnode;


typedef struct {
	histnode *head;
	void (*update)();
	unsigned char size;
}
histlist;



histlist *hist              ( void (*)() );
void      hist_add          ( histlist *const, void *const );
void      hist_update       ( histlist *const );
void      hist_delete       ( histlist *const, void *const );
void      hist_delete_force ( histlist *const, void *const );
void      hist_managers     ( histlist *const );
void      hist_systems      ( histlist *const );

#define hist_foreach( l, n ) \
    for ( histnode *n = l->head; n; n = n->next )
	