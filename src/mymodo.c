#include "mymodo.h" 

#define SYSTEM   & ( struct MODO_system  ) { &system,  &systemUpdate, &systemEnd,     &systemInfo,         }
#define MANAGER  & ( struct MODO_manager ) { &manager, &managerAdd,   &managerUpdate, &managerEnd,         }
#define ENTITY   & ( struct MODO_entity  ) { &entity,  &entityState,  &entityDelete,  &entityStateChanged, }

struct MODO         *const $  = & ( struct MODO ) { SYSTEM, MANAGER, ENTITY, &modo };
struct MODO_system  *const $s = SYSTEM;
struct MODO_manager *const $m = MANAGER;
struct MODO_entity  *const $e = ENTITY;






static System  *s_const;
static Manager *m_const;
static Entity  *e_const;
static void    *x_const;

#define $SS(x)  ({ s_const = x, $s })
#define $MM(x)  ({ m_const = x, $m })
#define $EE(x)  ({ s_const = x, $e })

// #define $SS(x)  ({ (s_const = x), $s })
// #define $MM(x)  ({ (m_const = x), $m })
// #define $EE(x)  ({ (s_const = x), $e })

// #define $SS(x)  ({ (s_const = x); $s; })
// #define $MM(x)  ({ (m_const = x); $m; })
// #define $EE(x)  ({ (s_const = x); $e; })

#define $(x)  ({ (s_const = x); $s; })
#define $MMm(x)  ({ (m_const = x); $m; })
#define $EEe(x)  ({ (s_const = x); $e; })


struct MODO_system  *const $S ( System *const x ) {
    s_const = x;
    return $s;
}

struct MODO_manager *const $M ( Manager *const x ) {
    m_const = x;
    return $m;
}

struct MODO_entity  *const $E ( Entity *const x ) {
    e_const = x;
    return $e;
}

#define $manTal ( { (m_const = manTal ); $m; } )

// M(manTal)->add( entity  );
// $manTal->add( entity  );
// $manTal->new();

// $$ ( manaasd )->add ( Entity );

Entity *const addEntityToManager ( Entity const * tpl ) {
    return managerAdd ( m_const, tpl );
}