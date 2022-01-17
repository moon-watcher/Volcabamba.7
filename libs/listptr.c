#include <genesis.h>
#include "listptr.h"


static int const listptrNode_s = sizeof ( listptrNode );


void listptr_init ( listptr *list, listptrFn freeFn )
{
    list->length = 0;
    list->head   = ((void*)0);
    list->freeFn = freeFn;
}


void listptr_destroy ( listptr *list )
{
	listptrNode *node;

	while ( list->head )
	{
		node       = list->head;
		list->head = node->next;

		listptr_remove ( list, node );
	}
}


int listptr_size ( listptr *list )
{
	return list->length;
}


listptrNode *listptr_add ( listptr *list, void *element )
{
	listptrNode *node = malloc ( listptrNode_s );

	node->data       = element;
	node->prev       = ((void*)0);
	node->next       = list->head;

	list->head       = node;
	list->head->prev = node;

	++list->length;

	return node;
}


void listptr_remove ( listptr *list, listptrNode *node )
{
    if ( !list->length )
    {
        return;
    }

    if ( list->freeFn )
    {
        list->freeFn ( node->data );
    }

    if ( node->prev )
    {
        node->prev->next = node->next;
    }
    else
    {
        list->head = node->next;
    }

    if ( node->next )
    {
        node->next->prev = node->prev;
    }

    list->length--;
    free ( node );
}


void listptr_iterate ( listptr *list, listptrFn iterator )
{
    listptr_foreach ( list, node )
    {
        iterator ( node->data );
    }
}


// listptrNode *node = list->head;
// while ( node )
// {
//     iterator ( node->data );
//     node = node->next;
// }