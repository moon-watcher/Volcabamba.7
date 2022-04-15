#pragma once

typedef struct BaseClass
{
	void (*constructor) ( );
	void (*destructor ) ( );
}
BaseClass;