#pragma once

#include "../libs/joyreader.h"

typedef struct ComponentInput
{
    Joyreader joy;
    void ( *handlerFn ) ( void *, void * );
}
ComponentInput;