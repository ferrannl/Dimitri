#pragma once
#include "../enums/EventEnum.cpp"

namespace Interfaces {
	class  __declspec(dllexport) IObserver{
	public:
		virtual void update(Enums::EventEnum event) = 0;
	};
}