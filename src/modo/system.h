#pragma once

//typedef void (*modoSystemUpdateFn) (void*, int);

typedef struct System
{
    void ( *update ) ( );
    void **list;
    unsigned length;
    unsigned max;
    char *name;
}
System;


void modoSystemInit   ( System *, void *, unsigned, char* );
void modoSystemUpdate ( System * );
void modoSystemDelete ( System * );


#define modoSystemAdd(S,V) \
    S->list [ S->length++ ] = V
