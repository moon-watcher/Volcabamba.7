#include <genesis.h>
#include "system.h"



// https://algorithmtutor.com/Data-Structures/Basic/Doubly-Linked-Lists/


static int const system_s     = sizeof ( System );
static int const systemNode_s = sizeof ( SystemNode );


System* system ( void (*update) (), char *const name ) {
    System *system = malloc ( system_s );
    
    system->update = update;
    system->name   = name;
    system->head   = ((void*)0);
    system->tail   = ((void*)0);

    return system;
}


void systemUpdate ( System *const system ) {
    if ( system->update )
        system->update ( system );
}


SystemNode *systemAdd ( System *const s, void *const data ) {
    SystemNode *node = malloc ( systemNode_s );

    node->data = data;
    node->next = NULL;
    node->prev = NULL;    
    
    if ( s->head == NULL )
        s->head = node;
    else {
        s->tail->next = node;
        node->prev = s->tail;
    }

    s->tail = node;

    return node;
}


void systemDelete ( System *const s, SystemNode *const node ) {
    if ( node->prev == NULL ) {
        if ( s->head->next != NULL )
            s->head->next->prev = NULL;
        
        SystemNode *next = s->head->next;
        free ( s->head );
        s->head = next;
    }
    else if ( node->next == NULL ) {
        if ( s->tail->prev != NULL )
            s->tail->prev->next = NULL;
        
        SystemNode *prev = s->tail->prev;
        s->tail->prev = NULL;
        free ( s->tail );
        s->tail = prev;
    }
    else { 
        SystemNode *next = node->next;
        SystemNode *prev = node->prev;
        
        next->prev = prev;
        prev->next = next;

        node->next = NULL;
        node->prev = NULL;

        free ( node );
    }
}