#pragma once

#ifdef _WIN64
#ifdef UTILITY_EXPORTS
#define UTILITY_API __declspec(dllexport)
#else 
#define UTILITY_API __declspec(dllimport)
#endif
#else
#define UTILITY_API
#endif

namespace Utility {
	namespace Interfaces {
		template <class T>
		class IObserver {
		public:
			virtual void update(const T& object) = 0;
		};
	}
}