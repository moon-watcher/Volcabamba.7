#pragma once


typedef void (*systemFn) (void*,int);

typedef struct System
{
    systemFn update;
    void **list;
    unsigned max;
    unsigned length;
    char *name;
}
System;


System* system       ( systemFn, unsigned, char* );
void    systemUpdate ( System* );
void    systemDelete ( System* );


#define systemAdd(S,V) \
    S->list [ S->length++ ] = V
