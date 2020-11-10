#include "MainController.h"
using namespace Game;
Controllers::MainController::MainController()
{
	_window_controller = std::make_shared<WindowController>();
	_level_controller = std::make_shared<Controllers::LevelController>(_window_controller);
	_input_controller = std::make_shared<Controllers::InputController>();
	
	_input_controller->subscribe(_window_controller);
	_input_controller->subscribe(_level_controller);
	run();
}

void Game::Controllers::MainController::run()
{
	_window_controller->set_level_textures(_level_controller->get_textures());
	_input_controller->poll_events();
}
