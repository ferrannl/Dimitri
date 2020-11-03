#pragma once
#include <memory>
#include "IObserver.h"

namespace Utility {
	namespace Interfaces {
		template <class T>
		class IObservable {
		public:
			/**
			* Call the update method on all observers
			*/
			virtual void notify(const T& object) = 0;
			/**
			* Subscribe to the observable
			*/
			virtual void subscribe(std::shared_ptr<Interfaces::IObserver<T>> observer) = 0;
		};
	}
}