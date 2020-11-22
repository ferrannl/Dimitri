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
		/**
		* \class IObserver
		* \brief Class contains the template method to update on a fired event
		*/
		class IObserver {
		public:
			/**
			*brief Updates the IObserver
			*/
			virtual void update(const T& object) = 0;
		};
	}
}