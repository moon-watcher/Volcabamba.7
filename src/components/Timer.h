#pragma once

typedef struct
{
	unsigned counter;
	unsigned max;
}
ComponentTimer;


struct $ComponentTimer
{
	void ( *Init    ) ( ComponentTimer*, unsigned );
	void ( *Reset   ) ( ComponentTimer* );
	void ( *Update  ) ( ComponentTimer* );
	int  ( *Timeout ) ( ComponentTimer* );
}
$ComponentTimer;