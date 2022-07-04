#include "modo/system.h"
#include "components/Timer.h"



systemFnDefine ( system_timer, {
    ComponentTimer *const t = systemFnGet;
    ComponentTimer_Update ( t );
});