#include <genesis.h>
#include "mymodo.h" 
// #include "mymodo.h" 
// #include "modo/entity.h"
#include "components/Input.h"

/**
 * Use:
 *  - ComponentInput
 *  - Entity
 */
systemDefineFn ( system_input, {
    systemGetParam ( ComponentInput, ci     );
    systemGetParam ( Entity,         entity );

    if ( ci->joy.port < 0 )
        continue;

    ComponentInput_Update ( ci );

    if ( ci->handler )
        ci->handler ( &ci->joy, entity );
});


System const system_Input_tpl = { &system_input, 2, 2, "Input" };