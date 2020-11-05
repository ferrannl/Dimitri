#pragma once

namespace Utility {
	namespace Interfaces {
		template <class T>
		class IObserver {
		public:
			/**
			* Update the IObserver
			*/
			virtual void update(const T& object) = 0;
		};
	}
}