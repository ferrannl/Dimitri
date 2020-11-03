#include "InputController.h"

using namespace Game;
Controllers::InputController::InputController() {
	_input_controller = std::make_unique<Input::Controllers::InputController>();
}

void Game::Controllers::InputController::poll_events() {
	_input_controller->subscribe(this->shared_from_this());
	_input_controller->poll_events();
}

void Game::Controllers::InputController::update(const Input::Enums::EventEnum& object)
{
	std::tuple<int, int> pos = _input_controller->get_mouse_position();
	notify(Game::Models::InputEvent(object, pos));
}

void Game::Controllers::InputController::notify(const Game::Models::InputEvent& object) {
	_observer->update(object);
}

void Game::Controllers::InputController::subscribe(std::shared_ptr<Utility::Interfaces::IObserver<Game::Models::InputEvent>> observer) {
	_observer = observer;
}
