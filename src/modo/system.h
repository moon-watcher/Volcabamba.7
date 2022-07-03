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
