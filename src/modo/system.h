#pragma once


typedef void (*modoSystemUpdateFn) (void*,int);

typedef struct System
{
    modoSystemUpdateFn update;
    void **list;
    unsigned max;
    unsigned length;
    char *name;
}
System;


System* modoSystem       ( modoSystemUpdateFn, unsigned, char* );
void    modoSystemUpdate ( System* );
void    modoSystemDelete ( System* );


#define modoSystemAdd(S,V) \
    S->list [ S->length++ ] = V
