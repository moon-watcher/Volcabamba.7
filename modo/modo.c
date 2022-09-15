#include <genesis.h>
#include "modo.h"
#include "manager.h"

void modo ( Entity *const entity ) {
    Manager *const m = manager ( );
    managerAdd ( m, entity );

    while ( 1 )
        managerUpdate ( m );
}