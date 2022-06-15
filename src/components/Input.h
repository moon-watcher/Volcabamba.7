#pragma once

#include "../libs/joyreader.h"

typedef struct ComponentInput {
    Joyreader joy;
    void ( *handler ) ( Joyreader*, void*, void* );
}
ComponentInput;


void ComponentInput_Init    ( ComponentInput* );
void ComponentInput_Update  ( ComponentInput* );
void ComponentInput_Handler ( ComponentInput*, void (*)() );