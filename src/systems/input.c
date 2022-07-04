#include <genesis.h>
#include "modo/system.h"
#include "modo/entity.h"
#include "components/Input.h"

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