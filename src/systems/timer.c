#include <genesis.h>

#include "inc/modo.h"
#include "inc/components.h"
#include "../libs/joyreader.h"


void system_timer ( System ref system ) {
    void *ref array = system->list;
    int length = system->length; 

    for ( int i = 0; i < length; ) {
        ComponentTimer ref t = array [ i++ ];
        ComponentTimer_Update ( t );
    }
}