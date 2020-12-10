#include "HighscoreManager.h"
#include "../Controllers/HomeController.h"
#include "../Controllers/InputController.h"
#include "../Controllers/WindowController.h"
#include "../Controllers/HomeController.h"


Game::Managers::HighscoreManager::HighscoreManager(std::shared_ptr<Game::Controllers::InputController> input_controller, std::shared_ptr<Game::Controllers::AudioController> audio_controller, std::shared_ptr<Game::Controllers::WindowController> window_controller, std::shared_ptr<Game::Controllers::HomeController> home_controller)
{
	_input_controller = input_controller;
	_audio_controller = audio_controller;
	_window_controller = window_controller;
	_home_controller = home_controller;
}

void Game::Managers::HighscoreManager::load_highscore()
{
	if (_window_controller->is_active("home")) {
		_input_controller->unsubscribe(_home_controller);
		_window_controller->toggle_view_visibility("timer");
		_window_controller->clear_views();
		_audio_controller->play_audio("highscore");
		_window_controller->open_view("highscore");
		_window_controller->set_scene_size(_window_controller->get_window_height(), _window_controller->get_window_width());
	}
}


