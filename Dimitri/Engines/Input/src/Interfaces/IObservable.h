#pragma once
#include "../enums/EventEnum.cpp"
#include "../interfaces/IObserver.h"

namespace Interfaces {
	class  __declspec(dllexport) IObservable {
	public:
		virtual void notify(Enums::EventEnum event) = 0;
		virtual void subscribe(std::shared_ptr<Interfaces::IObserver> observer) = 0;
	};
}