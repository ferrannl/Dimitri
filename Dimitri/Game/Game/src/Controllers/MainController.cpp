#include "MainController.h"
using namespace Game;
Controllers::MainController::MainController()
{
	_window_controller = std::make_shared<WindowController>();
	_level_controller = std::make_shared<Controllers::LevelController>();
	_input_controller = std::make_shared<Controllers::InputController>();
	_level = _level_controller->get_level();
	_level->add_music("level1", "/assets/audio/billy.wav");
	_level->play_music("level1");
	_input_controller->subscribe(_window_controller);
	_input_controller->subscribe(_level_controller);
	run();
}

void Game::Controllers::MainController::run()
{
	for (auto texture : _level_controller->get_textures()) {

		_window_controller->add_texture(texture);
	}
	std::thread draw_thread(&MainController::draw, this);
	_input_controller->poll_events();
	draw_thread.join();
}

void Game::Controllers::MainController::draw()
{
	while (true) {
		sleep_for(5ms);
		_window_controller->update_window();
	}
	_window_controller->destroy_window();
}
