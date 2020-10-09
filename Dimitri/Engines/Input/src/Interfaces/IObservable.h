#pragma once
#include "../enums/EventEnum.cpp"
namespace Interfaces {
	class  __declspec(dllexport) IObservable {
	public:
		virtual void notify(Enums::EventEnum event) = 0;
		virtual void subscribe(Interfaces::IObserver observer) = 0;
	};
}