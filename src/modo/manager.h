#pragma once

//#include "libs/listptr.h"
#include "entity.h"




struct ManagerNode
{
	void *data;
	struct ManagerNode *next, *prev;
};

typedef struct Manager
{
    int length;
	struct ManagerNode *entities;
}
Manager;


Manager *modoManager        ( );
void     modoManagerUpdate  ( Manager* );
void     modoManagerDelete  ( Manager* );
void     modoManagerAdd     ( Manager*, Entity* );
