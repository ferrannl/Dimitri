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
	unsigned int _fps;
	unsigned int _fpscount;
	Interval _fpsinterval;

public:

	Fps();

	/**
	*	Update the fps
	*/
	void update();

	unsigned int get() const;
	void setShown(bool shown);
	bool getShown();

private:
	bool shown;

};