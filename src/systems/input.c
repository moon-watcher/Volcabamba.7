#include <genesis.h>

#include "inc/modo.h"
#include "inc/components.h"
#include "../libs/joyreader.h"


void system_input ( System reff system ) {
    void *reff array = system->list;
    int length = system->length; 

    for ( int i = 0; i < length; ) {
        ComponentInput reff ci     = array [ i++ ];
        Entity         reff entity = array [ i++ ];
        
        ComponentInput_Update ( ci );

        if ( ci->handler ) {
            ci->handler ( &ci->joy, entity, NULL );
        }
    }
}