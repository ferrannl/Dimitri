#pragma once
#include <memory>
#include "IObserver.h"

namespace Utility {
	namespace Interfaces {
		template <class T>
		class IObservable {
		public:
			virtual void notify(const T& object) = 0;
			virtual void subscribe(std::shared_ptr<Interfaces::IObserver<T>> observer) = 0;
		};
	}
}