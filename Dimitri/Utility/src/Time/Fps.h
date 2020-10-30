#pragma once
#include "Interval.h"

class __declspec(dllexport) Fps
{
protected:
	unsigned int m_fps;
	unsigned int m_fpscount;
	Interval m_fpsinterval;

public:
	// Constructor
	Fps();

	// Update
	void update();

	// Get fps
	unsigned int get() const;
};