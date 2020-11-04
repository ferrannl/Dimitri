#include "Interval.h"
using namespace Utility;

unsigned int Time::Interval::value() const
{
	return GetTickCount() - initial_;
}

void Time::Interval::reset()
{
	initial_ = GetTickCount();
}
