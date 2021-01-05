#pragma once
#include <memory>
#include "IObserver.h"

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
		* \class IObservable
		* \brief Class contains the template methods to notify the Observers
		*/
		class IObservable {
		public:
			/**
			* \brief Calls the update method on all observers
			*/
			virtual void notify(const T& object) = 0;
			/**
			* \brief Subscribes to the observable
			*/
			virtual void subscribe(const std::shared_ptr<Interfaces::IObserver<T>> observer) = 0;

			/**
			* \brief Unsubscribes to the observable
			*/
			virtual void unsubscribe(const std::shared_ptr<IObserver<T>> observer) = 0;
		};
	}
}