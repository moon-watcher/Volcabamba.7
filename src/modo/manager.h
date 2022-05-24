#pragma once

#include "entity.h"
#include "libs/listptr.h"

typedef listptr Manager;

Manager *manager       ( );
Entity  *managerAdd    ( Manager*, Entity const* );
void     managerUpdate ( Manager* );
void     managerEnd    ( Manager* );

// #define managerForeach(M,E) \
//     for ( listptrNode *n = M->head, E = n->data;  n;  n = n->next, E = n->data )