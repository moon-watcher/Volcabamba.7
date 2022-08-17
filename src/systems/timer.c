#include "modo.h"
#include "components/Timer.h"



systemDefineFn ( system_timer, {
    systemGetParam ( ComponentTimer, t );
    
    ComponentTimer_Update ( t );
});