#pragma once


typedef void (*systemFn) ( );

typedef struct System
{
    systemFn update;
    void const* *list;
    unsigned max;
    unsigned length;
    unsigned max_length;
    char *name;
}
System;


System* system       ( systemFn, unsigned, char* );
void    systemUpdate ( System *const );
void    systemEnd    ( System *const );

#define systemAdd( S, V ) \
    S->list [ S->length++ ] = V


#define systemFnDefine( FUNCTION, CODE )   \
    void FUNCTION ( System *const s ) {       \
        void *const* array = (void*) s->list; \
        int length = s->length;            \
                                           \
        for ( int i = 0; i < length; )     \
            CODE                           \
    }

#define systemFnGet \
    array [ i++ ]