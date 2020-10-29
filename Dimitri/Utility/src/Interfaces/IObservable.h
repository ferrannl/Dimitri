#pragma once
#include <memory>
#include "IObserver.h"

#ifdef _WIN64
#ifdef UTILITY_EXPORTS
#define UTILITY_API __declspec(dllexport)
#else 
#define UTILITY_API __declspec(dllimport)
#endif
#else
#define GRAPHICS_API
#endif

namespace Utility {
	namespace Interfaces {
		template <class T>
		class  UTILITY_API IObservable {
		public:
			virtual void notify(const T& object) = 0;
			virtual void subscribe(std::shared_ptr<Interfaces::IObserver<T>> observer) = 0;
		};
	}
}