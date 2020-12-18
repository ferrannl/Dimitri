#include "MainController.h"
#include "../Mediators/CommandMediator.h"

using namespace Game;

Controllers::MainController::MainController() : Mediators::BaseComponent("MainController")
{
	_window_controller = std::make_shared<WindowController>();
	_audio_controller = std::make_shared<Game::Controllers::AudioController>();
	_cheats_controller = std::make_shared<Controllers::CheatsController>();
	_level_controller = std::make_shared<Controllers::LevelController>(_window_controller, _audio_controller);
	_input_controller = std::make_shared<Controllers::InputController>(_window_controller);
	_home_controller = std::make_shared<Controllers::HomeController>(720, 1280, _audio_controller);
	_credits_controller = std::make_shared<Controllers::CreditsController>(720, 1280);
	_help_controller = std::make_shared<Controllers::HelpController>(720, 1280);
	_save_game_controller = std::make_shared<Controllers::SaveGameController>(720, 1280);
	_advertisement_controller = std::make_shared<Controllers::AdvertisementController>(720, 1280);
	_level_manager = std::make_shared<Managers::LevelManager>(_input_controller, _level_controller, _window_controller, _home_controller);
	_level_controller->load_buttons();
	_highscore_manager = std::make_shared<Managers::HighscoreManager>(_input_controller, _audio_controller, _window_controller, _home_controller);
}

void Game::Controllers::MainController::run()
{
	Mediators::CommandMediator::init(this->shared_from_this());
	_window_controller->create_window(720, 1280);
	_window_controller->add_textures(_home_controller->get_textures(), Enums::ViewEnum::HOME);
	_window_controller->set_scene_size(_window_controller->get_window_height(), _window_controller->get_window_width());
	_level_controller->load_buttons();
	_highscore_manager->load_buttons();
	_input_controller->subscribe(this->shared_from_this());
	_input_controller->subscribe(_home_controller);
	_window_controller->set_textures(_level_controller->get_textures(Enums::LevelStateEnum::ACTIVE), Enums::ViewEnum::LEVEL);
	_window_controller->add_textures(_home_controller->get_textures(), Enums::ViewEnum::HOME);
	_window_controller->add_textures(_level_controller->get_level()->get_player()->get_extra_textures(), Enums::ViewEnum::HUD);
	_window_controller->add_textures(_credits_controller->get_textures(), Enums::ViewEnum::CREDTIS);
	_window_controller->add_textures(_help_controller->get_textures(), Enums::ViewEnum::HELP);
	_window_controller->add_textures(_level_controller->get_textures(Enums::LevelStateEnum::PAUSED), Enums::ViewEnum::PAUSE_LEVEL);
	_window_controller->add_textures(_level_controller->get_textures(Enums::LevelStateEnum::GAME_OVER), Enums::ViewEnum::GAME_OVER_LEVEL);
	_window_controller->add_textures(_level_controller->get_textures(Enums::LevelStateEnum::WIN), Enums::ViewEnum::WIN_LEVEL);
	_window_controller->add_textures(_advertisement_controller->get_textures(), Enums::ViewEnum::ADVERTISEMENT);
	_window_controller->add_textures(_highscore_manager->get_textures(), Enums::ViewEnum::HIGHSCORE);
	_window_controller->add_textures(_save_game_controller->get_textures(), Enums::ViewEnum::SAVE_GAME);
	_cheats_controller->initialize_textures(_window_controller->get_window_height(), _window_controller->get_window_width());
	_window_controller->set_textures(_cheats_controller->get_textures(), Enums::ViewEnum::CHEATS);

	_input_controller->poll_events();
}


void Controllers::MainController::update(const Events::InputEvent& object)
{
	Mediators::CommandMediator::instance()->notify(*this, object);
}

const std::shared_ptr<Controllers::InputController>& Game::Controllers::MainController::get_input_controller() const
{
	return _input_controller;
}

const std::shared_ptr<Controllers::AudioController>& Game::Controllers::MainController::get_audio_controller() const
{
	return _audio_controller;
}

const std::shared_ptr<Managers::LevelManager>& Game::Controllers::MainController::get_level_manager() const
{
	return _level_manager;
}

const std::shared_ptr<Managers::HighscoreManager>& Game::Controllers::MainController::get_highscore_manager() const
{
	return _highscore_manager;
}

const std::shared_ptr<Controllers::WindowController>& Game::Controllers::MainController::get_window_controller() const
{
	return _window_controller;
}

const std::shared_ptr<Controllers::LevelController>& Game::Controllers::MainController::get_level_controller() const
{
	return _level_controller;
}

const std::shared_ptr<Controllers::SaveGameController>& Game::Controllers::MainController::get_save_game_controller() const
{
	return _save_game_controller;
}

const std::shared_ptr<Controllers::HomeController>& Game::Controllers::MainController::get_home_controller() const
{
	return _home_controller;
}

const std::shared_ptr<Controllers::CreditsController>& Game::Controllers::MainController::get_credits_controller() const
{
	return _credits_controller;
}

const std::shared_ptr<Controllers::HelpController>& Game::Controllers::MainController::get_help_controller() const
{
	return _help_controller;
}

const std::shared_ptr<Controllers::CheatsController>& Game::Controllers::MainController::get_cheats_controller() const
{
	return _cheats_controller;
}
