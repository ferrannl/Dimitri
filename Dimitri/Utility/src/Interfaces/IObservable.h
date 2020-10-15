#pragma once
#include <memory>
#include "IObserver.h"

namespace Interfaces {
	template <class T>
	class  __declspec(dllexport) IObservable {
	public:
		virtual void notify(const T& object) = 0;
		virtual void subscribe(std::shared_ptr<Interfaces::IObserver<T>> observer) = 0;
	};
}