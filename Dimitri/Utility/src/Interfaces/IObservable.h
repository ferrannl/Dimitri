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
		class IObservable {
		public:
			/**
			* Call the update method on all observers
			*/
			virtual void notify(const T& object) = 0;
			/**
			* Subscribe to the observable
			*/
			virtual void subscribe(const std::shared_ptr<Interfaces::IObserver<T>>& observer) = 0;

			/**
			* Unsubscribe to the observable
			*/
			virtual void unsubscribe(const std::shared_ptr<IObserver<T>>& observer) = 0;
		};
	}
}