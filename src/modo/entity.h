#pragma once


typedef struct Entity
{
    struct State *state;
    
    void* components;
    int compsSize;
    int action;
    
    struct EntityExecInterface *exec;

    void ( *Awake  ) ( struct Entity * );
    void ( *Update ) ( struct Entity * );
    void ( *Delete ) ( struct Entity * );
    void ( *enter  ) ( struct Entity * ); // state
    void ( *exit   ) ( struct Entity * ); // state
}
Entity;


typedef struct State
{
    void ( *enter  ) ( Entity * );
    void ( *update ) ( Entity * );
    void ( *exit   ) ( Entity * );
    void *data;
}
State;


Entity *modoEntity       ( Entity const *tpl );
void    modoEntityDelete ( Entity *entity );
void    modoEntityState  ( Entity *entity, State const *state );