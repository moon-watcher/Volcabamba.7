#pragma once

#include "listptr.h"
#include "entity.h"


typedef struct Manager
{
    listptr entities;
}
Manager;


Manager *modoManager          ( );
void     modoManagerUpdate    ( Manager * );
void     modoManagerDelete    ( Manager * );
void     modoManagerAdd       ( Manager *, Entity * );
