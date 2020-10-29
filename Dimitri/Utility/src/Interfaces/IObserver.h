#pragma once

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
		class  UTILITY_API IObserver {
		public:
			virtual void update(const T& object) = 0;
		};
	}
}