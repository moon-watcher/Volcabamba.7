#include <genesis.h>
#include "modo/system.h"
#include "modo/system.h"
#include "modo/entity.h"
#include "components/Input.h"

/**
 * Use:
 *  - ComponentInput
 *  - Entity
 */
// systemFnDefine ( system_input, {
//     systemFnGet ( ComponentInput, ci     );
//     systemFnGet ( Entity,         entity );

//     if ( ci->joy.port < 0 )
//         continue;

//     ComponentInput_Update ( ci );

//     if ( ci->handler ) {
//         ci->handler ( &ci->joy, entity, NULL );
//     }
// });


void system_input  ( System *const s ){
    for ( SystemNode *n = s->head; n;  ){
        ComponentInput *const ci     = n->data; n = n->next;
        Entity         *const entity = n->data; n = n->next;

        if ( ci->joy.port < 0 )
            continue;

        ComponentInput_Update ( ci );

        if ( ci->handler ) {
            ci->handler ( &ci->joy, entity, NULL );
        }
    }
}