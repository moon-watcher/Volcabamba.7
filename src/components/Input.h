#pragma once

#include "../libs/joyreader.h"

typedef struct ComponentInput {
    Joyreader joy;
    void ( *handler ) ( Joyreader*, void*, void* );
}
ComponentInput;


struct $ComponentInput {
    void ( *Init    ) ( ComponentInput* );
    void ( *Update  ) ( ComponentInput* );
    void ( *Handler ) ( ComponentInput*, void (*)() );
}
$ComponentInput;