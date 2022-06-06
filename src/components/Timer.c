#include "Timer.h"


static void init ( ComponentTimer *this, unsigned max )
{
	this->counter = 0;
	this->max = max;
}

static void reset ( ComponentTimer *this )
{
	this->counter = 0;
}

static void update ( ComponentTimer *this )
{
	++this->counter;
}

static int timeout ( ComponentTimer *this )
{
	return (int) (this->counter > this->max);
}


struct $ComponentTimer $ComponentTimer = { init, reset, update, timeout };