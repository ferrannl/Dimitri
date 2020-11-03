#pragma once
#include <Windows.h>
#include <sysinfoapi.h>

class Interval
{
private:
	unsigned int initial_;

public:
	/**
	* Constructor
	*/
	inline Interval() : initial_(GetTickCount())
	{
	}
	/**
	* Return tick count - initial
	*/
	inline unsigned int value() const
	{
		return GetTickCount() - initial_;
	}
};