#pragma once
#include "Fps.h"

Fps::Fps()
{
	m_fps = { 0 };
	m_fpscount = { 0 };
}

void Fps::update()
{
	/**
	* increase the counter by one
	*/
	m_fpscount++;

	/*
	* one second elapsed? (= 1000 milliseconds)
	*/
	if (m_fpsinterval.value() > 1000)
	{
		/*
		* save the current counter value to m_fps
		*/
		m_fps = m_fpscount;

		/*
		*reset the counter and the interval
		*/
		m_fpscount = 0;
		m_fpsinterval = Interval();
	}
}

unsigned int Fps::get() const
{
	return m_fps;
}