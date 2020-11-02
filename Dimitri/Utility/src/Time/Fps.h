#pragma once
#include "Interval.h"

#ifdef _WIN64
#ifdef UTILITY_EXPORTS
#define UTILITY_API __declspec(dllexport)
#else 
#define UTILITY_API __declspec(dllimport)
#endif
#else
#define UTILITY_API
#endif

class UTILITY_API Fps
{
protected:
	unsigned int m_fps;
	unsigned int m_fpscount;
	Interval m_fpsinterval;

public:
	/*
	* Constructor
	*/
	Fps();

	/*
	*	Update
	*/
	void update();

	/*
	* Get fps
	*/
	unsigned int get() const;
};