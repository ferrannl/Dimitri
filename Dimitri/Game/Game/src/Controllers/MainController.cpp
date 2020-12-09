#include "MainController.h"
#include "../Mediators/CommandMediator.h"

using namespace Game;

Controllers::MainController::MainController() : Mediators::BaseComponent("MainController")
{
	_window_controller = std::make_shared<WindowController>();
	_audio_controller = std::make_shared<Game::Controllers::AudioController>();
	_level_controller = std::make_shared<Controllers::LevelController>(_window_controller, _audio_controller);
	_input_controller = std::make_shared<Controllers::InputController>(_window_controller);
	_home_controller = std::make_shared<Controllers::HomeController>(720, 1280, _audio_controller);
	_credits_controller = std::make_shared<Controllers::CreditsController>(720, 1280);
	_help_controller = std::make_shared<Controllers::HelpController>(720, 1280);
	_level_manager = std::make_shared<Managers::LevelManager>(_input_controller, _level_controller, _window_controller, _home_controller);
}

void Game::Controllers::MainController::run()
{
	Mediators::CommandMediator::init(this->shared_from_this());
	_window_controller->create_window(720, 1280);
	_window_controller->set_scene_size(_window_controller->get_window_height(), _window_controller->get_window_width());
	_level_controller->load_buttons();
	_input_controller->subscribe(this->shared_from_this());
	_input_controller->subscribe(_home_controller);
	_window_controller->set_textures(_level_controller->get_textures(Enums::LevelStateEnum::ACTIVE), "level");
	_window_controller->add_textures(_home_controller->get_textures(), "home");
	_window_controller->add_textures(_level_controller->get_level()->get_player()->get_extra_textures(), "hud_view");
	_window_controller->add_textures(_credits_controller->get_textures(), "credits");
	_window_controller->add_textures(_help_controller->get_textures(), "help");
	_window_controller->add_textures(_level_controller->get_textures(Enums::LevelStateEnum::PAUSED), "pause_level");
	_window_controller->add_textures(_level_controller->get_textures(Enums::LevelStateEnum::GAME_OVER), "game_over_level");
	_window_controller->add_textures(_level_controller->get_textures(Enums::LevelStateEnum::WIN), "win_level");
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

std::shared_ptr<Controllers::CreditsController> Game::Controllers::MainController::get_credits_controller() const
{
	return _credits_controller;
}

std::shared_ptr<Controllers::HelpController> Game::Controllers::MainController::get_help_controller() const
{
	return _help_controller;
}
