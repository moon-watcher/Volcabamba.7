#pragma once


#define ComponentTimer_Init( A, B ) \
	A->counter = 0;                 \
	A->max = B


#define ComponentTimer_Reset( A )   \
	A->counter = 0


#define ComponentTimer_Update( A )  \
	A->counter++


#define ComponentTimer_Timeout( A ) \
	(int) (A->counter > A->max)



typedef struct {
	unsigned counter;
	unsigned max;
}
ComponentTimer;