#include <genesis.h>
#include "mm.h" 
// #include "mymodo/mm.h" 
// #include "modo/entity.h"
#include "components/Input.h"

/**
 * Use:
 *  - ComponentInput
 *  - Entity
 */
defineSystemFn ( system_input, {
    systemGetParam ( ComponentInput, ci     );
    systemGetParam ( Entity,         entity );

    if ( ci->joy.port < 0 )
        continue;

    ComponentInput_Update ( ci );

    if ( ci->handler )
        ci->handler ( &ci->joy, entity );
});


System const system_Input_tpl = { &system_input, 5, 2, "Input" };