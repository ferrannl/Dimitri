#include "LevelManager.h"
#include "../Controllers/HomeController.h"
#include "../Controllers/InputController.h"
#include "../Controllers/WindowController.h"
#include "../Controllers/LevelController.h"

using namespace Game;

Game::Managers::LevelManager::LevelManager(std::shared_ptr<Game::Controllers::InputController> input_controller, std::shared_ptr<Game::Controllers::LevelController> level_controller, std::shared_ptr<Game::Controllers::WindowController> window_controller, std::shared_ptr<Game::Controllers::HomeController> home_controller)
{
	_input_controller = input_controller;
	_window_controller = window_controller;
	_level_controller = level_controller;
	_home_controller = home_controller;
}

void Game::Managers::LevelManager::load_level()
{
	_input_controller->unsubscribe(_home_controller);
	_input_controller->subscribe(_level_controller);
	_window_controller->set_scene_size(_level_controller->get_level()->get_height(), _level_controller->get_level()->get_width());
	_level_controller->start();
}

void Game::Managers::LevelManager::set_level_controller(const std::shared_ptr<Game::Controllers::LevelController>& level_controller)
{
	_level_controller = level_controller;
}


std::shared_ptr<Game::Controllers::WindowController> Game::Managers::LevelManager::get_window_controller() const
{
	return _window_controller;
}
