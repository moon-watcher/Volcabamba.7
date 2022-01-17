#pragma once

#include <genesis.h>


void drawText(const char* str, u16 x, u16 y);
void drawInt(u32 nb, u8 x, u8 y, u8 zeros);
void drawUInt(u32 nb, u8 x, u8 y, u8 zeros);
void drawFix32(fix32 nb, u8 x, u8 y, u8 zeros);
void drawMem(u8 x, u8 y);
