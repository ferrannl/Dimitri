#include "HighscoreButton.h"

Game::Models::Buttons::HighscoreButton::HighscoreButton(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, int scene_height) : Game::Models::Button(x, y, z, height, width, state, scene_height)
{
}

void Game::Models::Buttons::HighscoreButton::interact()
{
	/*_input_controller->unsubscribe(_home_controller);
	_window_controller->clear_views();
	_window_controller->open_view("home");
	_window_controller->open_view("fps");
	_window_controller->set_scene_size(_level_controller->get_level()->get_level_height(), _level_controller->get_level()->get_level_width());
	_input_controller->subscribe(_level_controller);
	_level_controller->start();*/
}
