#include "MainController.h"
#include "../Mediators/CommandMediator.h"

using namespace Game;

Controllers::MainController::MainController() : Mediators::BaseComponent("MainController")
{
	_window_controller = std::make_shared<WindowController>();
	_audio_controller = std::make_shared<Game::Controllers::AudioController>();
	_level_controller = std::make_shared<Controllers::LevelController>(_window_controller, _audio_controller);
	_input_controller = std::make_shared<Controllers::InputController>();
	_home_controller = std::make_shared<Controllers::HomeController>(720, 1280, _audio_controller);
	_level_manager = std::make_shared<Managers::LevelManager>(_input_controller, _level_controller, _window_controller, _home_controller);
	_home_controller->load_buttons(_level_manager);
}

void Game::Controllers::MainController::run()
{
	Mediators::CommandMediator::init(this->shared_from_this());
	_window_controller->create_window(720, 1280);
	_window_controller->set_scene_size(_window_controller->get_window_height(), _window_controller->get_window_width());
	_input_controller->subscribe(this->shared_from_this());
	_input_controller->subscribe(_home_controller);
	_window_controller->set_textures(_level_controller->get_textures(), "level");
	_window_controller->add_textures(_home_controller->get_textures(), "home");
	_input_controller->poll_events();
}


void Controllers::MainController::update(const Events::InputEvent& object)
{
	Mediators::CommandMediator::instance()->notify(*this, object);
}

std::shared_ptr<Controllers::InputController> Game::Controllers::MainController::get_input_controller() const
{
	return _input_controller;
}

std::shared_ptr<Controllers::AudioController> Game::Controllers::MainController::get_audio_controller() const
{
	return _audio_controller;
}

std::shared_ptr<Managers::LevelManager> Game::Controllers::MainController::get_level_manager() const
{
	return _level_manager;
}

std::shared_ptr<Controllers::WindowController> Game::Controllers::MainController::get_window_controller() const
{
	return _window_controller;
}

std::shared_ptr<Controllers::LevelController> Game::Controllers::MainController::get_level_controller() const
{
	return _level_controller;
}

std::shared_ptr<Controllers::HomeController> Game::Controllers::MainController::get_home_controller() const
{
	return _home_controller;
}
