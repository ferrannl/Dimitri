#include "Switch.h"
#include "../Controllers/LevelController.h"

Game::Models::Switch::Switch(int x, int y, int z, int height, int width, Game::Enums::StateEnum state) : Game::Models::IInteractable(x, y, z, height, width, state), _switch_x(x)
{
	initialize_textures();
	create_shape(x, y, height, width, true, true, PhysicsCollision::Enums::ShapeEnum::Square);
}

void Game::Models::Switch::initialize_textures()
{
	add_texture(Game::Enums::StateEnum::LEFT, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/switch01.png" }, Graphics::Enums::FlipEnum::NONE, false));
	add_texture(Game::Enums::StateEnum::RIGHT, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/switch01.png" }, Graphics::Enums::FlipEnum::HORIZONTAL, false));
	get_texture()->set_visible(true);
}


void Game::Models::Switch::interact(Controllers::LevelController* ctrl)
{
	if (_state == Game::Enums::StateEnum::LEFT) {
		set_state(Game::Enums::StateEnum::RIGHT);
		ctrl->turn_off_light(_switch_x);
	}
	else {
		set_state(Game::Enums::StateEnum::LEFT);
	}
}

void Game::Models::Switch::set_light(const int x)
{
	_switch_x = x;
}

