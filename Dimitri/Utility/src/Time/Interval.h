#pragma once
#include <Windows.h>
#include <sysinfoapi.h>

namespace Utility {
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