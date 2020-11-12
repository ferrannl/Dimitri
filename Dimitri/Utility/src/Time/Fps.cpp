#pragma once
#include "Fps.h"
using namespace Utility;

Time::Fps::Fps()
{
	_fps = { 0 };
	_fpscount = { 0 };
	_fpsinterval = std::make_unique<Time::Interval>();
}

void Time::Fps::update()
{
	// increase the counter by one
	_fpscount++;

	// one second elapsed? (= 1000 milliseconds)
	if (_fpsinterval->value() > 1000)
	{
		// save the current counter value to _fps
		_fps = _fpscount;

		// reset the counter and the interval
		_fpscount = 0;
		_fpsinterval->reset();
	}
}

unsigned int Time::Fps::get() const
{
	return _fps;
}

