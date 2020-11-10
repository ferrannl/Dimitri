#include "LevelController.h"
using namespace Game;

Game::Controllers::LevelController::LevelController()
{
	_level = std::make_shared<Game::Models::Level>();
	_level->load_objects();
	_level->add_music("level1", "/assets/audio/billy.wav");
	_running = false;
}

std::vector<std::shared_ptr<Graphics::Models::Texture>> Game::Controllers::LevelController::get_textures() const
{
	return _level->get_textures();
}

std::shared_ptr<Game::Models::Level> Game::Controllers::LevelController::get_level() const
{
	return _level;
}

void Game::Controllers::LevelController::start()
{
	if (!_running) {
		_running = true;
		_simulation_thread = std::thread(&Game::Controllers::LevelController::simulate, this);
		_level->play_music("level1");
	}
}

void Game::Controllers::LevelController::stop()
{
	if (_running) {
		_running = false;
		_simulation_thread.join();
		_level->stop_music("level1");
	}
}

void  Game::Controllers::LevelController::simulate() {
	while (_running) {
		sleep_for(1ms);
		_level->simulate();
		_level->get_player()->update();
	}
}