#pragma once

#include "../libs/joyreader.h"

typedef struct
{
    int active:1;
    int id:2;
    Joyreader *joy;
}
ComponentInput;