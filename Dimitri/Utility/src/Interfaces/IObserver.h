#pragma once

namespace Utility {
	namespace Interfaces {
		template <class T>
		class IObserver {
		public:
			virtual void update(const T& object) = 0;
		};
	}
}