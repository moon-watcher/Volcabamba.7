#include <genesis.h>
#include "hist.h"


// static int const hvlistNode_s = sizeof(hvlistNode);

// http://taggedwiki.zubiaga.org/new_content/a0aaf6287ad03103f81016980041de78



static histnode* _create ( void* data ) {
    histnode *node = malloc ( sizeof ( histnode ) );
    
    node->data = data;
    node->next = NULL;

    return node;
}



histlist *hist ( void (*update)() ) {
    histlist *h = malloc ( sizeof ( histlist ) );

    h->head = NULL;
    h->update = update;

    return h;
}


void hist_add ( histlist *const h, void *const data ) {

    if ( !h->head ) {
        h->head = _create ( data );
        return;
    }

    histnode *last = h->head;

    hist_foreach ( h, node ) {
        if ( node->data == data )
            return;

        last = node;
    }

    last->next = _create ( data );
}


void hist_update ( histlist *const h ) {
    void* (*update)() = h->update ? h->update : NULL;

    if ( update )
        hist_foreach ( h, node )
            update ( node->data );

    else
        hist_foreach ( h, node )
            ( (void(*)()) node->data ) ( );
}







//     histnode *last = h->head;
//     histnode *node = h->head;
//     histnode *new = malloc ( sizeof ( histnode ) );

//     new->data = data;
//     new->next = NULL;
//     new->counter = 1;

//     //if head is NULL, it is an empty list
//     if ( !h->head ) {
//         histnode *new = malloc ( sizeof ( histnode ) );
        
//         new->data    = data;
//         new->next    = NULL;
//         new->counter = 1;

//          h->head = new;
//     }
//     else {
//         while ( node ) {
//             if ( node->data == data ) {
//                 ++node->counter;
//                 return;
//             }

//             last = node;
//             node = node->next;
//         }
        
//         ++last->counter;
//     }



//     if ( !h->head )
//         h->head = malloc ( sizeof ( histnode ) );


//     histnode *last = h->head;
//     histnode *node = h->head;

//     while ( node ) {
//         if ( node->data == data ) {
//             ++node->counter;
//             return;
//         }

//         last = node;
//         node = node->next;
//     }

//     histnode *new = malloc ( sizeof ( histnode ) );

//     new->data    = data;
//     new->next    = NULL;
//     new->counter = 1;
//     if ( !last )
//         last = new;
//     else
//         last->next = new;
// }







// Forwards

//     node : = list.firstNode while node ≠ null<do something with node.data>
//                  node : = node.next

//                               Backwards

//                                   node : = list.lastNode while node ≠ null<do something with node.data>
//                                                node : = node.prev

                                                        
// void hvlist_insertAfter(hvlist * list, hvlistNode *node, hvlistNode *newNode)
// {
//     newNode->prev = node;
//     newNode->next = node->next;

//     if (!node->next)
//         list->tail = newNode;
//     else
//         node->next->prev = newNode;

//     node->next = newNode;
//     ++list->size;
// }

// void hvlist_insertBefore(hvlist *list, hvlistNode *node, hvlistNode *newNode)
// {
//     newNode->prev = node->prev;
//     newNode->next = node;

//     if (!node->prev)
//         list->head = newNode;
//     else
//         node->prev->next = newNode;

//     node->prev = newNode;
//     ++list->size;
// }

// void hvlist_insertBeginning(hvlist *list, hvlistNode *newNode)
// {
//     if (!list->head)
//     {
//         list->head = newNode;
//         list->tail = newNode;
//         newNode->prev = NULL;
//         newNode->next = NULL;
//         ++list->size;
//     }
//     else
//         hvlist_insertBefore(list, list->head, newNode);
// }

// void hvlist_insertEnd(hvlist *list, hvlistNode *newNode)
// {
//     if (!list->head)
//         hvlist_insertBeginning(list, newNode);
//     else
//         hvlist_insertAfter(list, list->head, newNode);
// }

// void hvlist_remove(hvlist *list, hvlistNode *node)
// {
//     if (!(list->size && list->head && node))
//         return;

//     if (!node->prev)
//         list->head = node->next;
//     else
//         node->prev->next = node->next;

//     if (!node->next)
//         list->tail = node->prev;
//     else
//         node->next->prev = node->prev;

//     free(node);

//     --list->size;
// }




// void hvlist_destroy(hvlist *list)
// {
//     hvlist_foreach(list, node)
//         hvlist_remove(list, node);
// }

// hvlistNode *hvlist_add(hvlist *list, void *element)
// {
//     hvlistNode *node = malloc(hvlistNode_s);

//     node->data = element;
//     node->prev = ((void *)0);
//     node->next = list->head;

//     if (list->head)
//         list->head->prev = node;

//     list->head = node;
//     ++list->length;

//     return node;
// }

// void hvlist_removesss(hvlist *list, hvlistNode *node)
// {
//     if (!(list->length && list->head && node))
//         return;

//     if (list->freeFn)
//         list->freeFn(node->data);

//     if (list->head == node)
//         list->head = node->next;

//     if (node->next)
//         node->next->prev = node->prev;

//     if (node->prev)
//         node->prev->next = node->next;

//     --list->length;
//     free(node);
// }

// void hvlist_iterate(hvlist *list, hvlistFn iterator)
// {
//     hvlist_foreach(list, node)
//         iterator(node->data);
// }

// // hvlistNode *node = list->head;
// // while ( node )
// // {
// //     iterator ( node->data );
// //     node = node->next;
// // }