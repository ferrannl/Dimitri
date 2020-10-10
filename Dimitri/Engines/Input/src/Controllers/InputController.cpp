#include "InputController.h"

Controllers::InputController::InputController()
{
	_event_facade = std::make_unique<Facades::EventFacade>();
	_mouse_facade = std::make_unique<Facades::MouseFacade>();
	_observers = std::shared_ptr<Interfaces::IObserver>();
}

std::tuple<int, int> Controllers::InputController::get_mouse_position()
{
	return _mouse_facade->get_mouse_position();
}

void Controllers::InputController::notify(Enums::EventEnum event)
{
	//for (std::shared_ptr<Interfaces::IObserver> observer : _observers) {
	_observers->update(event);
	//}
}

void Controllers::InputController::subscribe(std::shared_ptr<Interfaces::IObserver> observer)
{
	_observers = observer;
}


void Controllers::InputController::poll_events()
{
	while (true) {
		SDL_Delay(5);
		Enums::EventEnum event = _event_facade->poll_event();
		if (event != Enums::EventEnum::NOT_SUPPORTED) {
			notify(event);
		}
	}
}
