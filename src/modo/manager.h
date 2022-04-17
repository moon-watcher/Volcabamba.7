#pragma once

#include "entity.h"
#include "listptr.h"


typedef struct Manager
{
    listptr entities;
}
Manager;


void modoManagerInit   ( Manager* );
void modoManagerUpdate ( Manager* );
void modoManagerDelete ( Manager* );
void modoManagerAdd    ( Manager*, Entity* );


/*
#define modoManagerNewEntity(M,T)     \
    ({ Entity *e = modoEntity ( T );  \
       modoManagerAdd ( M, e );       \
       e; })
*/