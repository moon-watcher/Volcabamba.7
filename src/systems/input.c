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
systemFnDefine ( system_input, {
    systemFnGet ( ComponentInput, ci     );
    systemFnGet ( Entity,         entity );

    if ( ci->joy.port < 0 )
        continue;

    ComponentInput_Update ( ci );

    if ( ci->handler ) {
        ci->handler ( &ci->joy, entity, NULL );
    }
});