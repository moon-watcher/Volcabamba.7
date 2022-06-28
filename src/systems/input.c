#include <genesis.h>

#include "inc/modo.h"
#include "inc/components.h"
#include "../libs/joyreader.h"


void system_input ( System ref system ) {
    void *ref array = system->list;
    int length = system->length; 

    for ( int i = 0; i < length; ) {
        ComponentInput ref ci     = array [ i++ ];
        Entity         ref entity = array [ i++ ];
        
        ComponentInput_Update ( ci );

        if ( ci->handler ) {
            ci->handler ( &ci->joy, entity, NULL );
        }
    }
}