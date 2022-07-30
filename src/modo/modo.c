#include <genesis.h>
#include "modo.h"
#include "manager.h"


// static int const hvlistNode_s = sizeof(hvlistNode);

// http://taggedwiki.zubiaga.org/new_content/a0aaf6287ad03103f81016980041de78



static modoNode* _create ( void* data ) {
    modoNode *node = malloc ( sizeof ( modoNode ) );
    
    node->data = data;
    node->next = NULL;
    node->count = 1;

    return node;
}



modoList *modo ( void (*update)() ) {
    modoList *h = malloc ( sizeof ( modoList ) );

    h->head   = NULL;
    h->update = update;
    h->size   = 0;

    return h;
}


void modoAdd ( modoList *const h, void *const data ) {
    if ( !h->head ) {
        h->head = _create ( data );
        ++h->size;
        return;
    }

    modoNode *last = h->head;

    modoForeach ( h, node ) {
        if ( node->data == data ) {
            ++node->count;
            return;
        }

        last = node;
    }

    last->next = _create ( data );
    ++h->size;
}


void modoUpdate ( modoList *const h ) {
    void (*update)() = h->update ? h->update : NULL;

    if ( update )
        modoForeach ( h, node )
            update ( node->data );

    else
        modoForeach ( h, node )
            ( (void(*)()) node->data ) ( );
}


void modoDelete ( modoList *const h, void *const data ) {
    modoNode *temp = h->head, *prev;
 
    if ( temp  &&  temp->data == data ) {
        if ( --temp->count <= 0 ) {
            h->head = temp->next;
            --h->size;
            free ( temp );
        }

        return;
    }
 
    while ( temp  &&  temp->data != data ) {
        prev = temp;
        temp = temp->next;
    }
 
    if ( temp  &&  --temp->count <= 0 ) {
        prev->next = temp->next;
        --h->size;
        free ( temp );
    }
}


void modoDeleteForce ( modoList *const h, void *const data ) {
    modoNode *temp = h->head, *prev;
 
    if ( temp  &&  temp->data == data ) {
        h->head = temp->next;
        --h->size;
        free ( temp );

        return;
    }
 
    while ( temp  &&  temp->data != data ) {
        prev = temp;
        temp = temp->next;
    }
 
    if ( temp ) {
        prev->next = temp->next;
        --h->size;
        free ( temp );
    }
}


void modoInfoManagers ( modoList *const h ) {
    int i = 0;
    VDP_resetScreen();
    
    modoForeach ( h, nodo ) {
        Manager *const m = nodo->data;

        Text ( m->name,     0, i );
        Int ( nodo->count, 20, i, 4 );
        ++i;
    }

    waitMs(10000);
}



//     modoNode *last = h->head;
//     modoNode *node = h->head;
//     modoNode *new = malloc ( sizeof ( modoNode ) );

//     new->data = data;
//     new->next = NULL;
//     new->counter = 1;

//     //if head is NULL, it is an empty list
//     if ( !h->head ) {
//         modoNode *new = malloc ( sizeof ( modoNode ) );
        
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
//         h->head = malloc ( sizeof ( modoNode ) );


//     modoNode *last = h->head;
//     modoNode *node = h->head;

//     while ( node ) {
//         if ( node->data == data ) {
//             ++node->counter;
//             return;
//         }

//         last = node;
//         node = node->next;
//     }

//     modoNode *new = malloc ( sizeof ( modoNode ) );

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