#pragma once


typedef void (*systemFn) ( );

typedef struct {
    systemFn update;
    unsigned max;
	void const **list;
    unsigned length;
}
System;


System* system       ( systemFn );
void    systemUpdate ( System *const );
void    systemEnd    ( System *const );
void    systemInfo   ( System *const );


#define systemAdd( S, V )                \
	if ( S->length >= S->max )           \
		systemResize ( S );              \
    S->list [ S->length++ ] = V


#define systemFnDefine( FUNCTION, CODE )      \
    void FUNCTION ( System *const s ) {       \
        void *const *array = (void*) s->list; \
        int length = s->length;               \
                                              \
        for ( int i = 0; i < length; )        \
            CODE                              \
    }
	

#define systemFnGet(T, V) \
    T *const V = array [ i++ ]
