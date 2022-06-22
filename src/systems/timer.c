#include <genesis.h>

#include "inc/modo.h"
#include "inc/components.h"
#include "../libs/joyreader.h"


void system_timer ( System * const system ) {
    void ** const array = system->list;
    int length = system->length; 

    for ( int i = 0; i < length; ) {
        ComponentTimer * const t = array [ i++ ];
        ComponentTimer_Update ( t );
    }
}