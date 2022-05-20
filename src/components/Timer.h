#pragma once

typedef struct
{
	unsigned max;
	unsigned counter;
}
ComponentTimer;


struct $ComponentTimer
{
	void ( *Init    ) ( ComponentTimer*, unsigned );
	void ( *Reset   ) ( ComponentTimer* );
	void ( *Update  ) ( ComponentTimer* );
	int  ( *Timeout ) ( ComponentTimer* );
}
const $ComponentTimer;