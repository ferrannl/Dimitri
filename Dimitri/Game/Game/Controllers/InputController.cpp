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
	switch (object) {
	case Input::Enums::EventEnum::KEY_PRESS_LEFT:
		std::cout << "links";
		break;
	case Input::Enums::EventEnum::KEY_PRESS_RIGHT:
		std::cout << "rechts";
		break;
	case Input::Enums::EventEnum::MOUSE_PRESSED: {
		std::tuple<int, int> pos = _input_controller->get_mouse_position();
		std::cout << "Position: " << std::get<0>(pos) << ", " << std::get<1>(pos);
		break;
	}
	default:
		std::cout << "geen reactie";
	}
}
