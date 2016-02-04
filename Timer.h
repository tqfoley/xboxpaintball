#include <xtl.h>

#ifndef TIMER
#define TIMER

typedef class c_Timer
{
public:
	LARGE_INTEGER qwCountsPerSec;	// The Precision of the counter or Frequency
	LARGE_INTEGER qwCurrCount;		// The current count that is then converted to fCurrTime
	FLOAT	fCurrTime;		// The Current Time in seconds
	FLOAT	fPrevTime;		// The Prev value of fCurrTime
	FLOAT	fElapsedTime;	// fCurrTime - fPrevTime

	BYTE*	pRand;

	c_Timer();
	~c_Timer();
	BYTE Rand();
	void UpdateTime();
}c_CreateTimer, *p_Timer;

#endif