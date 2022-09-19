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
mm_systemDefineFn ( system_input, {
    mm_systemGetParam ( ComponentInput, ci     );
    mm_systemGetParam ( Entity,         entity );

    if ( ci->joy.port < 0 )
        continue;

    ComponentInput_Update ( ci );

    if ( ci->handler )
        ci->handler ( &ci->joy, entity );
});


System const system_Input_tpl = { &system_input, 5, 2, "Input" };