#include <genesis.h>
#include "modo.h"
#include "manager.h"
#include "system.h"


static Modo list_init    = { NULL, 0 };
static Modo list_manager = { NULL, 0 };
static Modo list_system  = { NULL, 0 };
static Modo list_end     = { NULL, 0 };


// http://taggedwiki.zubiaga.org/new_content/a0aaf6287ad03103f81016980041de78


#define FOR( H, N ) \
    for ( ModoNode *N = H; N; N = N->next )


inline static ModoNode* _create ( void* data ) {
    ModoNode *node = malloc ( sizeof ( ModoNode ) );
    
    node->data = data;
    node->next = NULL;
    node->count = 1;

    return node;
}

inline static void _add ( Modo *const list, void *const data ) {
    if ( !list->head ) {
        list->head = _create ( data );
        ++list->size;
        return;
    }

    ModoNode *last = list->head;

    FOR ( list->head, nodo ) {
        if ( nodo->data == data ) {
            ++nodo->count;
            return;
        }

        last = nodo;
    }

    last->next = _create ( data );
    ++list->size;
}

inline static void _delete ( Modo *const list, void *const data ) {
    if ( !list->size )
        return;

    ModoNode *temp = list->head, *prev;
 
    if ( temp  &&  temp->data == data ) {
        if ( --temp->count <= 0 ) {
            list->head = temp->next;
            --list->size;
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
        --list->size;
        free ( temp );
    }
}



void modo  ( ) {
    while ( 1 ) {
        FOR ( list_init.head,    node ) ((void(*)()) node->data) ( );
        FOR ( list_manager.head, node ) managerUpdate ( node->data );
        FOR ( list_system.head,  node ) systemUpdate  ( node->data );
        FOR ( list_end.head,     node ) ((void(*)()) node->data) ( );

        SYS_doVBlankProcess();
    }
}

void modo_addInit       ( void *const data ) { _add    ( &list_init,    data ); }
void modo_addManager    ( void *const data ) { _add    ( &list_manager, data ); }
void modo_addSystem     ( void *const data ) { _add    ( &list_system,  data ); }
void modo_addEnd        ( void *const data ) { _add    ( &list_end,     data ); }

void modo_deleteInit    ( void *const data ) { _delete ( &list_init,    data ); }
void modo_deleteManager ( void *const data ) { _delete ( &list_manager, data ); }
void modo_deleteSystem  ( void *const data ) { _delete ( &list_system,  data ); }
void modo_deleteEnd     ( void *const data ) { _delete ( &list_end,     data ); }

void modo_deleteForce ( Modo *const h, void *const data ) {
    h->size = 1;
    _delete ( h, data );
}



// struct Singleton {
//    char *Data;	
// };

// struct Singleton *singletonObjectPointer = NULL;

// struct Singleton *getInstance ( ) {
//     if ( singletonObjectPointer == NULL ) {
//         singletonObjectPointer = malloc ( sizeof ( struct Singleton ) ); 
//     }

// 	return singletonObjectPointer;
// }


// void implementation () {
//     struct Singleton *s = getInstance();
// }




// #include <genesis.h>
// #include "modo.h"
// #include "manager.h"
// #include "system.h"


// static Modo list_init    = { NULL, NULL };
// static Modo list_manager = { NULL, NULL };
// static Modo list_system  = { NULL, NULL };
// static Modo list_end     = { NULL, NULL };


// // http://taggedwiki.zubiaga.org/new_content/a0aaf6287ad03103f81016980041de78


// #define FOR( H, N ) \
//     for ( Modo *N = H; N; N = N->next )


// inline static Modo* _create ( void* data ) {
//     Modo *node = malloc ( sizeof ( Modo ) );
    
//     node->data = data;
//     node->next = NULL;

//     return node;
// }

// inline static void _add ( Modo *list, void *const data ) {
//     Modo *node = list;

//     while ( node )
//         node = node->next;

//     node = _create ( data );
// }

// inline static void _delete ( Modo *list, void *const data ) {
//     Modo *node = list;
//     Modo *prev = list;

//     while ( node ) {
//         if ( node->data == data ) {
//             prev->next = node->next;
//             free ( node );
//             return;
//         }
//         prev = node;
//         node = node->next;
//     }
// }



// void modo  ( ) {
//     while ( 1 ) {
//         FOR ( &list_init,    node ) ((void(*)()) node->data) ( );
//         FOR ( &list_manager, node ) managerUpdate ( node->data );
//         FOR ( &list_system,  node ) systemUpdate  ( node->data );
//         FOR ( &list_end,     node ) ((void(*)()) node->data) ( );

//         SYS_doVBlankProcess();
//     }
// }

// void modo_addInit       ( void *const data ) { _add    ( &list_init,    data ); }
// void modo_addManager    ( void *const data ) { _add    ( &list_manager, data ); }
// void modo_addSystem     ( void *const data ) { _add    ( &list_system,  data ); }
// void modo_addEnd        ( void *const data ) { _add    ( &list_end,     data ); }

// void modo_deleteInit    ( void *const data ) { _delete ( &list_init,    data ); }
// void modo_deleteManager ( void *const data ) { _delete ( &list_manager, data ); }
// void modo_deleteSystem  ( void *const data ) { _delete ( &list_system,  data ); }
// void modo_deleteEnd     ( void *const data ) { _delete ( &list_end,     data ); }



































// void modoInfoManagers ( Modo *const h ) {
//     int i = 0;
//     VDP_resetScreen();

//     if ( !h->size )
//         return;
    
//     for ( ModoNode *N = h->head; N; N = N->next ) {
//         Manager *const m = N->data;

//         Text ( m->name,     0, i );
//         Int ( N->count, 20, i, 4 );
//         ++i;
//     }

//     waitMs(10000);
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





// #include <genesis.h>
// #include "modo.h"
// #include "manager.h"
// #include "system.h"


// Modo modo_lists_init     = { NULL, 0 };
// Modo modo_lists_managers = { NULL, 0 };
// Modo modo_lists_middle   = { NULL, 0 };
// Modo modo_lists_systems  = { NULL, 0 };
// Modo modo_lists_end      = { NULL, 0 };



// // http://taggedwiki.zubiaga.org/new_content/a0aaf6287ad03103f81016980041de78




// void modo ( Manager *m, Entity *const e ) {
//     m = manager ( );

//     managerAdd ( m, e );
//     modo_add ( &modo_lists_managers, m );

//     while ( 1 ) {
//         for ( ModoNode *N = modo_lists[MODOLIST_INIT].head;    N; N = N->next )
//             ( (void(*)()) N->data ) ( );

//         for ( ModoNode *N = modo_lists[MODOLIST_MANAGER].head; N; N = N->next )
//             managerUpdate ( N->data );

//         for ( ModoNode *N = modo_lists[MODOLIST_MIDDLE].head;  N; N = N->next )
//             ( (void(*)()) N->data ) ( );

//         for ( ModoNode *N = modo_lists[MODOLIST_SYSTEM].head;  N; N = N->next )
//             systemUpdate  ( N->data );

//         for ( ModoNode *N = modo_lists[MODOLIST_END].head;     N; N = N->next )
//             ( (void(*)()) N->data ) ( );
//     }
// }


// static ModoNode* _create ( void* data ) {
//     ModoNode *node = malloc ( sizeof ( ModoNode ) );
    
//     node->data = data;
//     node->next = NULL;
//     node->count = 1;

//     return node;
// }


// void modo_add ( Modolist_t index, void *const data ) {
//     Modo *const h = &modo_lists [ index ];

//     if ( !h->head ) {
//         h->head = _create ( data );
//         ++h->size;
//         return;
//     }

//     ModoNode *last = h->head;

//     for ( ModoNode *N = h->head; N; N = N->next ) {
//         if ( N->data == data ) {
//             ++N->count;
//             return;
//         }

//         last = N;
//     }

//     last->next = _create ( data );
//     ++h->size;
// }



// void modo_delete ( Modolist_t index, void *const data ) {
//     Modo *const h = &modo_lists [ index ];
    
//     if ( !h->size )
//         return;

//     ModoNode *temp = h->head, *prev;
 
//     if ( temp  &&  temp->data == data ) {
//         if ( --temp->count <= 0 ) {
//             h->head = temp->next;
//             --h->size;
//             free ( temp );
//         }

//         return;
//     }
 
//     while ( temp  &&  temp->data != data ) {
//         prev = temp;
//         temp = temp->next;
//     }
 
//     if ( temp  &&  --temp->count <= 0 ) {
//         prev->next = temp->next;
//         --h->size;
//         free ( temp );
//     }
// }


// void modo_deleteForce ( Modo *const h, void *const data ) {
//     if ( !h->size )
//         return;

//     ModoNode *temp = h->head, *prev;
 
//     if ( temp  &&  temp->data == data ) {
//         h->head = temp->next;
//         --h->size;
//         free ( temp );

//         return;
//     }
 
//     while ( temp  &&  temp->data != data ) {
//         prev = temp;
//         temp = temp->next;
//     }
 
//     if ( temp ) {
//         prev->next = temp->next;
//         --h->size;
//         free ( temp );
//     }
// }






// void modoInfoManagers ( Modo *const h ) {
//     int i = 0;
//     VDP_resetScreen();

//     if ( !h->size )
//         return;
    
//     for ( ModoNode *N = h->head; N; N = N->next ) {
//         Manager *const m = N->data;

//         Text ( m->name,     0, i );
//         Int ( N->count, 20, i, 4 );
//         ++i;
//     }

//     waitMs(10000);
// }





// # define _foreach( L, N ) \
// 	for ( ModoNode *N = L->head; N; N = N->next )
	


// void modoUpdate ( Modo *const h ) {
//     if ( !h->size )
//         return;

//     void (*update)() = h->update ? h->update : NULL;

//     if ( update )
//         _foreach ( h, node )
//             update ( node->data );

//     else
//         _foreach ( h, node )
//             ( (void(*)()) node->data ) ( );
// }








//     ModoNode *last = h->head;
//     ModoNode *node = h->head;
//     ModoNode *new = malloc ( sizeof ( ModoNode ) );

//     new->data = data;
//     new->next = NULL;
//     new->counter = 1;

//     //if head is NULL, it is an empty list
//     if ( !h->head ) {
//         ModoNode *new = malloc ( sizeof ( ModoNode ) );
        
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
//         h->head = malloc ( sizeof ( ModoNode ) );


//     ModoNode *last = h->head;
//     ModoNode *node = h->head;

//     while ( node ) {
//         if ( node->data == data ) {
//             ++node->counter;
//             return;
//         }

//         last = node;
//         node = node->next;
//     }

//     ModoNode *new = malloc ( sizeof ( ModoNode ) );

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