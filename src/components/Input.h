#pragma once

#include "../libs/joyreader.h"


#define ComponentInput_Init( A ) \
    joyreader_init ( &A->joy, A->joy.port )


#define ComponentInput_Update( A ) \
    joyreader_update ( &A->joy )


#define ComponentInput_Handler( A, B ) \
    A->handler = B;



typedef struct ComponentInput {
    Joyreader joy;
    void ( *handler ) ( Joyreader*, void*, void* );
}
ComponentInput;