#include <genesis.h>

#include "inc/modo.h"
#include "inc/components.h"
#include "../libs/joyreader.h"


void system_timer ( System reff system ) {
    void *reff array = system->list;
    int length = system->length; 

    for ( int i = 0; i < length; ) {
        ComponentTimer reff t = array [ i++ ];
        ComponentTimer_Update ( t );
    }
}