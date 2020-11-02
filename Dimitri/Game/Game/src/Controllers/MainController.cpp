#include "MainController.h"
using namespace Game;
Controllers::MainController::MainController()
{
	_window_controller = std::make_shared<WindowController>();
	_input_controller = std::make_shared<Controllers::InputController>();
	_input_controller->subscribe(_window_controller);
	_input_controller->poll_events();
}
