#pragma once


//typedef void (*systemFn) ( );

typedef struct {
    void (*update) ();
    unsigned max;
	void const **list;
    unsigned length;
    unsigned params:3;
}
System;


System* system       ( void(*)(), int );
void    systemUpdate ( System *const );
void    systemUse    ( System *const );
void    systemEnd    ( System *const );
void    systemInfo   ( System *const );


#define systemFnDefine( F, C )                \
    void F ( System *const s ) {              \
        void *const *array = (void*) s->list; \
        int length = s->length;               \
        int i = 0;                            \
        while ( i < length )                  \
            C                                 \
    }
	
#define systemFnGet( T, V )            \
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
