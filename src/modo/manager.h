#pragma once

//#include "libs/listptr.h"
#include "entity.h"


		
typedef struct ManagerNode
	*data;
	*next;
	*prev;
} 

typedef struct 
{
	Entity *entities;
}
Manager;


Manager *modoManager        ( );
void     modoManagerUpdate  ( Manager* );
void     modoManagerDelete  ( Manager* );
void     modoManagerAdd     ( Manager*, Entity* );
