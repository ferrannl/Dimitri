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

/**
* \namespace Utility
* \brief Namespace for the utility project
*/
namespace Utility {
	/**
	* \namespace Utility::Time
	* \brief Namespace for the time classes in the utility project
	*/
	namespace Time {
		/**
		* \class Fps
		* \brief Class contains the methods calculate the fps
		*/
		class UTILITY_API Fps {
		protected:
			unsigned int _fps;
			unsigned int _fpscount;
			std::unique_ptr<Interval> _fpsinterval;
		public:
			Fps();

			/**
			* \brief Increments the fpscount and updates the fps if 1 seconds has passed
			*/
			void update();

			/**
			* \brief Returns the fps
			*/
			unsigned int get() const;
		};
	}
}