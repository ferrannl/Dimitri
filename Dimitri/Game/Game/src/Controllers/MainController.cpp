#include "MainController.h"
#include "../Commands/CommandFactory.h"

using namespace Game;

Controllers::MainController::MainController() {}

void Game::Controllers::MainController::setup()
{
	Commands::CommandFactory::init(this->shared_from_this());
	_shortcuts.push_back(std::make_unique<Models::Shortcut>(Commands::CommandFactory::instance()->get_command("exit_game"), Input::Enums::EventEnum::KEY_PRESS_QUIT));
	_shortcuts.push_back(std::make_unique<Models::Shortcut>(Commands::CommandFactory::instance()->get_command("open_credits_view"), Input::Enums::EventEnum::KEY_PRESS_C));
	_shortcuts.push_back(std::make_unique<Models::Shortcut>(Commands::CommandFactory::instance()->get_command("open_help_view"), Input::Enums::EventEnum::KEY_PRESS_H));
	_shortcuts.push_back(std::make_unique<Models::Shortcut>(Commands::CommandFactory::instance()->get_command("open_home_view"), Input::Enums::EventEnum::KEY_PRESS_ESC));
	_shortcuts.push_back(std::make_unique<Models::Shortcut>(Commands::CommandFactory::instance()->get_command("toggle_view"), Input::Enums::EventEnum::KEY_PRESS_F));

	_window_controller = std::make_shared<WindowController>();
	_audio_controller = std::make_shared<Game::Controllers::AudioController>();
	_level_controller = std::make_shared<Controllers::LevelController>(_window_controller, _audio_controller);
	_input_controller = std::make_shared<Controllers::InputController>();
	_home_controller = std::make_shared<Controllers::HomeController>(720, 1280, _audio_controller);
	_level_manager = std::make_shared<Managers::LevelManager>(_input_controller, _level_controller, _window_controller, _home_controller);
	_home_controller->load_buttons(_level_manager);
	_window_controller->create_window(720, 1280);
	_window_controller->set_scene_size(_window_controller->get_window_height(), _window_controller->get_window_width());
	_window_controller->set_textures(_level_controller->get_textures(), "level");
	_window_controller->add_textures(_home_controller->get_textures(), "home");
}

void Game::Controllers::MainController::run()
{	
	_input_controller->subscribe(this->shared_from_this());
	_input_controller->subscribe(_home_controller);	
	_input_controller->poll_events();
}


void Controllers::MainController::update(const Events::InputEvent& object)
{
	for (auto& s : _shortcuts) {
		if (s->get_event() == object.event_enum) {
			s->get_command()->execute();
			break;
		}
	}
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
