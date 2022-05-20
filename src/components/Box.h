#pragma once

typedef struct
{
	unsigned w, h;

	int (*area) (void*);
}
ComponentBox;
