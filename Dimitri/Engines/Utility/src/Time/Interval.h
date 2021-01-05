#pragma once
#include <Windows.h>
#include <sysinfoapi.h>

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
		* \class Interval
		* \brief Class contains the methods calculate the interval
		*/
		class UTILITY_API Interval {
		private:
			unsigned int initial_;
		public:
			inline Interval() : initial_(GetTickCount64()) {}

			/**
			* \brief Returns the amount of ticks from the initial ticks
			*/
			unsigned int value() const;

			/**
			* \brief Resets the initial ticks to the current ticks
			*/
			void reset();
		};

	}
}