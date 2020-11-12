#pragma once
#include "../Facades/EventFacade.h"
#include "../Facades/MouseFacade.h"
#include <SDL.h>
#include "../../../../Utility/src/Interfaces/IObservable.h"
#include "../../../../Utility/src/Interfaces/IObserver.h"
#include <chrono>
#include <thread>
#include <vector>
using namespace std::this_thread;
using namespace std::chrono_literals;

#ifdef _WIN64
#ifdef INPUT_EXPORTS
#define INPUT_API __declspec(dllexport)
#else 
#define INPUT_API __declspec(dllimport)
#endif
#else
#define INPUT_API
#endif

/**
* Namespace for the input engine
*/
namespace Input {
	/**
	* Namespace for the controllers
	*/
	namespace Controllers {
		/**
		* Is being used as an observable and contains the method to get fired events
		*/
		class INPUT_API InputController : public Utility::Interfaces::IObservable<Enums::EventEnum> {
		private:
			/**
			* The observers that observes key and mouse events
			*/
			std::vector<std::shared_ptr<Utility::Interfaces::IObserver<Enums::EventEnum>>> _observers;

			/**
			* The facade that contains the method from SDL which are needed for mouse events
			*/
			std::unique_ptr<Facades::MouseFacade> _mouse_facade;

			/**
			* The facade that contains the method from SDL which are needed for keyboard events
			*/
			std::unique_ptr<Facades::EventFacade> _event_facade;

		public:
			InputController();

			/**
			* Returns the X and Y of where the mouse clicked on the screen
			*/
			std::tuple<int, int> get_mouse_position();

			/**
			* notifies the observers
			*/
			void notify(const Enums::EventEnum& object);

			/**
			* Subscribes on this observable
			*/
			void subscribe(const std::shared_ptr<Utility::Interfaces::IObserver<Enums::EventEnum>>& observer);

			/**
			* Unsubscribes on this observable
			*/
			void unsubscribe(const std::shared_ptr<Utility::Interfaces::IObserver<Enums::EventEnum>>& observer);
			
			/**
			* Polls if events are fired
			*/
			void poll_events();
		};
	}
}