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
