#pragma once

typedef struct {
    void ( *enter  ) ( );
    void ( *update ) ( );
    void ( *exit   ) ( );
    char *name;
}
State;


#define stateDefineEx( ENTITY, NAME, STATE, ENTER, UPDATE, EXIT, COMPS ) \
    static void STATE##_enter  ( Entity *const ENTITY ) { COMPS(ENTITY); ENTER  }   \
    static void STATE##_update ( Entity *const ENTITY ) { COMPS(ENTITY); UPDATE }   \
    static void STATE##_exit   ( Entity *const ENTITY ) { COMPS(ENTITY); EXIT   }   \
    State const STATE = {                                         \
        .enter  = STATE##_enter,                                  \
        .update = STATE##_update,                                 \
        .exit   = STATE##_exit,                                   \
        .name   = NAME,                                           \
    };

#define stateDefine( STATE, ENTER, UPDATE, EXIT )                 \
    stateDefineEx( e, NULL, STATE, ENTER, UPDATE, EXIT, COMPS )
