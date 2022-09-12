#include <genesis.h>
#include "modo.h"
#include "manager.h"

void modo ( Entity *const entity ) {
    Manager *const scenemanager = manager ( );
    managerAdd ( scenemanager, entity );

    while ( 1 )
        managerUpdate ( scenemanager );
}