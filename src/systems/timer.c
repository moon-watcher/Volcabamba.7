#include "modo/system.h"
#include "components/Timer.h"



systemFnDefine ( system_timer, {
    systemFnGet ( ComponentTimer, t );
    
    ComponentTimer_Update ( t );
});