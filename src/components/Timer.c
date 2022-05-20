#include "Timer.h"


static inline void init ( ComponentTimer *this, unsigned max )
{
	this->counter = 0;
	this->max = max;
}

static inline void reset ( ComponentTimer *this )
{
	this->counter = 0;
}

static inline void update ( ComponentTimer *this )
{
	//drawText("asdfa", 5,6 );
	++this->counter;
	drawUInt ( this->counter, 0, 3, 8 );
}

static inline int timeout ( ComponentTimer *this )
{
	return (int) (this->counter > this->max);
}


struct $ComponentTimer const $ComponentTimer = { init, reset, update, timeout };