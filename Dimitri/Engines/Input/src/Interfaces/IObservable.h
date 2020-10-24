#pragma once
#include "../interfaces/IObserver.h"

#ifdef _WIN64
#ifdef INPUT_EXPORTS
#define INPUT_API __declspec(dllexport)
#else INPUT_API __declspec(import)
#endif
#else
#define INPUT_API
#endif

namespace Interfaces {
	class  INPUT_API IObservable {
	public:
		virtual void notify(Enums::EventEnum event) = 0;
		virtual void subscribe(std::shared_ptr<Interfaces::IObserver> observer) = 0;
	};
}