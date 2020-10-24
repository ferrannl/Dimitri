#pragma once
#include "../enums/EventEnum.cpp"

#ifdef _WIN64
#ifdef INPUT_EXPORTS
#define INPUT_API __declspec(dllexport)
#else INPUT_API __declspec(import)
#endif
#else
#define INPUT_API
#endif

namespace Interfaces {
	class  INPUT_API IObserver{
	public:
		virtual void update(Enums::EventEnum event) = 0;
	};
}