#include "Timer.h"


inline void ComponentTimer_Init ( ComponentTimer *this, unsigned max ) {
	this->counter = 0;
	this->max = max;
}

inline void ComponentTimer_Reset ( ComponentTimer *this ) {
	this->counter = 0;
}

inline void ComponentTimer_Update ( ComponentTimer *this ) {
	++this->counter;
}

inline int ComponentTimer_Timeout ( ComponentTimer *this ) {
	return (int) (this->counter > this->max);
}