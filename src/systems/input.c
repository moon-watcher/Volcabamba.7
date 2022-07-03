#include <genesis.h>

#include "inc/modo.h"
#include "inc/components.h"
#include "../libs/joyreader.h"

/**
 * Use:
 *  - ComponentInput
 *  - Entity
 */
systemFnDefine ( system_input, {
    ComponentInput *const ci     = systemFnGet;
    Entity         *const entity = systemFnGet;

    ComponentInput_Update ( ci );

    if ( ci->handler ) {
        ci->handler ( &ci->joy, entity, NULL );
    }
});


// void system_input ( System *const system ) {
//     void *ref array = system->list;
//     int length = system->length; 

//     for ( int i = 0; i < length; ) {
//         ComponentInput *const ci     = array [ i++ ];
//         Entity         *const entity = array [ i++ ];
        
//         ComponentInput_Update ( ci );

//         if ( ci->handler ) {
//             ci->handler ( &ci->joy, entity, NULL );
//         }
//     }
// }