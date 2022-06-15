#pragma once

typedef struct {
	unsigned counter;
	unsigned max;
}
ComponentTimer;


void ComponentTimer_Init    ( ComponentTimer*, unsigned );
void ComponentTimer_Reset   ( ComponentTimer* );
void ComponentTimer_Update  ( ComponentTimer* );
int  ComponentTimer_Timeout ( ComponentTimer* );