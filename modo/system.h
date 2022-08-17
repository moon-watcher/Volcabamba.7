#pragma once


typedef struct {
    void (*update) ();
	void const **list;
    unsigned max:6;
    unsigned length:6;
    unsigned params:3;
}
System;


System* system       ( void (*)(), int, int );
void    systemUpdate ( System *const );
void    systemEnd    ( System *const );
void    systemInfo   ( System *const );


#define systemDefineFn( FUNCTION, CODE )      \
    void FUNCTION ( System *const s ) {       \
        void *const *array = (void*) s->list; \
        for ( int i = 0; i < s->length; )     \
            CODE                              \
    }
	
#define systemGetParam( T, V )            \
    T *const V = array [ i++ ]

#define systemAdd( S, A )              \
    S->list [ S->length++ ] = A;

#define systemAdd2( S, A, B )          \
    S->list [ S->length++ ] = A;       \
    S->list [ S->length++ ] = B;

#define systemAdd3( S, A, B, C )       \
    S->list [ S->length++ ] = A;       \
    S->list [ S->length++ ] = B;       \
    S->list [ S->length++ ] = C;

#define systemAdd4( S, A, B, C, D )    \
    S->list [ S->length++ ] = A;       \
    S->list [ S->length++ ] = B;       \
    S->list [ S->length++ ] = C;       \
    S->list [ S->length++ ] = D;

#define systemAdd5( S, A, B, C, D, E ) \
    S->list [ S->length++ ] = A;       \
    S->list [ S->length++ ] = B;       \
    S->list [ S->length++ ] = C;       \
    S->list [ S->length++ ] = D;       \
    S->list [ S->length++ ] = E;
