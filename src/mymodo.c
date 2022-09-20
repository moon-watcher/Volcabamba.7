#include "mymodo.h" 

#define SYSTEM   & ( MYMODO_SYSTEM  ) { &system,  &systemUpdate, &systemEnd,     &systemInfo,         }
#define MANAGER  & ( MYMODO_MANAGER ) { &manager, &managerAdd,   &managerUpdate, &managerEnd,         }
#define ENTITY   & ( MYMODO_ENTITY  ) { &entity,  &entityState,  &entityDelete,  &entityStateChanged, }

MYMODO         *const $  = & ( MYMODO ) { SYSTEM, MANAGER, ENTITY, modo };
MYMODO_SYSTEM  *const $s = SYSTEM;
MYMODO_MANAGER *const $m = MANAGER;
MYMODO_ENTITY  *const $e = ENTITY;






// static System  *s_const;
// static Manager *m_const;
// static Entity  *e_const;
// static void    *x_const;

// #define $SS(x)  ({ s_const = x, $s })
// #define $MM(x)  ({ m_const = x, $m })
// #define $EE(x)  ({ s_const = x, $e })

// // #define $SS(x)  ({ (s_const = x), $s })
// // #define $MM(x)  ({ (m_const = x), $m })
// // #define $EE(x)  ({ (s_const = x), $e })

// // #define $SS(x)  ({ (s_const = x); $s; })
// // #define $MM(x)  ({ (m_const = x); $m; })
// // #define $EE(x)  ({ (s_const = x); $e; })

// #define $(x)  ({ (s_const = x); $s; })
// #define $MMm(x)  ({ (m_const = x); $m; })
// #define $EEe(x)  ({ (s_const = x); $e; })


// struct MYMODO_system  *const $S ( System *const x ) {
//     s_const = x;
//     return $s;
// }

// struct MYMODO_manager *const $M ( Manager *const x ) {
//     m_const = x;
//     return $m;
// }

// struct MYMODO_entity  *const $E ( Entity *const x ) {
//     e_const = x;
//     return $e;
// }

// #define $manTal ( { (m_const = manTal ); $m; } )

// // M(manTal)->add( entity  );
// // $manTal->add( entity  );
// // $manTal->new();

// // $$ ( manaasd )->add ( Entity );

// Entity *const addEntityToManager ( Entity const * tpl ) {
//     return managerAdd ( m_const, tpl );
// }