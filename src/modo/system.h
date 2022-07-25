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
void    systemResize ( System *const, int );
void    systemEnd    ( System *const );
void    systemInfo   ( System *const );


#define systemFnDefine( FUNCTION, CODE )      \
    void FUNCTION ( System *const s ) {       \
        void *const *array = (void*) s->list; \
        int length = s->length;               \
        int i = 0;                            \
        while ( i < length )                  \
            CODE                              \
    }
	
#define systemFnGet(T, V) \
    T *const V = array [ i++ ]

#define systemAdd( S, A )           \
    if ( S->length+1 >= S->max )    \
		systemResize ( S, 20 );     \
    S->list [ S->length++ ] = A;

#define systemAdd2( S, A, B )       \
    if ( S->length+2 >= S->max )    \
		systemResize ( S, 40 );     \
    S->list [ S->length++ ] = A;    \
    S->list [ S->length++ ] = B;

#define systemAdd3( S, A, B, C )    \
    if ( S->length+3 >= S->max )    \
		systemResize ( S, 60 );     \
    S->list [ S->length++ ] = A;    \
    S->list [ S->length++ ] = B;    \
    S->list [ S->length++ ] = C;

#define systemAdd4( S, A, B, C, D ) \
    if ( S->length+4 >= S->max )    \
		systemResize ( S, 80 );     \
    S->list [ S->length++ ] = A;    \
    S->list [ S->length++ ] = B;    \
    S->list [ S->length++ ] = C;    \
    S->list [ S->length++ ] = D;
