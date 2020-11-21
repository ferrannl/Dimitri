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
		class Interval {
		private:
			unsigned int initial_;
		public:
			inline Interval() : initial_(GetTickCount64()) {}
			/**
			* Return amount ticks from initial ticks
			*/
			unsigned int value() const;

			void reset();
		};

	}
}