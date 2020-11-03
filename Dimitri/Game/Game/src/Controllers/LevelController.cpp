#include "LevelController.h"

Game::Controllers::LevelController::LevelController()
{
	_level = std::make_shared<Game::Models::Level>();
	_level->load_objects();
}

std::vector<std::shared_ptr<Graphics::Models::Texture>> Game::Controllers::LevelController::get_textures()
{
	return _level->get_textures();
}

void Game::Controllers::LevelController::update(const Game::Events::InputEvent& object)
{
	switch (object.event_enum) {
	case Input::Enums::EventEnum::KEY_PRESS_LEFT:
		_level->get_player()->set_state("left");
		_level->get_player()->set_x(_level->get_player()->get_x() - 5);
		break;
	case Input::Enums::EventEnum::KEY_PRESS_RIGHT:
		_level->get_player()->set_state("right");
		_level->get_player()->set_x(_level->get_player()->get_x() + 5);
		break;
	}
}

std::shared_ptr<Game::Models::Level> Game::Controllers::LevelController::get_level()
{
	return _level;
}
