#pragma once

#include "../libs/joyreader.h"

typedef struct ComponentInput
{
    Joyreader joy;
    void ( *handler ) ( Joyreader *joy, void *ptr1, void *ptr2 );
}
ComponentInput;