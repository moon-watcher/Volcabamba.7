#include "modo.h"


MODO *const $ = &(MODO) {
    & ( struct MODO_system  ) { &system,  &systemUpdate, &systemEnd,     &systemInfo, },
    & ( struct MODO_manager ) { &manager, &managerAdd,   &managerUpdate, &managerEnd, },
    & ( struct MODO_entity  ) { &entity,  &entityState,  &entityDelete,               },
};