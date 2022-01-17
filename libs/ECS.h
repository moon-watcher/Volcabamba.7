#pragma once

#include <genesis.h>
#include "listptr.h"



#define EVENTS(entity)                              \
    State *state = &entity->state;                  \
    Event *event = &entity->event;                  \
    int (*condition)(void*) = event->condition;     \
    if ( condition  &&  condition ( entity ) ) {    \
        state = &event->state;                      \
        state->exec ( entity );                     \
    }                                               \
    condition = NULL;



struct Entity;


typedef struct
{
    unsigned state;
    void ( *exec ) ( struct Entity * );     // Run this function
}
State;


typedef struct
{
    int ( *condition ) ( struct Entity * ); // If this condition func returns...
    State state;      // states[3];  // ...0, 1, 2
}
Event;


typedef struct Entity
{
    bool  delete:1;

    int   compsSize:9;
    void* components; // ptr a un struct con componentes

    State state;
    Event event;

    void ( *Awake  ) ( struct Entity* );
    void ( *Init   ) ( struct Entity* );
    void ( *Update ) ( struct Entity* );
    void ( *Delete ) ( struct Entity* );
}
Entity;


typedef struct
{
    listptr entities;
}
Manager;


typedef struct
{
    void ( *updateFn ) ( void *, int );
    void **list;
    int max;
    char *name;
    int length;
}
System;


typedef struct
{
    struct 
    {
        Manager* ( *new    ) ( );
        void     ( *update ) ( Manager* );
        void     ( *delete ) ( Manager* );
    }
    manager;

    struct
    {
        Entity*  ( *new ) ( Manager*, Entity const* );
    }
    entity;
    
    struct 
    {
        System* ( *new    ) ( System const* );
        void    ( *init   ) ( System* );
        void    ( *update ) ( System* );
        void    ( *delete ) ( System* );
    }
    system;
}
ECS;


ECS ecs;