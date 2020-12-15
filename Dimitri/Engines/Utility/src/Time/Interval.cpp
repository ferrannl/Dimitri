#include "Interval.h"
using namespace Utility;

unsigned int Time::Interval::value() const
{
	return GetTickCount64() - initial_;
}

void Time::Interval::reset()
{
	initial_ = GetTickCount64();
}
