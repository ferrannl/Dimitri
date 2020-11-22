#pragma once
#include <Windows.h>
#include <sysinfoapi.h>

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
		class Interval {
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