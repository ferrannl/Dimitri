#pragma once
#include "Fps.h"

Fps::Fps()
{
	_fps = { 0 };
	_fpscount = { 0 };
	setShown(true);
}

void Fps::update()
{
	// increase the counter by one
	_fpscount++;

	// one second elapsed? (= 1000 milliseconds)
	if (_fpsinterval.value() > 1000)
	{
		// save the current counter value to m_fps
		_fps = _fpscount;

		// reset the counter and the interval
		_fpscount = 0;
		_fpsinterval = Interval();
	}
}

unsigned int Fps::get() const
{
	return _fps;
}

void Fps::setShown(bool shown)
{
	this->shown = shown;
}

bool Fps::getShown()
{
	return shown;
}

