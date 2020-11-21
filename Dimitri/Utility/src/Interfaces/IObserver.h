#pragma once

/**
* \namespace Utility
* \brief Namespace for the utility project
*/
namespace Utility {
	/**
	* \namespace Utility::Interfaces
	* \brief Namespace for the interfaces in the utility project
	*/
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