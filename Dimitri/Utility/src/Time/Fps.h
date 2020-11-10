#pragma once
#include "Interval.h"
#include <memory>

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
	namespace Time {
		class UTILITY_API Fps
		{
		private:
			bool shown;
		protected:
			unsigned int _fps;
			unsigned int _fpscount;
			std::unique_ptr<Interval> _fpsinterval;
		public:
			Fps();

			/**
			*	Update the fps
			*/
			void update();

			unsigned int get() const;
		};
	}
}