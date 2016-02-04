#include "Timer.h"

c_Timer::c_Timer()
{
	QueryPerformanceFrequency(&qwCountsPerSec);
	QueryPerformanceCounter(&qwCurrCount);
	fCurrTime = ((FLOAT)qwCurrCount.QuadPart/(FLOAT)qwCountsPerSec.QuadPart);
	fPrevTime = 0;

	pRand = (BYTE*)(&(qwCurrCount.LowPart));
}

void c_Timer::UpdateTime()
{
	fPrevTime = fCurrTime;
	QueryPerformanceCounter(&qwCurrCount);
	fCurrTime = ((FLOAT)qwCurrCount.QuadPart/(FLOAT)qwCountsPerSec.QuadPart);
	fElapsedTime = fCurrTime - fPrevTime;
}

BYTE c_Timer::Rand()
{
	DWORD t;
	QueryPerformanceCounter(&qwCurrCount);
	t = qwCurrCount.LowPart;
	t += 2433;
	while(t > qwCurrCount.LowPart)
		QueryPerformanceCounter(&qwCurrCount);
	return *pRand;
}

c_Timer::~c_Timer()
{
}