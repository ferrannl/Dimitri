#include "InputController.h"

Controllers::InputController::InputController()
{
	_event_facade = std::make_unique<Facades::EventFacade>();
	_mouse_facade = std::make_unique<Facades::MouseFacade>();
}

std::tuple<int, int> Controllers::InputController::get_mouse_position()
{
	return _mouse_facade->get_mouse_position();
}

void Controllers::InputController::notify(Enums::EventEnum event)
{
	_observer->update(event);
}

void Controllers::InputController::subscribe(std::shared_ptr<Interfaces::IObserver> observer)
{
	_observer = observer;
}


void Controllers::InputController::poll_events()
{
	Enums::EventEnum event = _event_facade->poll_event();
	if (event != Enums::EventEnum::NOT_SUPPORTED) {
		notify(event);
	}
}
