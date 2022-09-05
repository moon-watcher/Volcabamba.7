#include "modo.h"


struct MODO *const $ = &( struct MODO ) {
    & ( struct MODO_system  ) { &system,  &systemUpdate, &systemEnd,     &systemInfo, },
    & ( struct MODO_manager ) { &manager, &managerAdd,   &managerUpdate, &managerEnd, },
    & ( struct MODO_entity  ) { &entity,  &entityState,  &entityDelete,               },
};

struct MODO_system  *const $s = & ( struct MODO_system  ) { &system,  &systemUpdate, &systemEnd,     &systemInfo, };
struct MODO_manager *const $m = & ( struct MODO_manager ) { &manager, &managerAdd,   &managerUpdate, &managerEnd, };
struct MODO_entity  *const $e = & ( struct MODO_entity  ) { &entity,  &entityState,  &entityDelete,               };
